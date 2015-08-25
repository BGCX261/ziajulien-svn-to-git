#include "BuildResponse.h"
#include <fstream>

BuildResponse::BuildResponse(void)
{
}

BuildResponse::~BuildResponse(void)
{
}

/**
*  The preBuild event.
*  This module method will be called before building the response header
*  @param request a IHttpRequest
*  @param reponse a IHttpResponse
*  @return a ChainStatus
*/
IModule::ChainStatus	BuildResponse::onPreBuild(IHttpRequest* request, IHttpResponse* response)
{
	IModule::ChainStatus temp;
	return temp;
}

/**
*  The postBuild event.
*  This method will be called after the reponse header has been built
*  @param request a IHttpRequest
*  @param response a IHttpResponse
*  @return a ChainStatus
*/
IModule::ChainStatus	BuildResponse::onPostBuild(IHttpRequest* request, IHttpResponse* response)
{
	IModule::ChainStatus temp;
	temp = IModule::ChainStatus::CONTINUE;
	return temp; // ARenum
}

bool					fileExists(const std::string& fileName)
{
	std::fstream fin;
	fin.open(fileName.c_str(),std::ios::in);
	if( fin.is_open() )
	{
		fin.close();
		return true;
	}
	fin.close();
	return false;
}
