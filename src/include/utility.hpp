#pragma once
#include <cpprest/ws_client.h>
#include <cpprest/json.h>
#include <string>
#include <cpprest/details/web_utilities.h>

namespace DiscordPlus
{
    namespace Utility
    {
        web::json::value from_string(std::string const& to_parse);
        std::string StringT_To_String(utility::string_t string_t);
    }
};