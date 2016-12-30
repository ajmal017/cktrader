#include "strategy/StrategyButler.h"
#include "servicemgr_def.h"
#include "strategy/PositionBuffer.h"

namespace cktrader {

StrategyButler::StrategyButler(IServiceMgr* servicemgr, std::string strategyName)
{
	this->servicemgr = servicemgr;
	this->strategyName = strategyName;
}
StrategyButler::~StrategyButler()
{

}

std::string StrategyButler::sendOrder(std::string symbol, std::string pricetype, std::string orderType, double price, double volume, std::string currency)
{
	ContractData contract;		
	this->servicemgr->getContract(symbol, contract);

	OrderReq order;
	order.symbol = symbol;
	order.exchange = contract.exchange;
	order.price = price;
	order.volume = volume;

	order.productClass = contract.productClass;
	order.currency = currency;

	order.priceType = pricetype;

	if (orderType == ST_ORDER_BUY)
	{
		order.direction = DIRECTION_LONG;
		order.offset = OFFSET_OPEN;
	}
	else if (orderType == ST_ORDER_SELL)
	{
		order.direction = DIRECTION_SHORT;

		// 只有上期所才要考虑平今平昨
		if (contract.exchange != EXCHANGE_SHFE)
		{
			order.offset = OFFSET_CLOSE;
		}
		else
		{
			//获取持仓缓存数据
			std::map<std::string, PositionBuffer >::iterator it= posBufferDict.find(symbol);
			if (it == posBufferDict.end())
			{
				//如果获取持仓缓存失败，则默认平昨
				order.offset = OFFSET_CLOSE;
			}
			else if(it->second.longToday)
			{
				//否则如果有多头今仓，则使用平今
				order.offset = OFFSET_CLOSETODAY;
			}
			else
			{
				order.offset = OFFSET_CLOSE;
			}
		}			
	}
	else if (orderType == ST_ORDER_SHORT)
	{
		order.direction = DIRECTION_SHORT;
		order.offset = OFFSET_OPEN;
	}
	else if (orderType == ST_ORDER_COVER)
	{
		order.direction = DIRECTION_LONG;

		//只有上期所才要考虑平今平昨
		if (contract.exchange != EXCHANGE_SHFE)
		{
			order.offset = OFFSET_CLOSE;
		}
		else
		{
			//获取持仓缓存数据
			std::map<std::string, PositionBuffer >::iterator it = posBufferDict.find(symbol);
			if (it == posBufferDict.end())
			{
				//如果获取持仓缓存失败，则默认平昨
				order.offset = OFFSET_CLOSE;
			}
			else if (it->second.shortToday)
			{
				order.offset = OFFSET_CLOSETODAY;
			}
			else
			{
				order.offset = OFFSET_CLOSE;
			}
		}
	}

	IGateway* gate = servicemgr->getGateWay(contract.gateWayName);

	std::string orderID = gate->sendOrder(order);
	
	return orderID;
}

void StrategyButler::cancelOrder(std::string symbol, std::string orderID)
{
	CancelOrderReq req;

	ContractData contract;
	this->servicemgr->getContract(symbol, contract);
	req.symbol = symbol;
	req.exchange = contract.exchange;
	req.orderID = orderID;
	IGateway* gate = servicemgr->getGateWay(contract.gateWayName);
	gate->cancelOrder(req);
}

std::string StrategyButler::sendStopOrder(std::string symbol, std::string orderType, double price, double volume)
{
	stopOrderCount++;
	std::string stopOrderID = STOPORDERPREFIX + std::to_string(stopOrderCount);

	StopOrder so;
	so.tSymbol = symbol;
	so.orderType = orderType;
	so.price = price;
	so.volume = volume;
	so.stopOrderID = stopOrderID;
	so.status = STOPORDER_WAITING;

	if (orderType == ST_ORDER_BUY)
	{
		so.direction = DIRECTION_LONG;
		so.offset = OFFSET_OPEN;
	}
	else if (orderType == ST_ORDER_SELL)
	{
		so.direction = DIRECTION_SHORT;
		so.offset = OFFSET_CLOSE;
	}
	else if (orderType == ST_ORDER_SHORT)
	{
		so.direction = DIRECTION_SHORT;
		so.offset = OFFSET_OPEN;
	}
	else if (orderType == ST_ORDER_COVER)
	{
		so.direction = DIRECTION_LONG;
		so.offset = OFFSET_CLOSE;
	}

	// 保存stopOrder对象到字典中
	stopOrderDict[stopOrderID] = so;
	workingStopOrderDict[stopOrderID] = so;

	return stopOrderID;
}

void StrategyButler::cancelStopOrder(std::string orderID)
{
	std::map<std::string, StopOrder>::iterator it = workingStopOrderDict.find(orderID);
	if (it != workingStopOrderDict.end())
	{
		it->second.status = STOPORDER_CANCELLED;
		workingStopOrderDict.erase(orderID);
	}
}

void StrategyButler::processStopOrder(Datablk& data)
{
	TickData tick = data.cast<TickData>();

	for (auto item : workingStopOrderDict)
	{
		StopOrder so = item.second;
		if (so.tSymbol == tick.symbol)
		{
			bool longTriggered = (so.direction == DIRECTION_LONG) && (tick.lastPrice >= so.price);      // 多头停止单被触发
			bool shortTriggered = (so.direction == DIRECTION_SHORT) && (tick.lastPrice <= so.price);    // 空头停止单被触发

			if (longTriggered|| shortTriggered)
			{
				double price;
				if (so.direction == DIRECTION_LONG)
				{
					price = tick.upperLimit;
				}				
				else
				{
					price = tick.lowerLimit;
				}
				sendOrder(tick.symbol, PRICETYPE_MARKETPRICE, so.orderType, price, so.volume);

				workingStopOrderDict.erase(so.stopOrderID);
				stopOrderDict[so.stopOrderID].status = STOPORDER_TRIGGERED;				
			}
		}
	}
}
void StrategyButler::processTradeEvent(Datablk& data)
{
	TradeData trade = data.cast<TradeData>();

	std::map<std::string, PositionBuffer>::iterator it = posBufferDict.find(trade.tSymbol);
	if (it == posBufferDict.end())
	{
		PositionBuffer posBuffer;
		posBuffer.tSymbol = trade.tSymbol;
		posBuffer.updateTradeData(trade);
		posBufferDict[trade.tSymbol] = posBuffer;
	}
	else
	{
		it->second.updateTradeData(trade);
	}
}
void StrategyButler::processPositionEvent(Datablk& data)
{
	PositionData pos = data.cast<PositionData>();

	std::map<std::string, PositionBuffer>::iterator it = posBufferDict.find(pos.tSymbol);
	if (it == posBufferDict.end())
	{
		PositionBuffer posBuffer;
		posBuffer.tSymbol = pos.tSymbol;
		posBuffer.updatePositionData(pos);
		posBufferDict[pos.tSymbol] = posBuffer;
	}
	else
	{
		it->second.updatePositionData(pos);
	}
}

bool StrategyButler::subscribe(std::string symbol)
{
	EventEngine* pEvent = servicemgr->getEventEngine();
	ContractData contract;

	bool x = servicemgr->getContract(symbol, contract);
	if (!x)
	{
		return false;
	}

	pEvent->registerHandler(EVENT_TICK + symbol, std::bind(&StrategyButler::processStopOrder, this, std::placeholders::_1), strategyName+"StrategyButler");
	pEvent->registerHandler(EVENT_TRADE + symbol, std::bind(&StrategyButler::processTradeEvent, this, std::placeholders::_1), strategyName + "StrategyButler");
	pEvent->registerHandler(EVENT_POSITION + symbol, std::bind(&StrategyButler::processPositionEvent, this, std::placeholders::_1), strategyName + "StrategyButler");

	IGateway* gate = servicemgr->getGateWay(contract.symbol);
	SubscribeReq sub;
	sub.symbol = symbol;
	gate->subscribe(sub);

	return true;
}

bool StrategyButler::subscribe(std::vector<std::string> symbols)
{
	for (auto item : symbols)
	{
		bool ret = subscribe(item);

		if (!ret)
		{
			return false;
		}
	}

	return true;
}

}//cktrader
