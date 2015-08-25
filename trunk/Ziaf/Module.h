#ifndef _MODULE_
#define _MODULE_

#include "IModule.h"
#include "IClientSocket.h"
#include "ClientSocket.h"
using namespace zAPI;

class Module : public IModule
{
public:
	Module(void);
	~Module(void);
	virtual int                     getPriority(Event event) const;
};

#endif