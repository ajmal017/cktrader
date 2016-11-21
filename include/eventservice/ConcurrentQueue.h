#pragma once
#ifndef __CONCURRENTQUEUE_H__
#define __CONCURRENTQUEUE_H__

#include <mutex>
#include <queue>
#include <condition_variable>

#include "utils/ckdef.h"
#include "utils/cktypes.h"

namespace cktrader{
///�̰߳�ȫ�Ķ���
class ConcurrentQueue
{
private:
	//�������ȼ�����
	std::queue<Task> the_queue_priority_high;
	std::queue<Task> the_queue_priority_middle;
	std::queue<Task> the_queue_priority_low;

	mutable std::recursive_mutex the_mutex;							//������
	mutable std::condition_variable_any the_condition_variable;			//��������

public:
	//�����µ�����
	void push(Task const& data)
	{
		std::unique_lock<std::recursive_mutex> lck(the_mutex);				//��ȡ������

		//������д�������
		if (data.task_priority == Task::high)
		{
			the_queue_priority_high.push(data);
		}
		else if (data.task_priority == Task::middle)
		{
			the_queue_priority_middle.push(data);
		}
		else if (data.task_priority == Task::low)
		{
			the_queue_priority_low.push(data);
		}							

		the_condition_variable.notify_one();			//֪ͨ���������ȴ����߳�
	}

	//�������Ƿ�Ϊ��
	bool empty() const
	{
		std::unique_lock<std::recursive_mutex> lck(the_mutex);
		bool isEmpty = false;

		if (the_queue_priority_high.empty() &&
			the_queue_priority_middle.empty() &&
			the_queue_priority_low.empty())
		{
			isEmpty = true;
		}

		return isEmpty;		
	}

	//ȡ��
	Task wait_and_pop()
	{
		std::unique_lock<std::recursive_mutex> lck(the_mutex);

		while (the_queue_priority_high.empty() &&
				the_queue_priority_middle.empty() &&
				the_queue_priority_low.empty())						//������Ϊ��ʱ
		{
			the_condition_variable.wait(lck);			//�ȴ���������֪ͨ
		}

		Task popped_value;

		if (!the_queue_priority_high.empty())
		{
			popped_value = the_queue_priority_high.front();			//��ȡ�����е����һ������
			the_queue_priority_high.pop();
			return popped_value;
		}

		if (!the_queue_priority_middle.empty())
		{
			popped_value = the_queue_priority_middle.front();			//��ȡ�����е����һ������
			the_queue_priority_middle.pop();
			return popped_value;
		}

		if (!the_queue_priority_low.empty())
		{
			popped_value = the_queue_priority_low.front();			//��ȡ�����е����һ������
			the_queue_priority_low.pop();
			return popped_value;
		}
	}
};

}//cktrader

#endif