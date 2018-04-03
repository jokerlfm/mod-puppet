#include "Puppet.h"
#include "PuppetConfig.h"
#include "PuppetAI.h"

class Puppet_WorldScript : public WorldScript
{
public:
    Puppet_WorldScript()
        : WorldScript("Puppet_WorldScript")
    {
    }

    void OnAfterConfigLoad(bool reload) override
    {
        /* from skeleton module */
        if (!reload) {
            std::string conf_path = _CONF_DIR;
            std::string cfg_file = conf_path + "/puppet.conf";
#ifdef WIN32
            cfg_file = "puppet.conf";
#endif
            std::string cfg_def_file = cfg_file + ".dist";
            sConfigMgr->LoadMore(cfg_def_file.c_str());

            sConfigMgr->LoadMore(cfg_file.c_str());
        }
    }

    void OnUpdate(uint32 pmElapsed)
    {
        sPuppetMgr.ProcessPuppets(pmElapsed);
    }
};

class Puppet_PlayerScript : public PlayerScript
{
public:
    Puppet_PlayerScript()
        : PlayerScript("Puppet_PlayerScript")
    {
    }

    void OnBeforeUpdate(Player* player, uint32 p_time)
    {
        if (sPuppetMgr.activeAIMap.find(player->GetGUIDLow()) != sPuppetMgr.activeAIMap.end())
        {
            sPuppetMgr.activeAIMap[player->GetGUIDLow()]->UpdateAI(p_time);
        }
    }

    void OnChat(Player* pmSender, uint32 pmType, uint32 pmLanguage, std::string& pmContent, Player* pmReceiver)
    {
        if (sPuppetMgr.activeAIMap.find(pmReceiver->GetGUIDLow()) != sPuppetMgr.activeAIMap.end())
        {
            sPuppetMgr.activeAIMap[pmReceiver->GetGUIDLow()]->HandleChatCommand(pmSender, pmContent);
        }
    }

    void OnChat(Player* pmSender, uint32 pmType, uint32 pmLanguage, std::string& pmContent, Group* pmGroup)
    {
        for (GroupReference* itr = pmGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* player = itr->GetSource();
            if (sPuppetMgr.activeAIMap.find(player->GetGUIDLow()) != sPuppetMgr.activeAIMap.end())
            {
                sPuppetMgr.activeAIMap[player->GetGUIDLow()]->HandleChatCommand(pmSender, pmContent);
            }
        }
    }
};

class Puppet_UnitScript : public UnitScript
{
public:
    Puppet_UnitScript()
        : UnitScript("Puppet_UnitScript", true)
    {
    }

    uint32 DealDamage(Unit* AttackerUnit, Unit *playerVictim, uint32 damage, DamageEffectType /*damagetype*/) override
    {
        return damage;
    }
};

class Puppet_CommandScript : public CommandScript
{
public:
    Puppet_CommandScript() : CommandScript("Puppet_CommandScript") { }

    std::vector<ChatCommand> GetCommands() const
    {
        static std::vector<ChatCommand> commandTable =
        {
            { "disable puppet", SEC_GAMEMASTER, true, &HandleDisablePuppetCommand, "Disable puppet system" },
            { "enable puppet", SEC_GAMEMASTER, true, &HandleEnablePuppetCommand, "Enable puppet system" },
        };

        return commandTable;
    }

    static bool HandleDisablePuppetCommand(ChatHandler* handler, const char* args)
    {

        return false;
    }

    static bool HandleEnablePuppetCommand(ChatHandler* handler, const char* /*args*/)
    {
        return false;
    }
};

void LoadPuppet()
{
    new Puppet_WorldScript;
    new Puppet_PlayerScript;
    new Puppet_UnitScript;
    new Puppet_CommandScript;
}
