#ifndef __BUILDRESPONSE_H__
# define __BUILDRESPONSE_H__

#include "IBuildResponse.h"
#include <string>
using namespace zAPI;

class BuildResponse : public IBuildResponse
{
public:
	BuildResponse(void);
	~BuildResponse(void);
	virtual IModule::ChainStatus     onPreBuild(IHttpRequest* request, IHttpResponse* response);
	virtual IModule::ChainStatus     onPostBuild(IHttpRequest* request, IHttpResponse* response);
};

#endif /* !__BUILDRESPONSE_H__ */