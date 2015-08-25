#ifndef __serveur_h__ 
#define __serveur_h__ 


#define _gio_
//#define _norm_
//#define _RECV_
#define _SEND_
#include <winsock2.h>
#include <iostream>
#include <vector>
#include "Parsing.h"
#include "Execute.h"
#include "tinyxml.h"
#include <locale>

class serveur;

struct thread_param{
       serveur* ser;
       SOCKET soc;
};


class serveur{
private:
	/* CONNECTION */
	int           port;
	SOCKET	      ListeningSocket;
	bool          running;  
	SOCKADDR_IN   ServerAddr;
	std::map<string,string> Xmlparsing;

	/* THREAD*/
	DWORD         ClientThread(SOCKET);
	Parsing *parse;

	/* Client */
	string _Reponse;
	string _Answer;

public:
	/* constructeur par default */
	serveur(int);
	serveur();

	/* initialisation du serveur */
	int							  init();
	std::map<string,string> getXML();

	/* demarrage du serveur */
	int							 start ();

/*fonction utile*/
	
	/*retourne la date actuel */
	static std::string date();

	/* retourne la date actuel + nb de jour et nb d'heure date(jour, heure)*/
	static std::string date(int jour, int heure);

	/*select un elem dans une map*/
		static string serveur::getMap(string entry, std::map<string,string> temp);

	/* methode virtuel pour le traitement de chaque client */
	virtual string				do_client();

	/* fonction d'envoi et reception pour les clients */
private :
	void						readClient(SOCKET soc);
	void						readClient(SOCKET soc, int len); /*read pour nombre de caratere specifique*/ 
	void						sendClient(SOCKET soc);
public :
	/* recupe pointeur du parseur */
	Parsing						*getParse();
	string						getRequest();
	void						setAnswer(string answer);



	/* executeur pour les threads (il transforme l'objet au bon format) */
	static DWORD WINAPI ThreadLauncher(void *p){
		struct thread_param *Obj = reinterpret_cast<struct thread_param*>(p);               
		serveur *s = Obj->ser;                          
		return s->ClientThread(Obj->soc);       
	}
}; 



#endif
