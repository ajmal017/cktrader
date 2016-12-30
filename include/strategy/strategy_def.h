#pragma once
#ifndef __STRATEGY_DEF_H__
#define __STRATEGY_DEF_H__

#include "utils/ckdef.h"
#include "utils/cktypes.h"
#include "StrategyButler.h"

namespace cktrader {

class CK_EXPORTS IStrategy
{
protected:
	StrategyButler *butler = nullptr;

public:
	IStrategy(IServiceMgr* x, std::string name)
	{
		butler = new StrategyButler(x,name);
	}

	virtual ~IStrategy()
	{
		delete butler;
	}

	virtual bool onInit() = 0;
	virtual bool onStart() = 0;
	virtual bool onStop() = 0;
};

}//cktrader

#endif