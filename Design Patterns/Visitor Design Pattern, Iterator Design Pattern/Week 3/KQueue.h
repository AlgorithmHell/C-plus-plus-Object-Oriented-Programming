#pragma once
#define MAX_SIZE 100000
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include "KQueueIterator.h"
#include "QueueIterator.h"


template <class T>
class Visitor;

template <class T>
class Element
{

public:
	virtual void accept(Visitor<T>*visitor) = 0;
};

template <class T>
class KQueue : public Element<T>
{
	T*arr;
	int size;
	int current;
public:
	friend class QueueIterator<T>;
	void accept(Visitor<T>*visitor);
	KQueue(int _size = MAX_SIZE);
	KQueue(const KQueue&h);
	KQueue(std::initializer_list<T>&);
	KQueue(KQueue&&);
	~KQueue();
	void Append(std::initializer_list<T>&);
	bool Push(const T &);
	void Pop();
	const T&Front();
	const T&Back();
	size_t Size() const;
	const int& Capacity();
	bool isEmpty();
	void Clear();
	void Swap(KQueue&);
	void Resize(int&);
	template<typename T>
	friend std::ostream&operator<<(std::ostream&, KQueue<T>&);
	template<typename T>
	friend std::istream&operator >> (std::istream&, KQueue<T>&);
	KQueue<T> operator + ( KQueue<T>&);
	KQueue<T> operator +=( KQueue<T>&);
	KQueue<T> &operator=( KQueue<T>&);
	KQueue<T>& operator=(KQueue<T>&&);
	bool operator ==( KQueue<T>&);
	bool operator !=( KQueue<T>&);	

	T* begin() { return arr; }
	T*end() { return arr + current; }
	template<class...Args>
	void Emplace(const Args&...args);
};
template <typename T>
void KQueue<T>::accept(Visitor<T>*visitor)
{
	visitor->visit(*this);
}
template <typename T>
KQueue<T> CreateQueue(KQueue<T>&queue)
{
	KQueue<T> A(queue);
	return A;
}
template <typename T>
KQueue<T>::KQueue(int _size)
{

	size = _size;
	current = 0;
	arr = new T[size];

}
template <typename T>
KQueue<T>::KQueue(const  KQueue & h)
{
	size = h.size;
	current = h.current;
	arr = new T[size];
	for (int i = 0; i < current; i++)
	{
		arr[i] = h.arr[i];
	}

}
template <typename T>
KQueue<T>::KQueue(std::initializer_list<T>&_list) : current(0), size(_list.size())
{
	arr = new T[size];
	for (auto i : _list)
	{
		this->Push(i);
	}
}
template<class T>
KQueue<T>::KQueue(KQueue &&q) :size(q.size), current(q.current), arr(q.arr)
{
	q.arr = 0;
	q.size = 0;
	q.current = 0;
}
template <typename T>
KQueue<T>::~KQueue()
{
	delete[] arr;
}
template <typename T>
void KQueue<T>::Append(std::initializer_list<T>&_list)
{
	for (auto i : _list)
	{
		this->Push(i);
	}
}
template <typename T>
bool KQueue<T>::Push(const T & value)
{
	if (current == size)
	{
		(size * 2) >= MAX_SIZE ? size = MAX_SIZE : size *= 2;
		this->Resize(size);
	}

	if (current != MAX_SIZE)
	{
		arr[current++] = value;
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
void KQueue<T>::Pop()
{
	if (current != 0)
	{
		for (int i = 0; i < current; i++)
			arr[i] = arr[i + 1];
		current--;
	}

}
template <typename T>
const T&KQueue<T>::Front()
{
	if (current == 0)
	{
		return 0;
	}
	return arr[0];
}
template <typename T>
const T&KQueue<T>::Back()
{
	if (current == 0)
	{
		return 0;
	}
	return arr[current - 1];
}

template <typename T>
const int&KQueue<T>::Capacity()
{
	return size;
}
template <typename T>
bool KQueue<T>::isEmpty()
{
	return current == 0 ? true : false;
}
template <typename T>
void KQueue<T>::Clear()
{
	current = 0;
	arr[0] = 0;
}
template <typename T>
void KQueue<T>::Swap(KQueue &b)
{
	if (&(arr) != &(b.arr))
	{
		T*buf = arr;
		arr = b.arr;
		b.arr = buf;
		int buf1 = size;
		int buf2 = current;
		size = b.size;
		current = b.current;
		b.size = buf1;
		b.current = buf2;
	}

}
template <typename T>
void KQueue<T>::Resize(int &value)
{
	size = value;
	T*buf = new T[current];
	for (int i = 0; i < current; i++)
	{
		buf[i] = arr[i];
	}
	delete[] arr;
	arr = new T[size];
	for (int i = 0; i < current; i++)
	{
		arr[i] = buf[i];
	}
	delete[] buf;
}
template <typename T>
KQueue<T> KQueue<T>::operator+(KQueue<T> & obj)
{
	KQueue<T> buf(*this);
	
	for (KQueueIterator<T>iter = obj.begin();iter!=obj.end();++iter)
	{
		buf.Push(*iter);
	}
	return KQueue<T>(buf);
}
template <typename T>
KQueue<T> KQueue<T>::operator+=( KQueue<T> &obj)
{
	for (KQueueIterator<T> iter=obj.begin();iter!=obj.end();++iter)
	{
		this->Push(*iter);
	}
	return *this;
}
template <typename T>
KQueue<T> &KQueue<T>::operator=( KQueue<T> &obj)
{
	if (&arr != &(obj.arr))
	{
		delete[] arr;
		arr = new T[obj.size];
		size = obj.size;
		current = obj.current;
		for (KQueueIterator<T> iter=begin(),objIter=obj.begin();objIter!=obj.end();++iter,++objIter)
		{
			*iter = *objIter;
		}
	}
	return *this;
}
template<class T>
KQueue<T>& KQueue<T>::operator=(KQueue<T>&&q)
{

	size = q.size;
	current = q.current;
	arr = q.arr;
	q.arr = 0;
	q.size = 0;
	q.current = 0;
	return *this;
}
template <typename T>
bool KQueue<T>::operator==( KQueue<T> &obj)
{

	if (current != obj.current)
	{
		return false;
	}
	for (KQueueIterator<T> This=begin(),Obj=obj.begin();This!=end();++This,++Obj)
	{
		if (*This!=*Obj)
		{
			return false;
		}
	}
	return true;
}
template <typename T>
bool KQueue<T>::operator!=( KQueue<T> &obj)
{
	return *this == obj ? false : true;
}

template <typename T>
size_t KQueue<T>::Size() const
{
	return size_t(current);
}


template <typename T>
std::ostream & operator<<(std::ostream & os, KQueue<T>&q)
{
	for (int i = 0; i < q.current; i++)
	{
		os << q.arr[i] << std::ends;
	}
	return os;
}
template <typename T>
std::istream & operator >> (std::istream &in, KQueue<T> &obj)
{
	std::string line;
	T buf;
	getline(in, line);
	std::istringstream S(line);
	while (S >> buf)
	{
		obj.Push(buf);
	}
	return in;
}

template<class T>
template<class ...Args>
void KQueue<T>::Emplace(const Args& ...args)
{
	Push(T(args...));
}
