#pragma once

template <typename T>
class KQueue;


template <class T>
class KQueueIterator {
	T*ptr;
public:
	KQueueIterator(T* _ptr = 0);
	KQueueIterator(const KQueueIterator<T>&);
	T& operator*();
	T* operator->();
	T* operator++();
	T* operator--();
	bool operator==(const KQueueIterator<T>& _KQueueIterator);
	bool operator!=(const KQueueIterator<T>& _KQueueIterator) ;
	
};
template <typename T>
KQueueIterator<T>::KQueueIterator(T * _ptr) : ptr(_ptr) {}
template <typename T>
KQueueIterator<T>::KQueueIterator(const KQueueIterator<T>&Iter) { ptr = Iter.ptr; }
template <typename T>
T & KQueueIterator<T>::operator*() { return *ptr; }
template <typename T>
T * KQueueIterator<T>::operator->() { return ptr; }
template <typename T>
T * KQueueIterator<T>::operator++() { return ++ptr; }
template <typename T>
T *KQueueIterator<T>::operator--() { return --ptr; }
template <typename T>
bool KQueueIterator<T>::operator==(const KQueueIterator<T> & _KQueueIterator)   { return ptr == _KQueueIterator.ptr; }
template <typename T>
bool KQueueIterator<T>::operator!=(const KQueueIterator<T> & _KQueueIterator)  { return !(*this == _KQueueIterator); }
