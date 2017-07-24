#pragma once
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;


class arrayy
{
protected:
	static const int max = 100;
	int*arr;
	int size;
public:
	virtual ~arrayy() { delete[]arr; }
	arrayy() { size = 10; arr = new int[max]; };
	arrayy(int s, int val = 0);
	arrayy(arrayy&a);
	int&operator[](int i);
	arrayy operator+(arrayy&a);
	class wrong_index
	{
	public: int index;
			wrong_index(int i):index(i){}
	};
	class too_big {};
	class neg_size{};
	arrayy operator=(arrayy&p)
	{
		delete[]arr;
		size = p.size;
		arr = new int[size];
		for (int i(0); i < size; i++)
			arr[i] = p.arr[i];
		return *this;
	}
	friend ostream&operator<<(ostream&os, arrayy&a)
	{
		for (int i(0); i < a.size; i++)
			os << a.arr[i] << " ";
		return os;
	}
	friend istream&operator >> (istream&is, arrayy&a)
	{
		for (int i(0); i < a.size; i++)
			is >> a.arr[i];
		return is;
	}
};

class polinoms :public arrayy
{
public:
	polinoms(int s, int val = 0);
	polinoms() { size = 10; arr = new int[max]; };
	
	~polinoms() {}
	polinoms(arrayy&p);
	friend ostream&operator<<(ostream&os, polinoms&a)
	{
		 os << a.arr[0] << "+"<<a.arr[1]<<"x+";
		for (int i(2); i < a.size-1; i++)
			os << a.arr[i] <<"x^"<<i<<"+";
		os << a.arr[a.size-1] << "x^" << a.size - 1;
		return os;
	}
	friend istream&operator >> (istream&is, polinoms&a)
	{
		for (int i(0); i < a.size; i++)
			is >> a.arr[i];
		return is;
	}

	
	polinoms operator-(polinoms&a);
	polinoms operator+(polinoms&a)
	{
		arrayy buf = (arrayy)(*this)+(arrayy)(a);
		return polinoms(buf);

	}

	polinoms operator*(polinoms&a);
	bool operator>(polinoms&a);
	bool operator<(polinoms&a);
	bool operator==(polinoms&a);
	int calculation(int x);
	

};

