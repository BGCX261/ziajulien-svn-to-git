#include "ManageClient.h"


ManageClient::ManageClient(zAPI::IConfig *conf)
{
	_listClient = new std::list<Client *>();
	this->_Conf = conf;
}

ManageClient::~ManageClient(void)
{
}

bool					ManageClient::addClient(zAPI::IClientSocket *iclient)
{
	if (iclient != 0)
		this->_listClient->push_back(new Client(iclient));
	else
		return false;
	return true;
}
std::list<Client *>*	ManageClient::getListClient()
{
	return this->_listClient;
}

void					ManageClient::fillSelect(fd_set *fdread, fd_set *fdwrite)
{
	std::list<Client *>::iterator ii;
	for(ii=this->_listClient->begin(); ii != this->_listClient->end(); ++ii)  /* prepare select read/write client*/
	{
		Client * temp = *ii;
		if (temp->getClientSocket()->isClosed() == true)
		{

		}

		else
		{
			if (temp->getClientSocket()->isClosed() == false)
				FD_SET(temp->getClientSocket()->getPort(), fdread);
			if (temp->getIsSend() == true)
				FD_SET(temp->getClientSocket()->getPort(), fdwrite);
		}
	}
}

void					ManageClient::execClient(fd_set *fdread, fd_set *fdwrite)
{
	HANDLE                      _hProcessThread[1];
	struct thread_param         _ThreadParam;

	int ret;
	std::list<Client *>::iterator ii;
	for(ii=this->_listClient->begin(); ii != this->_listClient->end(); ++ii)  /* prepare select read/write client*/
	{
		Client * temp = *ii;
		if (FD_ISSET(temp->getClientSocket()->getPort(),fdread)) /* read */
		{
			char *toto = new char[2];
			ret = 0;
			toto[ret] = '\0';

			ret = temp->getClientSocket()->recv(toto,1);
			std::cout << ret << std::endl;
			if (ret <= 0)
				temp->getClientSocket()->close(true);
			else
			{
				toto[ret] = '\0';
				temp->addRecv(toto);
				int p = checkBuf(toto[0], temp);
				if(p == 1)
				{
					_ThreadParam.conf = this->_Conf;
					_ThreadParam.MgrClient = this;
					_ThreadParam.Cl = temp;
					_hProcessThread[0] = CreateThread(NULL, 0,&ManageClient::ThreadLauncher, &_ThreadParam,0,NULL);
					//std::cout << "fin reception donc " << std::endl << temp->getRecv() << std::endl;
					if ( _hProcessThread == NULL ){
						std::cerr << "ERROR : CreateThread Problem" <<GetLastError()<< std::endl;

					}
					else
					{
						WaitForMultipleObjects ( 1, _hProcessThread, TRUE, INFINITE);
						CloseHandle ( _hProcessThread[0] ) ;
						std::cout << "retour :" << _hProcessThread << std::endl;
						//closesocket(_NewConnection);
					}
				}
				delete [] toto;
			}
		}
		if (FD_ISSET(temp->getClientSocket()->getPort(),fdwrite))
		{
			ret = 0;
			int lenght = 0;
			int deleteTemp = 0;
			const char *buf;
			char * _answer = new char[1049];
			const char * _temp = new char[1049];

			lenght = temp->getResponse().length();
			if (lenght > 1048)
				lenght = 1048;
			if (lenght > 0)
			{
				ret = temp->getClientSocket()->send(temp->getResponse().c_str(),lenght);
				temp->subResponse(ret);
			}
			else
				temp->setIsSend(false);
		}
		temp = 0;
	}
}

zAPI::IModuleManager	*ManageClient::ChooseCommand(const HttpRequest& req, HttpResponse* res)
{
	if (req.getCommand().compare("GET") == 0)
		return new Get();
	else if (req.getCommand().compare("DELETE") == 0)
		return new Delete();
	else if (req.getCommand().compare("OPTION") == 0)
		return new Options();
	res->setResponseStatus(400);
	res->setResponseValue("Bad Request");
	return 0;
}

DWORD					ManageClient::ClientThread(zAPI::IConfig *conf, Client *Cl)
{
	Parser *parse = new Parser();
	ManageRequest *MgrRequest = new ManageRequest();

	HttpRequest req;
	HttpResponse res;
	if (MgrRequest->call(IModule::Event::onPreReceiveEvent,&req,&res) == IModule::ChainStatus::CONTINUE)
	{
#ifdef _RECV_
		std::cout << Cl->getRecv() << std::endl;
#endif

		parse->parse(&req,Cl->getRecv());

		zAPI::IModuleManager* myModule =  this->ChooseCommand(req,&res);
		if(myModule != 0)
		{
			myModule->call(zAPI::IModule::Event::onPreBuildEvent,&req,&res);
			myModule->call(zAPI::IModule::Event::onPostBuildEvent,&req,&res);
		}
		this->createBodyError(&req,&res);
		createResponse(&req, &res, Cl);
	}
	delete (res.getCurrentStream());
	delete (MgrRequest);
	delete (parse);
	return 0;
}

void					ManageClient::createResponse(IHttpRequest *req, IHttpResponse *res, Client *Cl)
{
	std::stringstream str;
	std::map<std::string, std::string> mapRes;

	str << req->getProtocol() << " ";
	str << res->getResponseStatus() << " ";
	str << res->getResponseValue() << "\n";
	std::map<std::string, std::string>::iterator it;
	mapRes = res->getHeaderOptions();

	for (it = mapRes.begin();it != mapRes.end(); ++it)
	{
		std::string key =  (*it).first;
		std::string value =  (*it).second;
		str << key << ": " << value << "\n";
	}
	str << "\n";
	char *tt = new char [res->getCurrentStream()->getSize() + 1];
	tt[res->getCurrentStream()->read(tt,res->getCurrentStream()->getSize())] = '\0';
	str << tt;
#ifdef _SEND_
	std::cout << str.str().c_str() << std::endl;
#endif

	Cl->setResponse(str.str().c_str());
	Cl->setIsSend(true);
}

void					ManageClient::createBodyError(IHttpRequest *req, IHttpResponse *res)
{
	if (res->getResponseStatus() != 200)
	{
		std::stringstream body;

		body << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" << "\n";
		body << "<head>" << "\n" << "<title>"<< res->getResponseStatus() << " " << res->getResponseValue() <<"</title>" << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\" />" << "\n";
		body << "</head>" << "\n" << "<body>" << "\n" << "<body>" << "<h1>Error :" << res->getResponseValue() <<"</h1>" << "\n" << "\n" << "</body>" << "\n" << "</html>";

		char taile[20];
		sprintf(taile, "%d",body.str().length());
		std::string lgth = taile;
		res->setHeaderOption("Content-Lenght", lgth);
		res->setHeaderOption("Content-Type", "text/html");

		res->appendStream(new ResponseStream(&body));
	}
}

int						ManageClient::checkBuf(char c, Client * temp)
{
	int p;
	p = 0;

	if(c == 13 && temp->getCommand() == 1)
	{
		p = 1;
		temp->setCommand(0);
	}
	else
	{
		p = 0;
		temp->setCommand(0);
	}
	if (c == 10 && temp->getCommand() == 0)
	{
		p = 0;
		temp->setCommand(1);
	}
	return p;
}
