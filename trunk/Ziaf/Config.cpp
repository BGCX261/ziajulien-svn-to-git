#include "Config.h"
#include <map>

Config::Config(void)
{
}

Config::~Config(void)
{
}

/**
*  Returns the value of the configuration parameter key passed in paramater as a string.
*  If the key is not found, NULL will be returned instead
*  @param key a configuration parameter key
*  @return a configuration parameter value
*/
const std::string*                  Config::getParam(const std::string& key) const
{

	std::map<std::string,std::string>::const_iterator it;

	for (it = this->Mapper.begin(); it != this->Mapper.end (); ++it)
	{
		std::string compare;
		std::string* compare2;
		compare = it->first;
		if (key == compare)
		{
			compare2 = new std::string(it->second);
			//std::cout << compare2 << std::endl;
			return compare2;
		}	
		/*std::string keyMap = (*it().first;
		if(key.compare(keyMap.c_str()) == 0)
		return (*it).second;*/

	}
	return new std::string("NULL");
}

/**
*  Returns the value of the configuration parameter key passed in paramater as a char*.
*  If the key is not found, NULL will be returned instead
*  @param key a configuration parameter key
*  @return a configuration parameter value
*/
const char*                         Config::getParamChar(const std::string& key) const
{
	std::map<std::string,std::string>::const_iterator it;

	for (it = Mapper.begin(); it != Mapper.end(); it++ )
	{
		std::string compare;
		compare = it->first;
		if (key == compare)
		{
			return it->second.c_str();	
		}
	}
	return "NULL";
}

/**
*  Sets a configuration parameter with a key / value pair passed in parameter
*  @param key the configuration parameter key
*  @param value the configuration parameter value
*/
void                                Config::setParam(const std::string& key, const std::string& value)
{
	Mapper[key] =  value;
}

/**
*  Checks whether a certain parameter key is set or not
*  @param key a configuration parameter key
*  @return whether the key is set or not
*/
bool                                Config::isSet(const std::string& key) const
{
	std::map<std::string,std::string>::const_iterator it;
	for (it = Mapper.begin(); it != Mapper.end(); it++ )
	{
		std::string test;
		std::string compare;
		compare = it->first;
		if (key == compare)
			test = compare.c_str();
		return true;	
	}

	return false;
}