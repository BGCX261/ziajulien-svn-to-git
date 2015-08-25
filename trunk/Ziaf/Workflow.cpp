#include "Workflow.h"

Workflow::Workflow(void)
{
}

Workflow::~Workflow(void)
{
}

/**
*  The workflow begin event.<br>
*  This method will be called at the begining of the transaction 
*  (after the accept event of the INetwork hook interface).
*  @param request the IHttpRequest of the transaction
*  @param response the IHttpResponse of the transaction
*  @return a ChainStatus
*/
IModule::ChainStatus     Workflow::onBegin(IHttpRequest* request, IHttpResponse* response)
{
	IModule::ChainStatus temp;temp = (IModule::ChainStatus)1;return temp; // ARenum
}

/**
*  The workflow end event.<br>
*  This method will be called at the end of the transaction
*  (when all the data has been sent and just before the end of the task)
*  @param request the IHttpRequest of the transaction
*  @param response the IHttpResponse of the transaction
*  @return a ChainStatus
*/
IModule::ChainStatus     Workflow::onEnd(IHttpRequest* request, IHttpResponse* response)
{
	IModule::ChainStatus temp;temp = (IModule::ChainStatus)1;return temp; // ARenum
}

/**
*  The workflow error event.<br>
*  This method will be called when a module failed to do his job and returned an ERRORMODULE ChainStatus.
*  @param request the IHttpRequest of the transaction
*  @param response the IHttpResponse of the transaction
*  @return a ChainStatus
*/
IModule::ChainStatus     Workflow::onError(IHttpRequest*, IHttpResponse*)
{
	IModule::ChainStatus temp;temp = (IModule::ChainStatus)1;return temp; // ARenum
}
