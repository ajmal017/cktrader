#pragma once

#ifndef __PositionBuffer_H__
#define __PositionBuffer_H__

#include "utils/ckdef.h"
#include "utils/cktypes.h"

namespace cktrader{

class PositionBuffer
{
public:
	std::string tSymbol;

	// ��ͷ
	double longPosition;
	double longToday;
	double longYd;

	//��ͷ
	double shortPosition;
	double shortToday;
	double shortYd;

public:
	PositionBuffer();
	PositionBuffer(const PositionBuffer & buffer);
	~PositionBuffer();

	void updatePositionData(PositionData& pos);
	void updateTradeData(TradeData& trade);
};

}

#endif 
