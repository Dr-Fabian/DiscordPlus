#include "include/string_to_json.hpp"
#include <cpprest/json.h>

namespace DiscordPlus
{
    namespace Utility
    {
        web::json::value from_string(std::string const& to_parse)
        {
            utility::stringstream_t s;

            s << to_parse;

            web::json::value json = web::json::value::parse(s);

            return json;
        }
    };
};