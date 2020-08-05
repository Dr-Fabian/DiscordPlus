#include "include/utility.hpp"
#include <cpprest/json.h>
#include <string>
#include <cpprest/details/web_utilities.h>

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

        std::string StringT_To_String(utility::string_t string_t)
        {
            return utility::conversions::to_utf8string(string_t);
        }
    };
};