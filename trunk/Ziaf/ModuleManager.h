#ifndef _ModuleManager_
#define _ModuleManager_

#include <iostream>
#include <string>
#include "IModule.h"
#include "IHttpRequest.h"
#include "IHttpResponse.h"
#include "IClientSocket.h"
#include "ClientSocket.h"
#include "IModuleInfo.h"
#include "IModuleManager.h"

using namespace zAPI;
class ModuleManager : public IModuleManager
{
public:
	ModuleManager(void);
	~ModuleManager(void);
	virtual bool    load(const std::string& filename);
	virtual void    unload(const std::string& filename);
	virtual size_t  processContent(IHttpRequest* req, IHttpResponse* res, char* buff, size_t size);
	virtual IModule::ChainStatus    call(IModule::Hook, IModule::Event);
	virtual IModule::ChainStatus    call(IModule::Hook, IModule::Event, IModuleInfo*);
	virtual IClientSocket*          call(IModule::Hook, IModule::Event, SOCKET);
	virtual IModule::ChainStatus    call(IModule::Hook, IModule::Event, const char*, size_t);
	virtual IModule::ChainStatus    call(IModule::Hook, IModule::Event, IHttpRequest*, IHttpResponse*);
};

#endif