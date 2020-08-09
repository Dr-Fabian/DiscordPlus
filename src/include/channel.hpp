#pragma once
#include <string>

class Channel
{
public:
    std::string id{};
    std::string type{};

    Channel(std::string id, std::string type) : id(id), type(type) {};

    //functions
    void remove();
    void send(const std::string message);
};