#ifndef _NETWORK_
#define _NETWORK_

#include "INetwork.h"
#include "ClientSocket.h"
using namespace zAPI;

class Network : public INetwork
{
public:
	Network(void);
	~Network(void);
	virtual IClientSocket*  onAccept(SOCKET socket);
	virtual IModule::ChainStatus     onReceive(char* buf, size_t length);
	virtual IModule::ChainStatus     onSend(char* buf, size_t length);
};

#endif