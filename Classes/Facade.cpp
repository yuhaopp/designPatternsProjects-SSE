#include "Facade.h"

void Movement::MoveFun(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (EventKeyboard::KeyCode::KEY_W == keyCode)
	{
		AMU.Up();
	}
	if (EventKeyboard::KeyCode::KEY_S == keyCode)
	{
		AMD.Down();
	}
	if (EventKeyboard::KeyCode::KEY_A == keyCode)
	{
		AML.Left();
	}
	if (EventKeyboard::KeyCode::KEY_D == keyCode)
	{
		AMR.Right();
	}
}

void ActualMoveUp::Up()
{
	playerPos.y += _tileMap->getTileSize().height;
}

void ActualMoveDown::Down()
{
	playerPos.y -= _tileMap->getTileSize().height;
}

void ActualMoveLeft::Left()
{
	playerPos.x -= _tileMap->getTileSize().width;
}

void ActualMoveRight::Right()
{
	playerPos.x += _tileMap->getTileSize().width;
}
