#ifndef _Client_
#define _Client_

#include <winsock2.h>
#include <iostream>
#include <string>

using namespace std;

class Client
{
private:
	SOCKET	_Socks;
	bool	_Send;
	int		_Cpt;
	int		_Flag;
	string	_Name;
	string	_Message;
public:
	Client(SOCKET socks);
	Client(void);
public:
	~Client(void);
 
	/*  SOCKET  */
	SOCKET getSocks(); /* recupere socket du client*/
	void	setSocks(SOCKET sock); 

	/*  send  */
	bool	getSend(); /*Savoir si le client doit send*/
	void	setSend(bool send);

	/*  Cpt  */
	int		getCpt(); /*Savoir si le message en cours de reception par le client correspond au header ou au body*/
	void	setCpt(int cpt);
	void	clrCpt();

	/*  Flag  */
	int		getFlag(); /*Savoir si le message en cours de reception par le client correspond au header ou au body*/
	void	setFlag(int flg);

	/* name */
	string	getName(); /* nom du client*/
	void	setName(string name);

	/* message */
	string	getMessage(); /* nom du client*/
	void	setMessage(char * c);
	void	clrMessage();
};

#endif
