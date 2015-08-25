#ifndef _Trace_
#define _Trace_
#include <iostream>
#include <string>
#include "Requette.h"

class Trace : public Requette
{
public:
	Trace(void);
	~Trace(void);
	std::string GetType();
	std::string GetReponse();
};

#endif