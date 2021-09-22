#pragma once

#include "cocos2d.h"

class Scene_CardTest : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Scene_CardTest);

private:
	static cocos2d::Node* createNewCard();
};