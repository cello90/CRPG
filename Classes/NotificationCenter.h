#pragma once

#include "cocos2d.h"

static class NotificationCenter
{
public:
	void AddObserver();
	void RemoveObserver();
	void Clean();
	void PostNotification(std::string* notificationName);
	void PostNotification(std::string* notificationName, cocos2d::Node* sender);
	void PostNotification(std::string* notificationName, cocos2d::Node* sender, cocos2d::Node* e);
};