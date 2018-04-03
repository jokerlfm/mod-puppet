#ifndef PUPPETMGR_H
#define PUPPETMGR_H

#include "PuppetPCH.h"
#include "PuppetAI.h"
#include "PuppetFactory.h"

enum PUPPET_SYSTEM_STATE :uint8
{
    PUPPET_SYSTEM_STATE_LOADING_CONFIG = 0,
    PUPPET_SYSTEM_STATE_DISABLED,
    PUPPET_SYSTEM_STATE_DELETING_ACCOUNTS,
    PUPPET_SYSTEM_STATE_CHECKING_DELETE,
    PUPPET_SYSTEM_STATE_CREATING_ACCOUNTS,
    PUPPET_SYSTEM_STATE_CHECKING_ACCOUNTS,
    PUPPET_SYSTEM_STATE_CREATING_CHARACTERS,
    PUPPET_SYSTEM_STATE_CHECKING_CHARACTERS,
    PUPPET_SYSTEM_STATE_CREATE_PUPPETS,
    PUPPET_SYSTEM_STATE_LOGIN_PUPPETS,
    PUPPET_SYSTEM_STATE_UPDATING
};

class PuppetAI;

class PuppetMgr
{
public:
    PuppetMgr();
    ~PuppetMgr();

    static PuppetMgr& instance()
    {
        static PuppetMgr instance;
        return instance;
    }

public:
    void ProcessPuppets(uint32 elapsed);

    void LogoutAllPuppets();
    void OnPlayerLogout(Player* player);
    void OnPlayerLogin(Player* player);

    unordered_map<uint8, unordered_map<uint32, WorldLocation>> teleportZoneCacheMap;
    unordered_map<uint32, uint32> arrowMap;
    unordered_map<uint32, uint32> bulletMap;
    unordered_map<uint32, uint32> healthPotionMap;
    unordered_map<uint32, uint32> manaPotionMap;
    unordered_map<uint32, uint32> foodMap;
    unordered_map<uint32, uint32> drinkMap;

    std::unordered_map<uint32, uint32> tamableCreatureMap;
    std::unordered_map<uint8, std::unordered_map<uint8, std::unordered_map<uint32, uint32>>> equipmentMap;
    std::unordered_map<uint32, std::set<uint32>> spellQuestsMap;
    std::unordered_map<uint32, PuppetAI*> activeAIMap;

    std::string GetRaceName(uint8 pmRace);
    std::string GetClassName(uint8 pmClass);
    std::string GetSpecialty(uint8 pmClass, uint8 pmTabIndex);
    bool IsAlliance(uint8 race);
    void split(std::string& s, std::string& delim, std::vector< std::string >* ret);
    std::string& replace_all_distinct(std::string& str, const std::string& old_value, const std::string& new_value);

private:
    uint8 puppetSystemState;
    void Initialize();

    std::unordered_map<uint32, uint32> validPuppetAccountsMap;
    unordered_map<uint32, set<uint32>> validPuppetCharactersMap;
    
    std::unordered_map<int, std::string> GenerateRandomPuppetNamesMap();

    map<uint8, vector<uint8> > availableAllianceRaces;
    map<uint8, vector<uint8> > availableHordeRaces;

    QueryResultHolderFuture puppetLoginQR;

    std::unordered_map<uint8, std::string> classesMap;
    std::unordered_map<uint8, std::string> racesMap;
    std::unordered_map<uint8, std::unordered_map<uint8, std::string> > specialtyMap;
};

#define sPuppetMgr PuppetMgr::instance()

#endif
