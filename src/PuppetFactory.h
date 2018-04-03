#ifndef PUPPETFACTORY_H
#define PUPPETFACTORY_H

#include "PuppetPCH.h"
#include "PuppetConfig.h"
#include "AccountMgr.h"
#include "DBCStore.h"
#include "SharedDefines.h"
#include "PuppetMgr.h"

class Player;
class PuppetMgr;
class ChatHandler;

using namespace std;

class PuppetFactory
{
public:
    PuppetFactory(Player* pmPuppet, uint32 pmLevel)
    {
        puppet = pmPuppet;
        level = pmLevel;
    }

    void Randomize();

private:        
    void InitEquipment();     
    void InitSkills();
    void SetRandomSkill(uint16 id);
    void InitSpells();
    void InitTalents();
    void InitTalents(uint32 specNo);    
    void InitPet();    
    void InitAttachment();
    void InitMounts();
    void InitPotions();
    void InitFoodAndDrink();
    void InitBags();
    void InitInventory();

private:
    Player* puppet;
    uint32 level;
    uint32 itemQuality;
    static uint32 tradeSkills[];
    static list<uint32> classQuestIds;
};
#endif
