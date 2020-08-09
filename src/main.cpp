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
        DiscordPlus::Message message = *(DiscordPlus:: Message*) pointer;
        std::cout << message.content << std::endl;
    });

    client.on("message_delete", [&](void* pointer){
        std::cout << "message deleted // delete handler" <<  std::endl;
        DiscordPlus::Message message = *(DiscordPlus:: Message*) pointer;
        std::cout << message.id << std::endl;
    });
    
    client.login("NjU5NTA0NTU1MDA4MTk2NjE5.XgPReg.hYvlx8s9wLCmBP5hJXHLOdrZGa8");

    return 1;
}