#include "Delete.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "time.h"
#include "ParseXml.h"
#include <stdio.h>

Delete::Delete(void)
{
}

Delete::~Delete(void)
{
}

IModule::ChainStatus	Delete::onPreBuild(IHttpRequest* request, IHttpResponse* response)
{
	std::string file;
	file  = ".";
	file += request->getUri();
	std::cout << file << std::endl;
	if(remove(file.c_str()) != 0)
	{
		response->setResponseStatus(404);
		response->setResponseValue("Not Found");
	}
	response->setResponseStatus(200);
	response->setResponseValue("Ok");
	response->setHeaderOption("Date", Date());
	response->setHeaderOption("Server", "Zia/0.1");
	return(IModule::CONTINUE);
}

IModule::ChainStatus	Delete::onPostBuild(IHttpRequest* request, IHttpResponse* response)
{
	return IModule::ChainStatus::CONTINUE;
}

bool					Delete::fileExists(const std::string& fileName)
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

std::string				Delete::Date()
{
	time_t t;
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	strftime (buffer,80,"%a, %d %b %Y %X GMT",timeinfo);
	return(buffer);
}

IModule::ChainStatus	Delete::call(IModule::Event Ev,IHttpRequest* request, IHttpResponse* response)
{
	if(Ev == zAPI::IModule::Event::onPreBuildEvent)
		return this->onPreBuild(request,response);
	else if (Ev == zAPI::IModule::Event::onPostBuildEvent)
		return this->onPostBuild(request,response);
	return zAPI::IModule::ChainStatus::ERRORMODULE;
}