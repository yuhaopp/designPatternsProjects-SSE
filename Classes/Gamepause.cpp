#include"cocos2d.h"
#include "Gamepause.h" 
#include"HelloWorldScene.h"
#include"levelScene.h"
USING_NS_CC;

//???????CCrenderTexture   
//??????????????§Ö????????????????????????????   
//?????????????????????????????????????????§Ø?????????§Õ???  

Scene* Gamepause::scene(RenderTexture* sqr)
{
	Scene *scene = Scene::create();
	Gamepause *layer = Gamepause::create();
	scene->addChild(layer,1);
	//???????????Game?????§ß????sqr??????????Sprite  
	//????Sprite?????GamePause????????  
	//?????????§³  
	Size visibleSize = Director::getInstance()->getWinSize();
	Sprite *back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	back_spr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2)); //????¦Ë??,??????????????¦Ë?¨¢?  
	back_spr->setFlipY(true);            //????????UI??????OpenGL?????  
	back_spr->setColor(Color3B::GRAY); //??????????  
	scene->addChild(back_spr);
	return scene;
}

bool Gamepause::init()
{

	if (!Layer::init())
	{
		return false;
	}
	//?????????§³  
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//???????  
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *background = Sprite::create("help.png");
	background->setScale(0.6f);
	background->setPosition(visibleSize / 2);
	this->addChild(background);

	//??????????  
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
