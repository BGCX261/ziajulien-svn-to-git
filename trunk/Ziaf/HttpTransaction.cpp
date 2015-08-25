#include "HttpTransaction.h"

HttpTransaction::HttpTransaction(void)
{
}

HttpTransaction::~HttpTransaction(void)
{
}

/**
*  Sets a header option with a key / value pair passed in parameters
*  @param key the key of the header option to set
*  @param value the value of the option
*/
void                                        HttpTransaction::setHeaderOption(const std::string& key, const std::string& value)
{
	this->_headerMap[key] = value;
}

/**
*  Returns the value matching the key passed in parameter.
*  Returns empty std::string if the key was not set yet
*  @return the value of the option
*/
std::string                                 HttpTransaction::getHeaderOption(const std::string& key) const
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
const std::map<std::string, std::string>&   HttpTransaction::getHeaderOptions() const
{
	return this->_headerMap;
}

/**
*  Checks wheter the header options matches the key passed in parameter
*  @param key the key to checkotherwise
*  @return true if the entry exists, else 
*/
bool                                        HttpTransaction::headerOptionIsSet(const std::string& key) const
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
void                                        HttpTransaction::setProtocol(const std::string& protocol)
{
	this->_currentProtocol = protocol;
}

/**
*  Returns the current header protocol
*  @return the header protocol
*/
const std::string&                          HttpTransaction::getProtocol() const
{
	return this->_currentProtocol;
}