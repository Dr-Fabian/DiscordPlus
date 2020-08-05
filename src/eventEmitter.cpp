#include "include/eventEmitter.hpp"
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

        (this->handler[index])(pointer);
    }
}

void EventEmitter::on(std::string event, std::function<void ( void* )> callback)
{
    addListener(event, callback);
}

void EventEmitter::addListener(std::string event, std::function<void ( void* )> callback)
{
    this->event.push_back(event);
    this->handler[this->event.size() - 1] = callback;
}