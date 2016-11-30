#include "Enemy.h"
#include "cocos2d.h"

typedef enum EnemyTypeTag
{
	enemy0,
	enemy2,
	enemyMove,
	enemyStable,
}ENEMYTYPE;

void Enemy_Move(Point pos, int i)
{
	//enemy for four direction
	auto enemy = _factory->createEnemy(enemyMove);
	enemy->setPosition(pos);
	addChild(enemy);
	if (i == 1){
		auto moveBy_1 = MoveBy::create(1.5f, Vec2(-160, 0));
		auto moveBy_2 = MoveBy::create(1.5f, Vec2(160, 0));
		auto seq = Sequence::create(moveBy_1, moveBy_2, nullptr);
		auto repeat = RepeatForever::create(seq);

		enemy->runAction(repeat);
	}
	else if (i == 2){
		auto moveBy_1 = MoveBy::create(1.5f, Vec2(160, 0));
		auto moveBy_2 = MoveBy::create(1.5f, Vec2(-160, 0));
		auto seq = Sequence::create(moveBy_1, moveBy_2, nullptr);
		auto repeat = RepeatForever::create(seq);

		enemy->runAction(repeat);
	}
	else if (i == 3){
		auto moveBy_1 = MoveBy::create(1.5f, Vec2(0, -96));
		auto moveBy_2 = MoveBy::create(1.5f, Vec2(0, 96));
		auto seq = Sequence::create(moveBy_1, moveBy_2, nullptr);
		auto repeat = RepeatForever::create(seq);

		enemy->runAction(repeat);
	}
	else if (i == 4){
		auto moveBy_1 = MoveBy::create(1.5f, Vec2(0, 96));
		auto moveBy_2 = MoveBy::create(1.5f, Vec2(0, -96));
		auto seq = Sequence::create(moveBy_1, moveBy_2, nullptr);
		auto repeat = RepeatForever::create(seq);

		enemy->runAction(repeat);
	}
	unchanged_enemies.pushBack(enemy);
}

void addEnemy(Point pos)
{
	pos.x+=100 * rand_minus1_1()
	pos.y+=100 * rand_minus1_1();
	auto enemy = _factory->createEnemy(enemy0);
	enemy->setPosition(pos);
	this->addChild(enemy);
	this->moveEnemy(enemy);

	_enemies.pushBack(enemy);

}

void addEnemy_2(Point pos)  
{
	pos.x += 100 * rand_minus1_1();
	pos.y += 100 * rand_minus1_1();   
	auto enemy = _factory->createEnemy(enemy2);
	enemy->setPosition(pos);
	this->addChild(enemy);
	this->moveEnemy(enemy);

	_enemies_2.pushBack(enemy);
}

void enemyMoveFinished(Object *pSender)
{
	Sprite *enemy = (Sprite *)pSender;

	this->moveEnemy(enemy);
}

void moveEnemy(Sprite *enemy)
{
	//speed
	actualDuration = 0.25f;
	if (poison == true)
		actualDuration = 0.15f;

	// Create the actions
	auto position = (_player->getPosition() - enemy->getPosition()).getNormalized() * 10;
	auto actionMove = MoveBy::create(actualDuration, position);
	auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(PlayScene::enemyMoveFinished, this));
	enemy->runAction(Sequence::create(actionMove, actionMoveDone, NULL));
}