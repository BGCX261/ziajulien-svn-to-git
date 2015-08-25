#include "HttpRequest.h"

HttpRequest::HttpRequest(void)
{
}

HttpRequest::~HttpRequest(void)
{
}

/**
*  Sets the request URI and whether the uri is relative or not.
*  The relative flag is set to tru by default
*  @param uri the request uri
*  @relative whether the uri is relative or not (default true)
*/
void										HttpRequest::setUri(const std::string& uri, bool relative)
{
	if (uri[0] == '/')
		relative = false ;
	else 
		relative = true;
	_currentUri = uri;
}

/**
*  Returns the URI
*  @return the uri
*/
const std::string&                          HttpRequest::getUri() const
{
	return this->_currentUri;
}

void                                        HttpRequest::setUriQuery(const std::string& query)
{
	_UriQuery = query;
}
const std::string&							HttpRequest::getUriQuery() const
{
	return _UriQuery;
}
void                                        HttpRequest::setBodyStream(zAPI::IResponseStream* stream)
{
	_Stream = stream;
}

zAPI::IResponseStream*                      HttpRequest::getBodyStream() const
{
	return _Stream;
}

/**
*  Sets a custom parameter that will not be used in the server.
*  Those parameters must only be used for modules purposes
*  @param key a parameter key
*  @param value a parameter value (casted as void*)
*/
bool                                        HttpRequest::setParam(const std::string& key, void* value)
{


	this->_paramMap[key] = value;
	/*_uriMap*/
	return true; // AR
}

/**
*  Returns the param value matching the key passed in parameter.
*  If the key is not found, NULL will be returned instead
*  @param key a param key
*  @return a param value (casted as void*)
*/
void*                                       HttpRequest::getParam(const std::string& parametre) const
{
	std::map<std::string, void*>::const_iterator it;


	for (it =  _paramMap.begin() ;it != _paramMap.end(); ++it)
	{
		std::string key = (*it).first;
		void* number = (*it).second;

		if ( parametre == key)
			return(number);
	}
	return "NULL";

}

/**
*  Sets the request command (GET, POST, PUT ...)
*  @param command a request command
*/
void                                        HttpRequest::setCommand(const std::string& command)
{
	this->_currentCommand = command;
}

/**
*  Returns the request command
*  @return a request command
*/
const std::string&                          HttpRequest::getCommand() const
{
	return this->_currentCommand;
}

/**
*  Sets the current configuration (can be request specific)
*  @param config a configuration object
*/
void                                        HttpRequest::setConfig(IConfig* config)
{
	this->_currentConfig = config;
}

/**
*  Returns the current configuration (can be request specific)
*  @return a configuration object
*/
IConfig*                                    HttpRequest::getConfig() const
{
	return this->_currentConfig;
}


/**
*  Return the current request ID
*  Used for identifying requests within workflow, and eventually
*  for the ModuleManager, in the case of a module list modification
*  while a request is proceced. In this case, this id will
*  allow the module manager to know which module list is associated with
*  this request.
*  @return the current request ID as an unsigned int.
*/
unsigned int                                HttpRequest::getRequestId() const
{
	return this->_currentRequestId;
}

/**
*  Set the current request's ID
*  To be getter as described for the associated getter, getRequestId()
*/
void                                        HttpRequest::setRequestId(unsigned int id)
{
	this->_currentRequestId = id;
}

void                                        HttpRequest::setClient(zAPI::IClientSocket* clt)
{
}
zAPI::IClientSocket*                        HttpRequest::getClient() const
{
	return new ClientSocket();
}


void                                        HttpRequest::setHeaderOption(const std::string& key, const std::string& value)
{
	this->_headerMap[key] = value;
}

/**
*  Returns the value matching the key passed in parameter.
*  Returns empty std::string if the key was not set yet
*  @return the value of the option
*/
std::string                                 HttpRequest::getHeaderOption(const std::string& key) const
{
	std::map<std::string,std::string>::const_iterator it;

	for (it = this->_headerMap.begin(); it != this->_headerMap.end (); ++it)
	{
		std::string keyMap = (*it).first;
		if(key.compare(keyMap.c_str()) == 0)
			return (*it).second;
	}
	return "NULL";
}

/**
*  Returns a string/string map containing all the header options
*  @return the options map
*/
const std::map<std::string, std::string>&   HttpRequest::getHeaderOptions() const
{
	return this->_headerMap;
}

/**
*  Checks wheter the header options matches the key passed in parameter
*  @param key the key to checkotherwise
*  @return true if the entry exists, else 
*/
bool                                        HttpRequest::headerOptionIsSet(const std::string& key) const
{
	std::map<std::string,std::string>::const_iterator it;

	for (it = this->_headerMap.begin(); it != this->_headerMap.end (); ++it)
	{
		std::string keyMap = (*it).first;
		if(key.compare(keyMap.c_str()) == 0)
			return true;
	}
	return false;
}

/**
*  Set the header protocol (typically "HTTP/1.1" or "HTTP/1.0")
*  @param protocol the header protocol
*/
void                                        HttpRequest::setProtocol(const std::string& protocol)
{
	this->_currentProtocol = protocol;
}

/**
*  Returns the current header protocol
*  @return the header protocol
*/
const std::string&                          HttpRequest::getProtocol() const
{
	return this->_currentProtocol;
}