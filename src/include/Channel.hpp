#pragma once
#include <string>


namespace DiscordPlus
{
    class Channel
    {
    public:
        std::string id{};
        std::string type{};

        Channel(){};
        Channel(std::string id, std::string type) : id(id), type(type) {};

        //functions
        void remove();
        void send(const std::string message);
    };
}