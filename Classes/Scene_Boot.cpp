#include "Scene_Boot.h"
#include "Scene_MainMenu.h"
#include "GameManager.h"
#include <iostream>

USING_NS_CC;

Scene* Scene_Boot::createScene()
{
	return Scene_Boot::create();
}

bool Scene_Boot::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Background images
    auto sprite = Sprite::create("Tests/B.png");
    if (sprite != nullptr)
    {
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(sprite, 0);
    }

    std::cout << "Test stuff!";
    CCLOG("Scene_Boot!");

    // Set up persistant
    GameManager* gm = GameManager::GetInstance();
    gm->SetTestInt(10);

    // Set up EventDispatcher 


    // Set up Keyboard event bindings


    // Set up Mouse event bindings


    // Callback to have next scene show up
    changeSceneCallback = CallFunc::create(CC_CALLBACK_0(Scene_Boot::MoveToMainMenu, this));
    delayTimer = DelayTime::create(1.0f);
    sequence = Sequence::create(delayTimer, changeSceneCallback, nullptr);
    this->runAction(sequence);

    return true;
}

void Scene_Boot::MoveToMainMenu()
{
    auto scene = Scene_MainMenu::createScene();
    Director::getInstance()->pushScene(scene);
}

