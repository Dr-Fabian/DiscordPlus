#include "include/eventEmitter.hpp"
#include "include/message.hpp"
#include <string>
#include <vector>
#include <boost/variant.hpp>
#include <algorithm>
#include <iostream>
#include <boost/any.hpp>

void EventEmitter::emit(std::string event, boost::variant<DiscordPlus::Message, std::vector<std::string>> data)
{
    //Vector iterator
    auto iterator = std::find(std::begin(this->event), std::end(this->event), event);
    //If event is registered
    if(iterator != std::end(this->event)){
        //Index of the callback
        int index = std::distance(std::begin(this->event), iterator);
        //Calls the handler
        if(event == "message")
        {
            boost::get<std::function<void ( DiscordPlus::Message )>>(this->handlers[index])(boost::get<DiscordPlus::Message>(data));
        }
    }
}

void EventEmitter::emit(std::string event)
{
    //Array iterator
    auto iterator = std::find(std::begin(this->event), std::end(this->event), event);
    //If event is registered
    if(iterator != std::end(this->event)){
        //Index of the callback
        int index = std::distance(std::begin(this->event), iterator);
        //Calls the handler
        boost::get<std::function<void ()>>(this->handlers[index])();
    }
}

//Registers the event handler
void EventEmitter::on(std::string event, boost::variant
        <
            std::function< void ()>,
            std::function< void ( DiscordPlus::Message )>,
            std::function< void ( std::vector<std::string> )>
        > callback)
{

    std::cout << "works" << std::endl;
    //Puts the event name in the event array
    this->event.push_back(event);
    //Puts the event handler in the handler array
    this->handlers.push_back(callback);
    std::cout << "works" << std::endl;

}
