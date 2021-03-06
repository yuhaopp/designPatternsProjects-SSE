#include"cocos2d.h"
#include "Gamepause.h" 
#include"HelloWorldScene.h"
#include"levelScene.h"
USING_NS_CC;

//Income a CCrenderTexture   
//Just like a running game's screenshot as a gamepause's background
//so that it's look like a dialog above the game scene just as the normal game's design

Scene* Gamepause::scene(RenderTexture* sqr)
{
	Scene *scene = Scene::create();
	Gamepause *layer = Gamepause::create();
	scene->addChild(layer,1);
	//added part: using the screenshot of gameScene's texture images to create sprite
	//and add sprite to gamepause Scene
	//in the end, get the size of game window
	Size visibleSize = Director::getInstance()->getWinSize();
	Sprite *back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	back_spr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2)); //set the position which is relative to the center 
	back_spr->setFlipY(true);            //flip the coordinate, because the UI's coordinate is different with OpenGL's.
	back_spr->setColor(Color3B::GRAY);   //turn the colorful pictures into gray. 
	scene->addChild(back_spr);
	return scene;
}

bool Gamepause::init()
{

	if (!Layer::init())
	{
		return false;
	}
	//Get window's size
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//origin coordinate
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *background = Sprite::create("help.png");
	background->setScale(0.6f);
	background->setPosition(visibleSize / 2);
	this->addChild(background);

	//Continue game button
	MenuItemImage *ContinueItem = MenuItemImage::create(
		"nextUp.png",
		"nextDown.png",
		this,
		menu_selector(Gamepause::menuContinueCallback));

	ContinueItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 ));

	MenuItem *backItem = MenuItemImage::create(
		"backUp.png",
		"backDown.png",
		this,
		menu_selector(Gamepause::menuBcakCallback)
	);
	backItem->setPosition(visibleSize.width / 2 - 100, visibleSize.height / 2);

	MenuItem *replayItem = MenuItemImage::create(
		"replayUp.png",
		"replayDown.png",
		this,
		menu_selector(Gamepause::menuReplayCallback)
		);
	replayItem->setPosition(visibleSize.width / 2 + 100, visibleSize.height / 2);

	Menu* Menu = Menu::create(ContinueItem,backItem,replayItem,NULL);
	Menu->setPosition(Vec2::ZERO);
	this->addChild(Menu, 2);
	return true;
}
void Gamepause::menuContinueCallback(Object* pSender)
{
	Director::getInstance()->popScene();
}
void Gamepause::menuReplayCallback(Object* pSender)
{
	auto playScene = PlayScene1::createScene();
	Director::getInstance()->replaceScene(playScene);
}
void Gamepause::menuBcakCallback(Object* pSender)
{
	auto levelScene = LevelScene::createScene();
	Director::getInstance()->replaceScene(levelScene);
}
