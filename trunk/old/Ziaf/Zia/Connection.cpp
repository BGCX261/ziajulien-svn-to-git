#include "Connection.h"
#include <winsock2.h>
#include <iostream>
#include <string>
#include <list>

#include <iterator>

Connection::Connection(int port)
{
  _Port = port;
}

Connection::~Connection(void)
{
}

bool Connection::startServ()
{
	/*SOCKADDR_IN                 ClientAddr;
	int                         ClientAddrLen;
	HANDLE                      hProcessThread;
	SOCKET                      NewConnection;
	struct thread_param         p;

	if( ( ListeningSocket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP ) ) == INVALID_SOCKET ){
		cerr << "ne peut créer la socket. Erreur n° " << WSAGetLastError()<< endl;
		WSACleanup();
		return 1;
	}

	if( bind( ListeningSocket, (SOCKADDR *)&ServerAddr, sizeof( ServerAddr ) ) == SOCKET_ERROR ){
		cerr << "bind a échoué avec l'erreur " << WSAGetLastError() << endl;
		cerr << "Le port est peut-être déjà utilisé par un autre processus " << endl;
		closesocket( ListeningSocket );
		WSACleanup();
		return 1;
	}

	if( listen( ListeningSocket, 5 ) == SOCKET_ERROR ){
		cerr << "listen a échoué avec l'erreur " << WSAGetLastError() << endl;
		closesocket( ListeningSocket );
		WSACleanup();
		return 1;
	}

	cout << "serveur démarré : à l'écoute du port " << port << endl;
	running = true;
	ClientAddrLen = sizeof( ClientAddr );

	while(running){

		if((NewConnection = accept( ListeningSocket, (SOCKADDR *) &ClientAddr, &ClientAddrLen)) == INVALID_SOCKET){
			cerr  << "accept a échoué avec l'erreur " << WSAGetLastError() << endl;;
			closesocket( ListeningSocket );
			WSACleanup();
			return 1;
		}

		p.ser = this;
		p.soc = NewConnection;

		cout << "client connecté ::  IP : " <<inet_ntoa( ClientAddr.sin_addr )<< " ,port = " <<ntohs( ClientAddr.sin_port ) << endl;

		hProcessThread = CreateThread(NULL, 0,&serveur::ThreadLauncher, &p,0,NULL);
		if ( hProcessThread == NULL ){
			cerr << "CreateThread a échoué avec l'erreur " <<GetLastError()<< endl;
		}
	}

	return 0;*/
	return false;
}

bool Connection::InitServ(string file)
{

	struct in_addr  MyAddress;
	struct hostent  *host;
	char HostName[100];
	WSADATA	      wsaData;

	if(WSAStartup(MAKEWORD(2,2), &wsaData ) != 0 ){
		cerr << "ERROR : WSAStartup " << endl;
		return false;
	}
	if( gethostname( HostName, 100 ) == SOCKET_ERROR ){
		cerr<< "ERROR : gethostname()" << endl;
		return false;
	}
	if( (host = gethostbyname( HostName ) ) == NULL){
		cerr << "ERROR : gethostbyname()" << endl;
		return false;
	}
	memcpy( &MyAddress.s_addr, host->h_addr_list[0], sizeof( MyAddress.s_addr ) );
	_ADRRServer.sin_family = AF_INET;
	_ADRRServer.sin_port = htons( _Port );
	//_ADRRServer.sin_addr.s_addr = inet_addr( inet_ntoa( MyAddress ) );
	_ADRRServer.sin_addr.s_addr = INADDR_ANY;;
	return true;
}

void Connection::Send(std::string answer, Client *temp)
{
	/*const char * buf;
	bool flag = true;
	int lenght_send;
	int i;

	while (flag != false)
	{
	i = answer.length();
		buf = answer.c_str();
		if (i > 1048)
			i = 1048;
		if (i != 0)
		{
			lenght_send = send(temp->getSocks(), buf, i, 0);
			answer = answer.substr(lenght_send);
		}
		else
		{
			flag = false;
		}
	}*/
}

void	Connection::clearmess(Client *temp)
{
	temp->clrMessage();
}

void Connection::Receive(Client *temp)
{
	
/*

	int msg_lenght;
	char msg_rcv[2];
	
	msg_lenght = recv(temp->getSocks(), msg_rcv, 1, 0);
	msg_rcv[msg_lenght] = '\0';
	cout << msg_rcv << endl;
	temp->setMessage(msg_rcv);
	int i = msg_rcv[0];

	if (msg_rcv[0] == 10 && temp->getFlag() == 0)
	{
		temp->setFlag(1);
	
	}
	else if (msg_rcv[0] == 13 && temp->getFlag() == 1)
	{
		temp->setCpt(1);
	}
	else
	{
		temp->setFlag(0);
	}

	if (temp->getCpt() == 1)
	{
		temp->clrCpt();
	cout << temp->getMessage();
		temp->setSend(true);
	}
	*/
}

void	Connection::setTimeval(int sec,int usec)
{
	//timeval temp = {1,0};
}

int Connection::doSelect()
{
	//FD_ZERO(&fdread); 
	//FD_ZERO(&fdwrite);

	//list<Client>::iterator ii;
	//FD_SET(sock,&fdread); /* prepare select read serveur */
	//for(ii=ClientList->begin(); ii != ClientList->end(); ++ii)  /* prepare select read/write client*/
	//{
	//	Client temp = *ii;
	//	FD_SET(temp.getSocks(),&fdread);
	//	/* mettre ici pour le write */
	//}

	return select(0 ,&fdread,NULL,NULL,&waiting);
}

void	Connection::readServ()
{
	//int sinsize = sizeof(csin);
	//if (FD_ISSET(sock,&fdread)) /* verifie si le serveur recoi*/
	//{
	//	if((csock = accept(sock, (SOCKADDR *)&csin, &sinsize)) != INVALID_SOCKET)
	//	{
	//		ClientList->push_back(Client(csock));

	//		//send(csock, "Bienvenue\r\n", 14, 0);
	//	}
	//}
}

void	Connection::readClient()
{
	//list<Client>::iterator ii;
	//for(ii=getListClient()->begin(); ii != getListClient()->end(); ++ii)  /* Verifie si le client recoi*/
	//{
	//	Client temp = *ii;
	//	if (FD_ISSET(temp.getSocks(),&fdread)) /*Action pour chacun des client qd il envoi qqchose*/
	//	{
	//		char tempo[256];
	//		int result;
	//		result = recv(temp.getSocks(),tempo,1,0);
	//		tempo[result] = '\0';
	//		/*cout << tempo;*/

	//	}
	//}
}

fd_set *Connection::getFdread()
{
	return &fdread;
}

std::list<Client> *Connection::getListClient()
{
	return ClientList;
}