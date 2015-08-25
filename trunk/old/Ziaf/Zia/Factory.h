#ifndef _Factory_
#define _Factory_
#include <iostream>
#include <string>
#include "Requette.h"
#include <map>


class Factory
{
public:
	Factory(void);
	~Factory(void);

	Requette* do_execute(std::map<std::string,std::string> select);
};

#endif

