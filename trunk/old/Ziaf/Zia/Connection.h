#ifndef _Connection_
#define _Connection_
#include <winsock2.h>
#include <iostream>
#include <string>
#include <list>
#include "Client.h"
#include <iterator>
using namespace std;
class Connection
{
protected:
SOCKET sock;
SOCKADDR_IN sin;
SOCKET csock;
SOCKADDR_IN csin;
WSADATA WSAData;
std::list<Client> *ClientList;
fd_set fdread;
fd_set fdwrite;
timeval waiting;
int _Port;
SOCKADDR_IN   _ADRRServer;

public:
	Connection(int port);
public:
	~Connection(void);

	bool			InitServ(string file);
	void			Send(std::string answer, Client *temp);
	void			Receive(Client *temp);
	void			initRead();
	void			setTimeval(int sec, int usec);
	timeval			getTimeval();
	int				doSelect();
	void			readServ();
	virtual void	readClient();
	void			clearmess(Client *temp);
	bool			startServ();
	std::list<Client> *getListClient();
	fd_set *getFdread();
};

#endif