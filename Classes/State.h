#pragma once

#include "cocos2d.h"

class State : public cocos2d::Node
{
public:
	State(void) { State::OnCreate(); };
	~State(void) { State::OnDestroy(); };
	virtual char* GetName();
	virtual void Enter();
	virtual void Exit();

protected:
	virtual void OnCreate();
	virtual void OnDestroy();
	virtual void AddListenders();
	virtual void RemoveListeners();
};