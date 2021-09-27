#pragma once

#include "State.h"

class State_TestState : public State
{
public:
	State_TestState(void) { }; 
	~State_TestState(void) {};
	char* GetName() override;
	void Enter() override;
	void Exit() override;
};