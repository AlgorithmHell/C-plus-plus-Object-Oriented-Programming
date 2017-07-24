#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class sett
{
	char* str;
	int size;
public:
	sett(char*s);
	sett(int size_t);
	sett();
	sett(sett &);
	~sett();
	int getsize();
	char* getstr();
	friend ostream &operator<<(ostream & print, sett &s);
	friend istream &operator >> (istream &read, sett&s);
	sett & operator=(const sett &);
	sett & sett::operator=(const char *);
	sett operator*(sett&);
	sett operator+( sett&a);
	sett operator-(const sett&);
	bool operator<(sett&);
	bool operator==(sett&);

};
