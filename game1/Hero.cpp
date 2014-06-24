#include "Hero.h"
using namespace cocos2d;

Hero::Hero(void)
{
}

Hero::~Hero(void)
{
}

bool Hero::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!ActionSprite::initWithSpriteFrameName("hero_idle_00.png"));

		int i;
		//idle animation
		CCArray *idleFrames = CCArray::createWithCapacity(6);
		for (i = 0; i < 6; i++)
		{
			CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("hero_idle_%02d.png", i)->getCString());
			idleFrames->addObject(frame);
		}
		CCAnimation *idleAnimation = CCAnimation::createWithSpriteFrames(idleFrames, float(1.0 / 12.0));
		this->setIdleAction(CCRepeatForever::create(CCAnimate::create(idleAnimation)));

		//attack animation
		CCArray *attackFrames = CCArray::createWithCapacity(3);
		for (i = 0; i < 3; i++)
		{
			CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("hero_attack_00_%02d.png", i)->getCString());
			attackFrames->addObject(frame);
		}
		CCAnimation *attackAnimation = CCAnimation::createWithSpriteFrames(attackFrames, float(1.0 / 24.0));
		this->setAttackAction(CCSequence::create(CCAnimate::create(attackAnimation), CCCallFunc::create(this, callfunc_selector(Hero::idle)), NULL));

		this->setCenterToBottom(39.0);
		this->setCenterToSides(29.0);
		this->setHitPoints(100.0);
		this->setDamage(20.0);
		this->setWalkSpeed(80.0);

		bRet = true;
	} while (0);

	return bRet;
}
