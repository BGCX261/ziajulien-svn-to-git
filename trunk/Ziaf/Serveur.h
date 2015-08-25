#ifndef _Serveur_
#define _Serveur_

#include <iostream>
#include "IConfig.h"
#include "Imodule.h"
#include <winsock.h>
#include <locale>
using namespace zAPI;

class Serveur
{
public:
	Serveur(void);
	~Serveur(void);
	IModule::ChainStatus	Init(IConfig* conf);
	IModule::ChainStatus	createSocket();
	IModule::ChainStatus	BindSocket();
	IModule::ChainStatus	ListenSocket(int nbrSocket = 10);
	SOCKET					AcceptClient();
	SOCKET					GetListenSocks();
	SOCKADDR_IN				GetServerAddr();
private:
	SOCKET					_ListeningSocket;
	SOCKADDR_IN				_ServerAddr;
	SOCKADDR_IN				_ClientAddr;
	int                     _ClientAddrLen;

};

#endif