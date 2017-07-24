#pragma once
#include <iostream>
using namespace std;
class arr
{
	int size;
	int *data;
public:
	arr(int tsize);
	~arr();
	void set(int index, int value);
	void get(int i);
	int getsize();
	arr(const arr &a);
	arr &operator=(arr&a);


};
