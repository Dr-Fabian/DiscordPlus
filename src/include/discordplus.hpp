#include <string>
#pragma once

namespace DiscordPlus
{
    class Client
    {
        public:
            static void connect(int version, std::string encoding); // Connect to gateway
            void login(std::string* token);                  // Gateway identify
    };
};