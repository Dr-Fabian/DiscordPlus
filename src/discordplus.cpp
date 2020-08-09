#include <string>
#include <iostream>
#include <cpprest/ws_client.h>
#include <cpprest/json.h>
#include <future>
#include <array>
#include "include/utility.hpp"
#include "include/discordplus.hpp"
#include "include/message.hpp"
#include <cpprest/details/web_utilities.h>

using namespace web::websockets::client;
using namespace DiscordPlus::Utility;

namespace DiscordPlus
{
    void Client::login(std::string token)
    {
        int heartbeats;

        websocket_client client;

        websocket_outgoing_message outgoing_message;

        client.connect(U("wss://gateway.discord.gg/?v=6&encoding=json")).wait();

        client.receive().then([&](websocket_incoming_message message) {
                            return message.extract_string();
                        })
            .then([&](std::string body) {
                
                web::json::value json = DiscordPlus::Utility::from_string(body);

                heartbeats = json["d"]["heartbeat_interval"].as_integer();

                web::json::value indentify_data;

                indentify_data["token"] = web::json::value::string(token);
                indentify_data["properties"]["$os"] = web::json::value::string("Linux");
                indentify_data["properties"]["$browser"] = web::json::value::string("DiscordPlus");
                indentify_data["properties"]["$device"] = web::json::value::string("DiscordPlus");

                web::json::value identify_payload;
                identify_payload["op"] = web::json::value::number(2);
                identify_payload["d"] = indentify_data;

                outgoing_message.set_utf8_message(identify_payload.serialize());

                client.send(outgoing_message);

                auto keep_alive_thread = std::async([&]() {
                    while (true)
                    {
                        web::json::value data = web::json::value::null();
                        web::json::value payload;
                        payload["op"] = web::json::value::number(1);
                        payload["d"] = data;

                        outgoing_message.set_utf8_message(payload.serialize());

                        client.send(outgoing_message).wait();

                        std::this_thread::sleep_for(std::chrono::milliseconds(heartbeats));
                    }
                });

                while (true)
                {

                    client.receive()
                        .then([&](websocket_incoming_message incoming_message) {
                            return incoming_message.extract_string();
                        })
                        .then([&](std::string message) {

                            web::json::value data = DiscordPlus::Utility::from_string(message);

                            //int opCode = data["op"].as_integer();

                            if(data["t"].is_null())
                            {
                                return;
                            } else if(data["t"].serialize() == "\"MESSAGE_CREATE\"")
                            {
                                //Create message object
                                Message discordMessage(StringT_To_String(data["d"]["content"].serialize()), StringT_To_String(data["d"]["id"].serialize()), StringT_To_String(data["d"]["timestamp"].serialize()), StringT_To_String(data["d"]["channel_id"].serialize()));
                                //Emit event
                                this->emit("message", &discordMessage);
                            } else if(data["t"].serialize() == "\"MESSAGE_DELETE\"")
                            {
                                std::cout << data << std::endl;
                                //Create message object
                                Message discordMessage("NULL", StringT_To_String(data["d"]["id"].serialize()), "NULL", StringT_To_String(data["d"]["channel_id"].serialize()));
                                //Emit event
                                this->emit("message_delete", &discordMessage);
                            } else if (data["t"].serialize() == "\"MESSAGE_DELETE_BULK\"")
                            {

                                auto deleted_messages = data["d"]["ids"].as_array();
                                //Create array of messages
                                std::vector<Message> messages;
                                //Put messages in the array
                                for(int i = 0; i < deleted_messages.size(); i++)
                                {
                                    //messages.push_back();
                                }
                                //Emit event
                                this->emit("bulk_delete", &data);
                            }       
                        })
                        .wait();
                }
            })
            .wait();
    };

}; // namespace DiscordPlus