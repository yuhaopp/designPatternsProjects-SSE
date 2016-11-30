#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "GameDefine.h"
USING_NS_CC;

class PlayScene;

class PlayScene : public cocos2d::Layer
{
protected:
	cocos2d::TMXTiledMap *_tileMap;
	cocos2d::TMXLayer *_background;
	cocos2d::Sprite *_player;
	cocos2d::Sprite *helper;
	cocos2d::TMXLayer *_meta;
	cocos2d::TMXLayer *_foreground_1;
	cocos2d::TMXLayer *_foreground_2;
	cocos2d::TMXLayer *_foreground_3;
	cocos2d::TMXLayer *_foreground_4;
	cocos2d::TMXLayer *_foreground_5;
	cocos2d::TMXLayer *_foreground_6;

	float actualDuration;

	int using_time=5;
	int heroHp = 3;

	bool group_2=true;
	bool group_3=true;
	bool done_2=false;
	bool done_3=false;
	bool guard_done=false;

	bool get_key = false;
	bool move_guard = false;
	bool speedup = false;
	bool get_helper = false;
	bool get_bullet = false;
	bool show_words = false;

	cocos2d::Point special_pos;

	cocos2d::Vector<cocos2d::Sprite *> stable_enemies;
	cocos2d::Vector<cocos2d::Sprite *> unchanged_enemies;
	cocos2d::Vector<cocos2d::Sprite *> _enemies;
	cocos2d::Vector<cocos2d::Sprite *> _enemies_2;
	cocos2d::Vector<cocos2d::Sprite *> _projectiles;

	static PlaySceneCover *_cover;
public:
	virtual bool init();
	CREATE_FUNC(PlayScene);

	void ViewPoint(cocos2d::Point position);
	void PlayerPosition(cocos2d::Point position);

	cocos2d::Point tileToPosition(cocos2d::Point position);
	void projectileMoveFinished(Object *pSender);
	
	void testCollisions(float dt);
	void test_super(float dt);
	void test_guard(float dt);
	void unchanged_test(float dt);
	
	void bullet(float dt);
	void myusingtime(float dt);
	void myhelper(float dt);
	void helper_get(float dt);
	
	void menuPauseCallback(Object* pSender);
};

class PlayScene1 : public PlayScene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(PlayScene1);
};

#endif // __GameMenu_SCENE_H__

