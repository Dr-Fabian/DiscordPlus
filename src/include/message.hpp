#pragma once
#include <string>
#include "channel.hpp"

class Message
{

public:
    std::string content;
    std::string id;
    Channel channel;
    //Author author;
    //Guild guild;
    //Member member;

    void reply(const std::string);
    //<< operator
};