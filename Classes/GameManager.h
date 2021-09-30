#pragma once

#include "cocos2d.h"

// Ideas from
// https://gist.github.com/solkar/8651478

class GameManager 
{
public:
	/*static GameManager& getInstance()
	{
		static GameManager* instance = new GameManager();
		return *instance;
	}
	void getDate();*/

	static GameManager* GetInstance();
	virtual ~GameManager() {};

	void SetTestInt(int);
	int GetTestInt();

protected:


private:
	GameManager();
	//GameManager(const GameManager&);
	void Init();
	//GameManager& operator= (const GameManager&);
	static GameManager* _instance;
};