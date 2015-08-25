#include "Options.h"
#include "ParseXml.h"
#include <stdio.h>
#include "time.h"
Options::Options(void)
{
}

Options::~Options(void)
{
}

IModule::ChainStatus	Options::onPreBuild(IHttpRequest* request, IHttpResponse* response)
{
	std::string file;
	file  = ".";
	file += request->getUri();
	std::cout << file << std::endl;
	if(remove(file.c_str()) != 0)
		std::cout << "Error deleting file" << std::endl;   //response->setResponseStatus	(int); erreur fichier delete trouver l int
	return(IModule::CONTINUE);
}

IModule::ChainStatus	Options::onPostBuild(IHttpRequest* request, IHttpResponse* response)
{
	return IModule::ChainStatus::CONTINUE;
}

void					Options::processBuild(IHttpRequest* request, IHttpResponse* response)
{
	response->setResponseStatus(200);
	response->setResponseValue("Ok");
	response->setHeaderOption("Date", Date());
	response->setHeaderOption("Server", "Zia/0.1");
	response->setHeaderOption("Allow", "GET, OPTIONS, DELETE");
	response->setHeaderOption("Content-lenght","0");
	response->setHeaderOption("Content-Type","text/html");
}
bool					Options::fileExists(const std::string& fileName)
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

std::string				Options::Date()
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

IModule::ChainStatus	Options::call(IModule::Event Ev,IHttpRequest* request, IHttpResponse* response)
{
	if(Ev == zAPI::IModule::Event::onPreBuildEvent)
		return this->onPreBuild(request,response);
	else if (Ev == zAPI::IModule::Event::onPostBuildEvent)
		return this->onPostBuild(request,response);
	return zAPI::IModule::ChainStatus::ERRORMODULE;
}