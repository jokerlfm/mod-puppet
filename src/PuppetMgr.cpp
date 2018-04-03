#include "PuppetMgr.h"

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

PuppetMgr::PuppetMgr()
{
    validPuppetAccountsMap.clear();
    validPuppetCharactersMap.clear();

    activeAIMap.clear();

    availableAllianceRaces.clear();

    availableHordeRaces.clear();
    teleportZoneCacheMap.clear();

    classesMap.clear();
    specialtyMap.clear();
    racesMap.clear();
    arrowMap.clear();
    bulletMap.clear();
    healthPotionMap.clear();
    manaPotionMap.clear();
    foodMap.clear();
    drinkMap.clear();
    tamableCreatureMap.clear();
    equipmentMap.clear();
    spellQuestsMap.clear();

    puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_LOADING_CONFIG;
    Initialize();
}

PuppetMgr::~PuppetMgr()
{
}

void PuppetMgr::ProcessPuppets(uint32 pmElapsed)
{
    if (puppetSystemState == PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_UPDATING)
    {
        for (std::unordered_map<uint32, PuppetAI*>::iterator it = activeAIMap.begin(); it != activeAIMap.end(); it++)
        {
            switch (it->second->puppetState)
            {
            case PUPPET_STATE::PUPPET_STATE_LOGIN:
            {
                it->second->FinishLogin();
            }
            }
        }
        return;
    }
    else
    {
        switch (puppetSystemState)
        {
        case PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_DISABLED:
        {
            break;
        }
        case PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_LOADING_CONFIG:
        {
            sPuppetConfig.Initialize();
            if (sPuppetConfig.enabled)
            {
                if (sPuppetConfig.deleteRandomPuppetAccounts)
                {
                    puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_DELETING_ACCOUNTS;
                }
                else
                {
                    puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CREATE_PUPPETS;
                }
            }
            else
            {
                puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_DISABLED;
            }
            sLog->outBasic("Random puppet config loaded");
            break;
        }
        case PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_DELETING_ACCOUNTS:
        {
            QueryResult results = LoginDatabase.PQuery("SELECT id FROM account where username like '%s%%'", sPuppetConfig.randomPuppetAccountPrefix.c_str());
            if (results)
            {
                do
                {
                    Field* fields = results->Fetch();
                    AccountMgr::DeleteAccount(fields[0].GetUInt32());
                } while (results->NextRow());
            }
            CharacterDatabase.DirectExecute("delete FROM puppet_info");
            //CharacterDatabase.DirectExecute("delete FROM puppet_spells");
            sLog->outBasic("Random puppet accounts deleted");
            puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CHECKING_DELETE;
            break;
        }
        case PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CHECKING_DELETE:
        {
            QueryResult checkQR = LoginDatabase.PQuery("SELECT count(*) FROM account where username like '%s%%'", sPuppetConfig.randomPuppetAccountPrefix.c_str());
            if (checkQR)
            {
                Field* countField = checkQR->Fetch();
                int checkCount = countField[0].GetUInt32();
                if (checkCount > 0)
                {
                    sLog->outDetail("Random puppet accounts deleting...");
                    break;
                }
            }
            QueryResult puppetInfoQR = CharacterDatabase.Query("SELECT count(*) FROM puppet_info");
            if (puppetInfoQR)
            {
                Field* countField = puppetInfoQR->Fetch();
                int checkCount = countField[0].GetUInt32();
                if (checkCount > 0)
                {
                    sLog->outDetail("Puppet info deleting...");
                    break;
                }
            }
            sLog->outBasic("Random puppet accounts deletion checked");
            puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CREATING_ACCOUNTS;
            break;
        }
        case PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CREATING_ACCOUNTS:
        {
            for (int accountNumber = 0; accountNumber < sPuppetConfig.randomPuppetAccountCount; ++accountNumber)
            {
                ostringstream out; out << sPuppetConfig.randomPuppetAccountPrefix << accountNumber;
                string accountName = out.str();
                QueryResult results = LoginDatabase.PQuery("SELECT id FROM account where username = '%s'", accountName.c_str());
                if (results)
                {
                    continue;
                }

                string password = "88888888";
                AccountMgr::CreateAccount(accountName, password);
                sLog->outDetail("Account %s created for random puppet", accountName.c_str());
            }
            sLog->outBasic("Random puppet accounts created");
            puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CHECKING_ACCOUNTS;
            break;
        }
        case PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CHECKING_ACCOUNTS:
        {
            QueryResult checkQR = LoginDatabase.PQuery("SELECT count(*) FROM account where username like '%s%%'", sPuppetConfig.randomPuppetAccountPrefix.c_str());
            if (checkQR)
            {
                Field* countField = checkQR->Fetch();
                int checkCount = countField[0].GetUInt32();
                if (checkCount >= sPuppetConfig.randomPuppetAccountCount)
                {
                    sLog->outBasic("Random puppet accounts creation checked");
                    LoginDatabase.PExecute("UPDATE account SET expansion = '%u' where username like '%s%%'", 2, sPuppetConfig.randomPuppetAccountPrefix.c_str());
                    puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CREATING_CHARACTERS;
                    break;
                }
            }
            sLog->outDetail("Random puppet accounts creating...");
            break;
        }
        case PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CREATING_CHARACTERS:
        {
            std::unordered_map<int, std::string> puppetNamesMap = GenerateRandomPuppetNamesMap();

            int checkAccountsCount = 0;
            int checkTotalCharactersCount = 0;
            int checkCharacterNamesCount = 0;
            for (int accountNumber = 0; accountNumber < sPuppetConfig.randomPuppetAccountCount; ++accountNumber)
            {
                ostringstream out; out << sPuppetConfig.randomPuppetAccountPrefix << accountNumber;
                string accountName = out.str();

                QueryResult results = LoginDatabase.PQuery("SELECT id FROM account where username = '%s'", accountName.c_str());
                if (!results)
                {
                    sLog->outError("Load account failed : %s", accountName.c_str());
                    continue;
                }
                Field* fields = results->Fetch();
                uint32 accountID = fields[0].GetUInt32();

                int count = AccountMgr::GetCharactersCount(accountID);
                if (count > 0)
                {
                    checkTotalCharactersCount += count;
                    validPuppetAccountsMap[accountID] = count;
                    continue;
                }

                // debug
                //for (uint8 cls = CLASS_WARRIOR; cls <= CLASS_WARRIOR; ++cls)
                for (uint8 cls = CLASS_WARRIOR; cls < MAX_CLASSES; ++cls)
                {
                    if (cls != 10 && cls != 6)
                    {
                        while (true)
                        {
                            if (checkCharacterNamesCount < puppetNamesMap.size())
                            {
                                QueryResult qr = CharacterDatabase.PQuery("SELECT guid FROM characters where name = '%s'", puppetNamesMap[checkCharacterNamesCount].c_str());
                                if (qr)
                                {
                                    sLog->outError("Name : %s is already been taken", puppetNamesMap[checkCharacterNamesCount].c_str());
                                    checkCharacterNamesCount++;
                                    continue;
                                }
                                else
                                {
                                    sLog->outDetail("Name : %s is available", puppetNamesMap[checkCharacterNamesCount].c_str());
                                    break;
                                }
                            }
                            else
                            {
                                sLog->outError("No available names");
                                return;
                            }
                        }

                        uint8 destClass = cls;

                        // debug
                        destClass = Classes::CLASS_WARRIOR;

                        sLog->outDetail("Creating new random puppet for class %d", destClass);
                        int isAlliance = checkAccountsCount % 2;

                        // debug
                        isAlliance = 1;

                        while (true)
                        {
                            uint8 gender = urand(0, 1);
                            uint8 race = 0;
                            if (isAlliance == 1)
                            {
                                race = availableAllianceRaces[destClass][urand(0, availableAllianceRaces[destClass].size() - 1)];
                            }
                            else
                            {
                                race = availableHordeRaces[destClass][urand(0, availableHordeRaces[destClass].size() - 1)];
                            }

                            // debug
                            //race = RACE_NIGHTELF;

                            uint8 checkSkin = urand(0, 6);
                            uint8 checkFace = urand(0, 6);
                            uint8 checkHairStyle = urand(0, 6);
                            uint8 checkHairColor = urand(0, 6);
                            uint8 checkFacialHair = urand(0, 6);
                            uint8 outfitId = 0;

                            WorldSession* session = new WorldSession(accountID, NULL, SEC_PLAYER, 2, 0, LOCALE_enUS, 0, false, true);
                            if (!session)
                            {
                                sLog->outError("Couldn't create session for random puppet account %d", accountID);
                                delete session;
                                break;
                            }

                            Player *player = new Player(session);
                            WorldPacket wp;
                            CharacterCreateInfo* cci = new CharacterCreateInfo(puppetNamesMap[checkCharacterNamesCount], race, destClass, gender, checkSkin, checkFace, checkHairStyle, checkHairColor, checkFacialHair, outfitId, wp);

                            if (!player->Create(sObjectMgr->GenerateLowGuid(HighGuid::HIGHGUID_PLAYER), cci))
                            {
                                player->DeleteFromDB(player->GetGUID(), accountID, true, true);
                                delete session;
                                delete player;
                                sLog->outError("Unable to create random puppet for account %d - name: \"%s\"; race: %u; class: %u",
                                    accountID, puppetNamesMap[checkCharacterNamesCount].c_str(), race, destClass);
                                sLog->outDetail("Try again");
                                continue;
                            }
                            player->SetLevel(1);
                            player->setCinematic(2);
                            player->SetAtLoginFlag(AT_LOGIN_NONE);                            
                            player->SaveToDB(true, true);
                            sLog->outDetail("Random puppet created for account %d - name: \"%s\"; race: %u; class: %u",
                                accountID, puppetNamesMap[checkCharacterNamesCount].c_str(), race, destClass);
                            break;
                        }
                        checkCharacterNamesCount++;
                        validPuppetAccountsMap[accountID]++;
                        checkTotalCharactersCount++;
                    }
                }

                checkAccountsCount++;
            }

            sLog->outBasic("%d random puppet accounts with %d characters available", checkAccountsCount, checkTotalCharactersCount);
            puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CHECKING_CHARACTERS;
            break;
        }
        case PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CHECKING_CHARACTERS:
        {
            validPuppetCharactersMap.clear();
            for (unordered_map<uint32, uint32>::iterator it = validPuppetAccountsMap.begin(); it != validPuppetAccountsMap.end(); it++)
            {
                QueryResult characterQR = CharacterDatabase.PQuery("SELECT guid FROM characters WHERE account = '%u'", it->first);
                if (!characterQR)
                {
                    sLog->outDetail("Wait to check character again : %u", it->first);
                    return;
                }
                do
                {
                    Field* characterField = characterQR->Fetch();
                    uint32 guid = characterField[0].GetUInt32();
                    validPuppetCharactersMap[it->first].insert(guid);
                } while (characterQR->NextRow());

                if (validPuppetCharactersMap[it->first].size() < it->second)
                {
                    sLog->outDetail("Wait to check character count again : %d - %d/%d", it->first, validPuppetCharactersMap[it->first].size(), it->second);
                    return;
                }
            }
            sLog->outBasic("characters creation checked");
            puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CREATE_PUPPETS;
            break;
        }
        case PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_CREATE_PUPPETS:
        {
            int checkEntry = 0;
            for (unordered_map<uint32, set<uint32>>::iterator accountIT = validPuppetCharactersMap.begin(); accountIT != validPuppetCharactersMap.end(); accountIT++)
            {
                for (set<uint32>::iterator characterIT = accountIT->second.begin(); characterIT != accountIT->second.end(); characterIT++)
                {
                    PuppetAI* eachPAI = new PuppetAI(checkEntry, accountIT->first, *characterIT);
                    activeAIMap[*characterIT] = eachPAI;                    
                    checkEntry++;
                }
            }
            sLog->outBasic("All puppets created");
            puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_LOGIN_PUPPETS;
            break;
        }
        case PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_LOGIN_PUPPETS:
        {
            for (std::unordered_map<uint32, PuppetAI*>::iterator it = activeAIMap.begin(); it != activeAIMap.end(); it++)
            {
                it->second->QueryLogin();
            }
            sLog->outBasic("All puppets are doing login queries.");
            puppetSystemState = PUPPET_SYSTEM_STATE::PUPPET_SYSTEM_STATE_UPDATING;
            break;
        }
        }
    }
}

void PuppetMgr::Initialize()
{
    // prepare all data
    classesMap[CLASS_DRUID] = "druid";
    specialtyMap[CLASS_DRUID][0] = "balance";
    specialtyMap[CLASS_DRUID][1] = "feral combat";
    specialtyMap[CLASS_DRUID][2] = "restoration";

    classesMap[CLASS_HUNTER] = "hunter";
    specialtyMap[CLASS_HUNTER][0] = "beast mastery";
    specialtyMap[CLASS_HUNTER][1] = "marksmanship";
    specialtyMap[CLASS_HUNTER][2] = "survival";

    classesMap[CLASS_MAGE] = "mage";
    specialtyMap[CLASS_MAGE][0] = "arcane";
    specialtyMap[CLASS_MAGE][1] = "fire";
    specialtyMap[CLASS_MAGE][2] = "frost";

    classesMap[CLASS_PALADIN] = "paladin";
    specialtyMap[CLASS_PALADIN][0] = "holy";
    specialtyMap[CLASS_PALADIN][1] = "protection";
    specialtyMap[CLASS_PALADIN][2] = "retribution";

    classesMap[CLASS_PRIEST] = "priest";
    specialtyMap[CLASS_PRIEST][0] = "discipline";
    specialtyMap[CLASS_PRIEST][1] = "holy";
    specialtyMap[CLASS_PRIEST][2] = "shadow";

    classesMap[CLASS_ROGUE] = "rogue";
    specialtyMap[CLASS_ROGUE][0] = "assasination";
    specialtyMap[CLASS_ROGUE][1] = "combat";
    specialtyMap[CLASS_ROGUE][2] = "subtlety";

    classesMap[CLASS_SHAMAN] = "shaman";
    specialtyMap[CLASS_SHAMAN][0] = "elemental";
    specialtyMap[CLASS_SHAMAN][1] = "enhancement";
    specialtyMap[CLASS_SHAMAN][2] = "restoration";

    classesMap[CLASS_WARLOCK] = "warlock";
    specialtyMap[CLASS_WARLOCK][0] = "affliction";
    specialtyMap[CLASS_WARLOCK][1] = "demonology";
    specialtyMap[CLASS_WARLOCK][2] = "destruction";

    classesMap[CLASS_WARRIOR] = "warrior";
    specialtyMap[CLASS_WARRIOR][0] = "warrior_arms";
    specialtyMap[CLASS_WARRIOR][1] = "warrior_fury";
    specialtyMap[CLASS_WARRIOR][2] = "warrior_protection";

    racesMap[RACE_DWARF] = "Dwarf";
    racesMap[RACE_GNOME] = "Gnome";
    racesMap[RACE_HUMAN] = "Human";
    racesMap[RACE_NIGHTELF] = "Night Elf";
    racesMap[RACE_ORC] = "Orc";
    racesMap[RACE_TAUREN] = "Tauren";
    racesMap[RACE_TROLL] = "Troll";
    racesMap[RACE_UNDEAD_PLAYER] = "Undead";
    racesMap[RACE_BLOODELF] = "Blood Elf";
    racesMap[RACE_DRAENEI] = "Draenei";

    availableAllianceRaces[CLASS_WARRIOR].push_back(RACE_HUMAN);
    availableAllianceRaces[CLASS_WARRIOR].push_back(RACE_NIGHTELF);
    availableAllianceRaces[CLASS_WARRIOR].push_back(RACE_GNOME);
    availableAllianceRaces[CLASS_WARRIOR].push_back(RACE_DWARF);
    availableAllianceRaces[CLASS_WARRIOR].push_back(RACE_DRAENEI);

    availableAllianceRaces[CLASS_PALADIN].push_back(RACE_HUMAN);
    availableAllianceRaces[CLASS_PALADIN].push_back(RACE_DWARF);
    availableAllianceRaces[CLASS_PALADIN].push_back(RACE_DRAENEI);

    availableAllianceRaces[CLASS_ROGUE].push_back(RACE_HUMAN);
    availableAllianceRaces[CLASS_ROGUE].push_back(RACE_DWARF);
    availableAllianceRaces[CLASS_ROGUE].push_back(RACE_NIGHTELF);
    availableAllianceRaces[CLASS_ROGUE].push_back(RACE_GNOME);

    availableAllianceRaces[CLASS_PRIEST].push_back(RACE_HUMAN);
    availableAllianceRaces[CLASS_PRIEST].push_back(RACE_DWARF);
    availableAllianceRaces[CLASS_PRIEST].push_back(RACE_NIGHTELF);
    availableAllianceRaces[CLASS_PRIEST].push_back(RACE_DRAENEI);

    availableAllianceRaces[CLASS_MAGE].push_back(RACE_HUMAN);
    availableAllianceRaces[CLASS_MAGE].push_back(RACE_GNOME);
    availableAllianceRaces[CLASS_MAGE].push_back(RACE_DRAENEI);

    availableAllianceRaces[CLASS_WARLOCK].push_back(RACE_HUMAN);
    availableAllianceRaces[CLASS_WARLOCK].push_back(RACE_GNOME);

    availableAllianceRaces[CLASS_SHAMAN].push_back(RACE_DRAENEI);

    availableAllianceRaces[CLASS_HUNTER].push_back(RACE_DWARF);
    availableAllianceRaces[CLASS_HUNTER].push_back(RACE_NIGHTELF);
    availableAllianceRaces[CLASS_HUNTER].push_back(RACE_DRAENEI);

    availableAllianceRaces[CLASS_DRUID].push_back(RACE_NIGHTELF);

    availableAllianceRaces[CLASS_DEATH_KNIGHT].push_back(RACE_NIGHTELF);
    availableAllianceRaces[CLASS_DEATH_KNIGHT].push_back(RACE_HUMAN);
    availableAllianceRaces[CLASS_DEATH_KNIGHT].push_back(RACE_DRAENEI);
    availableAllianceRaces[CLASS_DEATH_KNIGHT].push_back(RACE_GNOME);
    availableAllianceRaces[CLASS_DEATH_KNIGHT].push_back(RACE_DWARF);

    availableHordeRaces[CLASS_WARRIOR].push_back(RACE_ORC);
    availableHordeRaces[CLASS_WARRIOR].push_back(RACE_UNDEAD_PLAYER);
    availableHordeRaces[CLASS_WARRIOR].push_back(RACE_TAUREN);
    availableHordeRaces[CLASS_WARRIOR].push_back(RACE_TROLL);

    availableHordeRaces[CLASS_PALADIN].push_back(RACE_BLOODELF);

    availableHordeRaces[CLASS_ROGUE].push_back(RACE_ORC);
    availableHordeRaces[CLASS_ROGUE].push_back(RACE_TROLL);
    availableHordeRaces[CLASS_ROGUE].push_back(RACE_BLOODELF);

    availableHordeRaces[CLASS_PRIEST].push_back(RACE_TROLL);
    availableHordeRaces[CLASS_PRIEST].push_back(RACE_UNDEAD_PLAYER);
    availableHordeRaces[CLASS_PRIEST].push_back(RACE_BLOODELF);

    availableHordeRaces[CLASS_MAGE].push_back(RACE_UNDEAD_PLAYER);
    availableHordeRaces[CLASS_MAGE].push_back(RACE_TROLL);
    availableHordeRaces[CLASS_MAGE].push_back(RACE_BLOODELF);

    availableHordeRaces[CLASS_WARLOCK].push_back(RACE_UNDEAD_PLAYER);
    availableHordeRaces[CLASS_WARLOCK].push_back(RACE_ORC);
    availableHordeRaces[CLASS_WARLOCK].push_back(RACE_BLOODELF);

    availableHordeRaces[CLASS_SHAMAN].push_back(RACE_ORC);
    availableHordeRaces[CLASS_SHAMAN].push_back(RACE_TAUREN);
    availableHordeRaces[CLASS_SHAMAN].push_back(RACE_TROLL);

    availableHordeRaces[CLASS_HUNTER].push_back(RACE_ORC);
    availableHordeRaces[CLASS_HUNTER].push_back(RACE_TAUREN);
    availableHordeRaces[CLASS_HUNTER].push_back(RACE_TROLL);
    availableHordeRaces[CLASS_HUNTER].push_back(RACE_BLOODELF);

    availableHordeRaces[CLASS_DRUID].push_back(RACE_TAUREN);

    availableHordeRaces[CLASS_DEATH_KNIGHT].push_back(RACE_TAUREN);
    availableHordeRaces[CLASS_DEATH_KNIGHT].push_back(RACE_ORC);
    availableHordeRaces[CLASS_DEATH_KNIGHT].push_back(RACE_UNDEAD_PLAYER);
    availableHordeRaces[CLASS_DEATH_KNIGHT].push_back(RACE_TROLL);
    availableHordeRaces[CLASS_DEATH_KNIGHT].push_back(RACE_BLOODELF);

    healthPotionMap[1] = 118;
    healthPotionMap[3] = 858;
    healthPotionMap[12] = 929;
    healthPotionMap[21] = 1710;
    healthPotionMap[35] = 3928;
    healthPotionMap[45] = 13446;
    healthPotionMap[55] = 22829;
    healthPotionMap[65] = 39671;
    healthPotionMap[75] = 44698;
    manaPotionMap[5] = 2455;
    manaPotionMap[14] = 3385;
    manaPotionMap[22] = 3827;
    manaPotionMap[31] = 6149;
    manaPotionMap[41] = 13443;
    manaPotionMap[49] = 13444;
    manaPotionMap[55] = 22832;
    manaPotionMap[65] = 40067;
    manaPotionMap[70] = 33448;
    arrowMap[1] = 2512;
    arrowMap[10] = 2515;
    arrowMap[25] = 3030;
    arrowMap[40] = 11285;
    arrowMap[55] = 28053;
    arrowMap[70] = 30319;
    arrowMap[80] = 52021;
    bulletMap[1] = 2516;
    bulletMap[10] = 2519;
    bulletMap[25] = 3033;
    bulletMap[40] = 11284;
    bulletMap[55] = 28060;
    bulletMap[70] = 34582;
    bulletMap[80] = 52020;
    foodMap[1] = 4540;
    foodMap[5] = 4541;
    foodMap[15] = 4542;
    foodMap[25] = 4544;
    foodMap[35] = 4601;
    foodMap[45] = 23160;
    foodMap[55] = 27855;
    foodMap[65] = 29394;
    foodMap[75] = 35950;
    drinkMap[1] = 159;
    drinkMap[5] = 1179;
    drinkMap[15] = 1205;
    drinkMap[25] = 1708;
    drinkMap[35] = 1645;
    drinkMap[45] = 8766;
    drinkMap[55] = 18300;
    drinkMap[65] = 28760;
    drinkMap[75] = 33445;

    for (CreatureTemplateContainer::const_iterator it = sObjectMgr->GetCreatureTemplates()->begin(); it != sObjectMgr->GetCreatureTemplates()->end(); it++)
    {
        if (it->second.type == CreatureType::CREATURE_TYPE_BEAST)
        {
            if (it->second.IsTameable(false))
            {
                tamableCreatureMap[tamableCreatureMap.size()] = it->first;
            }
        }
    }
    sLog->outDetail("%d tamable beasts loaded", tamableCreatureMap.size());

    int checkCount = 0;
    for (ItemTemplateContainer::const_iterator it = sObjectMgr->GetItemTemplateStore()->begin(); it != sObjectMgr->GetItemTemplateStore()->end(); it++)
    {
        if (it->second.Class == ItemClass::ITEM_CLASS_ARMOR || it->second.Class == ItemClass::ITEM_CLASS_WEAPON)
        {
            if (it->second.RequiredLevel > 0)
            {
                uint8 levelRange = it->second.RequiredLevel / 10;
                uint8 equipSlot1 = EquipmentSlots::EQUIPMENT_SLOT_END;
                uint8 equipSlot2 = EquipmentSlots::EQUIPMENT_SLOT_END;
                switch (it->second.InventoryType)
                {
                case INVTYPE_HEAD:
                    equipSlot1 = EQUIPMENT_SLOT_HEAD;
                    break;
                case INVTYPE_NECK:
                    equipSlot1 = EQUIPMENT_SLOT_NECK;
                    break;
                case INVTYPE_SHOULDERS:
                    equipSlot1 = EQUIPMENT_SLOT_SHOULDERS;
                    break;
                case INVTYPE_BODY:
                    equipSlot1 = EQUIPMENT_SLOT_BODY;
                    break;
                case INVTYPE_CHEST:
                    equipSlot1 = EQUIPMENT_SLOT_CHEST;
                    break;
                case INVTYPE_ROBE:
                    equipSlot1 = EQUIPMENT_SLOT_CHEST;
                    break;
                case INVTYPE_WAIST:
                    equipSlot1 = EQUIPMENT_SLOT_WAIST;
                    break;
                case INVTYPE_LEGS:
                    equipSlot1 = EQUIPMENT_SLOT_LEGS;
                    break;
                case INVTYPE_FEET:
                    equipSlot1 = EQUIPMENT_SLOT_FEET;
                    break;
                case INVTYPE_WRISTS:
                    equipSlot1 = EQUIPMENT_SLOT_WRISTS;
                    break;
                case INVTYPE_HANDS:
                    equipSlot1 = EQUIPMENT_SLOT_HANDS;
                    break;
                case INVTYPE_FINGER:
                    equipSlot1 = EQUIPMENT_SLOT_FINGER1;
                    equipSlot2 = EQUIPMENT_SLOT_FINGER2;
                    break;
                case INVTYPE_TRINKET:
                    equipSlot1 = EQUIPMENT_SLOT_TRINKET1;
                    equipSlot2 = EQUIPMENT_SLOT_TRINKET2;
                    break;
                case INVTYPE_CLOAK:
                    equipSlot1 = EQUIPMENT_SLOT_BACK;
                    break;
                case INVTYPE_WEAPON:
                {
                    equipSlot1 = EQUIPMENT_SLOT_MAINHAND;
                    equipSlot2 = EQUIPMENT_SLOT_OFFHAND;
                    break;
                }
                case INVTYPE_SHIELD:
                    equipSlot1 = EQUIPMENT_SLOT_OFFHAND;
                    break;
                case INVTYPE_RANGED:
                    equipSlot1 = EQUIPMENT_SLOT_RANGED;
                    break;
                case INVTYPE_2HWEAPON:
                    equipSlot1 = EQUIPMENT_SLOT_MAINHAND;
                    break;
                case INVTYPE_WEAPONMAINHAND:
                    equipSlot1 = EQUIPMENT_SLOT_MAINHAND;
                    break;
                case INVTYPE_WEAPONOFFHAND:
                    equipSlot1 = EQUIPMENT_SLOT_OFFHAND;
                    break;
                case INVTYPE_THROWN:
                    equipSlot1 = EQUIPMENT_SLOT_RANGED;
                    break;
                }
                if (equipSlot1 != EquipmentSlots::EQUIPMENT_SLOT_END)
                {
                    equipmentMap[equipSlot1][levelRange][equipmentMap[equipSlot1][levelRange].size()] = it->first;
                    checkCount++;
                }
                if (equipSlot2 != EquipmentSlots::EQUIPMENT_SLOT_END)
                {
                    equipmentMap[equipSlot2][levelRange][equipmentMap[equipSlot1][levelRange].size()] = it->first;
                    checkCount++;
                }
            }
        }
    }
    sLog->outDetail("%d equipments loaded", checkCount);

    checkCount = 0;
    for (std::unordered_map<uint32, Quest*>::const_iterator it = sObjectMgr->GetQuestTemplates().begin(); it != sObjectMgr->GetQuestTemplates().end(); it++)
    {
        if (it->second->GetRequiredClasses() > 0)
        {
            if (it->second->GetRewSpell() > 0 || it->second->GetRewSpellCast() > 0)
            {
                spellQuestsMap[it->second->GetRequiredClasses()].insert(it->first);
                checkCount++;
            }
        }
    }
    sLog->outDetail("%d spell quests loaded", checkCount);

    QueryResult results = WorldDatabase.PQuery("SELECT CT.maxlevel, CI.map, CI.position_x, CI.position_y, CI.position_z FROM creature CI inner join creature_template CT on CI.id = CT.entry where CT.rank = 4 order by maxlevel");
    if (results)
    {
        sLog->outBasic("Loading rare mob teleport zone caches");
        do
        {
            Field* fields = results->Fetch();
            uint16 checkLevel = fields[0].GetUInt16();
            uint16 checkMap = fields[1].GetUInt16();
            float checkX = fields[2].GetFloat();
            float checkY = fields[3].GetFloat();
            float checkZ = fields[4].GetFloat();
            WorldLocation eachZone(checkMap, checkX, checkY, checkZ);
            uint16 levelRange = checkLevel / 10;
            teleportZoneCacheMap[levelRange][teleportZoneCacheMap[levelRange].size()] = eachZone;

            sLog->outBasic("Teleport cache %u, %f, %f, %f added", checkMap, checkX, checkY, checkZ);
        } while (results->NextRow());
    }


    sLog->outBasic("Puppet manager initialized");
}

void PuppetMgr::OnPlayerLogout(Player* player)
{
    for (std::unordered_map<uint32, PuppetAI*>::iterator it = activeAIMap.begin(); it != activeAIMap.end(); it++)
    {
        if (player == it->second->masterPlayer)
        {
            it->second->SetMaster(NULL);
            it->second->ResetStrategies();
            it->second->RandomTeleport();
            it->second->sourcePlayer->RemoveFromGroup();
        }
    }
}

void PuppetMgr::OnPlayerLogin(Player* player)
{

}

void PuppetMgr::LogoutAllPuppets()
{
    for (std::unordered_map<uint32, PuppetAI*>::iterator it = activeAIMap.begin(); it != activeAIMap.end(); it++)
    {
        Player* puppet = it->second->sourcePlayer;
        WorldSession * puppetWorldSessionPtr = puppet->GetSession();
        sLog->outBasic("Puppet %s logged out", puppet->GetName().c_str());
        puppetWorldSessionPtr->LogoutPlayer(true); // this will delete the bot Player object and PlayerbotAI object
        delete puppetWorldSessionPtr;  // finally delete the bot's WorldSession
    }
    activeAIMap.clear();
}

std::unordered_map<int, std::string> PuppetMgr::GenerateRandomPuppetNamesMap()
{
    std::unordered_map<int, std::string> result;

    QueryResult qr = WorldDatabase.Query("SELECT name_id, name FROM puppet_names order by rand()");
    if (qr)
    {
        int nameIndex = 0;
        do
        {
            Field* fields = qr->Fetch();
            int eachID = fields[0].GetInt32();
            std::string eachName = fields[1].GetString();
            result[nameIndex] = eachName;
            nameIndex++;
        } while (qr->NextRow());
    }
    else
    {
        sLog->outError("No names");
    }

    return result;
}

bool PuppetMgr::IsAlliance(uint8 race)
{
    return race == RACE_HUMAN || race == RACE_DWARF || race == RACE_NIGHTELF ||
        race == RACE_GNOME || race == Races::RACE_DRAENEI;
}

std::string PuppetMgr::GetRaceName(uint8 pmRace)
{
    return racesMap[pmRace];
}

std::string PuppetMgr::GetClassName(uint8 pmClass)
{
    return classesMap[pmClass];
}

std::string PuppetMgr::GetSpecialty(uint8 pmClass, uint8 pmTabIndex)
{
    return specialtyMap[pmClass][pmTabIndex];
}

void PuppetMgr::split(std::string& s, std::string& delim, std::vector< std::string >* ret)
{
    size_t last = 0;
    size_t index = s.find_first_of(delim, last);
    while (index != std::string::npos)
    {
        ret->push_back(s.substr(last, index - last));
        last = index + 1;
        index = s.find_first_of(delim, last);
    }
    if (index - last > 0)
    {
        ret->push_back(s.substr(last, index - last));
    }
}

std::string& PuppetMgr::replace_all_distinct(std::string& str, const std::string& old_value, const std::string& new_value)
{
    for (std::string::size_type pos(0); pos != std::string::npos; pos += new_value.length()) {
        if ((pos = str.find(old_value, pos)) != std::string::npos)
            str.replace(pos, old_value.length(), new_value);
        else   break;
    }
    return   str;
}
