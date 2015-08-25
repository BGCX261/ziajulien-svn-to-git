#ifndef _CONF_
#define _CONF_

#include "IConfig.h"
#include <iostream>
#include <map>
using namespace zAPI;

class Config : public IConfig
{
public:
	Config(void);
	~Config(void);
	virtual const std::string*                  getParam(const std::string& key) const;
	virtual const char*                         getParamChar(const std::string& key) const;
	virtual void                                setParam(const std::string& key, const std::string& value);
	virtual bool                                isSet(const std::string& key) const;
private:
	std::map<std::string, std::string> Mapper;
};

#endif // _CONF_