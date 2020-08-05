#include <cpprest/ws_client.h>
#include <cpprest/json.h>
#include <string>
#include <thread>
#include <future>
#include "include/discordplus.hpp"
#include "include/utility.hpp"
#include "include/message.hpp"

using namespace web::websockets::client;

int main()
{

    DiscordPlus::Client client;

    client.on("message", [&](void* pointer){
        std::cout << "message created // message handler" << std::endl;
        DiscordPlus::Message* message_pointer = (DiscordPlus::Message*) pointer;
        std::cout << message_pointer->content << std::endl;
    });
    
    client.login("");

    return 1;
}