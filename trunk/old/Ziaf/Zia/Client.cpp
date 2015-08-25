#include "Client.h"

Client::Client(void)
{
	_Send = false;
}

Client::Client(SOCKET socks)
{
	_Socks = socks;
	_Cpt = 0;
	_Flag = 0;
}

Client::~Client(void)
{
}


bool Client::getSend()
{
	return _Send;
}

int Client::getCpt()
{
	return _Cpt;
}

int Client::getFlag()
{
	return _Flag;
}

string Client::getName()
{
	return _Name;
}

SOCKET Client::getSocks()
{
	return _Socks;
}

string Client::getMessage()
{
	return _Message;
}

void	Client::setName(string name)
{
	_Name = name;
}

void	Client::setSend(bool send)
{
	_Send = send;
}

void	Client::setCpt(int cpt)
{
	_Cpt += cpt;
}

void	Client::setFlag(int flg)
{
	_Flag = flg;
}

void	Client::setSocks(SOCKET sock)
{
	_Socks = sock;
}

void	Client::setMessage(char * c)
{
	_Message += c;
}

void	Client::clrCpt()
{
	_Cpt = 0;
}

void	Client::clrMessage()
{
	_Message = "";
}