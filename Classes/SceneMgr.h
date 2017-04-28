
#ifndef __SceneMgr_h__
#define __SceneMgr_h__

#include "RtcScene.h"

class SceneMgr
{
public :
    static SceneMgr *getInstance();
    bool addScene(RtcScene* scene, std::string title);
    bool clear();
public:
    typedef std::pair<RtcScene*, std::string> SceneTitlePair;
    std::vector<SceneTitlePair> getScenes();

    struct RtcEngineConfig {
        agora::rtc::CHANNEL_PROFILE_TYPE cft = agora::rtc::CHANNEL_PROFILE_GAME_FREE_MODE;
        agora::rtc::CLIENT_ROLE_TYPE crt = agora::rtc::CLIENT_ROLE_TYPE::CLIENT_ROLE_BROADCASTER;

        std::string channel;

        long long ts = 0;

        bool muted = false;

        bool useMixing = false;

        float mLocalPitch = 1.0;
        unsigned short mVoiceVolume = 100;
        unsigned short mMixingVolume = 100;
        unsigned short mEffectVolume = 100;
    };

    RtcEngineConfig config;

private:
    std::vector<SceneTitlePair> _sections;
};
#endif /* __SceneMgr_h__ */
