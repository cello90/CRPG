#pragma once

//#include "cocos2d.h"
#include "State.h"
#include <queue>

class StateMachine //: public cocos2d::Node
{
public:
	State* GetCurrentState();
	void SetCurrentState(State*);

protected: 
	std::queue<State*> _currentQueue;
	virtual void Transition(State*);
	State* _currentState = nullptr;
	virtual void TransitionToNewState(State*);
};