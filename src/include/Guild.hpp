#pragma once
#include <string>
#include <vector>
#include "Message.hpp"
#include "Channel.hpp"

namespace DiscordPlus
{
    class Guild
    {
        public:
            DiscordPlus::Channel afkChannel;
            std::string afkChannelID;
            int afkTimeout;
            int approximateMemberCount;
            int approximatePresenceCount;
            bool available;
            std::string banner;
            //List of channels
            //Date of creation
            int createdTimestamp;
            int defaultMessageNotifications;
            bool deleted;
            std::string desciption;
            //Emojis
            //Content filter
            //Features
            std::string icon;
            std::string id;
            int joinedAtTimestamp;
            bool large;
            int maximumMembers;
            int maximumPresences;
            //Client user;
            int memberCount;
            //Members
            int mfaLevel;
            std::string name;
            std::string nameAcronym;
            //Owner as Member
            std::string ownerID;
            bool partner;
            int premiumSubscriptionCount;
            int premiumTier;
            DiscordPlus::Channel publicUpdatesChannel;
            std::string region;
            //Roles manager
            DiscordPlus::Channel rulesChannel;
            std::string rulesChannelID;
            std::string splash;
            DiscordPlus::Channel systemChannel;
            std::string systemChannelID;
            std::string vanityURLCode;
            int vanityURLUses;
            //Verification level
            bool verified;
            //Voice state

            Guild();
            ~Guild();
    };
};