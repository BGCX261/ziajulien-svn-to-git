#ifndef _Requette_
#define _Requette_
#include<iostream>
#include<string>
#include<map>

class Requette
{
public:
	Requette(void);
	~Requette(void);
	virtual std::string GetType();
	virtual std::string GetReponse();

protected:
	std::string _Reponse;
	std::string _Type;
};

#endif