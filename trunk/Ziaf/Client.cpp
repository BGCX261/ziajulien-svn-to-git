#include "Client.h"

Client::Client(zAPI::IClientSocket *Mclient)
{
	_Val = 0;
	this->_IsSend = false;
	this->_Client = Mclient;
	std::cout << "new client" << std::endl;
}

Client::~Client(void)
{
}

void					Client::setClientSocket(zAPI::IClientSocket *Mclient)
{
	this->_Client = Mclient;
}

zAPI::IClientSocket*	Client::getClientSocket()
{
	return this->_Client;
}

void					Client::addRecv(std::string add)
{
	this->_Recv += add;
}

void					Client::clrRecv()
{
	this->_Recv = "";
}

std::string				Client::getRecv()
{
	return this->_Recv;
}

bool					Client::getIsSend()
{
	return _IsSend;
}

void					Client::setIsSend(bool _send)
{
	_IsSend = _send;
}

std::string				Client::getResponse()
{
	return _Response;
}

void					Client::setResponse(std::string res)
{
	this->_Response = res;
}

void					Client::subResponse(int lenght)
{
	//str
	this->_Response = this->_Response.substr(lenght);
}

int						Client::getPosSend()
{
	return this->_pos;
}

void					Client::setPosSend(int pos)
{
	this->_pos = pos;
}

void					Client::setCommand(int i)
{
	_Val = i;
}

int						Client::getCommand()
{
	return _Val;
}