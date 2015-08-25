#ifndef _Delete_
#define _Delete_
#include <iostream>
#include <string>
#include <map>
#include "Requette.h"

class Delete : public Requette
{
public:
	Delete(void);
	Delete(std::map<std::string,std::string>);
	~Delete(void);
	std::string GetType();
	std::string GetReponse();
	std::string traitementmap();
protected:
	std::map<std::string,std::string> _map;
};

#endif