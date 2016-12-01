#include "PlayScene.h"
#include "GameOverScene.h"
#include "Factory.h"
#include "Enemy.h"

USING_NS_CC;

using namespace CocosDenshion;
using namespace ui;

Enemy* Factory::createEnemy(ENEMYTYPE type)
{
	Enemy *enemy = NULL;
		switch(type)
		{
			case enemy0:
				enemy = new Enemy0();
				break; 
			case enemy2:
				enemy = new Enemy2();
				break;
			case enemyMove:
				enemy = new Enemy_Move();
				break;
			case enemyStable:
				enemy = new Enemy_Stable();
				break;
			default:
				return NULL;
		}	
		return enemy;
}
