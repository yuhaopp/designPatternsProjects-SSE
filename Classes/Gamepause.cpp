#include"cocos2d.h"
#include "Gamepause.h" 
#include"HelloWorldScene.h"
#include"levelScene.h"
USING_NS_CC;

//����һ��CCrenderTexture   
//�൱��һ���������е���Ϸ�Ľ�ͼ��Ϊ�����ͣ�Ի���ı���   
//�����Ϳ��������ǶԻ�������Ϸ����֮�ϣ�һ����Ϸ���ж���������д�ġ�  

Scene* Gamepause::scene(RenderTexture* sqr)
{
	Scene *scene = Scene::create();
	Gamepause *layer = Gamepause::create();
	scene->addChild(layer,1);
	//���Ӳ��֣�ʹ��Game�����н�ͼ��sqr����ͼƬ����Sprite  
	//����Sprite��ӵ�GamePause��������  
	//�õ����ڵĴ�С  
	Size visibleSize = Director::getInstance()->getWinSize();
	Sprite *back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	back_spr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2)); //����λ��,������������λ�á�  
	back_spr->setFlipY(true);            //��ת����ΪUI�����OpenGL���겻ͬ  
	back_spr->setColor(Color3B::GRAY); //ͼƬ��ɫ���ɫ  
	scene->addChild(back_spr);
	return scene;
}

bool Gamepause::init()
{

	if (!Layer::init())
	{
		return false;
	}
	//�õ����ڵĴ�С  
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//ԭ������  
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *background = Sprite::create("help.png");
	background->setScale(0.6f);
	background->setPosition(visibleSize / 2);
	this->addChild(background);

	//������Ϸ��ť  
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
