#include "ParseXml.h"
#include "Config.h"
#include "Parser.h"
#include "HttpRequest.h"
#include "HttpTransaction.h"
#include "ManageNetwork.h"
#include "Zia.h"
#include <iostream>

#define _SEND_

void	main()
{
	Zia *MyZia;
	Serveur * serv = new Serveur();
	zAPI::IConfig * conf = new Config();
	ParseXml * bob = new ParseXml("toto.xml");
	bool retour;

	retour = bob->fillConfig(conf);
	MyZia = new Zia(conf);
	if (MyZia->StartServ(serv) == false)
		return;
	if (MyZia->MainLoop(serv) == false)
		return;
	if (MyZia->StopServ(serv) == false)
		return;
}
