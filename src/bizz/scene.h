#ifndef __SCENE_H__
#define __SCENE_H__

#include "protobuf/scene_map.pb.h"
#include "protobuf/cs.pb.h"
#include "protobuf/Protocol.pb.h"

#include "common/common.h"

using namespace NetProto;

class Scene
{
    public:
        Scene(uint32_t mapId);
        ~Scene();
    public:
        inline uint32_t id() { return m_id; }
        inline NetProto::SceneMap& GetSceneMap(){ return m_sceneMap; }
    public:
        bool init();
        void Show();
        Scene Clone();
        GS2CEnterScene ToGS2CEnterScene();

    private:
        uint32_t m_id;   // map config id : 1: home map 2: courtyard
	    NetProto::SceneMap m_sceneMap;
};

#endif //__SCENE_H__
