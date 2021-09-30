#include "GameManager.h"
#include "EventDispatcher.h"

#include <iostream>

USING_NS_CC;

GameManager* GameManager::_instance = 0;

EventDispatcher* dispatcher = new EventDispatcher();

int testInt = 0;

GameManager* GameManager::GetInstance()
{
	std::cout << "Working";
	if (!_instance)
	{
		CCLOG("GameManager GetInstance");
		_instance = new GameManager();
		_instance->Init();
	}
	return _instance;
}

GameManager::GameManager() {};

void GameManager::Init()
{
	CCLOG("GameManager working");
}

void GameManager::SetTestInt(int newInt)
{
	testInt = newInt;
}

int GameManager::GetTestInt()
{
	return testInt;
}
