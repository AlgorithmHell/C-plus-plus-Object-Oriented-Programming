#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

class frac
{
	int z;
	int r;
public:
	frac();
	frac(int zt, int rt);
	int getz();
	int getr();
	bool operator<=(frac&a);
	bool operator>=(frac&a);
	friend ostream &operator<<(ostream & print, frac&a);
	friend istream &operator >> (istream &read, frac&a);
	frac & operator=(frac&a);
	 frac operator*( frac&a);
	frac operator+(frac&a);
	frac operator-(frac&a);
	frac operator+=(frac&a);
};