#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
class KeyboardSettingScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void loadUI();
	void keyEventup(Ref*, TouchEventType type);
	void keyEventdown(Ref*, TouchEventType type);
	void keyEventleft(Ref*, TouchEventType type);
	void keyEventright(Ref*, TouchEventType type);
	CREATE_FUNC(KeyboardSettingScene);
};