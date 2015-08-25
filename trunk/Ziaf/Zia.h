#ifndef _Zia_
#define _Zia_

#include "IModule.h"
#include "Iconfig.h"
#include "Serveur.h"
#include "ManageNetwork.h"
#include "ManageClient.h"
#include <list>

class Zia
{
public:
	Zia(void);
	Zia(zAPI::IConfig* Config);
	~Zia(void);

	bool			StartServ(Serveur *Serv);
	bool			MainLoop(Serveur *Serv);
	bool			StopServ(Serveur *Serv);
private:
	zAPI::IConfig*	_Config;
	ManageNetwork	*_MngNet;
	ManageClient	*_MgrClient;
	fd_set			_fdread;
	fd_set			_fdwrite;
};

#endif