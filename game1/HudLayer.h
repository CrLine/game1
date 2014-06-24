#pragma once
#include "cocos2d.h"
#include "SimpleDPad.h"

class HudLayer : public cocos2d::CCLayer
{
public:
	HudLayer(void);
	~HudLayer(void);

	bool init();
	CREATE_FUNC(HudLayer);
	CC_SYNTHESIZE(SimpleDPad*, _dPad, DPad);
};
