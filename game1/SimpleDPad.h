#pragma once
#include "cocos2d.h"

class SimpleDPad;

class SimpleDPadDelegate
{
public:
	virtual void didChangeDirectionTo(SimpleDPad *simpleDPad, cocos2d::CCPoint direction) = 0;
	virtual void isHoldingDirection(SimpleDPad *simpleDPad, cocos2d::CCPoint direction) = 0;
	virtual void simpleDPadTouchEnded(SimpleDPad *simpleDPad) = 0;
};

class SimpleDPad : public cocos2d::CCSprite, public cocos2d::CCTargetedTouchDelegate
{
public:
	SimpleDPad(void);
	~SimpleDPad(void);

	static SimpleDPad* dPadWithFile(cocos2d::CCString *fileName, float radius);
	bool initWithFile(cocos2d::CCString *filename, float radius);

	void onEnterTransitionDidFinish();
	void onExit();
	void update(float dt);

	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	void updateDirectionForTouchLocation(cocos2d::CCPoint location);

	CC_SYNTHESIZE(SimpleDPadDelegate*, _delegate, Delegate);
	CC_SYNTHESIZE(bool, _isHeld, IsHeld);

protected:
	float _radius;
	cocos2d::CCPoint _direction;
};
