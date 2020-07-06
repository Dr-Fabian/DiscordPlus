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
        //Message handler
    });

    client.login("");

    return 1;
}