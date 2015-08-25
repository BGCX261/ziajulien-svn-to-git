#ifndef _SystemErr_
#define _SystemErr_

#include <iostream>
#include <string>
#include <map>


class SystemErr
{
public:
	SystemErr(void);
	~SystemErr(void);
void do_err(std::string numerr, std::string &reponse, std::map<std::string, std::string> _map);

protected:	
	std::string get_in_XML(std::string err);
};

#endif