/*#include <iostream>
using namespace std;
class CTest
{
	int info;
public:
	CTest(): info(22){}
	CTest &Method() { info = 33; return *this; }
	int getinfo() { return info; }


};
int main()
{
	CTest test;
	cout << test.getinfo() << endl;
	test.Method();
	cout << test.getinfo() << endl;
	return 0;
}*/ //THIS////////////////////////////////////////////
/* 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
class str
{
	char*s;
public:
	str() {};
	str(str&st) { *this = st; }
	str &method() { s = "Hello"; return *this; }
	str operator+(str &str1)
	{
		str res; res.s = new char(strlen(this->s) + strlen(str1.s) + 1);
		res.s[0] = 0;
		strcat(res.s, this->s);
		strcat(res.s, str1.s);
		return res;
	}
	void get() { cout << s; }
};
int main()
{
	str s1, s2, s3;
	s1.method();
	s2.method();
	s3 = s1 + s2;
	s3.get();

	return 0;
}*/



/*CLASS TUTORIAL*/

//complex::complex(double tre=1,double tim=0): re(tre),im(tim){} //constructor
//можем инициализировать константные поля
//если поля в классе изменятся, все равно будет работать
//скорость


//train


//EXPLICIT CONSTRUCTOR
/* 
#include <iostream>
using namespace std;
class timeh
{
	int hour;
	int min;
	int sec;
	
public:
	timeh() { hour = 0; min = 0; sec = 0; };
explicit timeh(int s) {hour = s / 3600; min = (s % 3600) / 60; sec=(s % 3600) % 60;	}
};


int main()
{
	timeh a(365);
	timeh b;
return 0;
}
*/

//COPYING CONSTRUCTOR
/*
arr(const arr&a)
{
size=a.size;
data=a.data;
}*/
//or *this=a;
/*arr a(10), b(a); когда будет вызываться деструктор, а и б указывают на один и тот же адрес ---ошибка на этапе выполнения*/