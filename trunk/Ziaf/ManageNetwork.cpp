#include "ManageNetwork.h"

ManageNetwork::ManageNetwork(void)
{
}

ManageNetwork::~ManageNetwork(void)
{
}

IClientSocket*          ManageNetwork::call(IModule::Event ev, SOCKET socks, IConfig *conf)
{
	if (IModule::Event::onAcceptEvent == ev)
	{
		std::string addr;
		return (this->onAccept(socks, addr,socks,conf));
	}
	else
		return 0;
}

IModule::ChainStatus    ManageNetwork::call(IModule::Event, const char*, size_t)
{
	return IModule::CONTINUE;
}
IClientSocket*			ManageNetwork::onAccept(SOCKET socket, const std::string& address, int port, zAPI::IConfig* config)
{
	SOCKET NewConnection;
	IClientSocket *NewClient;
	SOCKADDR_IN				_ClientAddr;
	int                     _ClientAddrLen;

	_ClientAddrLen = sizeof( _ClientAddr );
	if((NewConnection = accept( socket, (SOCKADDR *) &_ClientAddr, &_ClientAddrLen)) == INVALID_SOCKET){
		std::cerr  << "ERROR : accept Problem" << WSAGetLastError() << std::endl;
		WSACleanup();
		return 0;
	}
	NewClient = new ClientSocket(NewConnection);
	return NewClient;
}
IModule::ChainStatus    ManageNetwork::onReceive(const char* buf, size_t length)
{
	return IModule::CONTINUE;
}
IModule::ChainStatus    ManageNetwork::onSend(const char* buf, size_t length)
{
	return IModule::CONTINUE;
}