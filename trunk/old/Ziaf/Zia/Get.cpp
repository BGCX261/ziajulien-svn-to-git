#include "Get.h"
#include "SystemErr.h"
#include "serveur.h"

Get::Get(void)
{
	_Type = "GET";
}

Get::~Get(void)
{
}

Get::Get(std::map<std::string,std::string> mapparse)
{
	_map = mapparse;
	traitementmap();
}

std::string Get::GetType()
{
	return this->_Type;
}

std::string Get::GetReponse()
{
	return this->_Reponse;
}

std::string Get::traitementmap()
{
	bool ok;
	ok = false;
	int lines;
	int caractere = 0;
	std::string  fichier;
	std::string mess;
	std::string extension;
	std::string extendfolder;
	std::map<std::string,std::string>::iterator it;

	if(serveur::getMap("Protocole", _map).compare("HTTP/1.1") == 0)
	{
		if(serveur::getMap("host", _map).compare("Erreur") == 0)
		{
			_Reponse.clear();
			do_err("400",_Reponse,_map);
			return _Reponse;
		}
	}

	_Reponse = serveur::getMap("Protocole", _map);
	fichier = "." + serveur::getMap("get", _map);
	std::cout << fichier <<"-" << std::endl; 
	extension = serveur::getMap("get", _map).substr(serveur::getMap("get", _map).find_last_of('.') + 1,serveur::getMap("get", _map).length());
std::cout << extension <<"-" << std::endl; 
	if(extension == "html")
		extendfolder = "text/html";
	else if(extension == "jpeg")
		extendfolder = "image/jpeg";
	else if(extension == "mpeg")
		extendfolder= "audio/mpeg";
	else if(extension == "txt")
		extendfolder = "text/plain";
	else
		std::cout << "erreur extension fichier" << std::endl;
	std::ifstream file(fichier.c_str());
	std::string ligne; // variable contenant chaque ligne lu 
	if (file)
    {
		ok = true;
		_Reponse += "200 Ok\n" ;
	
	}	
	else
	{
	 _Reponse += " 404 Not Found\n";
	
	 string temp;
	 temp = "<!DOCTYPE HTML PUBLIC ";//IETF//DTD HTML 2.0//EN">
	 temp += "<html><head>\n";	
	 temp += "<title>404 Not Found</title>\n";
	 temp += "</head><body>\n";
	 temp += "<h1>Not Found</h1>\n";
	 temp += "<p>The requested URL /ltest.ffd was not found on this server.</p>\n";
	 temp += "</body></html>\n";

	 int a;
	a = (int)temp.length();
	char taile[20];
	sprintf(taile, "%d\n",a);
	std::string toto = taile;
	  _Reponse += "Content-Length: ";
	  _Reponse += toto;
	  _Reponse += "\n";
	  _Reponse += temp;
	  _Reponse += "\n";
	  return _Reponse;
	}	
	if (ok == true)
	{
		while ( std::getline(file, ligne ) )
      {  
		  mess += ligne;
		}
	}
	
	std::string temp;
	int a;
	a = (int)mess.length();
	char taile[20];
	sprintf(taile, "%d\n",a);
	std::string toto = taile;
	_Reponse += "Date : ";
	_Reponse += serveur::date().c_str();
	_Reponse += "\n";
	_Reponse += "Server : Zia/0.1\nContent-type: ";
	_Reponse += extendfolder.c_str();
	_Reponse += "\n";
	_Reponse += "Content-Length: " + toto;
	_Reponse += "\n";
	_Reponse += mess;
	_Reponse += "\n";
	//std::cout  << _Reponse <<"-----------------------------------------" << std::endl; 
	return _Reponse;
}
