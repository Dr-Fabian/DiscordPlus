#pragma once
#include <string>
#include <iostream>
#include "Channel.hpp"
#include "Guild.hpp"
#include "GuildMember.hpp"
#include "User.hpp"

namespace DiscordPlus
{
    class Guild;
    class GuildMember;
    class User;

    class Message
    {
    public:
        std::string content{};
        std::string id{};
        std::string timestamp{};
        std::string channelId{};
        DiscordPlus::Channel channel{};
        //Author author;
        DiscordPlus::Guild* guild;
        DiscordPlus::GuildMember* member;

        Message(std::string p_content, std::string p_id, std::string p_timestamp, std::string p_channelId) : content(p_content), id(p_id), timestamp(p_timestamp), channelId(p_channelId){};

        void reply(const std::string);
        //<< operator
    };

} // namespace DiscordPlus
