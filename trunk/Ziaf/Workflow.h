#ifndef WORKFLOW_H__
# define WORKFLOW_H__

#include "IWorkflow.h"
#include <string>
using namespace zAPI;

class Workflow : public IWorkflow
{
public:
	Workflow(void);
	~Workflow(void);
	virtual IModule::ChainStatus     onBegin(IHttpRequest* request, IHttpResponse* response);
	virtual IModule::ChainStatus     onEnd(IHttpRequest* request, IHttpResponse* response);
	virtual IModule::ChainStatus     onError(IHttpRequest*, IHttpResponse*);
};

#endif /* !WORKFLOW_H__ */
