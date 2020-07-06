#pragma once
#include <string>
#include <functional>
#include "eventEmitter.hpp"


namespace DiscordPlus
{
    class Client : public EventEmitter
    {
        public:
            void login(std::string token);// Gateway identify
    };
};