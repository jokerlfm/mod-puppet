#include "PuppetFactory.h"

using namespace std;

uint32 PuppetFactory::tradeSkills[] =
{
    SKILL_ALCHEMY,
    SKILL_ENCHANTING,
    SKILL_SKINNING,
    SKILL_TAILORING,
    SKILL_LEATHERWORKING,
    SKILL_ENGINEERING,
    SKILL_HERBALISM,
    SKILL_MINING,
    SKILL_BLACKSMITHING,
    SKILL_COOKING,
    SKILL_FIRST_AID,
    SKILL_FISHING
};

list<uint32> PuppetFactory::classQuestIds;

void PuppetFactory::Randomize()
{
    sLog->outBasic("Preparing to randomize...");
    if (puppet->isDead())
    {
        puppet->ResurrectPlayer(1.0f, false);
    }
    puppet->RemoveAllAuras();
    puppet->CombatStop(true);
    puppet->SetLevel(1);
    puppet->resetTalents(true);
    puppet->GiveLevel(level);
    puppet->SetUInt32Value(PLAYER_XP, 0);
    puppet->SaveToDB(false, false);

    sLog->outBasic("Initializing skills...");
    InitSkills();

    sLog->outBasic("Initializing bags...");
    InitBags();

    sLog->outBasic("Initializing inventory...");
    InitInventory();

    sLog->outBasic("Initializing spells...");
    InitSpells();

    sLog->outBasic("Initializing talents...");
    InitTalents();

    sLog->outBasic("Initializing food...");
    InitFoodAndDrink();

    sLog->outBasic("Initializing potions...");
    InitPotions();

    sLog->outBasic("Initializing equipmemt...");
    InitEquipment();

    sLog->outBasic("Initializing attachments...");
    InitAttachment();

    sLog->outBasic("Initializing pet...");
    InitPet();

    sLog->outBasic("Initializing mounts...");
    InitMounts();

    sLog->outBasic("Saving to DB...");
    puppet->SetMoney(urand(level * 1000, level * 5 * 1000));
    puppet->SaveToDB(false, false);

    CharacterDatabase.PExecute("INSERT INTO puppet_info (`character_guid`, `specialty`) VALUES (%d, '%s')", puppet->GetGUID(), sPuppetMgr.activeAIMap[puppet->GetGUIDLow()]->specialty.c_str());
    sLog->outBasic("Done.");
}

void PuppetFactory::InitPet()
{
    if (puppet->getClass() != CLASS_HUNTER)
        return;

    while (true)
    {
        uint32 creatureEntry = urand(0, sPuppetMgr.tamableCreatureMap.size());
        creatureEntry = sPuppetMgr.tamableCreatureMap[creatureEntry];

        Map* map = puppet->GetMap();
        if (!map)
            return;

        Pet* pet = new Pet(puppet, HUNTER_PET);
        if (!pet->Create(sObjectMgr->GenerateLowGuid(HighGuid::HIGHGUID_PET), map, 0, creatureEntry, 0))
        {
            delete pet;
            pet = NULL;
            sLog->outError("Puppet %s: assign pet failed, try again.", puppet->GetName().c_str());
            continue;
        }

        pet->UpdatePosition(puppet->GetPositionX(), puppet->GetPositionY(), puppet->GetPositionZ(), puppet->GetOrientation());
        pet->SavePetToDB(PET_SAVE_AS_CURRENT, false);
        sLog->outDetail("Pet %d created", creatureEntry);

        puppet->InitTamedPet(pet, puppet->getLevel(), 0);
        puppet->SetMinion(pet, true);
        puppet->GetMap()->AddToMap(pet->ToCreature());
        sLog->outDetail("Puppet %s: assign pet %d", puppet->GetName().c_str(), creatureEntry);

        for (PetSpellMap::const_iterator itr = pet->m_spells.begin(); itr != pet->m_spells.end(); ++itr)
        {
            if (itr->second.state == PETSPELL_REMOVED)
                continue;

            uint32 spellId = itr->first;
            const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
            if (spellInfo->IsPassive())
                continue;

            pet->ToggleAutocast(spellInfo, true);
        }
        break;
    }
}

void PuppetFactory::InitTalents()
{
    uint32 specNo1 = urand(0, 2);
    // debug
    specNo1 = 2;
    sPuppetMgr.activeAIMap[puppet->GetGUIDLow()]->specialty = sPuppetMgr.GetSpecialty(puppet->getClass(), specNo1);

    InitTalents(specNo1);

    if (puppet->GetFreeTalentPoints())
    {
        uint32 specNo2 = (specNo1 + urand(1, 2)) % 3;
        InitTalents(specNo2);
    }
}

void PuppetFactory::InitEquipment()
{
    uint32 randomStartIndex = 0;
    bool useTwoHand = false, useShield = false, useStaff = false, useDual = false, useWand = false, useRange = false, usePolearm = false, useThrow = false;
    uint8 puppetCLass = puppet->getClass();
    if (puppetCLass == Classes::CLASS_WARRIOR)
    {
        useTwoHand = (urand(0, 3) == 3 ? true : false);
        if (!useTwoHand)
        {
            useShield = true;
        }
        useRange = true;
    }
    else if (puppetCLass == Classes::CLASS_PALADIN)
    {
        useTwoHand = (urand(0, 3) == 3 ? true : false);
    }
    else if (puppetCLass == Classes::CLASS_DRUID || puppetCLass == Classes::CLASS_MAGE || puppetCLass == Classes::CLASS_PRIEST || puppetCLass == Classes::CLASS_WARLOCK)
    {
        useStaff = true;
        useWand = true;
    }
    else if (puppetCLass == Classes::CLASS_DEATH_KNIGHT)
    {
        useTwoHand = true;
    }
    else if (puppetCLass == Classes::CLASS_HUNTER)
    {
        usePolearm = true;
        useRange = true;
    }
    else if (puppetCLass == Classes::CLASS_ROGUE)
    {
        useDual = true;
        useThrow = true;
    }

    std::string selectedEquipmentName = "";

    uint8 checkSlot = EquipmentSlots::EQUIPMENT_SLOT_HEAD;
    while (checkSlot <= EquipmentSlots::EQUIPMENT_SLOT_RANGED)
    {
        puppet->DestroyItem(INVENTORY_SLOT_BAG_0, checkSlot, true);
        checkSlot++;
    }

    checkSlot = EquipmentSlots::EQUIPMENT_SLOT_HEAD;
    while (checkSlot <= EquipmentSlots::EQUIPMENT_SLOT_RANGED)
    {
        bool equipmentSelected = false;
        int checkLevelRange = puppet->getLevel() / 10;
        checkLevelRange -= 1;
        while (checkLevelRange >= 0)
        {
            std::unordered_map<uint32, uint32> targetEquipments = sPuppetMgr.equipmentMap[checkSlot][checkLevelRange];
            int totalSize = targetEquipments.size();
            randomStartIndex = urand(0, totalSize - 1);
            for (int checkSize = 0; checkSize < totalSize; checkSize++)
            {
                randomStartIndex++;
                if (randomStartIndex >= totalSize)
                {
                    randomStartIndex = 0;
                }
                const ItemTemplate* itProto = sObjectMgr->GetItemTemplate(targetEquipments[randomStartIndex]);
                if (itProto)
                {
                    if (checkSlot == EquipmentSlots::EQUIPMENT_SLOT_MAINHAND)
                    {
                        if (itProto->Class != ItemClass::ITEM_CLASS_WEAPON)
                        {
                            continue;
                        }
                        if (useStaff)
                        {
                            if (itProto->SubClass != ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_STAFF)
                            {
                                continue;
                            }
                        }
                        else if (useTwoHand)
                        {
                            if (itProto->SubClass != ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_AXE2&&itProto->SubClass != ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_SWORD2&&itProto->SubClass != ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_MACE2)
                            {
                                continue;
                            }
                        }
                        else if (usePolearm)
                        {
                            if (itProto->SubClass != ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_POLEARM)
                            {
                                continue;
                            }
                        }
                    }
                    else  if (checkSlot == EquipmentSlots::EQUIPMENT_SLOT_OFFHAND)
                    {
                        if (useDual)
                        {
                            if (itProto->Class != ItemClass::ITEM_CLASS_WEAPON)
                            {
                                continue;
                            }
                        }
                        else if (useShield)
                        {
                            if (itProto->Class != ItemClass::ITEM_CLASS_ARMOR)
                            {
                                continue;
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else  if (checkSlot == EquipmentSlots::EQUIPMENT_SLOT_RANGED)
                    {
                        if (useRange)
                        {
                            if (itProto->SubClass != ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_BOW&&itProto->SubClass != ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_GUN&&itProto->SubClass != ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_CROSSBOW)
                            {
                                continue;
                            }
                        }
                        else if (useThrow)
                        {
                            if (itProto->SubClass != ItemSubclassWeapon::ITEM_SUBCLASS_WEAPON_THROWN)
                            {
                                continue;
                            }
                        }
                    }
                    else if (checkSlot == EquipmentSlots::EQUIPMENT_SLOT_HEAD || checkSlot == EquipmentSlots::EQUIPMENT_SLOT_SHOULDERS || checkSlot == EquipmentSlots::EQUIPMENT_SLOT_BODY || checkSlot == EquipmentSlots::EQUIPMENT_SLOT_CHEST ||
                        checkSlot == EquipmentSlots::EQUIPMENT_SLOT_WAIST || checkSlot == EquipmentSlots::EQUIPMENT_SLOT_LEGS || checkSlot == EquipmentSlots::EQUIPMENT_SLOT_FEET || checkSlot == EquipmentSlots::EQUIPMENT_SLOT_WRISTS ||
                        checkSlot == EquipmentSlots::EQUIPMENT_SLOT_HANDS)
                    {
                        if (itProto->SubClass == ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_PLATE)
                        {
                            if (!puppet->HasSkill(SKILL_PLATE_MAIL))
                            {
                                continue;
                            }
                        }
                        else if (itProto->SubClass == ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_MAIL)
                        {
                            if (!puppet->HasSkill(SKILL_MAIL))
                            {
                                continue;
                            }
                        }
                        else if (itProto->SubClass == ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_LEATHER)
                        {
                            if (!puppet->HasSkill(SKILL_LEATHER))
                            {
                                continue;
                            }
                        }
                    }

                    uint16 eDest;
                    InventoryResult msg = puppet->CanEquipNewItem(NULL_SLOT, eDest, itProto->ItemId, true);
                    if (msg == EQUIP_ERR_OK)
                    {
                        selectedEquipmentName = itProto->Name1;
                        Item* equipedItem = puppet->EquipNewItem(eDest, itProto->ItemId, true);
                        equipedItem->SetItemRandomProperties(itProto->RandomProperty);
                        puppet->AutoUnequipOffhandIfNeed();
                        equipedItem->AddToUpdateQueueOf(puppet);
                        equipmentSelected = true;
                        break;
                    }
                }
            }
            if (equipmentSelected)
            {
                break;
            }
            checkLevelRange--;
        }

        if (equipmentSelected)
        {
            sLog->outDetail("Puppet %s: assign %s at slot %d", puppet->GetName().c_str(), selectedEquipmentName.c_str(), checkSlot);
        }
        else
        {
            sLog->outDetail("Puppet %s: assign at slot %d failed", puppet->GetName().c_str(), checkSlot);
        }

        checkSlot++;
    }
}

void PuppetFactory::InitBags()
{
    // Traveler's Backpack
    uint32 bagEntry = 4500;
    puppet->StoreNewItemInBestSlots(bagEntry, 4);
}

#define PLAYER_SKILL_INDEX(x)       (PLAYER_SKILL_INFO_1_1 + ((x)*3))
void PuppetFactory::InitSkills()
{
    CreatureTemplateContainer const* creatureTemplateContainer = sObjectMgr->GetCreatureTemplates();
    for (CreatureTemplateContainer::const_iterator i = creatureTemplateContainer->begin(); i != creatureTemplateContainer->end(); ++i)
    {
        CreatureTemplate const& co = i->second;

        if (co.trainer_type != TRAINER_TYPE_TRADESKILLS)
            continue;

        uint32 trainerId = co.Entry;

        TrainerSpellData const* trainer_spells = sObjectMgr->GetNpcTrainerSpells(trainerId);

        if (!trainer_spells)
            continue;

        for (TrainerSpellMap::const_iterator itr = trainer_spells->spellList.begin(); itr != trainer_spells->spellList.end(); ++itr)
        {
            TrainerSpell const* tSpell = &itr->second;

            if (!tSpell)
                continue;

            TrainerSpellState state = puppet->GetTrainerSpellState(tSpell);
            if (state != TRAINER_SPELL_GREEN)
                continue;

            puppet->learnSpell(tSpell->spell);
        }
    }
    puppet->UpdateSkillsToMaxSkillsForLevel();
}

void PuppetFactory::SetRandomSkill(uint16 id)
{
    uint32 maxValue = level * 5;
    uint32 curValue = urand(maxValue - level, maxValue);
    puppet->SetSkill(id, 0, curValue, maxValue);
}

void PuppetFactory::InitSpells()
{
    puppet->learnDefaultSpells();

    CreatureTemplateContainer const* creatureTemplateContainer = sObjectMgr->GetCreatureTemplates();
    for (CreatureTemplateContainer::const_iterator i = creatureTemplateContainer->begin(); i != creatureTemplateContainer->end(); ++i)
    {
        CreatureTemplate const& co = i->second;

        if (co.trainer_type != TRAINER_TYPE_CLASS)
            continue;
        if (co.trainer_class != puppet->getClass())
            continue;

        uint32 trainerId = co.Entry;

        TrainerSpellData const* trainer_spells = sObjectMgr->GetNpcTrainerSpells(trainerId);

        if (!trainer_spells)
            continue;

        for (TrainerSpellMap::const_iterator itr = trainer_spells->spellList.begin(); itr != trainer_spells->spellList.end(); ++itr)
        {
            TrainerSpell const* tSpell = &itr->second;

            if (!tSpell)
                continue;

            TrainerSpellState state = puppet->GetTrainerSpellState(tSpell);
            if (state != TRAINER_SPELL_GREEN)
                continue;

            puppet->learnSpell(tSpell->spell);
        }
    }

    for (std::unordered_map <uint32, std::set<uint32>>::iterator itr = sPuppetMgr.spellQuestsMap.begin(); itr != sPuppetMgr.spellQuestsMap.end(); ++itr)
    {
        uint32 requiredClasses = itr->first;
        if (requiredClasses == 0)
        {
            continue;
        }
        if ((requiredClasses & puppet->getClassMask()) == 0)
        {
            continue;
        }
        for (std::set<uint32>::iterator it = itr->second.begin(); it != itr->second.end(); it++)
        {
            uint32 checkQuestID = *it;
            while (true)
            {
                const Quest* checkQ = sObjectMgr->GetQuestTemplate(checkQuestID);
                puppet->learnQuestRewardedSpells(checkQ);
                // reward quest spells
                if (checkQ->GetNextQuestId() > 0)
                {
                    checkQuestID = checkQ->GetNextQuestId();
                    checkQ = NULL;
                }
                else
                {
                    checkQ = NULL;
                    break;
                }
            }
        }
    }
}

void PuppetFactory::InitTalents(uint32 specNo)
{
    uint32 classMask = puppet->getClassMask();

    map<uint32, vector<TalentEntry const*> > spells;
    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        TalentEntry const *talentInfo = sTalentStore.LookupEntry(i);
        if (!talentInfo)
            continue;

        TalentTabEntry const *talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);
        if (!talentTabInfo || talentTabInfo->tabpage != specNo)
            continue;

        if ((classMask & talentTabInfo->ClassMask) == 0)
            continue;

        spells[talentInfo->Row].push_back(talentInfo);
    }

    uint32 freePoints = puppet->GetFreeTalentPoints();
    for (map<uint32, vector<TalentEntry const*> >::iterator i = spells.begin(); i != spells.end(); ++i)
    {
        vector<TalentEntry const*> &spells = i->second;
        if (spells.empty())
        {
            sLog->outError("%s: No spells for talent row %d", puppet->GetName().c_str(), i->first);
            continue;
        }

        int attemptCount = 0;
        while (!spells.empty() && (int)freePoints - (int)puppet->GetFreeTalentPoints() < 5 && attemptCount++ < 3 && puppet->GetFreeTalentPoints())
        {
            int index = urand(0, spells.size() - 1);
            TalentEntry const *talentInfo = spells[index];
            for (int rank = 0; rank < MAX_TALENT_RANK && puppet->GetFreeTalentPoints(); ++rank)
            {
                uint32 spellId = talentInfo->RankID[rank];
                if (!spellId)
                    continue;
                int maxRank = 0;
                for (int rank = 0; rank < min((uint32)MAX_TALENT_RANK, puppet->GetFreeTalentPoints()); ++rank)
                {
                    uint32 spellId = talentInfo->RankID[rank];
                    if (!spellId)
                        continue;

                    maxRank = rank;
                }

                puppet->LearnTalent(talentInfo->TalentID, maxRank);
            }
            spells.erase(spells.begin() + index);
        }

        freePoints = puppet->GetFreeTalentPoints();
    }
}

void PuppetFactory::InitAttachment()
{
    if (puppet->getClass() == CLASS_HUNTER || puppet->getClass() == CLASS_WARRIOR)
    {
        Item* const pItem = puppet->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
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

        uint32 checkLevel = puppet->getLevel();
        while (checkLevel > 0)
        {
            if (subClass == ITEM_SUBCLASS_ARROW)
            {
                if (sPuppetMgr.arrowMap.find(checkLevel) == sPuppetMgr.arrowMap.end())
                {
                    checkLevel--;
                    continue;
                }
                puppet->StoreNewItemInBestSlots(sPuppetMgr.arrowMap[checkLevel], 100);
                puppet->SetAmmo(sPuppetMgr.arrowMap[checkLevel]);
                break;
            }
            else
            {
                if (sPuppetMgr.bulletMap.find(checkLevel) == sPuppetMgr.bulletMap.end())
                {
                    checkLevel--;
                    continue;
                }
                puppet->StoreNewItemInBestSlots(sPuppetMgr.bulletMap[checkLevel], 100);
                puppet->SetAmmo(sPuppetMgr.bulletMap[checkLevel]);
                break;
            }
        }
    }
    else if (puppet->getClass() == CLASS_WARLOCK)
    {
        uint32 soulShardEntry = 6265;
        puppet->StoreNewItemInBestSlots(soulShardEntry, 10);
    }
}

void PuppetFactory::InitMounts()
{
    if (puppet->getLevel() >= 70)
        puppet->SetSkill(SKILL_RIDING, 0, 300, 300);
    else if (puppet->getLevel() >= 60)
        puppet->SetSkill(SKILL_RIDING, 0, 225, 225);
    else if (puppet->getLevel() >= 40)
        puppet->SetSkill(SKILL_RIDING, 0, 150, 150);
    else if (puppet->getLevel() >= 20)
        puppet->SetSkill(SKILL_RIDING, 0, 75, 75);

    map<int32, vector<uint32> > spells;

    for (uint32 spellId = 0; spellId < sSpellStore.GetNumRows(); ++spellId)
    {
        SpellEntry const *pSpellEntry = sSpellStore.LookupEntry(spellId);
        const SpellInfo* pSpellInfo = sSpellMgr->GetSpellInfo(spellId);
        if (!pSpellInfo || pSpellEntry)
        {
            continue;
        }

        if (pSpellEntry->EffectApplyAuraName[0] != SPELL_AURA_MOUNTED)
            continue;

        if (pSpellInfo->CalcCastTime() < 500 || pSpellInfo->GetDuration() != -1)
            continue;

        int32 effect = max(pSpellEntry->EffectBasePoints[1], pSpellEntry->EffectBasePoints[2]);
        if (effect < 50)
            continue;

        spells[effect].push_back(spellId);
    }

    for (uint32 type = 0; type < 2; ++type)
    {
        for (map<int32, vector<uint32> >::iterator i = spells.begin(); i != spells.end(); ++i)
        {
            int32 effect = i->first;
            vector<uint32>& ids = i->second;
            uint32 index = urand(0, ids.size() - 1);
            if (index >= ids.size())
                continue;

            puppet->learnSpell(ids[index]);
        }
    }
}

void PuppetFactory::InitPotions()
{
    uint32 checkLevel = puppet->getLevel();
    while (checkLevel > 0)
    {
        if (sPuppetMgr.healthPotionMap.find(checkLevel) == sPuppetMgr.healthPotionMap.end())
        {
            checkLevel--;
            continue;
        }
        puppet->StoreNewItemInBestSlots(sPuppetMgr.healthPotionMap[checkLevel], 20);
        break;
    }

    if (puppet->getClass() != Classes::CLASS_WARRIOR&&puppet->getClass() != Classes::CLASS_ROGUE&&puppet->getClass() != Classes::CLASS_DEATH_KNIGHT)
    {
        checkLevel = puppet->getLevel();
        while (checkLevel > 0)
        {
            if (sPuppetMgr.manaPotionMap.find(checkLevel) == sPuppetMgr.manaPotionMap.end())
            {
                checkLevel--;
                continue;
            }
            puppet->StoreNewItemInBestSlots(sPuppetMgr.manaPotionMap[checkLevel], 20);
            break;
        }
    }
}

void PuppetFactory::InitFoodAndDrink()
{
    uint32 checkLevel = puppet->getLevel();
    while (checkLevel > 0)
    {
        if (sPuppetMgr.foodMap.find(checkLevel) == sPuppetMgr.foodMap.end())
        {
            checkLevel--;
            continue;
        }
        puppet->StoreNewItemInBestSlots(sPuppetMgr.foodMap[checkLevel], 20);
        break;
    }

    if (puppet->getClass() != Classes::CLASS_WARRIOR&&puppet->getClass() != Classes::CLASS_ROGUE&&puppet->getClass() != Classes::CLASS_DEATH_KNIGHT)
    {
        checkLevel = puppet->getLevel();
        while (checkLevel > 0)
        {
            if (sPuppetMgr.drinkMap.find(checkLevel) == sPuppetMgr.drinkMap.end())
            {
                checkLevel--;
                continue;
            }
            puppet->StoreNewItemInBestSlots(sPuppetMgr.drinkMap[checkLevel], 20);
            break;
        }
    }
}

void PuppetFactory::InitInventory()
{
    if (puppet->HasSkill(SKILL_MINING)) {
        // Mining Pick
        puppet->StoreNewItemInBestSlots(2901, 1);
    }
    if (puppet->HasSkill(SKILL_BLACKSMITHING) || puppet->HasSkill(SKILL_ENGINEERING)) {
        // Blacksmith Hammer
        puppet->StoreNewItemInBestSlots(5956, 1);
    }
    if (puppet->HasSkill(SKILL_ENGINEERING)) {
        // Arclight Spanner
        puppet->StoreNewItemInBestSlots(6219, 1);
    }
    if (puppet->HasSkill(SKILL_ENCHANTING)) {
        // Runed Arcanite Rod
        puppet->StoreNewItemInBestSlots(16207, 1);
    }
    if (puppet->HasSkill(SKILL_SKINNING)) {
        // Skinning Knife
        puppet->StoreNewItemInBestSlots(7005, 1);
    }
}
