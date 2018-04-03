#include "PuppetConfig.h"

using namespace std;

PuppetConfig::PuppetConfig()
{
}

bool PuppetConfig::Initialize()
{
    sLog->outBasic("Initializing Puppet system.");

    enabled = sConfigMgr->GetIntDefault("Puppet.Enabled", 0) == 0 ? false : true;
    if (!enabled)
    {
        sLog->outBasic("Puppet is Disabled.");
        return false;
    }

    reactDelay = sConfigMgr->GetIntDefault("Puppet.ReactDelay", 500);
    randomPuppetMinLevel = sConfigMgr->GetIntDefault("Puppet.RandomPuppetMinLevel", 20);
    randomPuppetMaxLevel = sConfigMgr->GetIntDefault("Puppet.RandomPuppetMaxLevel", 60);
    randomPuppetAccountPrefix = sConfigMgr->GetStringDefault("Puppet.RandomPuppetAccountPrefix", "puppet");
    randomPuppetAccountCount = sConfigMgr->GetIntDefault("Puppet.RandomPuppetAccountCount", 50);
    deleteRandomPuppetAccounts = sConfigMgr->GetBoolDefault("Puppet.DeleteRandomPuppetAccounts", false);
    tellAI = sConfigMgr->GetBoolDefault("Puppet.TellAI", false);

    return true;
}
