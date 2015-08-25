#ifndef _Get_
#define _Get_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <map>
#include "SystemErr.h"
#include "Requette.h"



class SystemErr;

class Get : public Requette, public SystemErr
{
public:
	Get(void);
	Get(std::map<std::string,std::string>);
	~Get(void);
	std::string GetType();
	std::string GetReponse();
	std::string traitementmap();

protected:
	std::map<std::string,std::string> _map;
};

#endif