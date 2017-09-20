#include "global_manager.h"

GlobalManager::GlobalManager()
{
}

GlobalManager::~GlobalManager()
{
}

GlobalManager& GlobalManager::Instance(){
    static GlobalManager globalManager;
    return globalManager;
}
