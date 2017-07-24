#pragma once
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

template <class T>
class larray
{
private:
	struct item
	{
		T data;
		iterator next;
		item():next(NULL){}

		item(T i, iterator n = NULL) :data(i), next(n) {}
	};
	item* first;
	item* last;
	int ItemsCount;

public:
	typedef item* iterator;
	larray();
	~larray();
	iterator begin() { return first; }
	iterator end() { return last; }
	void push_back(const T& value);
	void push_front(const T& value);
	void pop_back();
	void clear();
	T& at(int index);
	int size() { return ItemsCount; }
	T&operator[](int index);
	friend ostream & operator<<(ostream & os, larray<T>& src)
	{
		for (int i = 0; i < src.size(); i++)
			os << src[i] << ends;
		os << endl;
		return os;
	}


};

template<class T>
larray<T>::larray() : ItemsCount(0) { first = last = NULL; }



template<class T>
larray<T>::~larray()
{
	iterator current = NULL;
	iterator Next = first;
	while (Next)
	{
		current = Next;
		Next = Next->next;
		delete current;
	}
}

template<class T>
void larray<T>::push_back(const T&value)
{
	iterator newItem = new item(value);
	if (last == NULL)
		first = newItem;
	else last->next = newItem;
	last = newItem;
	ItemsCount++;
}



template<class T>
void larray<T>::push_front(const T & value)
{
	iterator newItem = new item(value);
	if (first == NULL)
		first = last = newItem;
	else  newItem->next = first;
	first = newItem;
	ItemsCount++;
}

template<class T>
void larray<T>::pop_back()
{
	iterator prev = NULL;
	iterator curr = first;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	delete curr;
	last = prev;
	last->next = NULL;
	ItemsCount--;
}

template<class T>
void larray<T>::clear()
{
	this->larray<T>::~larray();
	this->larray<T>::larray();

}

template<class T>
T& larray<T>::at(int index)
{
	assert(index >= 0); assert(index < ItemsCount);
	iterator cur = first;
	for (int i = 0; i < index; i++)
		cur = cur->next;
	return cur->data;
}


template<class T>
T&larray<T>::operator[](int index)
{
	int i = 0;
	item* cur = first;
	while (i < index)
	{
		cur = cur->next;
		i++;
	}

	return cur->data;
}









