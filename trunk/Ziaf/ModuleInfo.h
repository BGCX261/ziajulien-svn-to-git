#ifndef _ModuleInfo_
#define _ModuleInfo_

#include "IModuleInfo.h"
#include <string>
using namespace zAPI;

class ModuleInfo : public virtual IModuleInfo
{
public:
	ModuleInfo(void);
	~ModuleInfo(void);
	virtual zAPI::IModule*                                  getInstance();
	virtual const std::string&                              getName();
	virtual float                                           getVersion();
	virtual const std::string&                              getFileName();
	virtual void                                            addSupportedHook(IModule::Hook);
	virtual const std::vector<zAPI::IModule::Hook>&         getSupportedHooks();
private:
	std::string												_Name;
	std::string												_Filename;
	zAPI::IModule*											_CurentInstance; 
	float													_Version;
	std::vector<zAPI::IModule::Hook>						_Hooklist;

};


#endif