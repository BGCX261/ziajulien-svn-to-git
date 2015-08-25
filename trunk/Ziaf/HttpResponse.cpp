#include "HttpResponse.h"

HttpResponse::~HttpResponse(void)
{

}

void										HttpResponse::setResponseStatus(int statusCode)
{
	_statusCode = statusCode;
}

int											HttpResponse::getResponseStatus() const
{
	return _statusCode;;
}

void										HttpResponse::setResponseValue(const std::string& value)
{
	_value = value;
}

const std::string&							HttpResponse::getResponseValue() const
{
	return _value;

}

void										HttpResponse::appendStream(IResponseStream* stream)
{
	_CurrentResponse.push(stream);
	_Currentstream = stream;
}

std::queue<IResponseStream*>&				HttpResponse::getStreams()
{
	return _CurrentResponse;
}    

IResponseStream*							HttpResponse::getCurrentStream()
{
	return _Currentstream;
}

void										HttpResponse::skipToSend(IResponseStream* stream, bool flushStream, bool headerInStream)
{

}

void										HttpResponse::setHeaderInStream(bool headerInStream)
{
	_headerInStream = headerInStream;
}

bool										HttpResponse::getHeaderInStream() const
{
	return _headerInStream ;
}

void                                        HttpResponse::setHeaderOption(const std::string& key, const std::string& value)
{
	this->_headerMap[key] = value;
}

/**
*  Returns the value matching the key passed in parameter.
*  Returns empty std::string if the key was not set yet
*  @return the value of the option
*/
std::string                                 HttpResponse::getHeaderOption(const std::string& key) const
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
const std::map<std::string, std::string>&   HttpResponse::getHeaderOptions() const
{
	return this->_headerMap;
}

/**
*  Checks wheter the header options matches the key passed in parameter
*  @param key the key to checkotherwise
*  @return true if the entry exists, else 
*/
bool                                        HttpResponse::headerOptionIsSet(const std::string& key) const
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
void                                        HttpResponse::setProtocol(const std::string& protocol)
{
	this->_currentProtocol = protocol;
}

/**
*  Returns the current header protocol
*  @return the header protocol
*/
const std::string&                          HttpResponse::getProtocol() const
{
	return this->_currentProtocol;
}