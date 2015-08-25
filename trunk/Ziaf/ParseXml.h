#ifndef __ParseXml_h__ 
#define __ParseXml_h__ 

#include "tinyxml.h"
#include "IConfig.h"
#include <iostream>
#include <map>

using namespace zAPI;

class ParseXml
{
public:
	ParseXml(void);
	ParseXml(const char *); // constructeur avec prise en parametre du nom du xml a traiter.
	~ParseXml(void);
	const char *getValueXml(const char * key) const; // retour la valeur du xlm de la key passée en parametre, retour erreur si n'existe pas.
	bool		fillConfig(IConfig* c); // remplis la map Mapper de IConfig en fonction du xml de configuration du serveur.

private:
	std::map<std::string, std::string> XmlMapper;
	TiXmlDocument * doc;
};

#endif