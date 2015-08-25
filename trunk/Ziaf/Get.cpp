#include "Get.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "time.h"
#include "ParseXml.h"

Get::Get(void)
{
}

Get::~Get(void)
{
}

IModule::ChainStatus	Get::call(IModule::Event Ev,IHttpRequest* request, IHttpResponse* response)
{
	if(Ev == zAPI::IModule::Event::onPreBuildEvent)
		return this->onPreBuild(request,response);
	else if (Ev == zAPI::IModule::Event::onPostBuildEvent)
		return this->onPostBuild(request,response);
	return zAPI::IModule::ChainStatus::ERRORMODULE;
}

IModule::ChainStatus	Get::onPreBuild(IHttpRequest* request, IHttpResponse* response)
{
	std::string directory = "." + request->getUri();

	if(fileExists(directory) == true)
	{
		if((request->getProtocol().compare("HTTP/1.0") == 0) || (request->getProtocol().compare("HTTP/1.1") == 0))
		{	
			if(request->getProtocol().compare("HTTP/1.1") == 0 && request->getParam("Host") == 0)
			{
				response->setResponseStatus(400);
				response->setResponseValue("Bad Request");
			}
			else
			{
				processBuild(request, response);
				response->setResponseStatus(200);
				response->setResponseValue("Ok");
			}
		}
		else
		{
			response->setResponseValue("HTTP version not supported");
			response->setResponseStatus(505);
		}
	}
	else
	{

		response->setResponseStatus(404);
		response->setResponseValue("Not Found");
	}
	return(IModule::CONTINUE);
}

void					Get::processBuild(IHttpRequest* request, IHttpResponse* response)
{
	std::stringstream str;
	long length;
	char * buffer;
	std::string directory = "." + request->getUri();

	response->setHeaderOption("Date", Date());
	response->setHeaderOption("Server", "Zia/0.1");

	std::ifstream is;
	is.open ( directory.c_str() , std::ios::binary);

	// get length of file:
	is.seekg  (0, std::ios::end);
	length = is.tellg();
	is.seekg (0);

	char taile[20];
	sprintf(taile, "%d",length);
	std::string lgth = taile;
	response->setHeaderOption("Content-Lenght", lgth);
	response->setHeaderOption("Content-Type", this->extendfile(request,response));

	// allocate memory:
	buffer = new char [length + 1];

	// read data as a block:
	is.read(buffer,length);
	is.close();
	buffer[length] = NULL;
	str << buffer;

	response->appendStream(new ResponseStream(&str));
	delete[] buffer;
}


/**
*  The postBuild event.
*  This method will be called after the reponse header has been built
*  @param request a IHttpRequest
*  @param response a IHttpResponse
*  @return a ChainStatus
*/
IModule::ChainStatus	Get::onPostBuild(IHttpRequest* request, IHttpResponse* response)
{
	return IModule::ChainStatus::CONTINUE;
}


bool					Get::fileExists(const std::string& fileName)
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

std::string				Get::Date()
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

std::string				Get::extendfile(IHttpRequest* request, IHttpResponse* response)
{
	std::string extension;
	std::string extendfolder;


	extension = request->getUri().substr(1,request->getUri().length());
	extension = extension.substr(extension.find_last_of('.') + 1,extension.length());
	if(extension == "html")
		extendfolder = "text/html";
	else if(extension == "jpeg")
		extendfolder = "image/jpeg";
	else if(extension == "jpg")
		extendfolder = "image/jpg";
	else if(extension == "mpeg")
		extendfolder= "audio/mpeg";
	else if(extension == "txt")
		extendfolder = "text/plain";
	else
	{
		response->setResponseValue("Unauthorized");
		response->setResponseStatus(401);
	}
	return extendfolder;
}

