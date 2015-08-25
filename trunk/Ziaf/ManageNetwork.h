#ifndef _ManageNetwork_
#define _ManageNetwork_

#include "INetwork.h"
#include "CallImplement.h"

using namespace zAPI;

class ManageNetwork : public  zAPI::INetwork, public CallImplement
{
public:
	ManageNetwork(void);
	~ManageNetwork(void);
	virtual IClientSocket*          call(IModule::Event, SOCKET, IConfig *);
	virtual IModule::ChainStatus    call(IModule::Event, const char*, size_t);
	virtual IClientSocket*			onAccept(SOCKET socket, const std::string& address, int port, zAPI::IConfig* config);
	virtual IModule::ChainStatus    onReceive(const char* buf, size_t length);
	virtual IModule::ChainStatus    onSend(const char* buf, size_t length);
};

#endif