#include <string>
#include <functional>
#include <array>
#include <stdarg.h>
#include <boost/variant.hpp>
#include <stdlib.h>
#include "message.hpp"



class EventEmitter
{
private:
    std::vector
    <
        boost::variant
        <
            std::function< void ()>,
            std::function< void ( DiscordPlus::Message )>,
            std::function< void ( std::vector<std::string> )>
        >
    > handlers;
    std::vector<std::string> event;
public:
    std::function<void ( void* )> handler[36];
public:
    void on(std::string event, boost::variant
        <
            std::function< void ()>,
            std::function< void ( DiscordPlus::Message )>,
            std::function< void ( std::vector<std::string> )>
        > callbacks);
protected:
    void emit(std::string event);
    void emit(std::string event, boost::variant<DiscordPlus::Message, std::vector<std::string>>);
};