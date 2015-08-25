#include "Execute.h"
#include "serveur.h"

Execute::Execute(void)
{
}

Execute::~Execute(void)
{
}

Requette* Execute::do_execute(std::map<std::string,std::string> select)
{	
	if (serveur::getMap("get",select).compare("Erreur") != 0)
			return new Get(select);
	if (serveur::getMap("delete",select).compare("Erreur") != 0)
			return new Delete(select);
	return new Requette();
}
