#include "Delete.h"
#include "serveur.h"

Delete::Delete(void)
{
	_Type = "DELETE";
}

Delete::Delete(std::map<std::string,std::string> mapparse)
{
	_map = mapparse;
	traitementmap();
}
Delete::~Delete(void)
{
}

std::string Delete::GetReponse()
{
	return this->_Reponse;
}

std::string Delete::GetType()
{
	return this->_Type;
}

std::string Delete::traitementmap()
{
	_Reponse = "." + serveur::getMap("delete",_map);
	if(remove(_Reponse.c_str()) != 0)
		std::cout << "Le fichier est deja suprimer" << std::endl;
	else
		std::cout << "Reponse:" <<_Reponse << std::endl;
	return _Reponse;
}