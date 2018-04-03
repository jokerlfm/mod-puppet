#ifndef AIEVENT_H
#define AIEVENT_H

#include "PuppetPCH.h"

enum CONDITION_TYPE :uint16
{
    CONDITION_TYPE_NONE = 0,
    CONDITION_TYPE_ALL,
    CONDITION_TYPE_CHECK_TARGET,
    CONDITION_TYPE_CHECK_BATTLE,
    CONDITION_TYPE_CHECK_HP,
    CONDITION_TYPE_CHECK_MP,
    CONDITION_TYPE_CHECK_AURA,
    CONDITION_TYPE_CHECK_RANGE,
    CONDITION_TYPE_CHECK_PET
};

enum CONDITION_BATTLE_STATE :uint8
{
    CONDITION_BATTLE_STATE_OUT_COMBAT = 0,
    CONDITION_BATTLE_STATE_IN_COMBAT
};

enum CONDITION_VALID_STYLE :uint8
{
    CONDITION_VALID_STYLE_MATCH_ALL = 0,
    CONDITION_VALID_STYLE_DIFFERENCE
};

enum ACTION_TYPE :uint16
{
    ACTION_TYPE_NONE = 0,
    ACTION_TYPE_SAY,
    ACTION_TYPE_YELL,
    ACTION_TYPE_WANDERING,
    ACTION_TYPE_CAST,        
    ACTION_TYPE_REST,
    ACTION_TYPE_BAGGING,
    ACTION_TYPE_PREPARE
};

enum TARGET_FLAG :uint32
{
    TARGET_FLAG_FRIENDLY = 1,
    TARGET_FLAG_ATTACKABLE = 2,
    TARGET_FLAG_ALIVE = 4,
    TARGET_FLAG_DEAD = 8,
    TARGET_FLAG_IN_ACTIVE_RANGE = 16,
    TARGET_FLAG_OUT_ACTIVE_RANGE = 32,
    TARGET_FLAG_PLAYER = 64,
};

enum ACTIVE_TARGET_TYPE :uint8
{
    ACTIVE_TARGET_TYPE_CURRENT_TARGET = 0,
    ACTIVE_TARGET_TYPE_SELF
};

enum AURA_STATE :uint8
{
    AURA_STATE_MISS_ALL = 0,
    AURA_STATE_HAS_ALL,
    AURA_STATE_MISS_MINE,
    AURA_STATE_HAS_MINE
};

enum CHECK_PET_STATE :uint8
{
    CHECK_PET_STATE_UNSUMMONED = 0,
    CHECK_PET_STATE_SUMMONED,
    CHECK_PET_STATE_ALIVE,
    CHECK_PET_STATE_DEAD,
    CHECK_PET_STATE_HP_RANGE
};

struct PuppetAICondition
{
    int conditionIndex;
    uint16 conditionType;
    std::string conditionParameters;

    PuppetAICondition(int pmConditionIndex, uint16 pmConditionType, std::string pmConditionParameters)
    {
        conditionIndex = pmConditionIndex;
        conditionType = pmConditionType;
        conditionParameters = pmConditionParameters;
    }

    const bool operator < (const PuppetAICondition& rightAC)
    {
        return this->conditionIndex < rightAC.conditionIndex;
    }
};

struct PuppetAIAction
{
    int actionIndex;
    uint16 actionType;
    std::string actionParameters;

    PuppetAIAction(int pmActionIndex, uint16 pmActionType, std::string pmActionParameters)
    {
        actionIndex = pmActionIndex;
        actionType = pmActionType;
        actionParameters = pmActionParameters;
    }

    const bool operator < (const PuppetAIAction& rightAA)
    {
        return this->actionIndex < rightAA.actionIndex;
    }
};

struct AIEvent
{
    int eventEntry;
    std::string eventName;
    bool enabled;    
    int eventCheckDelay;
    int eventFinishDelay;
    int aiCheckDelay;
    int eventCheckElapsed;
    int currentCheckDelay;
    uint8 eventCheckProbability;
    int eventStatus;

    std::unordered_map<uint8, PuppetAICondition*> conditionsMap;
    std::unordered_map<uint8, PuppetAIAction*> actionsMap;

    AIEvent(int pmEntry)
    {
        eventEntry = pmEntry;
        eventName = "";
        enabled = true;        
        eventCheckProbability = 0;
        eventCheckDelay = 0;
        eventFinishDelay = 0;
        eventCheckElapsed = 0;
        currentCheckDelay = 0;
        eventStatus = 0;

        conditionsMap.clear();
        actionsMap.clear();
    }

    ~AIEvent()
    {

    }

    const bool operator < (const AIEvent& rightAE)
    {
        return this->eventEntry < rightAE.eventEntry;
    }
};

#endif
