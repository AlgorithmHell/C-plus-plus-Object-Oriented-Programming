#include <iostream>
#include <fstream>
#include <cstring>
#include "man.h"
using namespace std;
int main()
{
	man a1("Ivan", 17, 73, "man");
	man a2 = a1;
	man a3 = a2;
	a1.show();
	a2.show();
	a1.change_weight(74);
	a1.change_name("Vanya");
	a1.change_age(18);
	a1.show();
	if (a2 == a3) cout << "men are equal" << endl;
	if (a2 == a1) cout << "men are equal" << endl;
	else cout << "men are not equal" << endl;
	student a4("Olya", 18, 53,"woman", 2016);
	student a5 = a4;
	a5.change_age(19);
	a5.change_weight(50);
	a4.show();
	a5.show();
	if (a4 == a5) cout << "same studying age" << endl;
	a5.stud_age_increment();

	if (a4 == a5) cout << "same studying age" << endl;
	else cout << "not same studying age" << endl;
	cout << a4;
	cout << a1;

	int quit;
	cout << "Enter zero to clean the screen" << endl;
	cin >> quit;
	system("cls");
	ofstream out("out.txt");
	ifstream fin("fin.txt");

	int oneage = 0;
	int oneyear = 0;
	man*arr[7];
	int i = 0;
	while (!fin.eof())
	{
		int a, b, c;
		char*n=new char[15];
		char*s=new char[5];
		char type;
		fin >> type;
		if (type == 'm')
		{
			fin >> n >> a >> b >> s;
			arr[i++] = new man(n, a, b, s);
		}
		if(type=='s')
		{
			fin >> n >> a >> b >> s >> c;
			arr[i++] = new student(n, a, b, s, c);
		}
		
	}
	for (int i(0); i < 7; i++)
	{
		(*arr[i]).show();
	}
	cout << endl;
	/*student*stu;
	int size = 0;
	for (int i(0); i < 7; i++)
	{
		stu = dynamic_cast<student*>(arr[i]);
		if (stu) size++;
	}
	
	//int age[7];
	int*year = new int[size];
	for (int i = 0; i < 7; i++)
	{
		int count = 0;
		do {
			count++; i++;
		} while (*arr[i]==*arr[i+1]);
		cout <<count<<" people are "<< arr[i]->get_age() << " year old" << endl;
	}
	cout << endl;

	for (int i(0); i < 7; i++)
	{
		stu = dynamic_cast<student*>(arr[i]);
		if (stu) year[oneyear++]=stu->get_studage();
	}
	
	for (int i = 6; i>0; i--)
		for (int j = 0; j<i; j++)
			if (age[j] > age[j + 1])
				swap(age[j], age[j + 1]);
	for (int i = 3; i>0; i--)
		for (int j = 0; j<i; j++)
			if (year[j] > year[j + 1])
				swap(year[j], year[j + 1]);
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		do {
			count++; i++;
		} while (year[i] == year[i + 1]);
		cout << count << " people are " << year[i] << " year of stydying" << endl;
	}
	cout << endl;*/ 
	int age[4];
	int x = 0;
	student*s;
	for (int i(0); i < 7; i++)
	{
		s = dynamic_cast<student*>(arr[i]);
		if (s)
		{
			age[x++] = s->get_studage();
		}
	}
	
	for (int i = 3; i>0; i--)
		for (int j = 0; j<i; j++)
			if (age[j] > age[j + 1])
				swap(age[j], age[j + 1]);
	int q = -1;
	for(q;q<3;)
	{
		int count = 0;
		do {
			count++; q++;
		} while (age[q] == age[q + 1]);
		cout << count << " people are " << age[q] << " year of studying" << endl;
		
	}
	cout << endl;
	int ar[7];
	for (int i(0); i < 7; i++)
	{
		ar[i] = arr[i]->get_age();
	}
	for (int i = 3; i>0; i--)
		for (int j = 0; j<i; j++)
			if (ar[j] > ar[j + 1])
				swap(ar[j], ar[j + 1]);
	
	for (int i = -1; i < 6;)
	{
		int count = 0;
		do {
			count++; i++;
		} while (ar[i] == ar[i + 1]);
		cout << count << " people are " << ar[i]<< " year old" << endl;
	}


	
	return 0;
}