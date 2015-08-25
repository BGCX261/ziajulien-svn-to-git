#ifndef _interzia_
#define _interzia_

#include <iostream>
#include <string>
#include <map>
#include "Connection.h"
#include "Parsing.h"
#include "Execute.h"
#include "Requette.h"

class InterZia
{
protected :
	Connection  *myConnect;
	Parsing     *myParse;
	Execute		*myExec;
public:
	InterZia(void);
	~InterZia(void);
	virtual std::map<std::string, std::string> ParseRequest() = 0;
	virtual std::string executeRequest() = 0;

};

#endif