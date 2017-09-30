#pragma once

template <typename T>
class KQueue;


template <class T>
class QueueIterator {
	T*ptr;
	KQueue<T> queue;
public:
	QueueIterator(KQueue<T>&q);
	
	T& operator*();
	T* operator->();
	T* operator++();
	T* operator--();
	bool operator==(const T* _QueueIterator);
	bool operator!=(const T* _QueueIterator);
	T*first()
	{
		ptr = queue.begin();
		return queue.begin();
	}
	T*last()
	{
		ptr = queue.end() - 1;
		return queue.end() - 1;
	}
	bool isDone()
	{
		return ptr == queue.end()?true:false;
		 
	}
	T*next()
	{
			return ++ptr;
	}
};
template <typename T>
QueueIterator<T>::QueueIterator(KQueue<T>&q) : queue(q) { ptr = q.begin(); }

template <typename T>
T & QueueIterator<T>::operator*() { return *ptr; }
template <typename T>
T * QueueIterator<T>::operator->() { return ptr; }
template <typename T>
T * QueueIterator<T>::operator++() { return ++ptr; }
template <typename T>
T *QueueIterator<T>::operator--() { return --ptr; }
template <typename T>
bool QueueIterator<T>::operator==(const T* _QueueIterator) { return ptr == _QueueIterator.ptr; }
template <typename T>
bool QueueIterator<T>::operator!=(const T* _QueueIterator) { return !(*this.ptr == _QueueIterator); }
