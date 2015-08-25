#include "ModuleManager.h"

ModuleManager::ModuleManager(void)
{
}

ModuleManager::~ModuleManager(void)
{
}

bool					ModuleManager::load(const std::string& filename)
{
	return true;
}

void					ModuleManager::unload(const std::string& filename)
{
}

size_t					ModuleManager::processContent(IHttpRequest* req, IHttpResponse* res, char* buff, size_t size)
{
	return 0;
}

IModule::ChainStatus    ModuleManager::call(IModule::Hook, IModule::Event)
{
	IModule::ChainStatus temp;
	temp = (IModule::ChainStatus)1;
	return temp;
}

IModule::ChainStatus    ModuleManager::call(IModule::Hook, IModule::Event, IModuleInfo*)
{
	IModule::ChainStatus temp;
	temp = (IModule::ChainStatus)1;
	return temp;
}

IClientSocket*          ModuleManager::call(IModule::Hook, IModule::Event, SOCKET)
{
	return new ClientSocket();
}

IModule::ChainStatus    ModuleManager::call(IModule::Hook, IModule::Event, const char*, size_t)
{
	IModule::ChainStatus temp;temp = (IModule::ChainStatus)1;return temp;
}

IModule::ChainStatus    ModuleManager::call(IModule::Hook, IModule::Event, IHttpRequest*, IHttpResponse*)
{
	IModule::ChainStatus temp;temp = (IModule::ChainStatus)1;return temp;
}