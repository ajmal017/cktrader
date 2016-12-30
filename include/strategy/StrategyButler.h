#pragma once
#ifndef __STRATEGYBUTLER_H__
#define __STRATEGYBUTLER_H__

#include "utils/ckdef.h"
#include "utils/cktypes.h"

#include <atomic>
#include <vector>
#include <map>

namespace cktrader {

class IServiceMgr;
class PositionBuffer;

class CK_EXPORTS StrategyButler
{
public:
	StrategyButler(IServiceMgr* servicemgr, std::string strategyName);
	virtual ~StrategyButler();

	std::string sendOrder(std::string symbol, std::string pricetype, std::string orderType,double price, double volume, std::string currency = CURRENCY_CNY);
	void cancelOrder(std::string symbol, std::string orderID);

	std::string sendStopOrder(std::string symbol, std::string orderType, double price, double volume);
	void cancelStopOrder(std::string orderID);

	bool subscribe(std::string symbol);
	bool subscribe(std::vector<std::string> symbols);

	void processStopOrder(Datablk& data);
	void processTradeEvent(Datablk& data);
	void processPositionEvent(Datablk& data);

private:
	IServiceMgr* servicemgr;
	std::atomic<long> stopOrderCount = 0;
	std::map<std::string, PositionBuffer> posBufferDict;

	std::string strategyName;

	//����ֹͣ���ֵ�
	// keyΪstopOrderID��valueΪstopOrder����
	std::map< std::string,StopOrder> stopOrderDict;            //ֹͣ�������󲻻�ӱ��ֵ���ɾ��
	std::map<std::string,StopOrder> workingStopOrderDict;      // ֹͣ���������ӱ��ֵ���ɾ��
};

}
#endif