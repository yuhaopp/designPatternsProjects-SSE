#ifndef __FACADE_H__
#define __FACADE_H__


#include "cocos2d.h"
USING_NS_CC;

Class Movement
{
	private ActualMoveUp AMU;
	private ActualMoveDown AMD;
	private ActualMoveLeft AML;
	private ActualMoveRight AMR;
	
	public void MoveFun(EventKeyboard::KeyCode keyCode, Event* event);
}

Class ActualMoveUp
{
	public Up();
}

Class ActualMoveDown
{
	public Down();
}

Class ActualMoveLeft
{
	public Left();
}

Class ActualMoveRight
{
	public Right();
}

#endif