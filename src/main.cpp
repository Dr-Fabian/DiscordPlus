#include <cpprest/ws_client.h>
#include <cpprest/json.h>
#include <string>
#include <thread>
#include <future>
#include <vector>
#include "include/Client.hpp"
#include "include/utility.hpp"
#include "include/Message.hpp"

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
        for(unsigned long i = 0; i < messages.size(); i++)
        {
            std::cout << messages[i] << std::endl;
        }
    });
    
    client.on("ready", [&](){
        std::cout << "READY!" << std::endl;
    });
    
    client.login("NjU5NTA0NTU1MDA4MTk2NjE5.XgPReg.HvQ0kvYrtmqKac36lRYx3e6ayoY");

    return 1;
}