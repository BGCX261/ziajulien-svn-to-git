#include "Serveur.h"

Serveur::Serveur(void)
{
	_ClientAddrLen = sizeof( _ClientAddr );
}

Serveur::~Serveur(void)
{
}

IModule::ChainStatus	Serveur::Init(IConfig* conf)
{
	WSADATA	      wsaData;
	if(WSAStartup(MAKEWORD(2,2), &wsaData ) != 0 ){
		std::cerr <<"ERROR : WSAStartup Problem "<< std::endl;
		return IModule::ChainStatus::STOP;
	}
	_ServerAddr.sin_addr.s_addr = INADDR_ANY;
	_ServerAddr.sin_family = AF_INET;
	if(conf->isSet("Port") == true)
		_ServerAddr.sin_port = htons(atoi(conf->getParamChar("Port")));
	else
		_ServerAddr.sin_port = htons(80);
	return IModule::ChainStatus::CONTINUE;
}
IModule::ChainStatus	Serveur::createSocket()
{
	if( ( _ListeningSocket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP ) ) == INVALID_SOCKET ) /* creation du socket */
	{
		std::cerr << "ERROR : impossible de cree socket" << std::endl;
		WSACleanup();
		return IModule::ChainStatus::STOP;
	}
	return IModule::ChainStatus::CONTINUE;
}
IModule::ChainStatus	Serveur::BindSocket()
{
	if( bind( _ListeningSocket, (SOCKADDR *)&_ServerAddr, sizeof( _ServerAddr ) ) == SOCKET_ERROR ) /* defini la liaison entre le programmme et la socket*/
	{
		std::cerr << "ERROR : bind a echoue avec l'erreur " << std::endl;
		std::cerr << "Le port est peut-etre deje utilise par un autre processus " << std::endl;
		closesocket( _ListeningSocket );
		WSACleanup();
		return IModule::ChainStatus::STOP;
	}
	return IModule::ChainStatus::CONTINUE;
}
IModule::ChainStatus	Serveur::ListenSocket(int nbrSocket)
{
	if( listen( _ListeningSocket, nbrSocket ) == SOCKET_ERROR ) 
	{ 
		std::cerr << "ERROR : listen Problem"<< std::endl;
		closesocket( _ListeningSocket );
		WSACleanup();
		return IModule::ChainStatus::STOP;
	}
	return IModule::ChainStatus::CONTINUE;
}
SOCKET					Serveur::AcceptClient()
{
	SOCKET NewConnection;

	if((NewConnection = accept( _ListeningSocket, (SOCKADDR *) &_ClientAddr, &_ClientAddrLen)) == INVALID_SOCKET){
		std::cerr  << "ERROR : accept Problem" << WSAGetLastError() << std::endl;
		WSACleanup();
		return 0;
	}
	return NewConnection;
}

SOCKET					Serveur::GetListenSocks()
{
	return this->_ListeningSocket;
}

SOCKADDR_IN				Serveur::GetServerAddr()
{
	return this->_ServerAddr;
}