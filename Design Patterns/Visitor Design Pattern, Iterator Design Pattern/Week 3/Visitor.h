#pragma once
#include "KQueue.h"



template <typename T>
class Visitor
{
public:
	virtual void visit(KQueue<T>&queue)=0;
};
template <typename T>
class CountOperation : public Visitor<T>
{
	T count;
public:
	CountOperation(T _count=0):count(_count){}
	void visit(KQueue<T>&queue)
	{
		for (KQueueIterator<T> iter = queue.begin(); iter != queue.end(); ++iter)
		{
			count += *iter;
		}
	}
	friend std::ostream&operator<<(std::ostream&os, CountOperation<T>&CO)
	{
		os << CO.count;
		return os;
	}
	void reset()
	{
		count = 0;
	}
};
template <typename T>
class MultiplicationOperation : public Visitor<T>
{
	T multiply;
public:
	MultiplicationOperation(T _multiply=1):multiply(_multiply){}
	void visit(KQueue<T>&queue)
	{
		for (KQueueIterator<T> iter = queue.begin(); iter != queue.end(); ++iter)
		{
			multiply *= *iter;
		}
	}
	void reset()
	{
		multiply = 1;
	}
	friend std::ostream&operator<<(std::ostream&os, MultiplicationOperation<T>&MO)
	{
		os << MO.multiply;
		return os;
	}
};
