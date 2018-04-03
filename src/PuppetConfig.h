#ifndef PUPPETCONFIG_H
#define PUPPETCONFIG_H

#include "PuppetPCH.h"
#include "PuppetMgr.h"
#include "Config.h"

class Player;
class PuppetMgr;
class ChatHandler;

class PuppetConfig
{
public:
    PuppetConfig();
    static PuppetConfig& instance()
    {
        static PuppetConfig instance;
        return instance;
    }

public:
    bool Initialize();

    bool enabled;
    std::string randomPuppetAccountPrefix;
    bool deleteRandomPuppetAccounts;
    uint32 randomPuppetAccountCount;
    uint32 randomPuppetMinLevel, randomPuppetMaxLevel;    
    int reactDelay;
    bool tellAI;
};

#define sPuppetConfig PuppetConfig::instance()

#endif
