#ifndef _Connect_
#define _Connect_
#include <iostream>
#include <string>
#include "Requette.h"

class Connect : public Requette
{
public:
	Connect(void);
	~Connect(void);
	std::string GetType();
	std::string GetReponse();
};

#endif