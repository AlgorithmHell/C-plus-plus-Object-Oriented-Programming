
#pragma once

#include <iostream>
#include<cmath>
#include <fstream>

using namespace std;


class Series
{
protected:
	int a1;
	int d;
	int amount;
	int*arr;
public:
	int get_first_element() { return a1; }
	int get_d() { return d; }
	int get_amount() { return amount; }
	~Series() { delete[] arr; }
	Series() :a1(1), d(1) { arr = new int[10]; }
	Series(const int num, const int a11, const int dd) : a1(a11), d(dd), amount(num) { arr = new int[num]; }
	//??????????? ?? ?????????? ?????????, ??????? ???????? ? ????????(???????????) ?????????
	virtual void set_Series() = 0;
	virtual int get_element(const int&num) = 0;
	virtual double Sum() = 0;
	 void print();
};


class Liner :public Series
{
public:
	Liner() :Series::Series() {}
	~Liner() {}
	Liner(const int num, const int a11, const int dd) :Series::Series(num, a11, dd) {}
	void set_Series();
	int get_element(const int&num);
	double Sum();
	

};
class Exponential :public Series
{
public:
	Exponential() :Series::Series() {}
	~Exponential() {}
	Exponential(const int& num, const int&a11, const int&dd) :Series::Series(num, a11, dd) {}
	void set_Series();
	int get_element(const int&num);
	double Sum();
	

};
