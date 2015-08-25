#ifndef _ManageREQUEST_
#define _ManageREQUEST_

#include "IReceiveRequest.h"
#include "IBuildResponse.h"
#include "ISendResponse.h"
#include "CallImplement.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

using namespace zAPI;

class ManageRequest : public IReceiveRequest, public IBuildResponse, public ISendResponse, public CallImplement
{
public:
	ManageRequest(void);
	~ManageRequest(void);
	virtual IModule::ChainStatus call(IModule::Event, IHttpRequest*, IHttpResponse*);

	virtual IModule::ChainStatus onPreReceive(IHttpRequest* request, IHttpResponse* response);
	virtual IModule::ChainStatus onPostReceive(IHttpRequest* request, IHttpResponse* response);

	virtual IModule::ChainStatus onPreBuild(IHttpRequest* request, IHttpResponse* response);
	virtual IModule::ChainStatus onPostBuild(IHttpRequest* request, IHttpResponse* response);

	virtual IModule::ChainStatus onPreSend(IHttpRequest* request, IHttpResponse* response);
	virtual IModule::ChainStatus onPostSend(IHttpRequest* request, IHttpResponse* response);
	virtual size_t               onProcessContent(IHttpRequest* request, IHttpResponse* response, char* buff, size_t buffSize, const std::vector<zAPI::ISendResponse*>& modules, unsigned int index);
};

#endif