#include "ModuleInfo.h"

ModuleInfo::ModuleInfo(void)
{
}

ModuleInfo::~ModuleInfo(void)
{
}

zAPI::IModule*									ModuleInfo::getInstance()
{
	return this->_CurentInstance;
}

const std::string&								ModuleInfo::getName()
{
	return this->_Name;
}

float											ModuleInfo::getVersion()
{
	return this->_Version;
}

const std::string&								ModuleInfo::getFileName()
{
	return this->_Filename;
}

void											ModuleInfo::addSupportedHook(IModule::Hook)
{
	//IModule::Hook::
}
const std::vector<zAPI::IModule::Hook>&         ModuleInfo::getSupportedHooks()
{
	return this->_Hooklist;
}
