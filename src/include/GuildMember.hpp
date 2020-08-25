#include <string>
#include "Guild.hpp"
#include "Message.hpp"

namespace DiscordPlus
{
    class Guild;

    class GuildMember
    {
        public:
            bool bannable;
            //Client client
            bool deleted;
            int displayColor;
            std::string displayHexColor;
            std::string displayName;
            DiscordPlus::Guild* guild;
            std::string id;
            //Date joinedAt
            int joinedTimestamp;
            bool kickable;
            DiscordPlus::Message* lastMessage;
            std::string lastMessageID;
            bool manageable;
            std::string nickname;
            //Permissions
            //Date premiumSince
            int premiumSinceTimestamp;
            //Presence presence
            //GuildRolesManager Roles
            //User user
            //VoiceState voice

            // ! Constructors / Destructors
            GuildMember(){};
            ~GuildMember(){
                delete guild;
                delete lastMessage;
            };
    };
};