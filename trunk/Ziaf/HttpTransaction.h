#ifndef HTTPTRANSACTION_H__
# define HTTPTRANSACTION_H__

#include "IHttpTransaction.h"
#include <string>
#include <iterator>
#include <map>
using namespace zAPI;

class HttpTransaction : public IHttpTransaction
{
public:
	HttpTransaction(void);
	~HttpTransaction(void);
	void                                        setHeaderOption(const std::string& key, const std::string& value);
	std::string                                 getHeaderOption(const std::string& key) const;
	const std::map<std::string, std::string>&   getHeaderOptions() const;
	bool                                        headerOptionIsSet(const std::string& key) const;
	void                                        setProtocol(const std::string& protocol);
	const std::string&                          getProtocol() const;
private:
	std::map<std::string, std::string>			_headerMap;
	std::string									_currentProtocol;
};

# endif /* !HTTPTRANSACTION_H__ */
