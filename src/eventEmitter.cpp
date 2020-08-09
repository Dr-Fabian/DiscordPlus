#include "include/eventEmitter.hpp"
#include "include/message.hpp"
#include <string>
#include <algorithm>
#include <iostream>


void EventEmitter::emit(std::string event, void* pointer)
{
    //Vector iterator
    auto iterator = std::find(std::begin(this->event), std::end(this->event), event);
    //If event is registered
    if(iterator != std::end(this->event)){
        //Index of the callback
        int index = std::distance(std::begin(this->event), iterator);
        //Calls the handler
        (this->handler[index])(pointer);
    }
}

//Registers the event handler
void EventEmitter::on(std::string event, std::function<void ( void* )> callback)
{

    //Puts the event name in the event array
    this->event.push_back(event);
    //Puts the event handler in the handler array
    this->handler[this->event.size() - 1] = callback;
}
