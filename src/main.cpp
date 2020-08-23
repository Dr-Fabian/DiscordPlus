#include <cpprest/ws_client.h>
#include <cpprest/json.h>
#include <string>
#include <thread>
#include <future>
#include <vector>
#include "include/discordplus.hpp"
#include "include/utility.hpp"
#include "include/message.hpp"

using namespace web::websockets::client;

int main()
{
    DiscordPlus::Client client;

    client.on("message", [&](DiscordPlus::Message message){
        std::cout << message.content << std::endl;
    });

    client.on("message_delete", [&](DiscordPlus::Message message){
        std::cout << message.id << std::endl;
    });

    client.on("bulk_delete", [&](std::vector<std::string> messages){
        for(int i = 0; i < messages.size(); i++)
        {
            std::cout << messages[i] << std::endl;
        }
    });
    
    client.on("ready", [&](){
        std::cout << "READY!" << std::endl;
    });
    
    client.login("");

    return 1;
}