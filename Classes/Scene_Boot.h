#pragma once

#ifndef __SCENE_BOOT_H__
#define __SCENE_BOOT_H__

#include "cocos2d.h"

class Scene_Boot : public cocos2d::Scene 
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();


	CREATE_FUNC(Scene_Boot);

private:
	void MoveToMainMenu();
	cocos2d::CallFunc* changeSceneCallback;
	cocos2d::DelayTime* delayTimer;
	cocos2d::Sequence* sequence;
};

#endif //__SCENE_BOOT_H__