#pragma once
#include <string>
#include "eventEmitter.hpp"
#include <map>
#include "message.hpp"

namespace DiscordPlus
{
    class Client : public EventEmitter
    {
        public:
            std::map<std::string, DiscordPlus::Message> messages(); 
            void login(const std::string token);// Gateway identify
    };
};