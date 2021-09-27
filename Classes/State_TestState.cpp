#include "cocos2d.h"
#include "State_TestState.h"

USING_NS_CC;

char* State_TestState::GetName()
{
	return "State_TestState";
}

void State_TestState::Enter()
{
	CCLOG("Entering TestState");
}

void State_TestState::Exit()
{
	CCLOG("Exiting TestState");
}
