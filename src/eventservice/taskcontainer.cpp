#include "eventservice/taskcontainer.h"

#include <utility>

namespace cktrader {

TaskContainer::TaskContainer()
{
	task_map = new CKMap;

	task_handler_queue = new ConcurrentQueue<std::string>;
	task_type_queue = new BlockingConcurrentQueue<std::string>;
}

TaskContainer::~TaskContainer()
{
	//释放map
	for (CKMap::const_iterator it = task_map->begin(); it != task_map->end(); ++it)
	{
		delete it->second;
	}

	delete task_map;

	delete task_handler_queue;
	delete task_type_queue;
}

bool TaskContainer::wait_and_get_task(Task& t)
{
	//取消循环，这里是否有问题？如果item读取不成功，t是什么？
	std::string type;
	do
	{
		type = read_task_queue();
	} while (type.empty());

	MapItem* item = read_task_map(type);
	if (item)
	{
		return item->read(t);
	}
	return false;
}

void TaskContainer::put_task(Task& data)
{	
	write_task_map(data);
	task_type_queue->enqueue(data.type);
}

void TaskContainer::put_handler_task(Task& data)
{
	write_task_map(data);
	task_handler_queue->enqueue(data.type);
}

void TaskContainer::task_run_end(std::string task_type)
{
	CKMap::const_iterator it;
	it = task_map->find(task_type);
	if (it != task_map->end())
	{
		it->second->free_run_lock();
	}
	//(*task_map)[task_type]->free_run_lock();
}

std::string TaskContainer::read_task_queue()
{
	//等待队列有数据??
	std::string type ;

	if (task_handler_queue->try_dequeue(type))
	{
		return type;
	}
	task_type_queue->wait_dequeue(type);
	return type;
}

void TaskContainer::write_task_map(Task& data)
{
	CKMap::const_iterator it;
	it = task_map->find(data.type);

	if (it != task_map->end())
	{
		MapItem* item = (*task_map)[data.type];
		item->write(data);		
	}
	else
	{
		MapItem* item = new MapItem();
		item->write(data);
		task_map->insert(std::make_pair(data.type, item));
	}
}
MapItem* TaskContainer::read_task_map(std::string type)
{
	CKMap::const_iterator it;
	MapItem* item = nullptr;
	it = task_map->find(type);

	if (it != task_map->end())
	{
		item = it->second;
	}
	return item;
}

size_t TaskContainer::task_count()
{
	return task_handler_queue->size_approx() + task_type_queue->size_approx();
}

}//cktrader