#pragma once
#include "actionsprite.h"

class Hero : public ActionSprite
{
public:
	Hero(void);
	~Hero(void);

	CREATE_FUNC(Hero);
	bool init();	
};
