#include "Zia.h"

Zia::Zia(void)
{
}

Zia::Zia(zAPI::IConfig* Config)
{
	this->_Config = Config;
	_MngNet = new ManageNetwork();
	_MgrClient = new ManageClient(this->_Config);
}

Zia::~Zia(void)
{
	delete (this->_Config);
	delete (this->_MgrClient);
	delete this->_MngNet;
}

bool		Zia::StartServ(Serveur *Serv)
{

	if(Serv->Init(_Config) == zAPI::IModule::ChainStatus::STOP)
		return false;
	if(Serv->createSocket() == zAPI::IModule::ChainStatus::STOP)
		return false;
	if(Serv->BindSocket() == zAPI::IModule::ChainStatus::STOP)
		return false;
	if(Serv->ListenSocket() == zAPI::IModule::ChainStatus::STOP)
		return false;
	return true;

}

bool		Zia::MainLoop(Serveur *Serv)
{
	bool		Run;
	IClientSocket *client;
	SOCKET i;
	int ret;

	Run = true;
	while(Run != false)
	{
		FD_ZERO(&this->_fdread);
		FD_ZERO(&this->_fdwrite);
		FD_SET(Serv->GetListenSocks(),&this->_fdread);
		this->_MgrClient->fillSelect(&this->_fdread, &this->_fdwrite);
		ret = select(0,&this->_fdread,&this->_fdwrite,NULL,0);
		if (ret > 0)
		{
			if (FD_ISSET(Serv->GetListenSocks(),&this->_fdread))
			{
				if ((client = _MngNet->call(zAPI::IModule::Event::onAcceptEvent, Serv->GetListenSocks(),_Config)) == 0)	
					std::cout << "Client Refuse" << std::endl;
				else
				{
					this->_MgrClient->addClient(client);
				}
			}
			this->_MgrClient->execClient(&this->_fdread, &this->_fdwrite);
		}
	}
	return true;
}

bool		Zia::StopServ(Serveur *Serv)
{
	return false;
}