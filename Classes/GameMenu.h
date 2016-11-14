#ifndef __GAMEMENU_SCENE_H__
#define __GAMEMENU_SCENE_H__

#include "cocos2d.h"
#include"SimpleAudioEngine.h"
#include"PlayScene.h"
#include"SettingScene.h"
#include"HelpScene.h"
#include"LevelScene.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;

class GameMenu : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
	void menuItemHelpCallback(cocos2d::Ref* pSender);
	void menuItemPlayCallback(cocos2d::Ref* pSender);
	void menuItemSettingCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(GameMenu);
};
#endif // __GAMEMENU_SCENE_H__
