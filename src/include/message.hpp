#pragma once
#include <string>
#include "channel.hpp"

namespace DiscordPlus
{
    class Message
    {
    public:
        std::string content{};
        std::string id{};
        std::string timestamp{};
        std::string channelId{};
        //Channel channel{};
        //Author author;
        //Guild guild;
        //Member member;

        Message(std::string p_content, std::string p_id, std::string p_timestamp, std::string p_channelId) : content(p_content), id(p_id), timestamp(p_timestamp), channelId(p_channelId){};

        void reply(const std::string);
        //<< operator
    };

} // namespace DiscordPlus
