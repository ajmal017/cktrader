#include "strategy/PositionBuffer.h"

namespace cktrader{

PositionBuffer::PositionBuffer()
{
	tSymbol = "";

	// 多头
	longPosition = 0.0;
	longToday = 0.0;
	longYd = 0.0;

	//空头
	shortPosition = 0.0;
	shortToday = 0.0;
	shortYd = 0.0;
}

PositionBuffer::PositionBuffer(const PositionBuffer & buffer)
{
	this->tSymbol = buffer.tSymbol;

	// 多头
	this->longPosition = buffer.longPosition;
	this->longToday = buffer.longToday;
	this->longYd = buffer.longYd;

	//空头
	this->shortPosition = buffer.shortPosition;
	this->shortToday = buffer.shortToday;
	this->shortYd = buffer.shortYd;
}

PositionBuffer::~PositionBuffer()
{

}

void PositionBuffer::updatePositionData(PositionData& pos)
{
	//更新持仓数据
	if (pos.direction == DIRECTION_LONG)
	{
		this->longPosition = pos.position;
		this->longYd = pos.ydPosition;
		this->longToday = this->longPosition - this->longYd;
	}
	else
	{
		this->shortPosition = pos.position;
		this->shortYd = pos.ydPosition;
		this->shortToday = this->shortPosition - this->shortYd;
	}	
}
	
void PositionBuffer::updateTradeData(TradeData& trade)
{
	if (trade.direction == DIRECTION_LONG)
	{
		//多方开仓，则对应多头的持仓和今仓增加
		if (trade.offset == OFFSET_OPEN)
		{
			this->longPosition += trade.volume;
			this->longToday += trade.volume;
		}
		else if (trade.offset == OFFSET_CLOSETODAY)
		{
			//多方平今，对应空头的持仓和今仓减少
			this->shortPosition -= trade.volume;
			this->shortToday -= trade.volume;
		}
		else
		{
			//多方平昨，对应空头的持仓和昨仓减少
			this->shortPosition -= trade.volume;
			this->shortYd -= trade.volume;
		}
	}
	else
	{
		//空头和多头相同

		if (trade.offset == OFFSET_OPEN)
		{
			this->shortPosition += trade.volume;
			this->shortToday += trade.volume;
		}
		else if (trade.offset == OFFSET_CLOSETODAY)
		{
			this->longPosition -= trade.volume;
			this->longToday -= trade.volume;
		}
		else
		{
			this->longPosition -= trade.volume;
			this->longYd -= trade.volume;
		}
			
	}
}

}//cktrader