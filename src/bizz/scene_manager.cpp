#include "scene_manager.h"
#include "common/logger.h"

SceneMgr::SceneMgr()
{
}

SceneMgr::~SceneMgr()
{
    CLEAR_MAP_DATA(m_sceneTable);
}

SceneMgr& SceneMgr::Instance(){
    static SceneMgr sceneMgr;
    return sceneMgr;
}

bool SceneMgr::Init()
{
    uint32_t mapIds[] = { 1, };

    for(uint8_t i = 0; i < sizeof(mapIds) / sizeof(uint32_t); ++i)
    {
        LOG_DEBUG("SceneMgr::init mapId [%d]", mapIds[i]);
        Scene* tmp = new Scene(mapIds[i]);
        if(!tmp->init())
        {
            LOG_DEBUG("SceneMgr::init map[%u] error", mapIds[i]);
            return false;
        }
        else
        {
            m_sceneTable.insert(std::pair<uint32_t,Scene*>(tmp->id(),tmp));
            LOG_DEBUG("SceneMgr::init scene[%u] ok", mapIds[i]);
        }
    }
    return true;
}

