#ifndef CLIENT_SOCKET_H__
#define CLIENT_SOCKET_H__

#include <string>
#include "IClientSocket.h"

using namespace zAPI;

class ClientSocket : public IClientSocket
{
public:
	ClientSocket();
	ClientSocket(SOCKET socks);
	~ClientSocket();
	virtual int						recv(char *buf, int length);
	virtual int						send(const char *buf, int length);
	virtual int						send(const std::string& buf, int length);
	virtual void				    close(bool niceClosing);
	virtual bool				    isClosed() const;
	virtual SOCKET					getNativeSocket() const;
	virtual const std::string&		getIP() const;
    virtual int		                getPort() const;

private:
	bool _close;
	SOCKET _socks;
};

#endif //CLIENT_SOCKET_H__
