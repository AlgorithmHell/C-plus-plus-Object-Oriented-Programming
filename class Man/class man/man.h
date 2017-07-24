#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class man
{
protected:
	char*name;
	int age;
	char*sex;
	int weight;
public:
	int get_age() {return age;};
		man();
	man(char * namet, int aget, int weightt, char*sex);
	man(man&m);
	virtual ~man();
	virtual void show();
	void change_name(char*n);
	void change_age(const int a);
	void change_weight(const int w);
	bool is_man(man&);
	bool is_woman(man& );
	bool compare_weight(man&);
	bool compare_age(man&);
	virtual bool  operator==(man&);
	man operator=(man&);
	friend ostream& operator<<(ostream&print, man&);


};
class student :public man
{
	int studage;
public:
	int get_studage() { return studage; }
	student() :studage(2016) {};
	student(char*namet,int aget,int weightt,char*sext,int st) :studage(st), man(namet,aget,weightt,sext) {};
	student(student&s);
	void show();
	bool operator==(student &s);
	void change_stud_age(int a);
	void stud_age_increment();
	friend ostream&operator<<(ostream&print, student&);
};