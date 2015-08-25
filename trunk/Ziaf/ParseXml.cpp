#include "ParseXml.h"

ParseXml::ParseXml(void)
{
	doc = new TiXmlDocument("conf.xml");
}

ParseXml::ParseXml(const char * xml)
{
	doc = new TiXmlDocument(xml);
}

ParseXml::~ParseXml(void)
{
}

const char	*ParseXml::getValueXml(const char * key) const
{
	if(!doc->LoadFile()){
		std::cerr << "erreur lors du chargement" << std::endl;
		std::cerr << "error #" << doc->ErrorId() << " : " << doc->ErrorDesc() << std::endl;
		return "erreur";
	}

	TiXmlHandle hdl(doc);
	TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement( key ).Element();

	if(!elem){
		std::cerr << "le noeud a atteindre n'existe pas" << std::endl;
		return "erreur";
	}

	const char *titi = elem->GetText();
	elem = elem->NextSiblingElement();
	return titi;
}

bool		ParseXml::fillConfig(IConfig* c)
{
	if(!doc->LoadFile()){
		std::cerr << "erreur lors du chargement" << std::endl;
		std::cerr << "error #" << doc->ErrorId() << " : " << doc->ErrorDesc() << std::endl;
		return false;
	}

	TiXmlHandle hdl(doc);
	TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();

	if(!elem){
		std::cerr << "le noeud à atteindre n'existe pas" << std::endl;
		return false;
	}
	while (elem){
		const char * pKey = elem->Value();
		const char * pValue = elem->GetText();
		std::string temp(pKey);
		std::string temp2(pValue);
		c->setParam(temp, temp2);
		elem = elem->NextSiblingElement();
	}
	return true;
}
