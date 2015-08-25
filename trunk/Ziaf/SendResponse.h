#ifndef SENDRESPONSE_H__
# define SENDRESPONSE_H__

#include "ISendResponse.h"
#include <string>
using namespace zAPI;

class SendResponse : public ISendResponse
{
public:
	SendResponse(void);
	~SendResponse(void);
	virtual IModule::ChainStatus	onPreSend(IHttpRequest*, IHttpResponse*);
	virtual size_t					onProcessContent(IHttpRequest*, IHttpResponse*, char*, size_t, IModule**, unsigned int);
	virtual IModule::ChainStatus	onPostSend(IHttpRequest*, IHttpResponse*);
};

#endif /* !SENDRESPONSE_H__ */