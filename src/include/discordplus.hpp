#pragma once
#include <string>
#include "eventEmitter.hpp"
#include <unordered_map>
#include "message.hpp"

namespace DiscordPlus
{
    class Client : public EventEmitter
    {
        public:
            std::unordered_map<std::string, DiscordPlus::Message> messages;
            void login(const std::string token);// Gateway identify
    };
};