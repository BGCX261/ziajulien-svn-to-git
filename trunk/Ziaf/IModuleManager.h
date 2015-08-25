#ifndef IMODULEMANAGER_H
# define IMODULEMANAGER_H

#include <iostream>
#include <string>
#include "IModule.h"
#include "IHttpRequest.h"
#include "IHttpResponse.h"
#include "IClientSocket.h"
#include "IModuleInfo.h"

namespace zAPI
{
    /// Will manage module. This contains every modules instances.
    class   IModuleManager
    {
        public:
            virtual ~IModuleManager() {}
            virtual IModule::ChainStatus    call(IModule::Event) = 0;
            virtual IModule::ChainStatus    call(IModule::Event, IModuleInfo*) = 0;
            virtual IClientSocket*          call(IModule::Event, SOCKET, IConfig *) = 0;
            virtual IModule::ChainStatus    call(IModule::Event, const char*, size_t) = 0;
            virtual IModule::ChainStatus    call(IModule::Event, IHttpRequest*, IHttpResponse*) = 0;
    };
}

#endif // IMODULEMANAGER_H

