#pragma once

#include "Event.h"

#include <functional>
#include <map>
#include <vector>
#include <algorithm>

// Taken from https://github.com/Pseudomanifold/Events

template<typename T>
class EventDispatcher {

public:
	void subscribe(T type, const SlotType& funct)
	{
		_observers[type].push_back(funct);
	};

	void post(Event<T>& event)
	{
		if (_observers.find(event.type()) == _observers.end())
			return;

		for (auto&& observer : _observers.at(event.type()))
		{
			if (!event.isHandled()) observer(event);
		}
	};

private:
	using SlotType = std::function<void(const Event<T>&)>;
	std::map<T, std::vector<SlotType >> _observers;
};