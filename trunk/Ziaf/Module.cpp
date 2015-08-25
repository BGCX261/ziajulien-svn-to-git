#include "Module.h"

Module::Module(void)
{
}

Module::~Module(void)
{
}

/**
             * Is called by the ModuleManager when the module is loaded to get the priority
             * of the event passed in parameter.
             * @param event the event to get priority from
             * @return a priority
             */
int                     Module::getPriority(Event event) const {
	return 0;
}