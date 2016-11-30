#ifndef __GAME_HUD_H__
#define __GAME_HUD_H__
#include "cocos2d.h"

class GameHUD: public cocos2d:Layer {
    CREATE_FUNC(PlaySceneCover);
    bool init();

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event，string up, string down, string left, string right);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	void Up();
	void Down();
	void Left();
	void Right();

	cocos2d::Label *labelTime;
	cocos2d::Label *score;
	cocos2d::Label *state;
	void myclock(float dt);
	void myscore(float dt);
	void mystate(float dt);
	CC_SYNTHESIZE(PlayScene*, _gameLayer, GameLayer);

	void win();
	void lose();
}