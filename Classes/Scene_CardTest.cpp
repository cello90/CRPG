#include "Scene_CardTest.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* Scene_CardTest::createScene()
{
    return Scene_CardTest::create();
}

bool Scene_CardTest::init()
{
    // Initialize Scene
    if (!Scene::init())
    {
        return false;
    }

    // Screen Info
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto* testCard = Scene_CardTest::createNewCard();
    testCard->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(testCard);
}

cocos2d::Node* Scene_CardTest::createNewCard()
{
    // Screen Info
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Create card object
    auto* cardNode = Node::create();

    // Create background
    auto* rectNode = DrawNode::create();
    Vec2 rectangle[4];
    rectangle[0] = Vec2(-50, -75);
    rectangle[1] = Vec2(50, -75);
    rectangle[2] = Vec2(50, 75);
    rectangle[3] = Vec2(-50, 75);

    Color4F white(1, 1, 1, 1);
    rectNode->drawPolygon(rectangle, 4, white, 1, white);
    cardNode->addChild(rectNode, 0);

    // Add top label
    auto cardTitleLabel = Label::createWithTTF("Card Title", "fonts/arial.ttf", 24);
    cardTitleLabel->setTextColor(cocos2d::Color4B(0, 0, 0, 255));
    cardTitleLabel->setPosition(Vec2(0, 60));
    cardNode->addChild(cardTitleLabel, 5);

    // Add card image
    auto cardImage = Sprite::create("Tests/Plains.png");
    cardImage->setScale(0.2f);
    cardImage->setPosition(Vec2(0, 20));
    cardNode->addChild(cardImage, 1);

    // Card text body
    auto cardBodyLabel = Label::createWithTTF("Card details", "fonts/arial.ttf", 18);
    cardBodyLabel->setTextColor(cocos2d::Color4B(0, 0, 0, 255));
    cardBodyLabel->setPosition(Vec2(0, -30));
    cardNode->addChild(cardBodyLabel, 5);

    // Card cost
    auto cardCostLabel = Label::createWithTTF("3", "fonts/arial.ttf", 18);
    cardCostLabel->setTextColor(cocos2d::Color4B(0, 0, 0, 255));
    cardCostLabel->setPosition(Vec2(45, -69));
    cardNode->addChild(cardCostLabel, 5);

    // Card Type
    auto cardTypeLabel = Label::createWithTTF("T", "fonts/arial.ttf", 18);
    cardTypeLabel->setTextColor(cocos2d::Color4B(0, 0, 0, 255));
    cardTypeLabel->setPosition(Vec2(-45, -69));
    cardNode->addChild(cardTypeLabel, 5);

    return cardNode;
}