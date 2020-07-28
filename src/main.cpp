#include <cpprest/ws_client.h>
#include <cpprest/json.h>
#include <string>
#include <thread>
#include <future>
#include "include/discordplus.hpp"
#include "include/string_to_json.hpp"

using namespace web::websockets::client;

int main()
{

    DiscordPlus::Client client;

    client.on("message", [&](){
        std::cout << "message created // message handler" << std::endl;
    });
    
    client.login("NjU5NTA0NTU1MDA4MTk2NjE5.XxShCg.Apa3jna5ceiAJD5rWzVucIS4iyI");

    return 1;
}