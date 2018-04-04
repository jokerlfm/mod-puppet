#include "PuppetAI.h"

bool PuppetLoginQueryHolder::Initialize()
{
    SetSize(MAX_PLAYER_LOGIN_QUERY);

    bool res = true;
    uint32 lowGuid = GUID_LOPART(m_guid);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_FROM, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_AURAS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_AURAS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SPELL);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SPELLS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_QUESTSTATUS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_DAILYQUESTSTATUS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_DAILY_QUEST_STATUS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_WEEKLYQUESTSTATUS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_WEEKLY_QUEST_STATUS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_MONTHLYQUESTSTATUS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MONTHLY_QUEST_STATUS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SEASONALQUESTSTATUS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SEASONAL_QUEST_STATUS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_REPUTATION);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_REPUTATION, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_INVENTORY);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_INVENTORY, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_ACTIONS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_ACTIONS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_MAILCOUNT);
    stmt->setUInt32(0, lowGuid);
    stmt->setUInt64(1, uint64(time(NULL)));
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAIL_COUNT, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_MAILDATE);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAIL_DATE, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SOCIALLIST);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SOCIAL_LIST, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_HOMEBIND);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_HOME_BIND, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SPELLCOOLDOWNS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SPELL_COOLDOWNS, stmt);

    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED))
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_DECLINEDNAMES);
        stmt->setUInt32(0, lowGuid);
        res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_DECLINED_NAMES, stmt);
    }

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_ACHIEVEMENTS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_ACHIEVEMENTS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_CRITERIAPROGRESS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_CRITERIA_PROGRESS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_EQUIPMENTSETS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_EQUIPMENT_SETS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_ENTRY_POINT);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_ENTRY_POINT, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GLYPHS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_GLYPHS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_TALENTS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_TALENTS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PLAYER_ACCOUNT_DATA);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_ACCOUNT_DATA, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SKILLS);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SKILLS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_RANDOMBG);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_RANDOM_BG, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_BANNED);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_BANNED, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_QUESTSTATUSREW);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS_REW, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL_ASYNCH);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAIL, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_BREW_OF_THE_MONTH);
    stmt->setUInt32(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_BREW_OF_THE_MONTH, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ACCOUNT_INSTANCELOCKTIMES);
    stmt->setUInt32(0, m_accountId);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_INSTANCE_LOCK_TIMES, stmt);

    return res;
}

void PuppetAI::UpdateAI(uint32 pmElapsed)
{
    switch (puppetState)
    {
    case PUPPET_STATE::PUPPET_STATE_LOCK:
    {
        return;
    }
    case PUPPET_STATE::PUPPET_STATE_RANDOMIZE:
    {
        if (sourcePlayer->getLevel() == 1)
        {
            Randomize();
            sLog->outDetail("Puppet %s randomized.", sourcePlayer->GetName().c_str());
        }
        puppetState = PUPPET_STATE::PUPPET_STATE_PREPARATION;
        break;
    }
    case PUPPET_STATE::PUPPET_STATE_PREPARATION:
    {
        UpdateSpellsMap();
        InitialEvents();
        Prepare();
        RandomTeleport();
        //HandleTeleport();
        puppetState = PUPPET_STATE::PUPPET_STATE_READY;
        break;
    }
    }

    currentCheckDelay -= pmElapsed;
    checkElapsed += pmElapsed;

    if (sourcePlayer->IsBeingTeleported())
    {
        HandleTeleport();
        if (resurrecting)
        {
            sourcePlayer->ResurrectPlayer(100);
        }
        sourcePlayer->SetPvP(true);
        return;
    }

    if (currentCheckDelay > 0)
    {
        return;
    }

    // do ai tick
    currentCheckDelay = sPuppetConfig.reactDelay;
    interestingDuration -= checkElapsed;
    if (sourcePlayer->IsAlive())
    {
        if (!isAlive)
        {
            JustRevived();
        }
        isAlive = true;
    }
    else
    {
        if (isAlive)
        {
            JustDead();
        }
        isAlive = false;
        deadTime += checkElapsed;
        if (deadTime > 60000)
        {
            Revive();
            deadTime = 0;
        }
        return;
    }

    if (sourcePlayer->IsInCombat())
    {
        if (!isInCombat)
        {
            JustEnteredCombat();
        }
        isInCombat = true;
        UpdateAttacking();
    }
    else
    {
        if (isInCombat)
        {
            JustLeftCombat();
        }
        isInCombat = false;
    }

    std::set<AIEvent*> allEventSet = eventsMap[currentStrategyName];
    bool actioned = false;
    for (std::set<AIEvent*>::iterator it = allEventSet.begin(); it != allEventSet.end(); it++)
    {
        AIEvent* eachEvent = (*it);
        if (!eachEvent->enabled)
        {
            continue;
        }
        // check conditions
        eachEvent->eventCheckElapsed += checkElapsed;

        if (actioned)
        {
            continue;
        }
        if (eachEvent->eventCheckElapsed > eachEvent->currentCheckDelay)
        {
            eachEvent->eventCheckElapsed = 0;
            if (eachEvent->eventCheckProbability < 100)
            {
                if (urand(1, 100) > eachEvent->eventCheckProbability)
                {
                    continue;
                }
            }
            bool triggered = true;
            for (uint8 conditionCount = 0; conditionCount < eachEvent->conditionsMap.size(); conditionCount++)
            {
                if (!CheckCondition(eachEvent->conditionsMap[conditionCount]))
                {
                    triggered = false;
                    break;
                }
            }
            if (triggered)
            {
                int actionIndex = 0;
                bool eventSuccess = true;
                while (actionIndex < eachEvent->actionsMap.size())
                {
                    if (!TakeAction(eachEvent->actionsMap[actionIndex]))
                    {
                        eventSuccess = false;
                        break;
                    }
                    actionIndex++;
                }
                if (eventSuccess)
                {
                    eachEvent->currentCheckDelay = eachEvent->eventFinishDelay;
                    actioned = true;
                    if (eachEvent->aiCheckDelay > 0)
                    {
                        currentCheckDelay = eachEvent->aiCheckDelay;
                    }
                }
                else
                {
                    eachEvent->currentCheckDelay = eachEvent->eventCheckDelay;
                }
            }
            else
            {
                eachEvent->currentCheckDelay = eachEvent->eventCheckDelay;
            }
        }
    }
    checkElapsed = 0;
}

void PuppetAI::QueryLogin()
{
    PuppetLoginQueryHolder *holder = new PuppetLoginQueryHolder(accountID, characterGUIDLow);
    if (!holder->Initialize())
    {
        delete holder;
        sLog->outError("Puppet %d %d login query holder create failed.", accountID, characterGUIDLow);
        return;
    }
    qrhf = CharacterDatabase.DelayQueryHolder((SQLQueryHolder*)holder);
    sLog->outDetail("Puppet %d %d login query initialized.", accountID, characterGUIDLow);
    puppetState = PUPPET_STATE::PUPPET_STATE_LOGIN;
}

bool PuppetAI::FinishLogin()
{
    if (qrhf.ready())
    {
        SQLQueryHolder* param;
        qrhf.get(param);
        PuppetLoginQueryHolder* resultHolder = (PuppetLoginQueryHolder*)param;
        uint32 targetAccountId = resultHolder->GetAccountId();
        WorldSession *puppetSession = new WorldSession(targetAccountId, NULL, SEC_PLAYER, 2, 0, LOCALE_enUS, 0, false, true);

        if (!puppetSession)
        {
            delete puppetSession;
            sLog->outError("Puppet %d %d login session create failed.", accountID, characterGUIDLow);
            return false;
        }
        puppetSession->HandlePlayerLoginFromDB((LoginQueryHolder*)resultHolder);

        Player* puppetPlayer = puppetSession->GetPlayer();
        if (!puppetPlayer)
        {
            sLog->outError("Puppet %d %d login session is invalid.", accountID, characterGUIDLow);
            delete puppetSession;
            return false;
        }
        sourcePlayer = puppetPlayer;
        sLog->outBasic("Puppet %s logged in", puppetPlayer->GetName().c_str());
        qrhf.cancel();
        puppetState = PUPPET_STATE::PUPPET_STATE_RANDOMIZE;
        return true;
    }
    sLog->outDetail("Puppet %d %d login query is ongoing.", accountID, characterGUIDLow);
    return false;
}

void PuppetAI::QueueUpdateAI(uint32 pmTotalElapsed)
{
    uint32 eachElapsed = pmTotalElapsed - prevTotalElapsed;
    prevTotalElapsed = pmTotalElapsed;
    currentCheckDelay -= eachElapsed;
    checkElapsed += eachElapsed;

    if (sourcePlayer->IsBeingTeleported())
    {
        HandleTeleport();
        if (resurrecting)
        {
            sourcePlayer->ResurrectPlayer(100);
        }
        sourcePlayer->SetPvP(true);
        return;
    }

    if (currentCheckDelay > 0)
    {
        return;
    }

    // do ai tick
    currentCheckDelay = sPuppetConfig.reactDelay;
    interestingDuration -= checkElapsed;
    if (sourcePlayer->IsAlive())
    {
        if (!isAlive)
        {
            JustRevived();
        }
        isAlive = true;
    }
    else
    {
        if (isAlive)
        {
            JustDead();
        }
        isAlive = false;
        deadTime += checkElapsed;
        if (deadTime > 60000)
        {
            Revive();
            deadTime = 0;
        }
        return;
    }

    if (sourcePlayer->IsInCombat())
    {
        if (!isInCombat)
        {
            JustEnteredCombat();
        }
        isInCombat = true;
        UpdateAttacking();
    }
    else
    {
        if (isInCombat)
        {
            JustLeftCombat();
        }
        isInCombat = false;
    }

    std::set<AIEvent*> allEventSet = eventsMap[currentStrategyName];
    bool actioned = false;
    for (std::set<AIEvent*>::iterator it = allEventSet.begin(); it != allEventSet.end(); it++)
    {
        AIEvent* eachEvent = (*it);
        if (!eachEvent->enabled)
        {
            continue;
        }
        // check conditions
        eachEvent->eventCheckElapsed += checkElapsed;

        if (actioned)
        {
            continue;
        }
        if (eachEvent->eventCheckElapsed > eachEvent->currentCheckDelay)
        {
            eachEvent->eventCheckElapsed = 0;
            if (eachEvent->eventCheckProbability < 100)
            {
                if (urand(1, 100) > eachEvent->eventCheckProbability)
                {
                    continue;
                }
            }
            bool triggered = true;
            for (uint8 conditionCount = 0; conditionCount < eachEvent->conditionsMap.size(); conditionCount++)
            {
                if (!CheckCondition(eachEvent->conditionsMap[conditionCount]))
                {
                    triggered = false;
                    break;
                }
            }
            if (triggered)
            {
                int actionIndex = 0;
                bool eventSuccess = true;
                while (actionIndex < eachEvent->actionsMap.size())
                {
                    if (!TakeAction(eachEvent->actionsMap[actionIndex]))
                    {
                        eventSuccess = false;
                        break;
                    }
                    actionIndex++;
                }
                if (eventSuccess)
                {
                    eachEvent->currentCheckDelay = eachEvent->eventFinishDelay;
                    actioned = true;
                    if (eachEvent->aiCheckDelay > 0)
                    {
                        currentCheckDelay = eachEvent->aiCheckDelay;
                    }
                }
                else
                {
                    eachEvent->currentCheckDelay = eachEvent->eventCheckDelay;
                }
            }
            else
            {
                eachEvent->currentCheckDelay = eachEvent->eventCheckDelay;
            }
        }
    }
    checkElapsed = 0;
}

void PuppetAI::HandleChatCommand(Player* pmCommander, std::string pmChatContent)
{
    std::string lowerContent = strlwr(const_cast<char*>(pmChatContent.c_str()));
    if (lowerContent == "who")
    {
        sourcePlayer->Whisper("My specialty is : " + specialty, Language::LANG_UNIVERSAL, pmCommander->GetGUID());
        return;
    }
    else if (lowerContent == "prepare")
    {
        // debug part
        Prepare();
        return;
    }
    else if (lowerContent == "follow")
    {
        if (masterPlayer)
        {
            if (pmCommander->GetGUID() == masterPlayer->GetGUID())
            {
                if (!sourcePlayer->IsAlive())
                {
                    sourcePlayer->Whisper("I am dead, so I can not follow you", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                    return;
                }
                if (sourcePlayer->GetDistance2d(pmCommander) > 100)
                {
                    sourcePlayer->Whisper("You are too far away, so I can not follow you", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                    return;
                }
                Group* myGroup = sourcePlayer->GetGroup();
                if (!myGroup)
                {
                    sourcePlayer->Whisper("I am not in a group", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                    return;
                }
                sourcePlayer->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
                sourcePlayer->GetMotionMaster()->Clear();
                sourcePlayer->GetMotionMaster()->MoveFollow(pmCommander, 2, M_PI);
                sourcePlayer->Whisper("Following", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                return;
            }
        }
        sourcePlayer->Whisper("You are not my master", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
    }
    else if (lowerContent == "attack")
    {
        if (masterPlayer)
        {
            if (pmCommander->GetGUID() == masterPlayer->GetGUID())
            {
                if (!sourcePlayer->IsAlive())
                {
                    sourcePlayer->Whisper("I am dead, so I can not attack", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                    return;
                }
                if (sourcePlayer->GetDistance2d(pmCommander) > 100)
                {
                    sourcePlayer->Whisper("You are too far away, so I can not attack", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                    return;
                }
                Group* myGroup = sourcePlayer->GetGroup();
                if (!myGroup)
                {
                    sourcePlayer->Whisper("I am not in a group", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                    return;
                }
                Unit* masterTarget = masterPlayer->GetSelectedUnit();
                if (!masterTarget)
                {
                    sourcePlayer->Whisper("You do not have a target, so I can not attack", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                    return;
                }
                sourcePlayer->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
                sourcePlayer->GetMotionMaster()->Clear();
                MoveToAttack(masterTarget);
                sourcePlayer->Whisper("Prepare to attack " + masterTarget->GetName(), Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                return;
            }
        }
        sourcePlayer->Whisper("You are not my master", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
    }
    else if (lowerContent == "stay")
    {
        if (masterPlayer)
        {
            if (pmCommander->GetGUID() == masterPlayer->GetGUID())
            {
                if (!sourcePlayer->IsAlive())
                {
                    sourcePlayer->Whisper("I am dead, so I can stay", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                    return;
                }
                if (sourcePlayer->GetDistance(pmCommander) > 100)
                {
                    sourcePlayer->Whisper("You are too far away, so I can not stay", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                    return;
                }
                Group* myGroup = sourcePlayer->GetGroup();
                if (!myGroup)
                {
                    sourcePlayer->Whisper("I am not in a group", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                    return;
                }
                sourcePlayer->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
                sourcePlayer->GetMotionMaster()->Clear();
                sourcePlayer->Whisper("I will stay", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                return;
            }
        }
        sourcePlayer->Whisper("You are not my master", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
    }
    else
    {
        vector<string> pmArray;
        sPuppetMgr.split(lowerContent, string(" "), &pmArray);
        if (pmArray.at(0) == "event")
        {
            if (masterPlayer)
            {
                if (pmCommander->GetGUID() == masterPlayer->GetGUID())
                {
                    bool enabled = true;
                    int switchIndex = pmArray.size() - 1;
                    std::string switchPart = pmArray.at(switchIndex);
                    if (switchPart == "on")
                    {
                        enabled = true;
                    }
                    else if (switchPart == "off")
                    {
                        enabled = false;
                    }
                    else
                    {
                        sourcePlayer->Whisper("Command format error : " + pmChatContent, Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                        return;
                    }
                    std::string eventName = "";
                    for (int partIndex = 1; partIndex < switchIndex; partIndex++)
                    {
                        eventName += pmArray.at(partIndex);
                    }

                    for (std::unordered_map <std::string, std::set<AIEvent*>>::iterator it1 = eventsMap.begin(); it1 != eventsMap.end(); it1++)
                    {
                        for (std::set<AIEvent*>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
                        {
                            if ((*it2)->eventName == eventName)
                            {
                                (*it2)->enabled = enabled;
                            }
                        }
                    }
                    sourcePlayer->Whisper("Event : " + eventName + " switched to " + switchPart, Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                    return;
                }
            }
            sourcePlayer->Whisper("You are not my master", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
        }
        else if (pmArray.at(0) == "cast")
        {
            if (masterPlayer)
            {
                if (pmCommander->GetGUID() == masterPlayer->GetGUID())
                {
                    int targetTypeIndex = pmArray.size() - 1;
                    int targetType = atoi(pmArray.at(targetTypeIndex).c_str());
                    int spellRankIndex = targetTypeIndex - 1;
                    int spellRank = atoi(pmArray.at(spellRankIndex).c_str());
                    std::string spellName = "";
                    for (int partIndex = 1; partIndex < spellRankIndex; partIndex++)
                    {
                        spellName += pmArray.at(partIndex);
                    }

                    if (spellsMap.find(spellName) == spellsMap.end())
                    {
                        sourcePlayer->Whisper("Spell not found : " + spellName, Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                        return;
                    }
                    if (spellRank == 0)
                    {
                        // max rank
                        std::map<uint32, uint32>::iterator checkIT = spellsMap[spellName].end();
                        checkIT--;
                        spellRank = checkIT->first;
                    }
                    switch (targetType)
                    {
                    case ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_CURRENT_TARGET:
                    {
                        Unit* target = sourcePlayer->GetSelectedUnit();
                        if (!target)
                        {
                            sourcePlayer->Whisper("I do not have a target", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
                            return;
                        }
                        sourcePlayer->Say(spellName + " " + std::to_string(spellRank) + " on " + target->GetName(), Language::LANG_UNIVERSAL);
                        uint32 spellID = spellsMap[spellName][spellRank];
                        sourcePlayer->SetFacingToObject(target);
                        sourcePlayer->CastSpell(target, spellID);
                        return;
                        break;
                    }
                    case ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_SELF:
                    {
                        sourcePlayer->Say(spellName + " " + std::to_string(spellRank) + " on me", Language::LANG_UNIVERSAL);
                        uint32 spellID = spellsMap[spellName][spellRank];
                        sourcePlayer->CastSpell(sourcePlayer, spellID);
                        return;
                        break;
                    }
                    }
                    return;
                }
            }
            sourcePlayer->Whisper("You are not my master", Language::LANG_UNIVERSAL, pmCommander->GetGUID());
        }
    }
}

void PuppetAI::HandleGroupInvite(Player* pmInviter)
{
    if (interestingDuration <= 0)
    {
        int inviterLevel = pmInviter->getLevel();
        int acceptRate = 50;
        acceptRate = acceptRate + ((inviterLevel - sourcePlayer->getLevel()) * 10);
        if (acceptRate < 0)
        {
            acceptRate = 0;
        }
        else if (acceptRate > 100)
        {
            acceptRate = 90;
        }
        interested = (urand(0, 100) < acceptRate);
        interestingDuration = urand(600000, 1200000);
    }
    if (interested)
    {
        Group* group = sourcePlayer->GetGroupInvite();

        if (!group)
            return;

        // Remove player from invitees in any case
        group->RemoveInvite(sourcePlayer);

        // Group is full
        if (group->IsFull())
        {
            sourcePlayer->Whisper("Group is full, so I can not join", Language::LANG_UNIVERSAL, pmInviter->GetGUID());
            return;
        }

        Player* leader = ObjectAccessor::FindPlayer(group->GetLeaderGUID());

        // Forming a new group, create it
        if (!group->IsCreated())
        {
            // This can happen if the leader is zoning. To be removed once delayed actions for zoning are implemented
            if (!leader)
            {
                group->RemoveAllInvites();
                return;
            }

            // If we're about to create a group there really should be a leader present
            ASSERT(leader);
            group->RemoveInvite(leader);
            group->Create(leader);
            sGroupMgr->AddGroup(group);
        }

        // Everything is fine, do it, PLAYER'S GROUP IS SET IN ADDMEMBER!!!
        if (!group->AddMember(sourcePlayer))
            return;

        group->BroadcastGroupUpdate();
        SetMaster(pmInviter);
        SetStrategy("group");
        sourcePlayer->Whisper("I joined your group, so you are my master now. My strategy set to 'group'", Language::LANG_UNIVERSAL, pmInviter->GetGUID());
    }
    else
    {
        Group* group = sourcePlayer->GetGroupInvite();
        if (!group)
            return;

        // Remember leader if online (group pointer will be invalid if group gets disbanded)
        Player* leader = ObjectAccessor::FindPlayer(group->GetLeaderGUID());

        // uninvite, group can be deleted
        sourcePlayer->UninviteFromGroup();

        if (!leader || !leader->GetSession())
            return;

        // report
        WorldPacket data(SMSG_GROUP_DECLINE, sourcePlayer->GetName().length());
        data << sourcePlayer->GetName();
        leader->SendDirectMessage(&data);
        sourcePlayer->Whisper("I am not interested", Language::LANG_UNIVERSAL, pmInviter->GetGUID());
    }
}

void PuppetAI::ResetStrategies()
{
    for (std::unordered_map <std::string, std::set<AIEvent*>>::iterator it1 = eventsMap.begin(); it1 != eventsMap.end(); it1++)
    {
        for (std::set<AIEvent*>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
        {
            (*it2)->enabled = true;
        }
    }

    currentStrategyName = "solo";
    sourcePlayer->SetSelection(0);
    SetMaster(NULL);
}

void PuppetAI::SetStrategy(std::string pmNewStrategy)
{
    currentStrategyName = pmNewStrategy;
    sourcePlayer->SetSelection(0);
}

void PuppetAI::UpdateSpellsMap()
{
    spellsMap.clear();
    for (std::unordered_map<uint32, PlayerSpell*>::iterator it = sourcePlayer->GetSpellMap().begin(); it != sourcePlayer->GetSpellMap().end(); it++)
    {
        const SpellInfo* pSpellInfo = sSpellMgr->GetSpellInfo(it->first);
        if (pSpellInfo)
        {
            spellsMap[strlwr(pSpellInfo->SpellName[0])][pSpellInfo->GetRank()] = pSpellInfo->Id;
        }
    }
}

void PuppetAI::Prepare()
{
    if (sourcePlayer->GetPet())
    {
        Pet* currentPet = sourcePlayer->GetPet();
        if (currentPet->getPetType() == PetType::HUNTER_PET)
        {
            currentPet->SetPower(POWER_HAPPINESS, HAPPINESS_LEVEL_SIZE * 2);
        }
        currentPet->SetReactState(ReactStates::REACT_DEFENSIVE);
        for (PetSpellMap::const_iterator itr = currentPet->m_spells.begin(); itr != currentPet->m_spells.end(); ++itr)
        {
            if (itr->second.state == PETSPELL_REMOVED)
                continue;

            uint32 spellId = itr->first;
            const SpellInfo* pSpellInfo = sSpellMgr->GetSpellInfo(spellId);
            if (pSpellInfo->IsPassive())
                continue;

            currentPet->ToggleAutocast(pSpellInfo, true);
        }
    }

    uint8 checkClass = sourcePlayer->getClass();
    uint32 checkLevel = sourcePlayer->getLevel();

    // each class
    if (checkClass == CLASS_HUNTER || checkClass == CLASS_WARRIOR)
    {
        Item* const pItem = sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
        if (!pItem)
            return;

        uint32 subClass = 0;
        switch (pItem->GetTemplate()->SubClass)
        {
        case ITEM_SUBCLASS_WEAPON_GUN:
            subClass = ITEM_SUBCLASS_BULLET;
            break;
        case ITEM_SUBCLASS_WEAPON_BOW:
        case ITEM_SUBCLASS_WEAPON_CROSSBOW:
            subClass = ITEM_SUBCLASS_ARROW;
            break;
        }

        if (!subClass)
            return;

        while (checkLevel > 0)
        {
            if (subClass == ITEM_SUBCLASS_ARROW)
            {
                if (sPuppetMgr.arrowMap.find(checkLevel) == sPuppetMgr.arrowMap.end())
                {
                    checkLevel--;
                    continue;
                }
                uint32 currentCount = sourcePlayer->GetItemCount(sPuppetMgr.arrowMap[checkLevel]);
                if (currentCount < 1000)
                {
                    sourcePlayer->StoreNewItemInBestSlots(sPuppetMgr.arrowMap[checkLevel], 1000 - currentCount);
                }
                sourcePlayer->SetAmmo(sPuppetMgr.arrowMap[checkLevel]);

                basicItemsMap[sPuppetMgr.arrowMap[checkLevel]] = 1000;
                break;
            }
            else
            {
                if (sPuppetMgr.bulletMap.find(checkLevel) == sPuppetMgr.bulletMap.end())
                {
                    checkLevel--;
                    continue;
                }
                uint32 currentCount = sourcePlayer->GetItemCount(sPuppetMgr.bulletMap[checkLevel]);
                if (currentCount < 1000)
                {
                    sourcePlayer->StoreNewItemInBestSlots(sPuppetMgr.bulletMap[checkLevel], 1000 - currentCount);
                }
                sourcePlayer->SetAmmo(sPuppetMgr.bulletMap[checkLevel]);
                basicItemsMap[sPuppetMgr.bulletMap[checkLevel]] = 1000;
                break;
            }
        }
    }
    else if (checkClass == CLASS_WARLOCK)
    {
        uint32 soulShardEntry = 6265;
        uint32 currentCount = sourcePlayer->GetItemCount(soulShardEntry);
        if (currentCount < 20)
        {
            sourcePlayer->StoreNewItemInBestSlots(soulShardEntry, 20 - currentCount);
            basicItemsMap[soulShardEntry] = 20;
        }
    }
    // potions
    checkLevel = sourcePlayer->getLevel();
    while (checkLevel > 0)
    {
        if (sPuppetMgr.healthPotionMap.find(checkLevel) == sPuppetMgr.healthPotionMap.end())
        {
            checkLevel--;
            continue;
        }
        uint32 currentCount = sourcePlayer->GetItemCount(sPuppetMgr.healthPotionMap[checkLevel]);
        if (currentCount < 20)
        {
            sourcePlayer->StoreNewItemInBestSlots(sPuppetMgr.healthPotionMap[checkLevel], 20 - currentCount);
            basicItemsMap[sPuppetMgr.healthPotionMap[checkLevel]] = 20;
        }
        break;
    }

    if (checkClass != Classes::CLASS_WARRIOR&&checkClass != Classes::CLASS_ROGUE&&checkClass != Classes::CLASS_DEATH_KNIGHT)
    {
        checkLevel = sourcePlayer->getLevel();
        while (checkLevel > 0)
        {
            if (sPuppetMgr.manaPotionMap.find(checkLevel) == sPuppetMgr.manaPotionMap.end())
            {
                checkLevel--;
                continue;
            }
            uint32 currentCount = sourcePlayer->GetItemCount(sPuppetMgr.manaPotionMap[checkLevel]);
            if (currentCount < 20)
            {
                sourcePlayer->StoreNewItemInBestSlots(sPuppetMgr.manaPotionMap[checkLevel], 20 - currentCount);
                basicItemsMap[sPuppetMgr.manaPotionMap[checkLevel]] = 20;
            }
            break;
        }
    }
    // food and drink
    checkLevel = sourcePlayer->getLevel();
    while (checkLevel > 0)
    {
        if (sPuppetMgr.foodMap.find(checkLevel) == sPuppetMgr.foodMap.end())
        {
            checkLevel--;
            continue;
        }
        uint32 currentCount = sourcePlayer->GetItemCount(sPuppetMgr.foodMap[checkLevel]);
        if (currentCount < 20)
        {
            sourcePlayer->StoreNewItemInBestSlots(sPuppetMgr.foodMap[checkLevel], 20 - currentCount);
            basicItemsMap[sPuppetMgr.foodMap[checkLevel]] = 20;
        }
        break;
    }

    if (checkClass != Classes::CLASS_WARRIOR&&checkClass != Classes::CLASS_ROGUE&&checkClass != Classes::CLASS_DEATH_KNIGHT)
    {
        checkLevel = sourcePlayer->getLevel();
        while (checkLevel > 0)
        {
            if (sPuppetMgr.drinkMap.find(checkLevel) == sPuppetMgr.drinkMap.end())
            {
                checkLevel--;
                continue;
            }
            uint32 currentCount = sourcePlayer->GetItemCount(sPuppetMgr.drinkMap[checkLevel]);
            if (currentCount < 20)
            {
                sourcePlayer->StoreNewItemInBestSlots(sPuppetMgr.drinkMap[checkLevel], 20 - currentCount);
                basicItemsMap[sPuppetMgr.drinkMap[checkLevel]] = 20;
            }
            break;
        }
    }

    // pvp
    sourcePlayer->SetPvP(true);

    // preparation spells
    if (checkClass == Classes::CLASS_WARRIOR)
    {
        if (specialty == "warrior_arms")
        {
            std::string spellName = "battle stance";
            int spellRank = 0;
            int targetType = ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_SELF;
            if (spellsMap.find(spellName) == spellsMap.end())
            {
                return;
            }
            if (spellRank == 0)
            {
                // max rank
                std::map<uint32, uint32>::iterator checkIT = spellsMap[spellName].end();
                checkIT--;
                spellRank = checkIT->first;
            }
            sourcePlayer->Say(spellName, Language::LANG_UNIVERSAL);
            uint32 spellID = spellsMap[spellName][spellRank];
            sourcePlayer->CastSpell(sourcePlayer, spellID);
        }
        else if (specialty == "warrior_protection")
        {
            std::string spellName = "defensive stance";
            int spellRank = 0;
            int targetType = ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_SELF;
            if (spellsMap.find(spellName) == spellsMap.end())
            {
                return;
            }
            if (spellRank == 0)
            {
                // max rank
                std::map<uint32, uint32>::iterator checkIT = spellsMap[spellName].end();
                checkIT--;
                spellRank = checkIT->first;
            }
            sourcePlayer->Say(spellName, Language::LANG_UNIVERSAL);
            uint32 spellID = spellsMap[spellName][spellRank];
            sourcePlayer->CastSpell(sourcePlayer, spellID);
        }
    }
}

void PuppetAI::InitialEvents()
{
    eventsMap.clear();
    QueryResult puppetInfoQR = CharacterDatabase.PQuery("SELECT specialty FROM puppet_info where character_guid = %d", sourcePlayer->GetGUID());
    if (puppetInfoQR)
    {
        Field* fields = puppetInfoQR->Fetch();
        if (fields)
        {
            specialty = fields[0].GetString();
            LoadDetailEvents(specialty);
            return;
        }
    }
    sLog->outError("Can not find puppet info for Puppet '%s' , events initalize failed", sourcePlayer->GetName().c_str());
}

void PuppetAI::LoadDetailEvents(std::string pmSpecialty)
{
    QueryResult results = WorldDatabase.PQuery("SELECT condition_0_type, condition_1_type, condition_2_type, condition_3_type, condition_4_type, "
        "condition_0_parameters, condition_1_parameters, condition_2_parameters, condition_3_parameters, condition_4_parameters, "
        "action_0_type, action_1_type, action_2_type, action_3_type, action_4_type, "
        "action_0_parameters, action_1_parameters, action_2_parameters, action_3_parameters, action_4_parameters, "
        "strategy, event_check_probability, event_check_delay, event_finish_delay, ai_check_delay, enabled, event_name, entry "
        "FROM puppet_ai where specialty = '%s'", pmSpecialty.c_str());
    if (results)
    {
        do
        {
            Field* fields = results->Fetch();
            std::string condition_0_type = fields[0].GetString();
            std::string condition_1_type = fields[1].GetString();
            std::string condition_2_type = fields[2].GetString();
            std::string condition_3_type = fields[3].GetString();
            std::string condition_4_type = fields[4].GetString();

            std::string condition_0_parameters = fields[5].GetString();
            std::string condition_1_parameters = fields[6].GetString();
            std::string condition_2_parameters = fields[7].GetString();
            std::string condition_3_parameters = fields[8].GetString();
            std::string condition_4_parameters = fields[9].GetString();

            std::string action_0_type = fields[10].GetString();
            std::string action_1_type = fields[11].GetString();
            std::string action_2_type = fields[12].GetString();
            std::string action_3_type = fields[13].GetString();
            std::string action_4_type = fields[14].GetString();

            std::string action_0_parameters = fields[15].GetString();
            std::string action_1_parameters = fields[16].GetString();
            std::string action_2_parameters = fields[17].GetString();
            std::string action_3_parameters = fields[18].GetString();
            std::string action_4_parameters = fields[19].GetString();

            std::string eventStrategy = fields[20].GetString();
            int eventCheckProbability = fields[21].GetInt32();
            int eventCheckDelay = fields[22].GetInt32();
            int eventFinishDelay = fields[23].GetInt32();
            int aiCheckDelay = fields[24].GetInt32();
            bool enabled = fields[25].GetBool();
            std::string eventName = fields[26].GetString();
            int entry = fields[27].GetInt32();

            AIEvent* ae = new AIEvent(entry);
            int checkIndex = 0;
            if (condition_0_type != "")
            {
                PuppetAICondition* ac = new PuppetAICondition(checkIndex, GetConditionTypeCode(condition_0_type), condition_0_parameters);
                ae->conditionsMap[checkIndex] = ac;
                checkIndex++;
            }
            if (condition_1_type != "")
            {
                PuppetAICondition* ac = new PuppetAICondition(checkIndex, GetConditionTypeCode(condition_1_type), condition_1_parameters);
                ae->conditionsMap[checkIndex] = ac;
                checkIndex++;
            }
            if (condition_2_type != "")
            {
                PuppetAICondition* ac = new PuppetAICondition(checkIndex, GetConditionTypeCode(condition_2_type), condition_2_parameters);
                ae->conditionsMap[checkIndex] = ac;
                checkIndex++;
            }
            if (condition_3_type != "")
            {
                PuppetAICondition* ac = new PuppetAICondition(checkIndex, GetConditionTypeCode(condition_3_type), condition_3_parameters);
                ae->conditionsMap[checkIndex] = ac;
                checkIndex++;
            }
            if (condition_4_type != "")
            {
                PuppetAICondition* ac = new PuppetAICondition(checkIndex, GetConditionTypeCode(condition_4_type), condition_4_parameters);
                ae->conditionsMap[checkIndex] = ac;
                checkIndex++;
            }

            checkIndex = 0;
            if (action_0_type != "")
            {
                PuppetAIAction* ac = new PuppetAIAction(checkIndex, GetActionTypeCode(action_0_type), action_0_parameters);
                ae->actionsMap[checkIndex] = ac;
                checkIndex++;
            }
            if (action_1_type != "")
            {
                PuppetAIAction* ac = new PuppetAIAction(checkIndex, GetActionTypeCode(action_1_type), action_1_parameters);
                ae->actionsMap[checkIndex] = ac;
                checkIndex++;
            }
            if (action_2_type != "")
            {
                PuppetAIAction* ac = new PuppetAIAction(checkIndex, GetActionTypeCode(action_2_type), action_2_parameters);
                ae->actionsMap[checkIndex] = ac;
                checkIndex++;
            }
            if (action_3_type != "")
            {
                PuppetAIAction* ac = new PuppetAIAction(checkIndex, GetActionTypeCode(action_3_type), action_3_parameters);
                ae->actionsMap[checkIndex] = ac;
                checkIndex++;
            }
            if (action_4_type != "")
            {
                PuppetAIAction* ac = new PuppetAIAction(checkIndex, GetActionTypeCode(action_4_type), action_4_parameters);
                ae->actionsMap[checkIndex] = ac;
                checkIndex++;
            }
            ae->eventCheckProbability = eventCheckProbability;
            ae->eventCheckDelay = eventCheckDelay;
            ae->eventFinishDelay = eventFinishDelay;
            ae->aiCheckDelay = aiCheckDelay;
            ae->enabled = enabled;
            ae->eventName = eventName;
            eventsMap[eventStrategy].insert(ae);

        } while (results->NextRow());
    }
}

uint16 PuppetAI::GetConditionTypeCode(std::string pmConditionTypeName)
{
    std::string lowerName = strlwr(const_cast<char*>(pmConditionTypeName.c_str()));
    if (lowerName == "all")
    {
        return CONDITION_TYPE::CONDITION_TYPE_ALL;
    }
    else if (lowerName == "check target")
    {
        return CONDITION_TYPE::CONDITION_TYPE_CHECK_TARGET;
    }
    else if (lowerName == "check battle")
    {
        return CONDITION_TYPE::CONDITION_TYPE_CHECK_BATTLE;
    }
    else if (lowerName == "check hp")
    {
        return CONDITION_TYPE::CONDITION_TYPE_CHECK_HP;
    }
    else if (lowerName == "check mp")
    {
        return CONDITION_TYPE::CONDITION_TYPE_CHECK_MP;
    }
    else if (lowerName == "check aura")
    {
        return CONDITION_TYPE::CONDITION_TYPE_CHECK_AURA;
    }
    else if (lowerName == "check range")
    {
        return CONDITION_TYPE::CONDITION_TYPE_CHECK_RANGE;
    }
    else if (lowerName == "check pet")
    {
        return CONDITION_TYPE::CONDITION_TYPE_CHECK_PET;
    }

    return CONDITION_TYPE::CONDITION_TYPE_NONE;
}

uint16 PuppetAI::GetActionTypeCode(std::string pmActionTypeName)
{
    std::string lowerName = strlwr(const_cast<char*>(pmActionTypeName.c_str()));

    if (lowerName == "say")
    {
        return ACTION_TYPE::ACTION_TYPE_SAY;
    }
    else if (lowerName == "yell")
    {
        return ACTION_TYPE::ACTION_TYPE_YELL;
    }
    else if (lowerName == "wandering")
    {
        return ACTION_TYPE::ACTION_TYPE_WANDERING;
    }
    else if (lowerName == "cast")
    {
        return ACTION_TYPE::ACTION_TYPE_CAST;
    }
    else if (lowerName == "rest")
    {
        return ACTION_TYPE::ACTION_TYPE_REST;
    }
    else if (lowerName == "bagging")
    {
        return ACTION_TYPE::ACTION_TYPE_BAGGING;
    }
    else if (lowerName == "prepare")
    {
        return ACTION_TYPE::ACTION_TYPE_PREPARE;
    }

    return ACTION_TYPE::ACTION_TYPE_NONE;
}

bool PuppetAI::CheckCondition(PuppetAICondition* pmAC)
{
    switch (pmAC->conditionType)
    {
    case CONDITION_TYPE::CONDITION_TYPE_ALL:
    {
        return true;
    }
    case CONDITION_TYPE::CONDITION_TYPE_CHECK_TARGET:
    {
        vector<string> pmArray;
        sPuppetMgr.split(pmAC->conditionParameters, string(","), &pmArray);
        int flagCode = atoi(pmArray.at(0).c_str());
        int validStyle = atoi(pmArray.at(1).c_str());
        Unit* target = sourcePlayer->GetSelectedUnit();
        if (!target)
        {
            if (validStyle == CONDITION_VALID_STYLE_MATCH_ALL)
            {
                return false;
            }
            else if (validStyle == CONDITION_VALID_STYLE_DIFFERENCE)
            {
                return true;
            }
        }

        if (validStyle == CONDITION_VALID_STYLE_MATCH_ALL)
        {
            if (CheckTargetFlags(target, flagCode))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (validStyle == CONDITION_VALID_STYLE_DIFFERENCE)
        {
            if (CheckTargetFlags(target, flagCode))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        break;
    }
    case CONDITION_TYPE::CONDITION_TYPE_CHECK_BATTLE:
    {
        int battleState = atoi(pmAC->conditionParameters.c_str());
        if (battleState == 0)
        {
            if (sourcePlayer->IsInCombat())
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (battleState == 1)
        {
            if (sourcePlayer->IsInCombat())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    case CONDITION_TYPE::CONDITION_TYPE_CHECK_HP:
    {
        vector<string> pmArray;
        sPuppetMgr.split(pmAC->conditionParameters, string(","), &pmArray);
        float currentPCT = sourcePlayer->GetHealthPct();
        if (currentPCT >= atof(pmArray.at(0).c_str()) && currentPCT <= atof(pmArray.at(1).c_str()))
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
    case CONDITION_TYPE::CONDITION_TYPE_CHECK_MP:
    {
        vector<string> pmArray;
        sPuppetMgr.split(pmAC->conditionParameters, string(","), &pmArray);
        float currentPCT = sourcePlayer->GetPower(Powers::POWER_MANA) / sourcePlayer->GetMaxPower(Powers::POWER_MANA);
        if (currentPCT >= atof(pmArray.at(0).c_str()) && currentPCT <= atof(pmArray.at(1).c_str()))
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
    case CONDITION_TYPE::CONDITION_TYPE_CHECK_AURA:
    {
        vector<string> pmArray;
        sPuppetMgr.split(pmAC->conditionParameters, string(","), &pmArray);
        std::string spellName = pmArray.at(0);
        int spellRank = atoi(pmArray.at(1).c_str());
        int targetType = atoi(pmArray.at(2).c_str());
        int auraState = atoi(pmArray.at(3).c_str());
        int stackAmount = atoi(pmArray.at(4).c_str());
        if (spellsMap.find(spellName) == spellsMap.end())
        {
            return false;
        }
        if (spellRank == 0)
        {
            // max rank
            std::map<uint32, uint32>::iterator checkIT = spellsMap[spellName].end();
            checkIT--;
            spellRank = checkIT->first;
        }

        switch (targetType)
        {
        case ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_CURRENT_TARGET:
        {
            switch (auraState)
            {
            case AURA_STATE::AURA_STATE_MISS_ALL:
            {
                Unit* target = sourcePlayer->GetSelectedUnit();
                if (!target)
                {
                    return false;
                }
                if (target->GetAuraCount(spellsMap[spellName][spellRank]) < stackAmount)
                {
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            }
            case AURA_STATE::AURA_STATE_HAS_ALL:
            {
                Unit* target = sourcePlayer->GetSelectedUnit();
                if (!target)
                {
                    return false;
                }
                if (target->GetAuraCount(spellsMap[spellName][spellRank]) >= stackAmount)
                {
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            }
            case AURA_STATE::AURA_STATE_MISS_MINE:
            {
                Unit* target = sourcePlayer->GetSelectedUnit();
                if (!target)
                {
                    return false;
                }
                if (target->HasAura(spellsMap[spellName][spellRank], sourcePlayer->GetGUID()))
                {
                    return false;
                }
                else
                {
                    return true;
                }
                break;
            }
            case AURA_STATE::AURA_STATE_HAS_MINE:
            {
                Unit* target = sourcePlayer->GetSelectedUnit();
                if (!target)
                {
                    return false;
                }
                if (target->HasAura(spellsMap[spellName][spellRank]), sourcePlayer->GetGUID())
                {

                    return true;
                }
                else
                {
                    return false;
                }
                break;
            }
            }
            break;
        }
        case ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_SELF:
        {
            switch (auraState)
            {
            case AURA_STATE::AURA_STATE_MISS_ALL:
            {
                if (sourcePlayer->HasAura(spellsMap[spellName][spellRank]))
                {
                    return false;
                }
                else
                {
                    return true;
                }
                break;
            }
            case AURA_STATE::AURA_STATE_HAS_ALL:
            {
                if (sourcePlayer->HasAura(spellsMap[spellName][spellRank]))
                {
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            }
            case AURA_STATE::AURA_STATE_MISS_MINE:
            {
                break;
            }
            case AURA_STATE::AURA_STATE_HAS_MINE:
            {
                break;
            }
            }
            break;
        }
        }
    }
    case CONDITION_TYPE::CONDITION_TYPE_CHECK_RANGE:
    {
        Unit* target = sourcePlayer->GetSelectedUnit();
        if (!target)
        {
            return false;
        }
        vector<string> pmArray;
        sPuppetMgr.split(pmAC->conditionParameters, string(","), &pmArray);
        float minRange = atof(pmArray.at(0).c_str());
        float maxRange = atof(pmArray.at(1).c_str());
        float actualDistance = sourcePlayer->GetDistance2d(target);
        if (actualDistance >= minRange && actualDistance <= maxRange)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    }

    case CONDITION_TYPE::CONDITION_TYPE_CHECK_PET:
    {
        vector<string> pmArray;
        sPuppetMgr.split(pmAC->conditionParameters, string(","), &pmArray);
        uint8 checkPetState = atoi(pmArray.at(0).c_str());
        switch (checkPetState)
        {
        case CHECK_PET_STATE::CHECK_PET_STATE_UNSUMMONED:
        {
            Pet* checkPet = sourcePlayer->GetPet();
            if (!checkPet)
            {
                return false;
            }
            if (!checkPet->IsInWorld())
            {
                return true;
            }
            break;
        }
        case CHECK_PET_STATE::CHECK_PET_STATE_SUMMONED:
        {
            Pet* checkPet = sourcePlayer->GetPet();
            if (!checkPet)
            {
                return false;
            }
            if (checkPet->IsInWorld())
            {
                return true;
            }
            break;
        }
        case CHECK_PET_STATE::CHECK_PET_STATE_ALIVE:
        {
            Pet* checkPet = sourcePlayer->GetPet();
            if (!checkPet)
            {
                return false;
            }
            if (checkPet->IsAlive())
            {
                return true;
            }
            break;
        }
        case CHECK_PET_STATE::CHECK_PET_STATE_DEAD:
        {
            Pet* checkPet = sourcePlayer->GetPet();
            if (!checkPet)
            {
                return false;
            }
            if (!checkPet->IsAlive())
            {
                return true;
            }
            break;
        }
        case CHECK_PET_STATE::CHECK_PET_STATE_HP_RANGE:
        {
            Pet* checkPet = sourcePlayer->GetPet();
            if (!checkPet)
            {
                return false;
            }
            if (!checkPet->IsInWorld())
            {
                return false;
            }
            float currentPCT = checkPet->GetHealthPct();
            if (currentPCT >= atof(pmArray.at(1).c_str()) && currentPCT <= atof(pmArray.at(2).c_str()))
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        }
        }
        break;
    }
    }

    return false;
}

bool PuppetAI::TakeAction(PuppetAIAction* pmAA)
{
    switch (pmAA->actionType)
    {
    case ACTION_TYPE::ACTION_TYPE_SAY:
    {
        sourcePlayer->Say(pmAA->actionParameters, Language::LANG_UNIVERSAL);
        return true;
    }
    case ACTION_TYPE::ACTION_TYPE_YELL:
    {
        sourcePlayer->Yell(pmAA->actionParameters, Language::LANG_UNIVERSAL);
        return true;
    }
    case ACTION_TYPE::ACTION_TYPE_WANDERING:
    {
        sourcePlayer->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
        if (DoLoot())
        {
            return true;
        }
        if (DoRandomAttack())
        {
            return true;
        }
        if (DoRandomMove())
        {
            return true;
        }
        return false;
    }
    case ACTION_TYPE::ACTION_TYPE_CAST:
    {
        vector<string> pmArray;
        sPuppetMgr.split(pmAA->actionParameters, string(","), &pmArray);
        std::string spellName = pmArray.at(0);
        int spellRank = atoi(pmArray.at(1).c_str());
        int targetType = atoi(pmArray.at(2).c_str());
        if (spellsMap.find(spellName) == spellsMap.end())
        {
            return false;
        }
        if (spellRank == 0)
        {
            // max rank
            std::map<uint32, uint32>::iterator checkIT = spellsMap[spellName].end();
            checkIT--;
            spellRank = checkIT->first;
        }
        switch (targetType)
        {
        case ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_CURRENT_TARGET:
        {
            Unit* target = sourcePlayer->GetSelectedUnit();
            if (!target)
            {
                return false;
            }
            sLog->outDetail("%s %d on %s", spellName.c_str(), spellRank, target->GetName().c_str());
            sourcePlayer->Say(spellName + " " + std::to_string(spellRank) + " on " + target->GetName(), Language::LANG_UNIVERSAL);
            uint32 spellID = spellsMap[spellName][spellRank];
            sourcePlayer->SetFacingToObject(target);
            sourcePlayer->CastSpell(target, spellID);
            return true;
            break;
        }
        case ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_SELF:
        {
            sLog->outDetail("%s %d on me", spellName.c_str(), spellRank);
            sourcePlayer->Say(spellName + " " + std::to_string(spellRank) + " on me", Language::LANG_UNIVERSAL);
            uint32 spellID = spellsMap[spellName][spellRank];
            sourcePlayer->CastSpell(sourcePlayer, spellID);
            return true;
            break;
        }
        }
        break;
    }
    case ACTION_TYPE::ACTION_TYPE_REST:
    {
        uint32 foodEntry = 0;
        uint32 checkLevel = sourcePlayer->getLevel();
        while (checkLevel > 0)
        {
            if (sPuppetMgr.foodMap.find(checkLevel) == sPuppetMgr.foodMap.end())
            {
                checkLevel--;
                continue;
            }
            foodEntry = sPuppetMgr.foodMap[checkLevel];
            break;
        }
        if (foodEntry > 0)
        {
            Item* foodItem = sourcePlayer->GetItemByEntry(foodEntry);
            if (foodItem)
            {
                sourcePlayer->Say("I have to take a break", Language::LANG_UNIVERSAL);
                UseItem(foodItem, ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_SELF);
            }
            else
            {
                sourcePlayer->Say("Food is run out", Language::LANG_UNIVERSAL);
            }
        }
        else
        {
            sourcePlayer->Say("Food is run out", Language::LANG_UNIVERSAL);
        }
        if (sourcePlayer->getPowerType() == Powers::POWER_MANA)
        {
            uint32 drinkEntry = 0;
            uint32 checkLevel = sourcePlayer->getLevel();
            while (checkLevel > 0)
            {
                if (sPuppetMgr.drinkMap.find(checkLevel) == sPuppetMgr.drinkMap.end())
                {
                    checkLevel--;
                    continue;
                }
                drinkEntry = sPuppetMgr.drinkMap[checkLevel];
                break;
            }
            if (drinkEntry > 0)
            {
                Item* drinkItem = sourcePlayer->GetItemByEntry(drinkEntry);
                if (drinkItem)
                {
                    sourcePlayer->Say("I have to take a break", Language::LANG_UNIVERSAL);
                    UseItem(drinkItem, ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_SELF);
                }
                else
                {
                    sourcePlayer->Say("Drink is run out", Language::LANG_UNIVERSAL);
                }
            }
            else
            {
                sourcePlayer->Say("Drink is run out", Language::LANG_UNIVERSAL);
            }
        }
        return true;
        break;
    }
    case ACTION_TYPE::ACTION_TYPE_BAGGING:
    {
        sourcePlayer->Say("I need to arrange my bags", Language::LANG_UNIVERSAL);
        sourcePlayer->GetMotionMaster()->Clear();
        DoBagging();
        return true;
        break;
    }
    case ACTION_TYPE::ACTION_TYPE_PREPARE:
    {
        sourcePlayer->Say("I will get prepared again", Language::LANG_UNIVERSAL);
        sourcePlayer->GetMotionMaster()->Clear();
        Prepare();
        return true;
        break;
    }
    }

    return false;
}

bool PuppetAI::CheckTargetFlags(Unit* pmTarget, uint32 pmFlags)
{
    uint32 andValue = pmFlags & TARGET_FLAG::TARGET_FLAG_FRIENDLY;
    if (andValue == TARGET_FLAG::TARGET_FLAG_FRIENDLY)
    {
        if (sourcePlayer->IsHostileTo(pmTarget))
        {
            return false;
        }
    }
    andValue = pmFlags & TARGET_FLAG::TARGET_FLAG_ATTACKABLE;
    if (andValue == TARGET_FLAG::TARGET_FLAG_ATTACKABLE)
    {
        if (!sourcePlayer->IsValidAttackTarget(pmTarget))
        {
            return false;
        }
    }
    andValue = pmFlags & TARGET_FLAG::TARGET_FLAG_ALIVE;
    if (andValue == TARGET_FLAG::TARGET_FLAG_ALIVE)
    {
        if (!pmTarget->IsAlive())
        {
            return false;
        }
    }
    andValue = pmFlags & TARGET_FLAG::TARGET_FLAG_DEAD;
    if (andValue == (uint32)TARGET_FLAG::TARGET_FLAG_DEAD)
    {
        if (sourcePlayer->IsAlive())
        {
            return false;
        }
    }
    andValue = pmFlags & TARGET_FLAG::TARGET_FLAG_IN_ACTIVE_RANGE;
    if (andValue == (uint32)TARGET_FLAG::TARGET_FLAG_IN_ACTIVE_RANGE)
    {
        if (sourcePlayer->GetDistance2d(pmTarget) > 100)
        {
            return false;
        }
    }
    andValue = pmFlags & TARGET_FLAG::TARGET_FLAG_OUT_ACTIVE_RANGE;
    if (andValue == (uint32)TARGET_FLAG::TARGET_FLAG_OUT_ACTIVE_RANGE)
    {
        if (sourcePlayer->GetDistance2d(pmTarget) < 100)
        {
            return false;
        }
    }
    andValue = pmFlags & TARGET_FLAG::TARGET_FLAG_PLAYER;
    if (andValue == (uint32)TARGET_FLAG::TARGET_FLAG_PLAYER)
    {
        if (pmTarget->GetTypeId() != TYPEID_PLAYER)
        {
            return false;
        }
    }

    return true;
}

void PuppetAI::JustEnteredCombat()
{
    sLog->outBasic("Puppet %s just entered combat", sourcePlayer->GetName().c_str());
    sourcePlayer->SetStandState(UNIT_STAND_STATE_STAND);
}

void PuppetAI::JustLeftCombat()
{
    sLog->outBasic("Puppet %s just left combat", sourcePlayer->GetName().c_str());
    sourcePlayer->Say("What a battle!", Language::LANG_UNIVERSAL);
    sourcePlayer->SetStandState(UNIT_STAND_STATE_STAND);
    sourcePlayer->GetMotionMaster()->Clear();
    sourcePlayer->SetSelection(0);
    sourcePlayer->HandleEmoteCommand(Emote::EMOTE_ONESHOT_LAUGH);
}

void PuppetAI::JustDead()
{
    sLog->outBasic("Puppet %s just dead", sourcePlayer->GetName().c_str());
    deadTime = 0;
    sourcePlayer->GetMotionMaster()->Clear();
    sourcePlayer->SetSelection(0);
}

void PuppetAI::JustRevived()
{
    sLog->outBasic("Puppet %s just revived", sourcePlayer->GetName().c_str());
    sourcePlayer->Say("I live again!", Language::LANG_UNIVERSAL);
    sourcePlayer->SetStandState(UNIT_STAND_STATE_STAND);
    sourcePlayer->GetMotionMaster()->Clear();
    sourcePlayer->HandleEmoteCommand(Emote::EMOTE_ONESHOT_CHEER);
    sourcePlayer->SetSelection(0);
}

void PuppetAI::UpdateAttacking()
{
    bool validAttackTarget = true;
    Unit* currentTarget = sourcePlayer->GetSelectedUnit();
    if (currentTarget)
    {
        if (sourcePlayer->GetDistance2d(currentTarget) > 50)
        {
            validAttackTarget = false;
        }
        else if (!sourcePlayer->IsValidAttackTarget(currentTarget))
        {
            validAttackTarget = false;
        }
        else if (!currentTarget->IsAlive())
        {
            validAttackTarget = false;
        }
    }
    else
    {
        validAttackTarget = false;
    }
    if (!validAttackTarget)
    {
        sourcePlayer->AttackStop();
        sourcePlayer->SetSelection(0);
        sourcePlayer->GetMotionMaster()->Clear();
        if (sourcePlayer->getAttackers().size() > 0)
        {
            for (std::unordered_set<Unit*>::const_iterator it = sourcePlayer->getAttackers().begin(); it != sourcePlayer->getAttackers().end(); it++)
            {
                if ((*it)->GetTypeId() == TYPEID_PLAYER)
                {
                    sourcePlayer->Say((*it)->GetName() + " you are next!", Language::LANG_UNIVERSAL);
                    sourcePlayer->SetSelection((*it)->GetGUID());
                    sourcePlayer->SetFacingToObject((*it));
                    validAttackTarget = true;
                    break;
                }
            }
            if (!validAttackTarget)
            {
                for (std::unordered_set<Unit*>::const_iterator it = sourcePlayer->getAttackers().begin(); it != sourcePlayer->getAttackers().end(); it++)
                {
                    sourcePlayer->Say((*it)->GetName() + " you are next!", Language::LANG_UNIVERSAL);
                    sourcePlayer->SetSelection((*it)->GetGUID());
                    sourcePlayer->SetFacingToObject((*it));
                    break;
                }
            }
        }
    }

    Unit* target = sourcePlayer->GetSelectedUnit();
    if (target)
    {
        MoveToAttack(target);
    }
}

void PuppetAI::MoveToAttack(Unit* pmTarget)
{
    float combatRange = 2;
    switch (sourcePlayer->getClass())
    {
    case Classes::CLASS_DRUID:
    {
        if (specialty != "feral combat")
        {
            combatRange = 25;
        }
        break;
    }
    case Classes::CLASS_HUNTER:
    {
        combatRange = 30;
        break;
    }
    case Classes::CLASS_MAGE:
    {
        combatRange = 25;
        break;
    }
    case Classes::CLASS_PRIEST:
    {
        combatRange = 25;
        break;
    }
    case Classes::CLASS_SHAMAN:
    {
        if (specialty != "enhancement")
        {
            combatRange = 25;
        }
        break;
    }
    case Classes::CLASS_WARLOCK:
    {
        combatRange = 25;
        break;
    }
    }

    if (MoveClose(pmTarget, combatRange))
    {
        if (combatRange < 5)
        {            
            sourcePlayer->Attack(pmTarget, true);
        }
    }
}

bool PuppetAI::MoveClose(Unit* pmTarget, float pmDistance)
{
    float currentDistance = sourcePlayer->GetDistance2d(pmTarget);
    if (currentDistance > pmDistance)
    {
        float angle = sourcePlayer->GetAngle(pmTarget);
        float destX = sourcePlayer->GetPositionX() + currentDistance * std::cos(angle);
        float destY = sourcePlayer->GetPositionY() + currentDistance * std::sin(angle);
        float destZ = sourcePlayer->GetPositionZ();
        sourcePlayer->UpdateGroundPositionZ(destX, destY, destZ);
        sourcePlayer->GetMotionMaster()->Clear();
        sourcePlayer->GetMotionMaster()->MovePoint(0, destX, destY, destZ);
        return true;
    }
    else
    {
        sourcePlayer->SetFacingToObject(pmTarget);
    }
    return false;
}

void PuppetAI::DoOpen(uint64 pmTargetGUID)
{

}

bool PuppetAI::DoLoot()
{
    bool looted = false;
    if (!looted)
    {
        list<Unit*> targets;
        Trinity::AnyDeadUnitObjectInRangeCheck u_check(sourcePlayer, INTERACTION_DISTANCE);
        Trinity::UnitListSearcher<Trinity::AnyDeadUnitObjectInRangeCheck> searcher(sourcePlayer, targets, u_check);
        sourcePlayer->VisitNearbyObject(INTERACTION_DISTANCE, searcher);

        if (targets.size() > 0)
        {
            for (list<Unit*>::iterator it = targets.begin(); it != targets.end(); it++)
            {
                Creature *creature = (*it)->ToCreature();
                if (creature && creature->getDeathState() == CORPSE)
                {
                    if (creature->HasFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE))
                    {
                        if (lootedCreaturesSet.find(creature->GetGUID()) != lootedCreaturesSet.end())
                        {
                            continue;
                        }
                        bool canLoot = false;

                        if (creature->GetLootRecipient() == sourcePlayer)
                        {
                            canLoot = true;
                        }
                        else
                        {
                            if (sourcePlayer->GetGroup())
                            {
                                if (creature->GetLootRecipientGroup() == sourcePlayer->GetGroup())
                                {
                                    canLoot = true;
                                }
                            }
                        }
                        if (canLoot)
                        {
                            if (sourcePlayer->IsNonMeleeSpellCast(false))
                            {
                                sourcePlayer->InterruptNonMeleeSpells(false);
                            }
                            DoLootCreatureCorpse(creature);
                            if (lootedCreaturesSet.size() > 50)
                            {
                                lootedCreaturesSet.clear();
                            }
                            lootedCreaturesSet.insert(creature->GetGUID());
                            looted = true;
                        }
                        break;
                    }
                }
            }
        }
    }
    if (!looted)
    {
        list<Unit*> targets;
        Trinity::AnyDeadUnitObjectInRangeCheck u_check(sourcePlayer, 50);
        Trinity::UnitListSearcher<Trinity::AnyDeadUnitObjectInRangeCheck> searcher(sourcePlayer, targets, u_check);
        sourcePlayer->VisitNearbyObject(50, searcher);

        if (targets.size() > 0)
        {
            for (list<Unit*>::iterator it = targets.begin(); it != targets.end(); it++)
            {
                Creature *creature = (*it)->ToCreature();
                if (creature && creature->getDeathState() == CORPSE)
                {
                    if (creature->HasFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE))
                    {
                        bool canLoot = false;

                        if (creature->GetLootRecipient() == sourcePlayer)
                        {
                            canLoot = true;
                        }
                        else
                        {
                            if (sourcePlayer->GetGroup())
                            {
                                if (creature->GetLootRecipientGroup() == sourcePlayer->GetGroup())
                                {
                                    canLoot = true;
                                }
                            }
                        }
                        if (canLoot)
                        {
                            sourcePlayer->Say("I am going to get close to '" + creature->GetName() + "' for looting", Language::LANG_UNIVERSAL);
                            MoveClose(creature, INTERACTION_DISTANCE);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return looted;
}

bool PuppetAI::DoRandomAttack()
{
    bool validAttackTarget = true;
    Unit* currentTarget = sourcePlayer->GetSelectedUnit();
    if (currentTarget)
    {
        if (sourcePlayer->GetDistance2d(currentTarget) > 50)
        {
            validAttackTarget = false;
        }
        else if (!sourcePlayer->IsValidAttackTarget(currentTarget))
        {
            validAttackTarget = false;
        }
        else if (!currentTarget->IsAlive())
        {
            validAttackTarget = false;
        }
    }
    else
    {
        validAttackTarget = false;
    }
    if (!validAttackTarget)
    {
        sourcePlayer->AttackStop();
        sourcePlayer->SetSelection(0);
        sourcePlayer->GetMotionMaster()->Clear();
        list<Unit*> targets;
        Trinity::AnyUnitInObjectRangeCheck u_check(sourcePlayer, 50);
        Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(sourcePlayer, targets, u_check);
        sourcePlayer->VisitNearbyObject(50, searcher);

        if (targets.size() > 0)
        {
            for (list<Unit*>::iterator it = targets.begin(); it != targets.end(); it++)
            {
                if ((*it)->GetGUID() != sourcePlayer->GetGUID())
                {
                    if ((*it)->IsWithinLOS(sourcePlayer->GetPositionX(), sourcePlayer->GetPositionY(), sourcePlayer->GetPositionZ()))
                    {
                        if (!sourcePlayer->IsValidAttackTarget((*it)))
                        {
                            continue;
                        }
                        if (!(*it)->IsAlive())
                        {
                            continue;
                        }
                        sourcePlayer->SetSelection((*it)->GetGUID());
                        sourcePlayer->Say((*it)->GetName() + " you are my target now!", Language::LANG_UNIVERSAL);
                        break;
                    }
                }
            }
        }
    }

    Unit* target = sourcePlayer->GetSelectedUnit();
    if (!target)
    {
        return false;
    }
    MoveToAttack(target);
    return true;
}

bool PuppetAI::DoRandomMove()
{
    bool validAttackTarget = true;
    Unit* currentTarget = sourcePlayer->GetSelectedUnit();
    if (currentTarget)
    {
        if (sourcePlayer->GetDistance2d(currentTarget) > 50)
        {
            validAttackTarget = false;
        }
        else if (!sourcePlayer->IsValidAttackTarget(currentTarget))
        {
            validAttackTarget = false;
        }
        else if (!currentTarget->IsAlive())
        {
            validAttackTarget = false;
        }
    }
    else
    {
        validAttackTarget = false;
    }
    if (validAttackTarget)
    {
        return false;
    }
    sourcePlayer->AttackStop();
    sourcePlayer->SetSelection(0);
    sourcePlayer->GetMotionMaster()->Clear();
    WorldLocation currentWL = sourcePlayer->GetWorldLocation();
    Map* dstMap = sMapMgr->FindBaseNonInstanceMap(currentWL.m_mapId);
    if (!dstMap)
    {
        return false;
    }
    float xDest = currentWL.GetPositionX() + frand(-40, 40);
    float yDest = currentWL.GetPositionY() + frand(-40, 40);
    float zDest = currentWL.GetPositionZ();
    sourcePlayer->UpdateGroundPositionZ(xDest, yDest, zDest);

    sourcePlayer->SetStandState(UNIT_STAND_STATE_STAND);
    sourcePlayer->Say("Let me see what'going on here", Language::LANG_UNIVERSAL);
    sourcePlayer->GetMotionMaster()->Clear();
    sourcePlayer->GetMotionMaster()->MovePoint(0, xDest, yDest, zDest, true);
    return true;
}

void PuppetAI::DoLootCreatureCorpse(Creature* pmTarget)
{
    if (sourcePlayer->GetLootGUID())
    {
        sourcePlayer->GetSession()->DoLootRelease(sourcePlayer->GetLootGUID());
    }

    Loot* loot;
    PermissionTypes permission = ALL_PERMISSION;

    // must be in range and creature must be alive for pickpocket and must be dead for another loot
    if (!pmTarget || pmTarget->IsAlive() || !pmTarget->IsWithinDistInMap(sourcePlayer, INTERACTION_DISTANCE))
    {
        return;
    }

    if (sourcePlayer->IsFriendlyTo(pmTarget))
    {
        return;
    }

    loot = &pmTarget->loot;

    Group* lrg = pmTarget->GetLootRecipientGroup();
    Group* puppetGroup = sourcePlayer->GetGroup();
    if (lrg)
    {
        if (loot->loot_type == LOOT_NONE)
        {
            switch (lrg->GetLootMethod())
            {
            case GROUP_LOOT:
                // GroupLoot: rolls items over threshold. Items with quality < threshold, round robin
                lrg->GroupLoot(loot, pmTarget);
                break;
            case NEED_BEFORE_GREED:
                lrg->NeedBeforeGreed(loot, pmTarget);
                break;
            case MASTER_LOOT:
                lrg->MasterLoot(loot, pmTarget);
                break;
            default:
                break;
            }
        }
        if (puppetGroup)
        {
            if (puppetGroup == lrg)
            {
                switch (puppetGroup->GetLootMethod())
                {
                case MASTER_LOOT:
                    permission = puppetGroup->GetMasterLooterGuid() == sourcePlayer->GetGUID() ? MASTER_PERMISSION : RESTRICTED_PERMISSION;
                    break;
                case FREE_FOR_ALL:
                    permission = ALL_PERMISSION;
                    break;
                case ROUND_ROBIN:
                    permission = ROUND_ROBIN_PERMISSION;
                    break;
                default:
                    permission = GROUP_PERMISSION;
                    break;
                }
            }
        }
        else
        {
            permission = NONE_PERMISSION;
        }
    }
    else if (pmTarget->GetLootRecipient() == sourcePlayer)
    {
        permission = OWNER_PERMISSION;
    }
    else
    {
        permission = NONE_PERMISSION;
    }

    loot->loot_type = LootType::LOOT_CORPSE;

    if (permission != NONE_PERMISSION)
    {
        sourcePlayer->SetLootGUID(pmTarget->GetGUID());
        LootView lv = LootView(*loot, sourcePlayer, permission);
        // add 'this' player as one of the players that are looting 'loot'
        loot->AddLooter(sourcePlayer->GetGUID());
        sourcePlayer->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOOTING);

        uint8 lootSlotType = LootSlotType::LOOT_SLOT_TYPE_ALLOW_LOOT;
        if (puppetGroup)      //item, pickpocket and players can be looted only single player
        {
            lootSlotType = LootSlotType::LOOT_SLOT_TYPE_MASTER;

            std::vector<Player*> playersNear;
            for (GroupReference* itr = puppetGroup->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* member = itr->GetSource();
                if (!member)
                    continue;

                if (sourcePlayer->IsAtGroupRewardDistance(member))
                    playersNear.push_back(member);
            }

            uint32 goldPerPlayer = uint32((loot->gold) / (playersNear.size()));

            for (std::vector<Player*>::const_iterator i = playersNear.begin(); i != playersNear.end(); ++i)
            {
                (*i)->ModifyMoney(goldPerPlayer);
                (*i)->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY, goldPerPlayer);

                WorldPacket data(SMSG_LOOT_MONEY_NOTIFY, 4 + 1);
                data << uint32(goldPerPlayer);
                data << uint8(playersNear.size() <= 1); // Controls the text displayed in chat. 0 is "Your share is..." and 1 is "You loot..."
                (*i)->GetSession()->SendPacket(&data);
            }
        }
        else
        {
            sourcePlayer->Say("I loot " + std::to_string(loot->gold) + " copper", Language::LANG_UNIVERSAL);
            sourcePlayer->ModifyMoney(loot->gold);
            sourcePlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY, loot->gold);
        }

        loot->gold = 0;
        loot->NotifyMoneyRemoved();

        for (uint8 i = 0; i < loot->items.size(); ++i)
        {
            ItemTemplate const *proto = sObjectMgr->GetItemTemplate(loot->items[i].itemid);
            if (proto)
            {
                if (loot->items[i].AllowedForPlayer(sourcePlayer))
                {
                    if (proto->Quality > 1)
                    {
                        if (lootSlotType == LootSlotType::LOOT_SLOT_TYPE_MASTER)
                        {
                            continue;
                        }
                    }
                    sourcePlayer->StoreLootItem(i, loot);
                    sourcePlayer->Say("I loot '" + proto->Name1 + "' " + std::to_string(loot->items[i].count), Language::LANG_UNIVERSAL);
                }
            }
        }
    }

    sourcePlayer->GetSession()->DoLootRelease(sourcePlayer->GetLootGUID());
}

void PuppetAI::DoBagging()
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(sourcePlayer->getFaction());
    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(sourcePlayer->getFaction());

    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
    {
        Item* pItem = sourcePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && !pItem->IsInTrade())
        {
            const ItemTemplate* pProto = pItem->GetTemplate();
            if (pProto)
            {
                // all puppet basic items will be ignored
                if (basicItemsMap.find(pProto->ItemId) != basicItemsMap.end())
                {
                    sourcePlayer->Say(pProto->Name1 + " will be ignored for bagging", Language::LANG_UNIVERSAL);
                    continue;
                }

                if (pItem->IsSoulBound())
                {
                    // sell directly
                    if (pProto->SellPrice > 0)
                    {
                        uint32 money = pProto->SellPrice * pItem->GetCount();
                        sourcePlayer->ModifyMoney(money);
                        sourcePlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS, money);
                        sourcePlayer->DestroyItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
                    }
                }
                else if (pProto->Quality == 0)
                {
                    // sell directly
                    if (pProto->SellPrice > 0)
                    {
                        uint32 money = pProto->SellPrice * pItem->GetCount();
                        sourcePlayer->ModifyMoney(money);
                        sourcePlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS, money);
                        sourcePlayer->DestroyItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
                    }
                }
                else
                {
                    int32 bidPrice = pProto->BuyPrice;
                    bool doAuction = false;
                    bool doSell = false;
                    if (pProto->Quality == 1)
                    {
                        if (pItem->GetCount() >= pProto->Stackable)
                        {
                            doAuction = urand(0, 100) < 50;
                            doSell = !doAuction;
                        }
                        else
                        {
                            doAuction = urand(0, 100) < 1;
                        }
                        if (doAuction)
                        {
                            if (bidPrice == 0)
                            {
                                bidPrice = pProto->ItemLevel * 100;
                            }
                        }
                    }
                    else if (pProto->Quality == 2)
                    {
                        if (pItem->GetCount() >= pProto->Stackable)
                        {
                            doAuction = urand(0, 100) < 70;
                            doSell = !doAuction;
                        }
                        else
                        {
                            doAuction = urand(0, 100) < 10;
                        }
                        if (doAuction)
                        {
                            if (bidPrice == 0)
                            {
                                bidPrice = pProto->ItemLevel * 100;
                            }
                            bidPrice = bidPrice * 2;
                        }
                    }
                    else if (pProto->Quality == 3)
                    {
                        if (pItem->GetCount() >= pProto->Stackable)
                        {
                            doAuction = urand(0, 100) < 90;
                            doSell = !doAuction;
                        }
                        else
                        {
                            doAuction = urand(0, 100) < 10;
                        }
                        if (doAuction)
                        {
                            if (bidPrice == 0)
                            {
                                bidPrice = pProto->ItemLevel * 100;
                            }
                            bidPrice = bidPrice * 3;
                        }
                    }
                    else
                    {
                        doSell = true;
                    }
                    if (doAuction)
                    {
                        bidPrice = urand(bidPrice * 2, bidPrice * 5);

                        AuctionEntry* auctionEntry = new AuctionEntry();
                        auctionEntry->Id = sObjectMgr->GenerateAuctionID();
                        auctionEntry->owner = sourcePlayer->GetGUIDLow();
                        auctionEntry->item_guidlow = pItem->GetGUIDLow();
                        auctionEntry->item_template = pItem->GetEntry();
                        auctionEntry->startbid = bidPrice;
                        auctionEntry->buyout = ((float)auctionEntry->startbid)*frand(1.2, 2);
                        auctionEntry->bidder = 0;
                        auctionEntry->bid = 0;
                        auctionEntry->deposit = sAuctionMgr->GetAuctionDeposit(ahEntry, 172800, pItem, pItem->GetCount());
                        auctionEntry->auctionHouseEntry = ahEntry;
                        auctionEntry->expire_time = time(NULL) + 48 * HOUR;

                        sAuctionMgr->AddAItem(pItem);

                        auctionEntry->SaveToDB(trans);
                        sourcePlayer->MoveItemFromInventory(pItem->GetBagSlot(), pItem->GetSlot(), true);
                        pItem->DeleteFromInventoryDB(trans);
                        pItem->SaveToDB(trans);

                        auctionHouse->AddAuction(auctionEntry);
                    }
                    else if (doSell)
                    {
                        if (pProto->SellPrice > 0)
                        {
                            uint32 money = pProto->SellPrice * pItem->GetCount();
                            sourcePlayer->ModifyMoney(money);
                            sourcePlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS, money);
                            sourcePlayer->DestroyItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
                        }
                    }
                }
            }
        }
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
    {
        if (Bag* pBag = sourcePlayer->GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                Item* pItem = sourcePlayer->GetItemByPos(i, j);
                if (pItem && !pItem->IsInTrade())
                {
                    const ItemTemplate* pProto = pItem->GetTemplate();
                    if (pProto)
                    {
                        if (pItem->IsSoulBound())
                        {
                            // sell directly
                            if (pProto->SellPrice > 0)
                            {
                                uint32 money = pProto->SellPrice * pItem->GetCount();
                                sourcePlayer->ModifyMoney(money);
                                sourcePlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS, money);
                                sourcePlayer->DestroyItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
                            }
                        }
                        else if (pProto->Quality == 0)
                        {
                            // sell directly
                            if (pProto->SellPrice > 0)
                            {
                                uint32 money = pProto->SellPrice * pItem->GetCount();
                                sourcePlayer->ModifyMoney(money);
                                sourcePlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS, money);
                                sourcePlayer->DestroyItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
                            }
                        }
                        else if (pProto->Quality == 1)
                        {
                            // add into auctionhouse
                            int32 basePrice = pProto->BuyPrice;
                            if (basePrice == 0)
                            {
                                basePrice = pProto->ItemLevel * 100;
                            }

                            AuctionEntry* auctionEntry = new AuctionEntry();
                            auctionEntry->Id = sObjectMgr->GenerateAuctionID();
                            auctionEntry->owner = sourcePlayer->GetGUIDLow();
                            auctionEntry->item_guidlow = pItem->GetGUIDLow();
                            auctionEntry->item_template = pItem->GetEntry();
                            auctionEntry->startbid = basePrice * urand(2, 5);
                            auctionEntry->buyout = ((float)auctionEntry->startbid)*frand(1.2, 2);
                            auctionEntry->bidder = 0;
                            auctionEntry->bid = 0;
                            auctionEntry->deposit = sAuctionMgr->GetAuctionDeposit(ahEntry, 172800, pItem, pItem->GetCount());
                            auctionEntry->auctionHouseEntry = ahEntry;
                            auctionEntry->expire_time = time(NULL) + 48 * HOUR;

                            sAuctionMgr->AddAItem(pItem);

                            auctionEntry->SaveToDB(trans);
                            sourcePlayer->MoveItemFromInventory(pItem->GetBagSlot(), pItem->GetSlot(), true);
                            pItem->DeleteFromInventoryDB(trans);
                            pItem->SaveToDB(trans);

                            auctionHouse->AddAuction(auctionEntry);
                        }
                        else if (pProto->Quality == 2)
                        {
                            // add into auctionhouse
                            int32 basePrice = pProto->BuyPrice;
                            if (basePrice == 0)
                            {
                                basePrice = pProto->ItemLevel * 500;
                            }

                            AuctionEntry* auctionEntry = new AuctionEntry();
                            auctionEntry->Id = sObjectMgr->GenerateAuctionID();
                            auctionEntry->owner = sourcePlayer->GetGUIDLow();
                            auctionEntry->item_guidlow = pItem->GetGUIDLow();
                            auctionEntry->item_template = pItem->GetEntry();
                            auctionEntry->startbid = basePrice * urand(2, 5);
                            auctionEntry->buyout = ((float)auctionEntry->startbid)*frand(1.2, 2);
                            auctionEntry->bidder = 0;
                            auctionEntry->bid = 0;
                            auctionEntry->deposit = sAuctionMgr->GetAuctionDeposit(ahEntry, 172800, pItem, pItem->GetCount());
                            auctionEntry->auctionHouseEntry = ahEntry;
                            auctionEntry->expire_time = time(NULL) + 48 * HOUR;

                            sAuctionMgr->AddAItem(pItem);

                            auctionEntry->SaveToDB(trans);
                            sourcePlayer->MoveItemFromInventory(pItem->GetBagSlot(), pItem->GetSlot(), true);
                            pItem->DeleteFromInventoryDB(trans);
                            pItem->SaveToDB(trans);

                            auctionHouse->AddAuction(auctionEntry);
                        }
                        else if (pProto->Quality == 3)
                        {
                            // add into auctionhouse
                            int32 basePrice = pProto->BuyPrice;
                            if (basePrice == 0)
                            {
                                basePrice = pProto->ItemLevel * 1500;
                            }

                            AuctionEntry* auctionEntry = new AuctionEntry();
                            auctionEntry->Id = sObjectMgr->GenerateAuctionID();
                            auctionEntry->owner = sourcePlayer->GetGUIDLow();
                            auctionEntry->item_guidlow = pItem->GetGUIDLow();
                            auctionEntry->item_template = pItem->GetEntry();
                            auctionEntry->startbid = basePrice * urand(2, 5);
                            auctionEntry->buyout = ((float)auctionEntry->startbid)*frand(1.2, 2);
                            auctionEntry->bidder = 0;
                            auctionEntry->bid = 0;
                            auctionEntry->deposit = sAuctionMgr->GetAuctionDeposit(ahEntry, 172800, pItem, pItem->GetCount());
                            auctionEntry->auctionHouseEntry = ahEntry;
                            auctionEntry->expire_time = time(NULL) + 48 * HOUR;

                            sAuctionMgr->AddAItem(pItem);

                            auctionEntry->SaveToDB(trans);
                            sourcePlayer->MoveItemFromInventory(pItem->GetBagSlot(), pItem->GetSlot(), true);
                            pItem->DeleteFromInventoryDB(trans);
                            pItem->SaveToDB(trans);

                            auctionHouse->AddAuction(auctionEntry);
                        }
                        else
                        {
                            // sell directly
                            if (pProto->SellPrice > 0)
                            {
                                uint32 money = pProto->SellPrice * pItem->GetCount();
                                sourcePlayer->ModifyMoney(money);
                                sourcePlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS, money);
                                sourcePlayer->DestroyItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
                            }
                        }
                    }
                }
            }
        }
    }

    sourcePlayer->SaveInventoryAndGoldToDB(trans);
    CharacterDatabase.CommitTransaction(trans);
}

void PuppetAI::UseItem(Item* pmItem, uint8 pmActiveTargetType)
{
    if (!pmItem)
    {
        return;
    }

    ItemTemplate const* proto = pmItem->GetTemplate();
    if (!proto)
    {
        return;
    }

    // some item classes can be used only in equipped state
    if (proto->InventoryType != INVTYPE_NON_EQUIP && !pmItem->IsEquipped())
    {
        return;
    }

    InventoryResult msg = sourcePlayer->CanUseItem(pmItem);
    if (msg != EQUIP_ERR_OK)
    {
        return;
    }

    // only allow conjured consumable, bandage, poisons (all should have the 2^21 item flag set in DB)
    if (proto->Class == ITEM_CLASS_CONSUMABLE && !(proto->Flags & ITEM_PROTO_FLAG_USEABLE_IN_ARENA) && sourcePlayer->InArena())
    {
        return;
    }

    // don't allow items banned in arena
    if (proto->Flags & ITEM_PROTO_FLAG_NOT_USEABLE_IN_ARENA && sourcePlayer->InArena())
    {
        return;
    }

    if (sourcePlayer->IsInCombat())
    {
        for (int i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(proto->Spells[i].SpellId))
            {
                if (!spellInfo->CanBeUsedInCombat())
                {
                    return;
                }
            }
        }
    }

    // check also  BIND_WHEN_PICKED_UP and BIND_QUEST_ITEM for .additem or .additemset case by GM (not binded at adding to inventory)
    if (pmItem->GetTemplate()->Bonding == BIND_WHEN_USE || pmItem->GetTemplate()->Bonding == BIND_WHEN_PICKED_UP || pmItem->GetTemplate()->Bonding == BIND_QUEST_ITEM)
    {
        if (!pmItem->IsSoulBound())
        {
            pmItem->SetState(ITEM_CHANGED, sourcePlayer);
            pmItem->SetBinding(true);
        }
    }

    SpellCastTargets targets;

    SpellCastTargets useTarget;
    switch (pmActiveTargetType)
    {
    case ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_CURRENT_TARGET:
    {
        Unit* currentTarget = sourcePlayer->GetSelectedUnit();
        if (currentTarget)
        {
            useTarget.SetUnitTarget(currentTarget);
        }
        break;
    }
    case ACTIVE_TARGET_TYPE::ACTIVE_TARGET_TYPE_SELF:
    {
        useTarget.SetUnitTarget(sourcePlayer);
        break;
    }
    default:
    {
        useTarget.SetUnitTarget(sourcePlayer);
        break;
    }
    }

    // Note: If script stop casting it must send appropriate data to client to prevent stuck item in gray state.
    if (!sScriptMgr->OnItemUse(sourcePlayer, pmItem, targets))
    {
        // no script or script not process request by self
        sourcePlayer->CastItemUseSpell(pmItem, targets, 1, 0);
    }
}

SpellInfo* PuppetAI::GetHighestRankSpellInfoByName(std::string pmSpellName)
{
    return NULL;
}

void PuppetAI::SetMaster(Player * pmMaster)
{
    masterPlayer = pmMaster;
}

void PuppetAI::HandleTeleport()
{
    sourcePlayer->GetMotionMaster()->Clear(true);
    if (sourcePlayer->IsBeingTeleportedNear())
    {
        sourcePlayer->SetSemaphoreTeleportNear(0);

        uint32 old_zone = sourcePlayer->GetZoneId();

        WorldLocation const& dest = sourcePlayer->GetTeleportDest();
        Position oldPos(*sourcePlayer);

        sourcePlayer->UpdatePosition(dest, true);

        // xinef: teleport pets if they are not unsummoned
        if (Pet* pet = sourcePlayer->GetPet())
        {
            if (!pet->IsWithinDist3d(sourcePlayer, sourcePlayer->GetMap()->GetVisibilityRange() - 5.0f))
                pet->NearTeleportTo(sourcePlayer->GetPositionX(), sourcePlayer->GetPositionY(), sourcePlayer->GetPositionZ(), pet->GetOrientation());
        }

        if (oldPos.GetExactDist2d(sourcePlayer) > 100.0f)
        {
            uint32 newzone, newarea;
            sourcePlayer->GetZoneAndAreaId(newzone, newarea, true);
            sourcePlayer->UpdateZone(newzone, newarea);

            // new zone
            if (old_zone != newzone)
            {
                // honorless target
                if (sourcePlayer->pvpInfo.IsHostile)
                    sourcePlayer->CastSpell(sourcePlayer, 2479, true);

                // in friendly area
                else if (sourcePlayer->IsPvP() && !sourcePlayer->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
                    sourcePlayer->UpdatePvP(false, false);
            }
        }

        // resummon pet
        sourcePlayer->ResummonPetTemporaryUnSummonedIfAny();

        //lets process all delayed operations on successful teleport
        sourcePlayer->ProcessDelayedOperations();

        sourcePlayer->GetMotionMaster()->ReinitializeMovement();

        // pussywizard: client forgets about losing control, resend it
        if (sourcePlayer->HasUnitState(UNIT_STATE_FLEEING | UNIT_STATE_CONFUSED) || sourcePlayer->IsCharmed()) // only in such cases SetClientControl(self, false) is sent
            sourcePlayer->SetClientControl(sourcePlayer, false, true);
    }
    else if (sourcePlayer->IsBeingTeleportedFar())
    {
        sourcePlayer->SetSemaphoreTeleportFar(0);

        // get the teleport destination
        WorldLocation const& loc = sourcePlayer->GetTeleportDest();

        // possible errors in the coordinate validity check
        if (!MapManager::IsValidMapCoord(loc))
        {
            RandomTeleport();
            return;
        }

        // get the destination map entry, not the current one, this will fix homebind and reset greeting
        MapEntry const* mEntry = sMapStore.LookupEntry(loc.GetMapId());
        InstanceTemplate const* mInstance = sObjectMgr->GetInstanceTemplate(loc.GetMapId());

        Map* oldMap = sourcePlayer->GetMap();
        if (sourcePlayer->IsInWorld())
        {
            sLog->outError("Player (Name %s) is still in world when teleported from map %u to new map %u", sourcePlayer->GetName().c_str(), oldMap->GetId(), loc.GetMapId());
            oldMap->RemovePlayerFromMap(sourcePlayer, false);
        }

        // reset instance validity, except if going to an instance inside an instance
        if (sourcePlayer->m_InstanceValid == false && !mInstance)
        {
            sourcePlayer->m_InstanceValid = true;
            // pussywizard: m_InstanceValid can be false only by leaving a group in an instance => so remove temp binds that could not be removed because player was still on the map!
            if (!sInstanceSaveMgr->PlayerIsPermBoundToInstance(sourcePlayer->GetGUIDLow(), oldMap->GetId(), oldMap->GetDifficulty()))
                sInstanceSaveMgr->PlayerUnbindInstance(sourcePlayer->GetGUIDLow(), oldMap->GetId(), oldMap->GetDifficulty(), true);
        }

        // relocate the player to the teleport destination
        Map* newMap = sMapMgr->CreateMap(loc.GetMapId(), sourcePlayer);
        // the CanEnter checks are done in TeleporTo but conditions may change
        // while the player is in transit, for example the map may get full
        if (!newMap || !newMap->CanEnter(sourcePlayer, false))
        {
            sLog->outError("Map %d could not be created for player %d, porting player to homebind", loc.GetMapId(), sourcePlayer->GetGUIDLow());
            sourcePlayer->TeleportTo(sourcePlayer->m_homebindMapId, sourcePlayer->m_homebindX, sourcePlayer->m_homebindY, sourcePlayer->m_homebindZ, sourcePlayer->GetOrientation());
            return;
        }

        sourcePlayer->Relocate(loc.GetPositionX(), loc.GetPositionY(), loc.GetPositionZ(), loc.GetOrientation());

        sourcePlayer->ResetMap();
        sourcePlayer->SetMap(newMap);

        sourcePlayer->SendInitialPacketsBeforeAddToMap();
        if (!sourcePlayer->GetMap()->AddPlayerToMap(sourcePlayer))
        {
            sLog->outError("WORLD: failed to teleport player %s (%d) to map %d because of unknown reason!", sourcePlayer->GetName().c_str(), sourcePlayer->GetGUIDLow(), loc.GetMapId());
            sourcePlayer->ResetMap();
            sourcePlayer->SetMap(oldMap);
            sourcePlayer->TeleportTo(sourcePlayer->m_homebindMapId, sourcePlayer->m_homebindX, sourcePlayer->m_homebindY, sourcePlayer->m_homebindZ, sourcePlayer->GetOrientation());
            return;
        }

        oldMap->AfterPlayerUnlinkFromMap();

        // pussywizard: transport teleport couldn't teleport us to the same map (some other teleport pending, reqs not met, etc.), but we still have transport set until player moves! clear it if map differs (crashfix)
        if (Transport* t = sourcePlayer->GetTransport())
            if (!t->IsInMap(sourcePlayer))
            {
                t->RemovePassenger(sourcePlayer);
                sourcePlayer->SetTransport(NULL);
                sourcePlayer->m_movementInfo.transport.Reset();
                sourcePlayer->m_movementInfo.RemoveMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
            }

        if (!sourcePlayer->getHostileRefManager().isEmpty())
            sourcePlayer->getHostileRefManager().deleteReferences(); // pussywizard: multithreading crashfix

        CellCoord pair(Trinity::ComputeCellCoord(sourcePlayer->GetPositionX(), sourcePlayer->GetPositionY()));
        Cell cell(pair);
        if (!GridCoord(cell.GridX(), cell.GridY()).IsCoordValid())
        {
            RandomTeleport();
            return;
        }
        newMap->LoadGrid(sourcePlayer->GetPositionX(), sourcePlayer->GetPositionY());

        // pussywizard: player supposed to enter bg map
        if (sourcePlayer->InBattleground())
        {
            // but landed on another map, cleanup data
            if (!mEntry->IsBattlegroundOrArena())
                sourcePlayer->SetBattlegroundId(0, BATTLEGROUND_TYPE_NONE, PLAYER_MAX_BATTLEGROUND_QUEUES, false, false, TEAM_NEUTRAL);
            // everything ok
            else if (Battleground* bg = sourcePlayer->GetBattleground())
            {
                if (sourcePlayer->IsInvitedForBattlegroundInstance()) // GMs are not invited, so they are not added to participants
                    bg->AddPlayer(sourcePlayer);
            }
        }

        // pussywizard: arena spectator stuff
        {
            if (newMap->IsBattleArena() && ((BattlegroundMap*)newMap)->GetBG() && sourcePlayer->HasPendingSpectatorForBG(((BattlegroundMap*)newMap)->GetInstanceId()))
            {
                sourcePlayer->ClearReceivedSpectatorResetFor();
                sourcePlayer->SetIsSpectator(true);
                ArenaSpectator::SendCommand(sourcePlayer, "%sENABLE", SPECTATOR_ADDON_PREFIX);
                ((BattlegroundMap*)newMap)->GetBG()->AddSpectator(sourcePlayer);
                ArenaSpectator::HandleResetCommand(sourcePlayer);
            }
            else
                sourcePlayer->SetIsSpectator(false);

            sourcePlayer->SetPendingSpectatorForBG(0);

            if (uint32 inviteInstanceId = sourcePlayer->GetPendingSpectatorInviteInstanceId())
            {
                if (Battleground* tbg = sBattlegroundMgr->GetBattleground(inviteInstanceId))
                    tbg->RemoveToBeTeleported(sourcePlayer->GetGUID());
                sourcePlayer->SetPendingSpectatorInviteInstanceId(0);
            }
        }

        // xinef: do this again, player can be teleported inside bg->AddPlayer(sourcePlayer)!!!!
        CellCoord pair2(Trinity::ComputeCellCoord(sourcePlayer->GetPositionX(), sourcePlayer->GetPositionY()));
        Cell cell2(pair2);
        if (!GridCoord(cell2.GridX(), cell2.GridY()).IsCoordValid())
        {
            RandomTeleport();
            return;
        }
        newMap->LoadGrid(sourcePlayer->GetPositionX(), sourcePlayer->GetPositionY());

        sourcePlayer->SendInitialPacketsAfterAddToMap();

        // resurrect character at enter into instance where his corpse exist after add to map
        Corpse* corpse = sourcePlayer->GetCorpse();
        if (corpse && corpse->GetType() != CORPSE_BONES && corpse->GetMapId() == sourcePlayer->GetMapId())
        {
            if (mEntry->IsDungeon())
            {
                sourcePlayer->ResurrectPlayer(0.5f, false);
                sourcePlayer->SpawnCorpseBones();
            }
        }

        bool allowMount = !mEntry->IsDungeon() || mEntry->IsBattlegroundOrArena();
        if (mInstance)
        {
            Difficulty diff = sourcePlayer->GetDifficulty(mEntry->IsRaid());
            if (MapDifficulty const* mapDiff = GetMapDifficultyData(mEntry->MapID, diff))
                if (mapDiff->resetTime)
                    if (time_t timeReset = sInstanceSaveMgr->GetResetTimeFor(mEntry->MapID, diff))
                    {
                        uint32 timeleft = uint32(timeReset - time(NULL));
                        sourcePlayer->SendInstanceResetWarning(mEntry->MapID, diff, timeleft, true);
                    }
            allowMount = mInstance->AllowMount;
        }

        // mount allow check
        if (!allowMount)
            sourcePlayer->RemoveAurasByType(SPELL_AURA_MOUNTED);

        // update zone immediately, otherwise leave channel will cause crash in mtmap
        uint32 newzone, newarea;
        sourcePlayer->GetZoneAndAreaId(newzone, newarea, true);
        sourcePlayer->UpdateZone(newzone, newarea);

        // honorless target
        if (sourcePlayer->pvpInfo.IsHostile)
            sourcePlayer->CastSpell(sourcePlayer, 2479, true);

        // in friendly area
        else if (sourcePlayer->IsPvP() && !sourcePlayer->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
            sourcePlayer->UpdatePvP(false, false);

        // resummon pet
        sourcePlayer->ResummonPetTemporaryUnSummonedIfAny();

        //lets process all delayed operations on successful teleport
        sourcePlayer->ProcessDelayedOperations();
    }
}

void PuppetAI::Randomize()
{
    uint32 maxLevel = sPuppetConfig.randomPuppetMaxLevel;
    if (maxLevel > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        maxLevel = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
    uint32 minLevel = sPuppetConfig.randomPuppetMinLevel;
    if (minLevel < 20)
    {
        minLevel = 20;
    }
    if (minLevel > maxLevel)
    {
        maxLevel = minLevel;
    }
    int resultLevel = urand(minLevel, maxLevel);
    PuppetFactory factory(sourcePlayer, resultLevel);
    factory.Randomize();
}

void PuppetAI::RandomTeleport()
{
    sLog->outDetail("Preparing location to random teleporting puppet %s for level %u", sourcePlayer->GetName().c_str(), sourcePlayer->getLevel());

    uint32 mapID = 0;
    float x = 0;
    float y = 0;
    float z = 0;
    int targetLevelRange = sourcePlayer->getLevel() / 10;
    unordered_map<uint32, WorldLocation> dstWLMap = sPuppetMgr.teleportZoneCacheMap[targetLevelRange];
    uint32 randomIndex = urand(0, dstWLMap.size() - 1);
    WorldLocation dstWL = dstWLMap[randomIndex];
    mapID = dstWL.m_mapId;
    Map* dstMap = sMapMgr->FindBaseNonInstanceMap(mapID);
    if (!dstMap)
    {
        sLog->outError("Target map for teleport is not valid %u", mapID);
        return;
    }
    while (true)
    {
        x = dstWL.GetPositionX() + frand(-200, 200);
        y = dstWL.GetPositionY() + frand(-200, 200);
        z = dstWL.GetPositionZ();
        sourcePlayer->UpdateGroundPositionZ(x, y, z);
        if (MapManager::IsValidMapCoord(mapID, x, y, z))
        {
            break;
        }
    }

    sourcePlayer->TeleportTo(mapID, x, y, z, sourcePlayer->GetOrientation());
}

void PuppetAI::Revive()
{
    sLog->outDetail("Preparing location to revive puppet %s", sourcePlayer->GetName().c_str());

    while (true)
    {
        float x = sourcePlayer->GetPositionX() + frand(-50, 50);
        float y = sourcePlayer->GetPositionY() + frand(-50, 50);
        float z = sourcePlayer->GetPositionZ();
        sourcePlayer->UpdateGroundPositionZ(x, y, z);
        if (MapManager::IsValidMapCoord(sourcePlayer->m_mapId, x, y, z))
        {
            sourcePlayer->TeleportTo(sourcePlayer->m_mapId, x, y, z, sourcePlayer->GetOrientation());
            resurrecting = true;
            return;
        }
    }
}
