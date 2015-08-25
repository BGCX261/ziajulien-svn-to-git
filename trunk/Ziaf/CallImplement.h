#ifndef _Call_
#define _Call_

#include "IModuleManager.h"
#include "IModule.h"
#include "IConfig.h"
#include "ClientSocket.h"

using namespace zAPI;

class CallImplement : public zAPI::IModuleManager
{
public:
	CallImplement(void);
	~CallImplement(void);

	virtual IModule::ChainStatus    call(IModule::Event);
	virtual IModule::ChainStatus    call(IModule::Event, IModuleInfo*);
	virtual IClientSocket*          call(IModule::Event, SOCKET, zAPI::IConfig *);
	virtual IModule::ChainStatus    call(IModule::Event, const char*, size_t);
	virtual IModule::ChainStatus    call(IModule::Event, IHttpRequest*, IHttpResponse*);

};

#endif