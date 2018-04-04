#ifndef PUPPETAI_H
#define PUPPETAI_H

#include "PuppetPCH.h"
#include "PuppetConfig.h"
#include "PuppetMgr.h"
#include "AIEvent.h"
#include "DatabaseEnv.h"
#include "MotionMaster.h"
#include "PathGenerator.h"
#include "MoveSplineInit.h"
#include "Battleground.h"
#include "MovementGenerator.h"
#include "ThreatManager.h"
#include "LootMgr.h"
#include "BattlefieldWG.h"
#include "AuctionHouseMgr.h"
#include "ScriptMgr.h"
#include "GroupMgr.h"
#include "Transport.h"
#include "ArenaSpectator.h"
#include "WorldSession.h"
#include "BattlegroundMgr.h"
#include "QueryHolder.h"

using namespace std;

enum PUPPET_STATE :uint8
{
    PUPPET_STATE_LOCK,
    PUPPET_STATE_LOGIN,
    PUPPET_STATE_RANDOMIZE,
    PUPPET_STATE_PREPARATION,
    PUPPET_STATE_READY
};

class PuppetLoginQueryHolder : public SQLQueryHolder
{
private:
    uint32 m_accountId;
    uint64 m_guid;
public:
    PuppetLoginQueryHolder(uint32 accountId, uint64 guid)
        : m_accountId(accountId), m_guid(guid) { }
    uint64 GetGuid() const { return m_guid; }
    uint32 GetAccountId() const { return m_accountId; }
    bool Initialize();
};


class PuppetAI
{
    const bool operator < (const PuppetAI& rightPAI)
    {
        return this->entry < rightPAI.entry;
    }

public:
    PuppetAI(int pmEntry, uint32 pmAccountID, uint32 pmCharacterGUIDLow)
    {
        accountID = pmAccountID;
        characterGUIDLow = pmCharacterGUIDLow;
        sourcePlayer = NULL;
        masterPlayer = NULL;
        puppetState = PUPPET_STATE::PUPPET_STATE_LOCK;
        prevTotalElapsed = 0;
        checkElapsed = 0;
        currentCheckDelay = 0;
        isAlive = true;
        isInCombat = false;
        specialty = "";
        currentStrategyName = "solo";
        deadTime = 0;
        interestingDuration = 0;
        interested = true;
        resurrecting = false;
        lootedCreaturesSet.clear();
        basicItemsMap.clear();
    }

    ~PuppetAI()
    {

    }

public:
    int entry;
    uint8 puppetState;
    Player * sourcePlayer;
    Player * masterPlayer;
    std::string specialty;
    void InitialEvents();
    void QueryLogin();
    bool FinishLogin();
    void UpdateAI(uint32 pmElapsed);
    void QueueUpdateAI(uint32 pmTotalElapsed);
    void HandleTeleport();
    void HandleChatCommand(Player* pmCommander, std::string pmChatContent);
    void HandleGroupInvite(Player* pmInviter);
    void ResetStrategies();
    void SetStrategy(std::string pmNewStrategy);
    void UpdateSpellsMap();
    void Prepare();
    void SetMaster(Player* pmMaster);

    void Randomize();
    void RandomTeleport();
    void Revive();

private:
    uint32 accountID;
    uint32 characterGUIDLow;
    QueryResultHolderFuture qrhf;
    uint32 prevTotalElapsed;
    uint32 checkElapsed;
    int currentCheckDelay;
    bool isAlive;
    bool isInCombat;
    uint32 deadTime;
    int interestingDuration;
    bool interested;
    bool resurrecting;
    std::set<uint64> lootedCreaturesSet;
    std::unordered_map<uint32, uint32> basicItemsMap;
    std::unordered_map <std::string, std::set<AIEvent*>> eventsMap;
    std::string currentStrategyName;
    void LoadDetailEvents(std::string pmSpecialtyName);
    uint16 GetConditionTypeCode(std::string pmConditionTypeName);
    uint16 GetActionTypeCode(std::string pmActionTypeName);
    bool CheckCondition(PuppetAICondition* pmAC);
    bool TakeAction(PuppetAIAction* pmAA);
    SpellInfo* GetHighestRankSpellInfoByName(std::string pmSpellName);
    std::unordered_map<std::string, std::map<uint32, uint32>> spellsMap;

    bool CheckTargetFlags(Unit* pmTarget, uint32 pmFlags);

    void JustEnteredCombat();
    void JustLeftCombat();
    void JustDead();
    void JustRevived();
    void UpdateAttacking();
    void MoveToAttack(Unit* pmTarget);
    bool MoveClose(Unit* pmTarget, float pmDistance);
    void DoOpen(uint64 pmTargetGUID);
    bool DoLoot();
    bool DoRandomAttack();
    bool DoRandomMove();
    void DoLootCreatureCorpse(Creature* pmTarget);
    void DoBagging();
    void UseItem(Item* pmItem, uint8 pmActiveTargetType);
};
#endif
