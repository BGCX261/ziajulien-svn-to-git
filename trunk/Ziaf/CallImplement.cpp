#include "CallImplement.h"

CallImplement::CallImplement(void)
{
}

CallImplement::~CallImplement(void)
{
}

IModule::ChainStatus    CallImplement::call(IModule::Event)
{
	return IModule::CONTINUE;
}

IModule::ChainStatus    CallImplement::call(IModule::Event, IModuleInfo*)
{
	return IModule::CONTINUE;
}

IClientSocket*          CallImplement::call(IModule::Event, SOCKET, zAPI::IConfig *)
{
	return new ClientSocket();
}
IModule::ChainStatus    CallImplement::call(IModule::Event, const char*, size_t)
{
	return IModule::CONTINUE;
}

IModule::ChainStatus    CallImplement::call(IModule::Event, IHttpRequest*, IHttpResponse*)
{
	return IModule::CONTINUE;
}