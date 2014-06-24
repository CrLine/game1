#include "ActionSprite.h"
using namespace cocos2d;

ActionSprite::ActionSprite(void)
{
	_idleAction = NULL;
	_attackAction = NULL;
	_walkAction = NULL;
	_hurtAction = NULL;
	_knockedOutAction = NULL;
}

ActionSprite::~ActionSprite(void)
{
}

void ActionSprite::idle()
{
	if (_actionState != kActionStateIdle)
	{
		this->stopAllActions();
		this->runAction(_idleAction);
		_actionState = kActionStateIdle;
		_velocity = CCPointZero;
	}
}

void ActionSprite::attack()
{
	if (_actionState == kActionStateIdle || _actionState == kActionStateAttack || _actionState == kActionStateWalk)
	{
		this->stopAllActions();
		this->runAction(_attackAction);
		_actionState = kActionStateAttack;
	}
}

void ActionSprite::hurtWithDamage(float damage)
{

}

void ActionSprite::knockout()
{

}

void ActionSprite::walkWithDirection(CCPoint direction)
{

}

void ActionSprite::update(float dt)
{

}
