#ifndef __MODULEEVENT_H__
# define __MODULEEVENT_H__

#include "IModuleEvent.h"
#include "IModule.h"
#include "IModuleInfo.h"
#include "ClientSocket.h"
#include <string>
using namespace zAPI;

class ModuleEvent : public IModuleEvent
{
public:
	virtual ~ModuleEvent(void);
	virtual IModule::ChainStatus	onLoadModule(IModuleInfo* module);
	virtual IModule::ChainStatus	onUnloadModule(IModuleInfo* module);
	};

#endif /* !__MODULEEVENT_H__ */