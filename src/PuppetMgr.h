#ifndef PUPPETMGR_H
#define PUPPETMGR_H

#include "PuppetPCH.h"
#include "PuppetAI.h"
#include "PuppetFactory.h"

enum PUPPET_SYSTEM_STATE :uint8
{    
    PUPPET_SYSTEM_STATE_DISABLED = 0,
    PUPPET_SYSTEM_STATE_CREATE_PUPPETS,
    PUPPET_SYSTEM_STATE_LOGIN_PUPPETS,
    PUPPET_SYSTEM_STATE_UPDATING
};

class PuppetAI;

enum PUPPET_CREATING_STATE :uint8
{
    PUPPET_CREATING_STATE_PREPARING,
    PUPPET_CREATING_STATE_DELETING_ACCOUNT,
    PUPPET_CREATING_STATE_CHECKING_DELETE,
    PUPPET_CREATING_STATE_CREATING_ACCOUNT,
    PUPPET_CREATING_STATE_CHECKING_ACCOUNT,
    PUPPET_CREATING_STATE_CREATING_CHARACTER,
    PUPPET_CREATING_STATE_CHECK_CHARACTER,
    PUPPET_CREATING_STATE_FINISHED
};

class PuppetCreator
{
public:
    PuppetCreator(uint32 pmMaxAccountCount, bool pmDeleteAccounts);
    ~PuppetCreator();

public:
    void UpdateCreating();
    uint8 creatingState;

private:
    std::unordered_map<int, std::string> puppetNamesMap;    
    bool deleteAccounts;
    uint32 maxAccountCount;    
    uint32 currentAccountNumber;
    uint8 currentDestClass;
    uint32 checkCharacterNameIndex;
};

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

    map<uint8, vector<uint8> > availableAllianceRaces;
    map<uint8, vector<uint8> > availableHordeRaces;

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

    PuppetCreator* pc;

    QueryResultHolderFuture puppetLoginQR;

    std::unordered_map<uint8, std::string> classesMap;
    std::unordered_map<uint8, std::string> racesMap;
    std::unordered_map<uint8, std::unordered_map<uint8, std::string> > specialtyMap;
};

#define sPuppetMgr PuppetMgr::instance()

#endif
