#ifndef _Ziaserve_
#define _Ziaserve_
#pragma comment(lib, "ws2_32.lib")


#include "InterZia.h"
#include "Execute.h"
#include "Parsing.h"
#include "serveur.h"
using namespace std;

class ZiaServe : public serveur, public Execute
{
private:
	typedef std::map<string,string> temp;
public:
	ZiaServe(int p);
	ZiaServe();
public:
	~ZiaServe(void);
	std::string do_client();
	
	
};

#endif