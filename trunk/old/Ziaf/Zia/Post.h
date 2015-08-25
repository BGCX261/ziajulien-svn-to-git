#ifndef _Post_
#define _Post_
#include <iostream>
#include <string>
#include "Requette.h"

class Post : public Requette
{
public:
	Post(void);
	~Post(void);
	std::string GetType();
	std::string GetReponse();
};

#endif