#include <cpprest/ws_client.h>
#include <cpprest/json.h>
#include <string>

namespace DiscordPlus
{
    namespace Utility
    {
        web::json::value from_string(std::string const& to_parse);
    }
};