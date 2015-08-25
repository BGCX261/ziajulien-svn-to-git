#ifndef _Put_
#define _Put_
#include <iostream>
#include <string>
#include "Requette.h"

class Put : public Requette
{
public:
	Put(void);
	~Put(void);
	std::string GetType();
	std::string GetReponse();
};

#endif