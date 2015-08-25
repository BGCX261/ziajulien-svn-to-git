#pragma once
#include "IBuildResponse.h"
#include "IModule.h"
#include <sstream>
#include <iostream>
#include <fstream>
using namespace zAPI;

class FileExtend: public IBuildResponse
{
public:
	FileExtend(void);
	~FileExtend(void);
	IModule::ChainStatus	 call(IModule::Event,IHttpRequest* request, IHttpResponse* response);
	IModule::ChainStatus     onPreBuild(IHttpRequest* request, IHttpResponse* response);
	IModule::ChainStatus     onPostBuild(IHttpRequest* request, IHttpResponse* response);
private:
	bool fileExists(const std::string& fileName);
	std::string date(int jour, int heure);
};
