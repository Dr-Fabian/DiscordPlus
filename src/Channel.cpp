#include "include/channel.hpp"
#include <string>
#include <cpprest/http_client.h>

void Channel::send(const std::string message) 
{

    web::http::http_request sendMessage;
    sendMessage.set_method(web::http::methods::POST);
    sendMessage.set_request_uri("discord api endpoint");

}