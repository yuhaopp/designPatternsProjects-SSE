#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "GameDefine.h"
#include "Enemy.h"
USING_NS_CC;


typedef enum EnemyTypeTag
{
	enemy0,
	enemy2,
	enemyMove,
	enemyStable,
}ENEMYTYPE;

class Factory
{
public:
	Factory();
	virtual ~Factory();
	Enemy* createEnemy(ENEMYTYPE type);

}