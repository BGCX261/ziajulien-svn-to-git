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

class Delete : public IBuildResponse , public CallImplement
{
public:
	Delete(void);
	~Delete(void);
	
	IModule::ChainStatus	call(IModule::Event,IHttpRequest* request, IHttpResponse* response);
	IModule::ChainStatus	onPreBuild(IHttpRequest* request, IHttpResponse* response);
	IModule::ChainStatus	onPostBuild(IHttpRequest* request, IHttpResponse* response);
private:
	bool					fileExists(const std::string& fileName);
	std::string				Date();
};