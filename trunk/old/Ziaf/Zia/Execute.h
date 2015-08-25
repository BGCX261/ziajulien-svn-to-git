#ifndef _execute_
#define _execute_
#include <iostream>
#include <string>
#include "Requette.h"
#include "Get.h"
#include "Delete.h"
#include <iterator>
#include <map>

class Execute
{
public:
	Execute(void);
	~Execute(void);
	Requette* do_execute(std::map<std::string,std::string> select);
};

#endif
