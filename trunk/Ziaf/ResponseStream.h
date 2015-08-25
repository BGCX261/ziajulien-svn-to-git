#ifndef _ResponseStream_
#define _ResponseStream_

#include "IResponseStream.h"
#include "IModule.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace zAPI;

class ResponseStream : public IResponseStream
{
public:
	ResponseStream(void);
	ResponseStream(std::stringstream* t);
	ResponseStream(std::stringstream t);
	~ResponseStream(void);

	virtual std::iostream&      getContent();
	virtual size_t              read(char* buff, size_t size);
	virtual bool                completed() const;
	virtual bool                good() const;
	virtual size_t              getSize() const;
private:
	size_t						_Size;
	std::stringstream  temp;
};

#endif