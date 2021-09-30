#include "NotificationCenter.h"
#include <map>

USING_NS_CC;

std::map<std::string, int> _table;

void AddObserver()
{

}

void RemoveObserver()
{

}

void Clean()
{

}

void NotificationCenter::PostNotification(std::string* notificationName)
{
	NotificationCenter::PostNotification(notificationName, nullptr);
}

void NotificationCenter::PostNotification(std::string* notificationName, cocos2d::Node* sender)
{
	NotificationCenter::PostNotification(notificationName, sender, nullptr);
}

// TODO e will need to be an event at some point
void NotificationCenter::PostNotification(std::string* notificationName, cocos2d::Node* sender, cocos2d::Node* e)
{
	if (notificationName == nullptr || notificationName->length() < 1)
	{
		CCLOG("NotificationCenter -> Notification name is empty");
		return;
	}
}