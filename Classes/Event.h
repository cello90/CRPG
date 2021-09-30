#pragma once

#include <string>

// Taken from https://github.com/Pseudomanifold/Events

template <typename T>
class Event
{
public:
	Event() = default;
	virtual~Event();
	Event(T type, const std::string& name = "") : _type(type), _name(name) {};
	inline const T type() const { return _type; };
	inline const std::string& getName() const { return _name; };
	virtual bool isHandled() { return _handled; };

protected:
	T _type;
	std::string _name;
	bool _handled = false;
};