#ifndef HTTPREQUEST_H__
# define HTTPREQUEST_H__

#include "IHttpTransaction.h"
#include "IHttpRequest.h"
#include "IConfig.h"
#include "ClientSocket.h"
#include <iterator>
#include <iostream>
#include <map>
#include <string>
using namespace zAPI;

class HttpRequest : public IHttpRequest, public IHttpTransaction
{
public:
	HttpRequest(void);
	~HttpRequest(void);
	virtual void                                        setUri(const std::string& uri, bool relative= true);
	virtual const std::string&                          getUri() const;
	virtual void                                        setUriQuery(const std::string& query);
	virtual const std::string&							getUriQuery() const;
	virtual void                                        setBodyStream(zAPI::IResponseStream* stream);
	virtual zAPI::IResponseStream*                      getBodyStream() const;
	virtual bool                                        setParam(const std::string& key, void* value);
	virtual void*                                       getParam(const std::string&) const;
	virtual void                                        setCommand(const std::string& command);
	virtual const std::string&                          getCommand() const;
	virtual void                                        setConfig(IConfig* config);
	virtual IConfig*                                    getConfig() const;
	virtual unsigned int                                getRequestId() const;
	virtual void                                        setRequestId(unsigned int id);
	virtual void                                        setClient(zAPI::IClientSocket* clt);
	virtual zAPI::IClientSocket*                        getClient() const;
	/* http transaction */
	void												setHeaderOption(const std::string& key, const std::string& value);
	std::string											getHeaderOption(const std::string& key) const;
	const std::map<std::string, std::string>&			getHeaderOptions() const;
	bool												headerOptionIsSet(const std::string& key) const;
	void												setProtocol(const std::string& protocol);
	const std::string&									getProtocol() const;

private:
	std::string											_currentUri;
	std::string											_currentCommand;
	std::string											_UriQuery;
	std::map<std::string, std::string>					_bodyMap;
	std::map<std::string, void*>						_paramMap;
	IConfig*											_currentConfig;
	unsigned int										_currentRequestId;
	std::string											temp;
	zAPI::IResponseStream *								_Stream;

	std::map<std::string, std::string>					_headerMap;
	std::string											_currentProtocol;
};

#endif /* !HTTPREQUEST_H__ */
