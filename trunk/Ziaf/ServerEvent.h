#ifndef _SERVER_EVENT_
#define _SERVER_EVENT_

#include "IServerEvent.h"
#include "CallImplement.h"
#include "IConfig.h"
#include "ParseXml.h"

using namespace zAPI;

class ServerEvent : public IServerEvent, public CallImplement
{
public:
	ServerEvent(void);
	ServerEvent(zAPI::IConfig *conf, const char * dir);
	~ServerEvent(void);
	virtual IModule::ChainStatus	call(IModule::Event);
	virtual IModule::ChainStatus	onServerStart();
	virtual IModule::ChainStatus	onServerStop();
private:
	IConfig			*_Conf;
	const char *	_Directory;

};

#endif // _SERVER_EVENT_