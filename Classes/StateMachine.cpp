#include "StateMachine.h"

USING_NS_CC;

StateMachine::StateMachine() {};
StateMachine::~StateMachine() {};

StateMachine* StateMachine::create()
{
	StateMachine* sm = new StateMachine();
	CCLOG("stateMachine::create() reached");
	return sm;
}

// Getter for _currentState
State* StateMachine::GetCurrentState()
{
	return _currentState;
}

// Setter for _currentState
void StateMachine::SetCurrentState(State* state)
{
	StateMachine::Transition(state);
}

// Transition between states checks and prep
void StateMachine::Transition(State* state)
{
	CCLOG("StateMachine::Transition reached");
	_currentQueue.push(state);

	if (state == nullptr)
	{
		CCLOG("StateMachine::Transition >> nullptr");
		return;
	}
	else if (StateMachine::GetCurrentState() == nullptr)
	{
		StateMachine::TransitionToNewState(state);
	}
	else if (state->GetName() != StateMachine::GetCurrentState()->GetName())
	{
		StateMachine::TransitionToNewState(state);
	}
	else
	{
		CCLOG("StateMachine::Transition >> else reached >> State name: ", typeid(state).name());
		return;
	}
}

// Transition between states
void StateMachine::TransitionToNewState(State* state)
{
	CCLOG("StateMachine::TransitionToNewState reached. State: ", typeid(state).name());
	if (_currentState != nullptr)
		_currentState->Exit();

	_currentState = state;

	if (_currentState != nullptr)
		_currentState->Enter();
}