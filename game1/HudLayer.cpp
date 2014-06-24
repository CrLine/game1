#include "HudLayer.h"
using namespace cocos2d;

HudLayer::HudLayer(void)
{
	_dPad = NULL;
}

HudLayer::~HudLayer(void)
{
}

bool HudLayer::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		_dPad = SimpleDPad::dPadWithFile(CCString::create("pd_dpad.png"), 64);
		_dPad->setPosition(ccp(64.0, 64.0));
		_dPad->setOpacity(100);
		this->addChild(_dPad);

		bRet = true;
	} while (0);

	return bRet;
}
