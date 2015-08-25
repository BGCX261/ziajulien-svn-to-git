#ifndef _PARSER_
#define _PARSER_

#include <sstream>
#include <string>
#include "ResponseStream.h"
#include "HttpRequest.h"
#include "HttpTransaction.h"
using namespace zAPI;

class Parser
{
public : 
	Parser(void);
	~Parser(void);
	
	void	firstline(std::string ligne ,IHttpRequest* req);
	void	parse(IHttpRequest* req, std::string fichier);
	void	separe(zAPI::IHttpRequest *req, std::string ligne );

};
#endif
