#include "ServerEvent.h"

ServerEvent::ServerEvent(void)
{
}

ServerEvent::ServerEvent(zAPI::IConfig *conf, const char * dir)
{
	_Conf = conf;
	_Directory = dir;
}

ServerEvent::~ServerEvent(void)
{
}

IModule::ChainStatus	ServerEvent::call(IModule::Event ev)
{
	if (IModule::Event::onServerStartEvent == ev)
		return this->onServerStart();
	else if (IModule::Event::onServerStopEvent == ev)
		return this->onServerStop();
	else
		return IModule::ChainStatus::ERRORMODULE;
}

/**
*  The serverStart event.
*  This method will be called just after the server has been launched.
*  @return a ChainStatus
*/
IModule::ChainStatus	ServerEvent::onServerStart()
{
	ParseXml *parse = new ParseXml(this->_Directory);

	if (parse->fillConfig(this->_Conf) == true)
		return IModule::ChainStatus::CONTINUE;
	else
		return IModule::STOP;
}

/**
*  The serverStop event.
*  This method will be called before the server stops.
*  @return a ChainStatus
*/
IModule::ChainStatus	ServerEvent::onServerStop()
{
	delete this->_Conf;
	return IModule::ChainStatus::STOP;
}
