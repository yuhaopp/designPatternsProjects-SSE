#include"cocos2d.h"

Public class Enemy{
    void PlayScene::addEnemy(Point pos);
    void Enemy_Move(Point pos, int i);
    void PlayScene::addEnemy_2(Point pos);
    void PlayScene::enemyMoveFinished(Object *pSender);
    void PlayScene::moveEnemy(Sprite *enemy);
}

class Enemy0:public Enemy
{
public:
	Enemy0(){return new Enemy("enemy_0.png");}
}

class Enemy2:public Enemy
{
public:
	Enemy2(){return new Enemy("enemy_2.png");}
}

class Enemy_Move:public Enemy
{
public:
	Enemy_Move(){return new Enemy("enemy_move.png");}
}

class Enemy_Stable:public Enemy
{
public:
	Enemy_Move(){return new Enemy("enemy_stable.png");}
}