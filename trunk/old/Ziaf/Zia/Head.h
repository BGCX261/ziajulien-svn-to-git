#ifndef _Head_
#define _Head_
#include <iostream>
#include <string>
#include "Requette.h"

class Head : public Requette
{
public:
	Head(void);
	~Head(void);
	std::string GetType();
	std::string GetReponse();
};

#endif