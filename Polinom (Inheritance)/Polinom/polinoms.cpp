#include "polinoms.h"



arrayy::arrayy(int s, int val)
	
{
	if (s < 0) throw neg_size();
	else 
	{
		if (s >= max) throw too_big();
		else size = s;
	}
	arr = new int[s];
	for (int i(0); i < size; i++)
		arr[i] = val;
}

arrayy::arrayy(arrayy & a):size(a.size)
{
	arr = new int[a.size];
	for (int i(0); i < a.size; i++)
		arr[i] = a.arr[i];
}

int & arrayy::operator[](int i)
{
	
	if (i >= 0 && i < size) return arr[i];
	else throw wrong_index(i);

}

arrayy arrayy::operator+(arrayy & a)
{
	if (size > a.size)
	{
		arrayy buf(*this);
		for (int i(0); i < a.size; i++)
			buf[i] += a[i];
		return buf;
	}
	else
	{
		arrayy buf(a);
		for (int i = 0; i < size; i++)
			buf[i] += arr[i];
		return buf;
	}
	
}

polinoms::polinoms(int s, int val):arrayy::arrayy(s,val)
{
	
}

polinoms::polinoms(arrayy & a)
{
	arrayy::arrayy(a);
}


polinoms polinoms::operator-(polinoms & a)
{
	if (size > a.size)
	{
		polinoms buf(*this);
		for (int i(0); i < a.size; i++)
			buf[i] -= a[i];
		return buf;
	}
	else
	{
		polinoms buf(a);
		for (int i = 0; i < size; i++)
			buf[i] -= arr[i];
		return buf;
	}
}

polinoms polinoms::operator*(polinoms & a)
{
	polinoms buf;
	buf.size = a.size + size - 1;
	delete[]buf.arr;
	buf.arr = new int[a.size + size - 1];
	
	for (int i = 0; i <  a.size + size - 1; i++)
		buf.arr[i] = 0; //обнулила массив для произведения

	for (int x = a.size + size - 2; x >= 0; x--)
	{
		for (int c = a.size - 1; c >= 0; c--)
		{
			for (int b = size - 1; b >= 0; b--)
				if (x == c + b) buf.arr[x] += arr[b] * a.arr[c];
		}
	}
	return buf;
}

bool polinoms::operator>(polinoms & a)
{
	if (size > a.size)return true;
	else return false;
}

bool polinoms::operator<(polinoms & a)
{
	if (size < a.size)return true;
	else return false;
}

bool polinoms::operator==(polinoms & a)
{
	if (size == a.size)
	{
		bool switcher = true;
		for (int i(0); i < size; i++)
		{
			if (arr[i] != a.arr[i]) { switcher = false; break; }
		}
		if (switcher)return true;
		else return false;
	}
	else return false;
}

int polinoms::calculation(int x)
{
	int calc = arr[0];
	for (int i(1); i < size; i++)
		calc += arr[i] * pow(x, i);
	return calc;
}
