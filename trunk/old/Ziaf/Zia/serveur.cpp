#include <winsock2.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include "tinyxml.h"
#include "serveur.h"

#define _MAX_HOST_LENGTH_ 100

using namespace std;

map<string,string> serveur::getXML()
{
	TiXmlDocument doc("conf.xml");
if(!doc.LoadFile()){
    cerr << "erreur lors du chargement" << endl;
    cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << endl;
   
}
string temp1;
string temp2;


TiXmlHandle hdl(&doc);
TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();

if(!elem){
	cerr << "le noeud à atteindre n'existe pas" << endl;
}


while (elem){
	temp2 = elem->Value();
	temp1 = elem->GetText();
	Xmlparsing[temp2] = temp1;
	elem = elem->NextSiblingElement(); // iteration 
}
return Xmlparsing;
}

serveur::serveur(){

	running	= false;
	std::map<string,string> temp;

	temp = getXML();
	/* recupere le port */
	if (getMap("Port", temp).compare("Erreur") == 0)
	{
		cout << "le fichier de conf ne contient pas de port" << endl;
		system("pause");
		exit(0);
	}
	else
	{
		port = atoi(getMap("Port", temp).c_str());
	}
}

serveur::serveur(int p){
	port	= p;
	running	= false;
}

string serveur::getMap(string entry, std::map<string,string> temp)
{
	std::map<string,string>::iterator it;
	
	
	for (it = temp.begin (); it != temp.end (); ++it)
	{
		std::string key = (*it).first;
		string number = (*it).second;
		if (strcmp(key.c_str(), entry.c_str()) == 0)
		{
			return(number);
		}
	}
	return "Erreur";
}

int serveur::init(){
	WSADATA	      wsaData;
	if(WSAStartup(MAKEWORD(2,2), &wsaData ) != 0 ){
		cerr <<"ERROR : WSAStartup Problem "<< endl;
		return 1;
	}
	ServerAddr.sin_addr.s_addr = INADDR_ANY;
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons( port );
	cout <<"Zia Initialise" << endl;
	return 0;
}

int serveur::start (){
	SOCKADDR_IN                 _ClientAddr;
	int                         _ClientAddrLen;
	HANDLE                      _hProcessThread[1];
	SOCKET                      _NewConnection;
	struct thread_param         _ThreadParam;
	vector<SOCKET> listPort;




	/* SOCKET */
	if( ( ListeningSocket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP ) ) == INVALID_SOCKET ) /* creation du socket */
	{
		cerr << "ERROR : impossible de cree socket" << endl;
		WSACleanup();
		return 1;
	}


	/* BIND */
	if( bind( ListeningSocket, (SOCKADDR *)&ServerAddr, sizeof( ServerAddr ) ) == SOCKET_ERROR ) /* defini la liaison entre le programmme et la socket*/
	{
		cerr << "ERROR : bind a echoue avec l'erreur " << endl;
		cerr << "Le port est peut-etre deje utilise par un autre processus " << endl;
		closesocket( ListeningSocket );
		WSACleanup();
		return 1;
	}

	/* LISTEN */
	if( listen( ListeningSocket, 5 ) == SOCKET_ERROR ) 
	{ 
		cerr << "ERROR : listen Problem"<< endl;
		closesocket( ListeningSocket );
		WSACleanup();
		return 1;
	}
	cout << "Zia demarre Port : " << port << endl;
	running = true;
	_ClientAddrLen = sizeof( _ClientAddr );

	while(running){

		if((_NewConnection = accept( ListeningSocket, (SOCKADDR *) &_ClientAddr, &_ClientAddrLen)) == INVALID_SOCKET){
			cerr  << "ERROR : accept Problem" << WSAGetLastError() << endl;;
			closesocket( ListeningSocket );
			WSACleanup();
			return 1;
		}

		_ThreadParam.ser = this;
		_ThreadParam.soc = _NewConnection;

		cout << "client IP : " << inet_ntoa( _ClientAddr.sin_addr ) << " ,port = " <<ntohs( _ClientAddr.sin_port ) << endl;
			_hProcessThread[0] = CreateThread(NULL, 0,&serveur::ThreadLauncher, &_ThreadParam,0,NULL);
			if ( _hProcessThread == NULL ){
				cerr << "ERROR : CreateThread Problem" <<GetLastError()<< endl;
			
			}
			else
			{
				WaitForMultipleObjects ( 1, _hProcessThread, TRUE, INFINITE);
				CloseHandle ( _hProcessThread[0] ) ;
				//cout << "retour :" << _hProcessThread << endl;
				//closesocket(_NewConnection);
			}
	}

	return 0;
}

string			serveur::getRequest()
{
	return this->_Reponse;
}

void			serveur::setAnswer(std::string answer)
{
	_Answer = answer;
}

void			serveur::readClient(SOCKET soc)
{
	bool quit;
	quit = false;
	int msg_lenght;
	char msg_rcv[16];
	int end_line;

	end_line = 0;
	while (quit != true)
	{
		msg_lenght = recv(soc, msg_rcv, 1 , 0) ; /*reception du message caractere par caratere*/
		msg_rcv[msg_lenght] = '\0';
		_Reponse += msg_rcv;
		if(msg_rcv[0] == 13 && end_line == 1)
			quit = true;
		else
			end_line = 0;
		if(msg_rcv[0] == 10)
			end_line = 1;

	}
}

void		serveur::readClient(SOCKET soc, int len)
{
	bool quit;
	quit = false;
	int msg_lenght;
	char msg_rcv[2];
	int i;
	i = 0;
	if (len > 0)
	{
		while (quit != true)
		{
			msg_lenght = recv(soc, msg_rcv, 1 , 0) ; /*reception du message caractere par caratere*/
			msg_rcv[msg_lenght] = '\0';
			if (msg_lenght > 0)
			{
			_Reponse += msg_rcv;
			i++;
			if(i > len+1)
				quit = true;
			}
			else
				quit = true;

		}
	}
}

void			serveur::sendClient(SOCKET soc)
{
	string msgSend;
	const char * buf;
	bool flag = true;
	int lenght_send;
	int i;

	#ifdef _SEND_
	cout << _Answer << endl;
	#endif
	msgSend = _Answer;
	_Answer.clear();
	while (flag != false)
	{
		i = (int)msgSend.length();
		buf = msgSend.c_str();
		if (i > 1048)
			i = 1048;
		if (i != 0)
		{
			lenght_send = send(soc, buf, i, 0);
			msgSend = msgSend.substr(lenght_send);
		}
		else
		{
			flag = false;
		}
	}
	
	_Reponse.clear();
	msgSend.clear();
}

DWORD serveur::ClientThread(SOCKET soc){
	parse = new Parsing();

	bool connect;


	connect = false;

	readClient(soc);
#ifdef _norm_
	parse->parser(this->getRequest());
#endif
#ifdef _gio_
	parse->parser("Delete /test/test.txt http/1.1\n");
#endif
	/*	cout << " retour fct depalm : " << parse->check("connection").c_str() << endl;
	if(parse->check("connection").compare("close") == 0 || parse->check("connection").compare("keep-alive") == 0)
	connect = true;*/
	if (parse->check("content-length").compare("Erreur") != 0)
	{
		int len = atoi(parse->check("content-length").c_str());
		readClient(soc, len);
	}
	setAnswer(do_client());
#ifdef _RECV_
	cout << _Reponse << endl;
#endif 
	

	sendClient(soc);


	//closesocket( soc );
	_Reponse.clear();
	/*Virtual  Do_client*/
	cout << " fin de reception " << endl;
	delete (parse);
	return 0;
}


string serveur::do_client()
{
	return "toto";
}

Parsing *serveur::getParse()
{
	return parse;
}

std::string serveur::date()
{
	time_t t;
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	strftime (buffer,80,"%a, %d %b %Y %X GMT",timeinfo);
	return(buffer);
}
std::string serveur::date(int jour, int heure)
{
	time_t t;
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];
	heure = heure * 3600;
	jour = jour * 84600;

	time ( &rawtime);
	rawtime += (heure + jour);
	timeinfo = localtime ( &rawtime );
	strftime (buffer,80,"%a, %d %b %Y %X GMT",timeinfo);
	return(buffer);
}