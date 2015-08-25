#include "Network.h"

Network::Network(void)
{
}

Network::~Network(void)
{
}

/**
*  The accept event.
*  This method will be called just after a accept has been performed.
*  It lets you change the socket used for the transaction with your own 
*  IClientSocket implementation. Typically, you can use this event to replace
*  the classic IClientSocket by it's SLL implementation.
*  @param socket the socket built from the accept call
*  @return a IClientSocket that will be used until the end of the transaction
*/
IClientSocket*			Network::onAccept(SOCKET socket)
{
	return new ClientSocket();
}

/**
*  The receive event.
*  This method will be called after each reveive performed on the IClientSocket.
*  You'll got the received datas on a buffer and it's length as parameters.
*  That way, you'll be allowed to modify all incomming datas.
*  @param buf the buffer containg the receivded datas
*  @param length the datas length
*  @return a ChainStatus
*/
IModule::ChainStatus	Network::onReceive(char* buf, size_t length){
	IModule::ChainStatus temp;temp = (IModule::ChainStatus)1;return temp; // ARenum
}

/**
*  The send event.
*  This method will be called before each send performed on the IClientSocket.
*  You'll got the datas to be sent along with it's length as parameters.
*  That way, you'll be allowed to modify all outgoing datas.
*  @param buf the buffer containing the datas to be sent
*  @param length the datas length
*  @return a ChainStatus
*/
IModule::ChainStatus	Network::onSend(char* buf, size_t length){
	IModule::ChainStatus temp;temp = (IModule::ChainStatus)1;return temp; // ARenum
}