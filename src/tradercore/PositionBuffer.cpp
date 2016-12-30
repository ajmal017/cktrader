#include "strategy/PositionBuffer.h"

namespace cktrader{

PositionBuffer::PositionBuffer()
{
	tSymbol = "";

	// ��ͷ
	longPosition = 0.0;
	longToday = 0.0;
	longYd = 0.0;

	//��ͷ
	shortPosition = 0.0;
	shortToday = 0.0;
	shortYd = 0.0;
}

PositionBuffer::PositionBuffer(const PositionBuffer & buffer)
{
	this->tSymbol = buffer.tSymbol;

	// ��ͷ
	this->longPosition = buffer.longPosition;
	this->longToday = buffer.longToday;
	this->longYd = buffer.longYd;

	//��ͷ
	this->shortPosition = buffer.shortPosition;
	this->shortToday = buffer.shortToday;
	this->shortYd = buffer.shortYd;
}

PositionBuffer::~PositionBuffer()
{

}

void PositionBuffer::updatePositionData(PositionData& pos)
{
	//���³ֲ�����
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
		//�෽���֣����Ӧ��ͷ�ĳֲֺͽ������
		if (trade.offset == OFFSET_OPEN)
		{
			this->longPosition += trade.volume;
			this->longToday += trade.volume;
		}
		else if (trade.offset == OFFSET_CLOSETODAY)
		{
			//�෽ƽ�񣬶�Ӧ��ͷ�ĳֲֺͽ�ּ���
			this->shortPosition -= trade.volume;
			this->shortToday -= trade.volume;
		}
		else
		{
			//�෽ƽ�򣬶�Ӧ��ͷ�ĳֲֺ���ּ���
			this->shortPosition -= trade.volume;
			this->shortYd -= trade.volume;
		}
	}
	else
	{
		//��ͷ�Ͷ�ͷ��ͬ

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