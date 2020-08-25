#pragma once
#include <string>
#include "Message.hpp"

namespace DiscordPlus
{
    class Message;

    class User
    {
        public:
            std::string avatar;
            bool bot;
            //Client client
            //Date createdAt
            int createdAtTimestamp;
            std::string defaultAvatarURL;
            std::string discriminator;
            //DmChannel dmChannel
            //Userflags flags
            std::string id;
            DiscordPlus::Message* lastMessage;
            std::string lastMessageChannelID;
            std::string lastMessageID;
            //Presence presence
            bool system;
            std::string tag;
            std::string username;

            User(){};
            ~User(){};
    };
};