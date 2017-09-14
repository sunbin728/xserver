#ifndef __SCENEMGR_H__
#define __SCENEMGR_H__

#include "scene.h"

typedef  std::map<uint32_t,Scene*> SceneTable;

class SceneMgr
{
    private:
        SceneMgr();
        ~SceneMgr();
        SceneMgr(const SceneMgr &sceneMgr);
        SceneMgr& operator=(const SceneMgr &sceneMgr);

    public:
        static SceneMgr& Instance();

        Scene* operator [](uint32_t i)
        {
            if(m_sceneTable.find(i) != m_sceneTable.end())
            {
                return m_sceneTable[i];
            }
            return NULL;
        }

        bool Init();

        Scene* DefaultScene(){
            return operator[](1);
        }

    private:
        SceneTable m_sceneTable;
};

#endif //__SCENEMGR_H__
