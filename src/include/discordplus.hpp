#pragma once
#include <string>
#include "eventEmitter.hpp"


namespace DiscordPlus
{
    class Client : public EventEmitter
    {
        public:
            void login(const std::string token);// Gateway identify
    };
};