#include "StateMachine.h"
#include <typeinfo>

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

void StateMachine::Transition(State* state)
{
	_currentQueue.push(state);

	if (state == nullptr)
	{
		return;
	}
	else if (StateMachine::GetCurrentState() == nullptr)
	{
		StateMachine::TransitionToNewState(state);
	}
	else if (typeid(state).name() != typeid(StateMachine::GetCurrentState()).name())
	{
		StateMachine::TransitionToNewState(state);
	}
	else
	{
		return;
	}
}

void StateMachine::TransitionToNewState(State* state)
{
	if (_currentState != nullptr)
		_currentState->Exit();

	_currentState = state;

	if (_currentState != nullptr)
		_currentState->Enter();
}