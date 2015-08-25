#define _Xml_


#include "ZiaServe.h"
#include "serveur.h"

int main()
{
	ZiaServe *test = new ZiaServe(80);

#ifdef _Xml_
	ZiaServe *MyServer = new ZiaServe();
	if(MyServer->init()!=0){
		cerr << "ne peut initialiser le serveur"<< endl;
		return 1;
	}
  
	if(MyServer->start()!=0){
		cerr << "ne peut démarrer le serveur"<< endl;
		return 1;
	}
#endif

#ifdef _NOXml_
	ZiaServe *MyServer = new ZiaServe(8080);
	if(MyServer->init()!=0){
		cerr << "ne peut initialiser le serveur"<< endl;
		return 1;
	}
  
	if(MyServer->start()!=0){
		cerr << "ne peut démarrer le serveur"<< endl;
		return 1;
	}
#endif

	return 0;
}
