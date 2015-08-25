#include "ManageRequest.h"

ManageRequest::ManageRequest(void)
{
}

ManageRequest::~ManageRequest(void)
{
}

IModule::ChainStatus ManageRequest::call(IModule::Event ev, IHttpRequest* rq, IHttpResponse* rp)
{
	if (IModule::Event::onPreReceiveEvent == ev)
		return (this->onPreReceive(rq, rp));
	else if (IModule::Event::onPostReceiveEvent == ev)
		return (this->onPostReceive(rq, rp));
	else if (IModule::Event::onPreBuildEvent == ev)
		return (this->onPreBuild(rq, rp));
	else if (IModule::Event::onPostBuildEvent == ev)
		return (this->onPostBuild(rq, rp));
	else if (IModule::Event::onPreSendEvent == ev)
		return (this->onPreSend(rq, rp));
	else if (IModule::Event::onPostSendEvent == ev)
		return (this->onPostSend(rq, rp));
	else
		return IModule::ERRORMODULE;
}

IModule::ChainStatus ManageRequest::onPreReceive(IHttpRequest* request, IHttpResponse* response)
{
	return IModule::CONTINUE;
}

IModule::ChainStatus ManageRequest::onPostReceive(IHttpRequest* request, IHttpResponse* response)
{
	return IModule::CONTINUE;
}

IModule::ChainStatus ManageRequest::onPreBuild(IHttpRequest* request, IHttpResponse* response)
{
	return IModule::CONTINUE;
}

IModule::ChainStatus ManageRequest::onPostBuild(IHttpRequest* request, IHttpResponse* response)
{
	return IModule::CONTINUE;
}

IModule::ChainStatus ManageRequest::onPreSend(IHttpRequest* request, IHttpResponse* response)
{
	return IModule::CONTINUE;
}

IModule::ChainStatus ManageRequest::onPostSend(IHttpRequest* request, IHttpResponse* response)
{
	return IModule::CONTINUE;
}

size_t               ManageRequest::onProcessContent(IHttpRequest* request, IHttpResponse* response, char* buff, size_t buffSize, const std::vector<zAPI::ISendResponse*>& modules, unsigned int index)
{
	return 0;
}
