#pragma once

#include "State.h"

class State_GameInit : public State 
{
public:
	~State_GameInit(void) { State::OnDestroy(); };
	char* GetName() override;
	void Enter() override;
	void Exit() override;

protected:
	void OnCreate() override;
};