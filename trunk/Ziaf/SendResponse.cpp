#include "SendResponse.h"

SendResponse::SendResponse(void)
{
}

SendResponse::~SendResponse(void)
{
}

IModule::ChainStatus SendResponse::onPreSend(IHttpRequest*, IHttpResponse*)
{
	IModule::ChainStatus temp;temp = (IModule::ChainStatus)1;return temp;
}

size_t      SendResponse::onProcessContent(IHttpRequest*, IHttpResponse*, char*, size_t, IModule**, unsigned int)
{
	return 0;
}

IModule::ChainStatus SendResponse::onPostSend(IHttpRequest*, IHttpResponse*)
{
	IModule::ChainStatus temp;temp = (IModule::ChainStatus)1;return temp;
}
