#include "SystemErr.h"
#include "serveur.h"

SystemErr::SystemErr(void)
{
}

SystemErr::~SystemErr(void)
{
}



void SystemErr::do_err(std::string numerr, std::string &reponse, std::map<std::string, std::string> _map)
{
		std::string temp;
	int a;
	char taile[20];

	reponse = serveur::getMap("Protocole",_map);
	reponse += " " + numerr;
	reponse += " " + get_in_XML(numerr);
	reponse += "date : " + serveur::date();

	temp = "<!DOCTYPE HTML PUBLIC ";//IETF//DTD HTML 2.0//EN">
	temp += "<html><head>\n";	
	temp += "<title>";
	temp += numerr  + " " + get_in_XML(numerr);
	temp +=	 "</title>\n";
	temp += "</head><body>\n";
	temp += "<h1>";
	temp +=	 get_in_XML(numerr);
	temp +=	 "</h1>\n";
	temp += "<p>The requested URL can't execute on this server.</p>\n";
	temp += "</body></html>\n";

	a = (int)temp.length();
	sprintf(taile, "%d\n",a);
	std::string toto = taile;
	reponse += "Content-Length: ";
	reponse += toto;
	reponse += "\n";
	reponse += temp;
	reponse += "\n";

}

std::string SystemErr::get_in_XML(std::string err)
{
	std::map<string,string> Xmlparsing;
	TiXmlDocument doc("error.xml");
	if(!doc.LoadFile()){
		cerr << "erreur lors du chargement" << endl;
		cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << endl;

	}
	string temp1;
	string temp2;


	TiXmlHandle hdl(&doc);
	TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();

	if(!elem){
		cerr << "le noeud à atteindre n'existe pas" << endl;
	}


	while (elem){
		temp2 = elem->Value();
		temp1 = elem->GetText();
		Xmlparsing[temp2] = temp1;
		elem = elem->NextSiblingElement(); // iteration 
	}
	return serveur::getMap(err,Xmlparsing);
}