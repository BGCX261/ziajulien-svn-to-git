#pragma once

#include "IBuildResponse.h"
#include "IModule.h"
#include "CallImplement.h"
#include "ResponseStream.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace zAPI;

class Get : public IBuildResponse , public CallImplement
{
public:
	Get(void);
	~Get(void);
	IModule::ChainStatus		call(IModule::Event,IHttpRequest* request, IHttpResponse* response);
	IModule::ChainStatus		onPreBuild(IHttpRequest* request, IHttpResponse* response);
	IModule::ChainStatus		onPostBuild(IHttpRequest* request, IHttpResponse* response);
	void						processBuild(IHttpRequest* request, IHttpResponse* response);
	std::string					extendfile(IHttpRequest* request, IHttpResponse* response);
private:
	bool						fileExists(const std::string& fileName);
	std::string					Date();
};
