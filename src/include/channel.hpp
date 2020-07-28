#pragma once
#include <string>

class Channel
{
public:
    std::string id;
    std::string type;

    //functions
    void remove();
    void send(const std::string message);
};