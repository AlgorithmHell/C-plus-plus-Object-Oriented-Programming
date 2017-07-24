#pragma once
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class arrayy
{protected:
	int*arr;
	int size;
public:
	~arrayy() { delete[]arr; }
	arrayy() : size(10) { arr = new int[10]; }
	arrayy(const int s) : size(s) { arr = new int[s]; }
	arrayy(const int*a,const int s):size(s)
	{
		arr = new int[s];
		for (int i(0); i < s; i++)
			arr[i] = a[i];
	}
	arrayy(const arrayy&a)
	{
		size = a.size;
		arr = new int[a.size];
		for (int i(0); i < a.size; i++)
			arr[i] = a.arr[i];
	}
	virtual void print()
	{
		for (int i(0); i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	 friend ostream&operator<<(ostream&os, const arrayy&ar)
	{
		for (int i(0); i < ar.size; i++) cout << ar.arr[i] << " ";
		return os;
	}
	 friend istream&operator >> (istream&is, const arrayy&ar)
	{
		for (int i(0); i < ar.size; i++)
			is >> ar.arr[i];
		return 	is;
	}
	arrayy operator=(const arrayy&a)
	{
		assert(size == a.size);
		size = a.size;
		arr = new int[a.size];
		for (int i(0); i < a.size; i++)
			arr[i] = a.arr[i];
		return arrayy(*this);
		
	}
};

class stackk: public arrayy
{protected:
	int top;
public:
	int get_top() { return top; }
	stackk():arrayy::arrayy(),top(-1){}
	stackk(int a) :arrayy::arrayy(a), top(-1) {}
	void push(const int val)
	{
		if (top == size) cout << "stack is full";
		else arr[++top]=val;

	}
	virtual int pop()
	{
		if (top == -1) {cout << "stack is empty"; return 8985950;}
		else return arr[top--];		
	}
	 void print()
	{
		for (int i(top); i > -1; i--)
			cout << arr[i] << " ";
	}

};
class queuee :public stackk
{
	
public:
	queuee():stackk::stackk(){}
	queuee(int i):stackk::stackk(i){}
	int pop()
	{
		if (top <= 0) { cout << "queue is empty" << endl; return 489489; }
		else
		{
			int a = arr[0];
			for (int i(0); i < top; i++)
			{
				arr[i] = arr[i + 1];

			}
			top--;
			return a;
		}
	}
	void push(int val)
	{
		if (top<size-1)
		{
			arr[++top] = val;
		}
		else { cout << "queue is full" << endl; return; }
	}
	void print()
	{
		for (int i(0); i <= top; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	
};
