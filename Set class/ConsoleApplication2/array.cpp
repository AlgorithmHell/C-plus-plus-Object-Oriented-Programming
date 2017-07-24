#include "array.h"

arr::arr(int tsize)
{
	size = tsize;
	data = new int[size];
}

arr::~arr()
{
	delete[] data;
}

void arr::set(int index, int value)
{
}

void arr::get(int i)
{
}

int arr::getsize()
{
	return 0;
}

arr::arr(const arr & a)
{
	size = a.size;
	data = new int[size];
	for (int i(0); i < size; i++)
	{
		data[i] = a.data[i];
	}
	//можно вызвать конструктор с одним параметром

}

arr & arr::operator=(arr & a)
{
	if (this != &a)
	{
		size = a.size;
		delete[]data;
		data = new int[size];
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
		return *this;
	}
	/*arr a(10), b(20); b=a; 
	нужно уменьшить/увеличить размер*/
}
