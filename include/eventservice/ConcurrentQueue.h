#pragma once
#ifndef __CONCURRENTQUEUE_H__
#define __CONCURRENTQUEUE_H__

#include <mutex>
#include <queue>
#include <condition_variable>

namespace cktrader{
///�̰߳�ȫ�Ķ���
template<class Data>
class ConcurrentQueue
{
private:
	std::queue<Data> the_queue;								//��׼�����
	mutable std::recursive_mutex the_mutex;							//������
	mutable std::condition_variable_any the_condition_variable;			//��������

public:
	//�����µ�����
	void push(Data const& data)
	{
		std::unique_lock<std::recursive_mutex> lck(the_mutex);				//��ȡ������
		the_queue.push(data);							//������д�������

		the_condition_variable.notify_one();			//֪ͨ���������ȴ����߳�
	}

	//�������Ƿ�Ϊ��
	bool empty() const
	{
		std::unique_lock<std::recursive_mutex> lck(the_mutex);
		bool isEmpty = the_queue.empty();

		return isEmpty;
		
	}

	//ȡ��
	Data wait_and_pop()
	{
		std::unique_lock<std::recursive_mutex> lck(the_mutex);

		while (the_queue.empty())						//������Ϊ��ʱ
		{
			the_condition_variable.wait(lck);			//�ȴ���������֪ͨ
		}

		Data popped_value;
		popped_value = the_queue.front();			//��ȡ�����е����һ������
		the_queue.pop();								//ɾ��������

		return popped_value;							//���ظ�����
	}

	size_t size()
	{
		std::unique_lock<std::recursive_mutex> lck(the_mutex);
		return the_queue.size();
	}
};

}//cktrader

#endif