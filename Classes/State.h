#pragma once

class State 
{
public:
	State(void);
	~State(void) { State::OnDestroy(); };
	virtual void Enter();
	virtual void Exit();

protected:
	virtual void OnDestroy();
	virtual void AddListenders();
	virtual void RemoveListeners();
};