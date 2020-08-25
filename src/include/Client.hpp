#pragma once
#include <string>
#include <unordered_map>
#include "eventEmitter.hpp"
#include "Message.hpp"

namespace DiscordPlus
{
    class Client : public EventEmitter
    {
        public:
            std::unordered_map<std::string, DiscordPlus::Message> messages;
            void login(const std::string token);// Gateway identify
    };
};