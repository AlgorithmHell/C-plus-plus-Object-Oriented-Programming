#include "man.h"

man::man() :age(0), weight(0)
{
	sex = new char[3];
	sex = "man";
	name = new char[9];
	name = "empty man";
}

man::man(char * namet, int aget, int weightt, char*sext) :weight(weightt), age(aget)
{
	sex = new char[strlen(sext) + 1];
	strcpy(sex, sext);
	name = new char[strlen(namet) + 1];
	strcpy(name, namet);

}

man::man(man & m):weight(m.weight),age(m.age)
{
	sex = new char[strlen(m.sex) + 1];
	strcpy(sex, m.sex);
	name = new char[strlen(m.name) + 1];
	strcpy(name, m.name);
}

man::~man()
{
	delete[] name;
	delete[] sex;
}

void man::show()
{
	cout << name << endl
		<< "sex: " << sex << endl
		<< "age: " << age << endl
		<< "weight: " << weight<<endl<<endl;
}

void man::change_name(char * n)
{
	delete[]name;
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

void man::change_age(const int a)
{
	age = a;
}

void man::change_weight(const int w)
{
	weight = w;
}

bool man::is_man(man & m)
{
	if (strcmp(m.sex, "man") == 0) return true;
	else return false;
}

bool man::is_woman(man &m)
{
	if (strcmp(m.sex, "woman") == 0) return true;
	else return false;
}

bool man::compare_weight(man &m)
{
	if (weight == m.weight) return 0;
	if (weight > m.weight) return 1;
	else return -1;

}

bool man::compare_age(man &m)
{
	if (age == m.age) return 0;
	if (age > m.age) return 1;
	else return -1;
}

bool man::operator==(man &m)
{
	if (age == m.age)
		return true;
	else return false;
	
}

man man::operator=(man &m)
{
	weight = m.weight;
	age = m.age;
	delete[]sex;
	delete[] name;
	sex = new char[strlen(m.sex) + 1];
	strcpy(sex, m.sex);
	name = new char[strlen(m.name) + 1];
	strcpy(name, m.name);
	return man(*this);
}

student::student(student &s): studage(s.studage), man(s)
{
	
}

void student::show()
{
	man::show();
	cout << "studying age: " << studage <<endl<< endl;
}

bool student::operator==(student &s)
{
	if (studage == s.studage) return true;
	else return false;
}

void student::change_stud_age(int a)
{
	studage = a;
}

void student::stud_age_increment()
{
	studage++;
}

ostream & operator<<(ostream & print, man &m)
{
	return print << m.name << endl
		<< "sex: " << m.sex << endl
		<< "age: " << m.age << endl
		<< "weight: " << m.weight << endl<<endl;
}

ostream & operator<<(ostream & print, student &m)
{
	return print << m.name << endl
		<< "sex: " << m.sex << endl
		<< "age: " << m.age << endl
		<< "weight: " << m.weight << endl
		<< "studying age: " << m.studage<<endl<<endl;
}
