#include "ModuleEvent.h"

ModuleEvent::~ModuleEvent(void)
{
}

IModule::ChainStatus     ModuleEvent::onLoadModule(IModuleInfo* module)
{
	return IModule::ChainStatus::CONTINUE;
}

/**
*  The unloadModule event
*  This method will be called after a module has been unloaded
*  @param module the module that just has been uloaded
*  @return a ChainStatus
*/
IModule::ChainStatus     ModuleEvent::onUnloadModule(IModuleInfo* module)
{
	return IModule::ChainStatus::SKIPTONEXTEVENT;
}
