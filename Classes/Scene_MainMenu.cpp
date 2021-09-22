#include "Scene_MainMenu.h"
#include "ui/CocosGUI.h"
#include "Scene_CardTest.h"

USING_NS_CC;

Scene* Scene_MainMenu::createScene()
{
    return Scene_MainMenu::create();
}

bool Scene_MainMenu::init()
{
    // Initialize Scene
    if (!Scene::init())
    {
        return false;
    }

    // Screen Info
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Menu Layer
    auto menuLayer = Layer::create();
    this->addChild(menuLayer);

    // Main Menu Label
    auto mainMenuLabelText = Label::createWithTTF("Main Menu", "fonts/arial.ttf", 42);
    mainMenuLabelText->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 50));
    menuLayer->addChild(mainMenuLabelText, 1);

    // Menu----------------------
    Vector<MenuItem*> menuItems;

    // Push play game lable
    auto playGameLabel = Label::createWithTTF("Play Game", "fonts/arial.ttf", 24);
    auto playGameItem = MenuItemLabel::create(playGameLabel,
        [](Ref* sender)
        {
            CCLOG("Play Game label was clicked!!");
            auto scene = Scene_CardTest::createScene();
            Director::getInstance()->pushScene(scene);
        });
    menuItems.pushBack(playGameItem);

    // Push options lable
    auto optionsLabel = Label::createWithTTF("Options", "fonts/arial.ttf", 24);
    auto optionsItem = MenuItemLabel::create(optionsLabel,
        [](Ref* sender)
        {
            CCLOG("Options label was clicked!!");
        });
    optionsItem->setPosition(Vec2(0, -25));
    menuItems.pushBack(optionsItem);

    // Push quit game lable
    auto quitLabel = Label::createWithTTF("Quit", "fonts/arial.ttf", 24);
    auto quitItem = MenuItemLabel::create(quitLabel,
        [](Ref* sender)
        {
            CCLOG("Quit label was clicked!!");
        });
    quitItem->setPosition(Vec2(0, -50));
    menuItems.pushBack(quitItem);

    auto menu = Menu::createWithArray(menuItems);
    menuLayer->addChild(menu, 1);

    return true;
}

