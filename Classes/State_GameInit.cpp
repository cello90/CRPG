#include "cocos2d.h"
#include "State_GameInit.h"

USING_NS_CC;

char* State_GameInit::GetName()
{
	return "State_GameInit";
}

void State_GameInit::Enter() 
{
	CCLOG("Entering GameInit");
}

void State_GameInit::Exit()
{
	CCLOG("Exiting GameInit");
}

void State_GameInit::OnCreate()
{
	//State::stateName = "State_GameInit";
}

