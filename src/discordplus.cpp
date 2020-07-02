#include <string>
#include <iostream>
#include "include/discordplus.hpp"
#include <cpprest/ws_client.h>

namespace DiscordPlus
{
    void Client::connect(int version, std::string encoding)
    {

        //Connect
        web::websockets::client::websocket_client client;
        client.connect("wss://gateway.discord.gg/?v=6&encoding=ENCODING").wait();

        std::cout << "Works" << std::endl;
    };
};