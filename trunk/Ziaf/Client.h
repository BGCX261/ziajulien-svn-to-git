#ifndef _Client_
#define _Client_

#include "IClientSocket.h"
#include <iostream>
#include <string>


class Client
{
public:
	Client(zAPI::IClientSocket *Mclient);
	~Client(void);

	void					setClientSocket(zAPI::IClientSocket *Mclient);
	zAPI::IClientSocket*	getClientSocket();
	void					addRecv(std::string add);
	void					clrRecv();
	std::string				getRecv();
	bool					getIsSend();
	void					setIsSend(bool _send);
	std::string				getResponse();
	void					setResponse(std::string res);
	void					subResponse(int lenght);
	int						getPosSend();
	void					setPosSend(int pos);
	void					setCommand(int i);
	int						getCommand();
private:
	int						_pos;
	zAPI::IClientSocket		*_Client;
	std::string				_Recv;
	bool					_IsSend;
	std::string				_Response;
	int						_Val;
};

#endif