#ifndef _MgrClient_
#define _MgrClient_

#include <iostream>
#include <list>
#include "Client.h"
#include "IConfig.h"
#include "Parser.h"
#include "ManageRequest.h"
#include <locale>
#include <map>
#include "Get.h"
#include "Delete.h"
#include "Options.h"

#define _RECV_
#define _SEND_

class ManageClient;

struct thread_param{
	zAPI::IConfig *conf;
	ManageClient *MgrClient;
	Client *Cl;
};

class ManageClient
{
public:
	ManageClient(zAPI::IConfig *conf);
	~ManageClient(void);
	zAPI::IModuleManager				*ChooseCommand(const HttpRequest& req, HttpResponse* res);
	bool								addClient(zAPI::IClientSocket *client);
	std::list<Client *>*				getListClient();
	void								fillSelect(fd_set *fdread, fd_set *fdwrite);
	void								execClient(fd_set *fdread, fd_set *fdwrite);
	void								createResponse(IHttpRequest *req, IHttpResponse *res, Client *Cl);
	void								createBodyError(IHttpRequest *req, IHttpResponse *res);
	int									checkBuf(char c, Client * temp);


	/* executeur pour les threads (il transforme l'objet au bon format) */
	static DWORD WINAPI ThreadLauncher(void *p){
		struct thread_param *Obj = reinterpret_cast<struct thread_param*>(p);               
		ManageClient *s = Obj->MgrClient;                          
		return s->ClientThread(Obj->conf, Obj->Cl);       
	}

private:
	DWORD								ClientThread(zAPI::IConfig *conf, Client *Cl);
	std::list<Client *>*				_listClient;
	zAPI::IConfig						*_Conf;
};

#endif