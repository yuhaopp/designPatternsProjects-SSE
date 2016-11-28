#include "KeyboardSettingScene.h"
#include "Command.h"
USING_NS_CC;

using namespace CocosDenshion;
bool isPause;
Scene* KeyboardSettingScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SettingScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool KeyboardSettingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *Background = Sprite::create("back.png");
	Background->setScale(1.35f);
	Background->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(Background);

	string direction;

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	EventListenerKeyboard* keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(KeyboardSettingScene::onKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(KeyboardSettingScene::onKeyReleased, this);
	dispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);


	return true;
}

void KeyboardSettingScene::loadUI(){
	auto upBtn = (Button*)Helper::seekWidgetByName(UI,"upBtn");
	upBtn->addTouchEventListener(this,toucheventselector(KeyboardSettingScene::keyEventup));

	auto downBtn = (Button*)Helper::seekWidgetByName(UI,"DownBtn");
	upBtn->addTouchEventListener(this,toucheventselector(KeyboardSettingScene::keyEventdown));

	auto leftBtn = (Button*)Helper::seekWidgetByName(UI,"LeftBtn");
	upBtn->addTouchEventListener(this,toucheventselector(KeyboardSettingScene::keyEventleft));

	auto rightBtn = (Button*)Helper::seekWidgetByName(UI,"RightBtn");
	upBtn->addTouchEventListener(this,toucheventselector(KeyboardSettingScene::keyEventright));
}

void KeyboardSettingScene::keyEventup(Ref*, TouchEventType type){
	switch (type){
		case TouchEventType::TOUCH_EVENT_BEGAN:
		direction = "up";
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		       break; 
	}

void KeyboardSettingScene::keyEventdown(Ref*, TouchEventType type){
	switch (type){
		case TouchEventType::TOUCH_EVENT_BEGAN:
		direction = "down";
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		       break; 
	}
}
void KeyboardSettingScene::keyEventleft(Ref*, TouchEventType type){
	switch (type){
		case TouchEventType::TOUCH_EVENT_BEGAN:
		direction = "left";
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		       break; 
	}
}
void KeyboardSettingScene::keyEventright(Ref*, TouchEventType type){
	switch (type){
		case TouchEventType::TOUCH_EVENT_BEGAN:
		direction = "right";
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		       break; 
	}
}

void PlayScene::onKeyReleased(EventKeyboard::KeyCode keyCode, string key)
{
	key = keynode;
}