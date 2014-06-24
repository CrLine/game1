#pragma once
#include "cocos2d.h"
#include "Defines.h"

class ActionSprite : public cocos2d::CCSprite
{
public:
	ActionSprite(void);
	~ActionSprite(void);

	//action methods
	void idle();
	void attack();
	void hurtWithDamage(float damage);
	void knockout();
	void walkWithDirection(cocos2d::CCPoint direction);

	//scheduled methods
	void update(float dt);

	//actions
	CC_SYNTHESIZE_RETAIN(cocos2d::CCAction*, _idleAction, IdleAction);
	CC_SYNTHESIZE_RETAIN(cocos2d::CCAction*, _attackAction, AttackAction);
	CC_SYNTHESIZE_RETAIN(cocos2d::CCAction*, _walkAction, WalkAction);
	CC_SYNTHESIZE_RETAIN(cocos2d::CCAction*, _hurtAction, HurtAction);
	CC_SYNTHESIZE_RETAIN(cocos2d::CCAction*, _knockedOutAction, KnockedOutAction);

	//states
	CC_SYNTHESIZE(ActionState, _actionState, ActionState);

	//attributes
	CC_SYNTHESIZE(float, _walkSpeed, WalkSpeed);
	CC_SYNTHESIZE(float, _hitPoints, HitPoints);
	CC_SYNTHESIZE(float, _damage, Damage);

	//movement
	CC_SYNTHESIZE(cocos2d::CCPoint, _velocity, Velocity);
	CC_SYNTHESIZE(cocos2d::CCPoint, _desiredPosition, DesiredPosition);

	//measurements
	CC_SYNTHESIZE(float, _centerToSides, CenterToSides);
	CC_SYNTHESIZE(float, _centerToBottom, CenterToBottom);
};
