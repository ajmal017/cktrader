#pragma once
#ifndef __EVENTENGINE_H__
#define __EVENTENGINE_H__

#include "utils/ckdef.h"
#include "utils/cktypes.h"
#include "ConcurrentQueue.h"

#include <thread>
#include <map>
#include <atomic>

namespace cktrader {

class CK_EXPORTS EventEngine
{
public:
	EventEngine();
	EventEngine(EventEngine& engine);
	~EventEngine();

	bool registerHandler(std::string type, Handler f);
	bool unRegisterHandler(std::string type);
	bool put(Task &t);

	bool startEngine();
	bool stopEngine();

private:
	void processTask();
	void trigerTimer();

private:
	std::vector<std::thread*> *m_task_thread_pool=nullptr;

	ConcurrentQueue *task_queue = nullptr;//�¼��������
	std::atomic<bool> m_active = false;//�¼������Ƿ�ʼ����ı�־
	std::multimap<std::string, Handler> *handlers = nullptr;

	mutable std::recursive_mutex the_mutex_handlers;		//������

	std::thread* m_timer_thread = nullptr;;//for timer
};

}//cktrader

#endif