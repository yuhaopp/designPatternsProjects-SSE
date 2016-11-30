#include "GameHUD.h"
#include "PlayScene.h"

using namespace cocos2d;

bool GameHUD::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	TTFConfig config("fonts/DFT_YYD.ttf", 30);
	
	labelTime = Label::createWithTTF(config, StringUtils::format("Time: %d ", m_time));
	labelTime->setPosition(Vec2(visibleSize.width / 2 + 300, visibleSize.height - 32));
	labelTime->setTag(11);
	labelTime->setColor(Color3B::BLUE);
	addChild(labelTime);

	score = Label::createWithTTF(config, StringUtils::format("SCORE: %d/15", _numCollected));
	score->setPosition(Vec2(visibleSize.width / 2 + 300, visibleSize.height - 64));
	score->setTag(12);
	score->setColor(Color3B::BLUE);
	addChild(score);

	state = Label::createWithTTF(config, StringUtils::format("STATE: %s", "NORMAL"));
	state->setPosition(Vec2(visibleSize.width / 2 + 300, visibleSize.height - 96));
	state->setTag(13);
	state->setColor(Color3B::BLUE);
	addChild(state);

	schedule(schedule_selector(PlaySceneCover::myclock), 1.0f);
	schedule(schedule_selector(PlaySceneCover::mystate));
	schedule(schedule_selector(PlaySceneCover::myscore));

	MenuItemImage *pCloseItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(PlayScene::menuPauseCallback));

	pCloseItem->setPosition(Vec2(visibleSize.width - pCloseItem->getContentSize().width / 2,
		visibleSize.height - pCloseItem->getContentSize().height / 2));

	// create menu, it's an autorelease object  
	Menu* pMenu = Menu::create(pCloseItem, NULL);
	pMenu->setPosition(Vec2::ZERO);
	this->addChild(pMenu, 1);
}

void PlayScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event, string up, string down, string left, string right)
{
	auto playerPos = _player->getPosition();

	if (EventKeyboard::KeyCode::up == keyCode)
	{
		Up();
	}
	if (EventKeyboard::KeyCode::down == keyCode)
	{
		Down();
	}
	if (EventKeyboard::KeyCode::left == keyCode)
	{
		Left();
	}
	if (EventKeyboard::KeyCode::right == keyCode)
	{
		Right();

	}
	if (playerPos.x <= (_tileMap->getMapSize().width * _tileMap->getMapSize().width) &&
		playerPos.y <= (_tileMap->getMapSize().height * _tileMap->getMapSize().height) &&
		playerPos.y >= 0 &&
		playerPos.x >= 0)
	{
		this->PlayerPosition(playerPos);
	}

	this->ViewPoint(_player->getPosition());
}

void PlayScene::onTouchEnded(Touch *touch, Event *unused_event)
{
	if (judge == 0 && get_bullet == true) {
		judge = 1;
		// Find where the touch is
		auto touchLocation = touch->getLocation();
		touchLocation = this->convertToNodeSpace(touchLocation);

		// Create a projectile and put it at the player's location
		auto projectile = Sprite::create("bullet.png");
		projectile->setPosition(_player->getPosition());
		this->addChild(projectile);

		int realX;

		// Are we shooting to the left or right?
		auto diff = touchLocation - _player->getPosition();
		if (diff.x > 0)
		{
			realX = (_tileMap->getMapSize().width * _tileMap->getTileSize().width) +
				(projectile->getContentSize().width / 2);
		}
		else {
			realX = -(_tileMap->getMapSize().width * _tileMap->getTileSize().width) -
				(projectile->getContentSize().width / 2);
		}
		float ratio = (float)diff.y / (float)diff.x;
		int realY = ((realX - projectile->getPosition().x) * ratio) + projectile->getPosition().y;
		auto realDest = Point(realX, realY);

		// Determine the length of how far we're shooting
		int offRealX = realX - projectile->getPosition().x;
		int offRealY = realY - projectile->getPosition().y;
		float length = sqrtf((offRealX*offRealX) + (offRealY*offRealY));
		float velocity;
		if (speedup == false)
			velocity = 60 / 1; 
		else
			velocity = 100 / 1;
		float realMoveDuration = length / velocity;

		SimpleAudioEngine::getInstance()->playEffect("bullet.wav");
		// Move projectile to actual endpoint
		auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(PlayScene::projectileMoveFinished, this));
		projectile->runAction(Sequence::create(MoveTo::create(realMoveDuration, realDest), actionMoveDone, NULL));

		_projectiles.pushBack(projectile);
	}
}

void Up()
{
	playerPos.y += _tileMap->getTileSize().height;
}

void Down()
{
	playerPos.y -= _tileMap->getTileSize().height;
}

void Left()
{
	playerPos.x -= _tileMap->getTileSize().width;
}

void Right()
{
	playerPos.x += _tileMap->getTileSize().width;
}

void PlayScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
}

void PlaySceneCover::myclock(float dt)
{ 
	--m_time;
	if (m_time == 0)
	{
		this->lose();
	}
	if (m_time > 0) {
		Label *labelTime = (Label *)this->getChildByTag(11);
		labelTime->setString(StringUtils::format("Time: %d ", m_time));
	}
}

void PlaySceneCover::myscore(float dt)
{
	if (_numCollected >= 15)
	{
		SimpleAudioEngine::getInstance()->playEffect("win.mp3");
		this->win();
	}
	if (_numCollected<15) {
		Label *score = (Label *)this->getChildByTag(12);
		score->setString(StringUtils::format("SCORE: %d/15", _numCollected));
	}
}

void PlaySceneCover::mystate(float dt)
{
	if (poison == true){
		Label *state = (Label *)this->getChildByTag(13);
		state->setString(StringUtils::format("STATE: %s", "POISONING"));
	}
}