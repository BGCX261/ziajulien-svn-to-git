#include "ClientSocket.h"
#include <winsock2.h>

ClientSocket::ClientSocket()
{
}

ClientSocket::ClientSocket(SOCKET client)
{
	this->_socks = client;
	this->_close = false;
}

ClientSocket::~ClientSocket(void)
{
}

int					ClientSocket::recv(char *buf, int length)
{
	return::recv(_socks,buf,length,0);
}

int					ClientSocket::send(const char *buf, int length)
{
	return ::send(_socks,buf,length,0);

}

int					ClientSocket::send(const std::string& buf, int length)
{
	return ::send(_socks,buf.c_str(),length,0);

}

void				ClientSocket::close(bool niceClosing)
{
	if (niceClosing == true)
	{
		::shutdown(this->_socks,2);
		this->_close = true;
	}
	else
		this->_close = true;
}

bool				ClientSocket::isClosed() const
{
	return _close; // AR
}

SOCKET				ClientSocket::getNativeSocket() const
{
	return _socks;
}

const std::string&  ClientSocket::getIP() const
{
	return "toto";
}

int                 ClientSocket::getPort() const
{
	return this->_socks;
}
