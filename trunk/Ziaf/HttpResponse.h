#ifndef HttpReponse_H_
#define HttpReponse_H_


#include <queue>
#include "IHttpTransaction.h"
#include "IResponseStream.h"
#include "IHttpResponse.h"
using namespace zAPI;

class HttpResponse: public IHttpResponse
{
public:
	~HttpResponse(void);
	virtual void								setResponseValue(const std::string& value);
	virtual void								setResponseStatus(int statusCode);
	virtual int									getResponseStatus() const;
	virtual const std::string&					getResponseValue() const;
	virtual void								appendStream(IResponseStream* stream);
	virtual std::queue<IResponseStream*>&		getStreams();
	IResponseStream*							getCurrentStream();
	virtual void								skipToSend(IResponseStream* stream, bool flushStream, bool headerInStream);
	virtual void								setHeaderInStream(bool headerInStream);
	virtual bool								getHeaderInStream() const;
	void                                        setHeaderOption(const std::string& key, const std::string& value); // header
	std::string                                 getHeaderOption(const std::string& key) const;
	const std::map<std::string, std::string>&   getHeaderOptions() const;
	bool                                        headerOptionIsSet(const std::string& key) const;
	void                                        setProtocol(const std::string& protocol);
	const std::string&                          getProtocol() const;
private:
	int											_statusCode;
	std::queue<IResponseStream*>				_CurrentResponse;
	zAPI::IResponseStream*						_Currentstream;
	std::string									_value;
	bool										_headerInStream;
	std::map<std::string, std::string>			_headerMap;
	std::string									_currentProtocol;

	std::iostream*								_stream;
};

#endif /* !HTTPRESPONSE_H__ */