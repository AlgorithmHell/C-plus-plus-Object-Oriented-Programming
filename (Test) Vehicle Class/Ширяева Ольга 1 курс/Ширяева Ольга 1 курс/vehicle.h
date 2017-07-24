#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define vehicle Vehicle
#define car Car
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;


class vehicle
{
protected:
	char founder[50];
	int price;
	int year;
public:
	vehicle();
	vehicle(char*f, int p, int y);
	virtual~vehicle() {}
	int get_year() { return year; }
	char*get_founder() { return founder; }
	void changefounder(char*f);
	void changeyear(int y);
	virtual void print(ofstream&out) = 0;
	virtual double recountprice() = 0;
	virtual char*get_mark() = 0;


};

class car : public vehicle
{
private:
	int speed;
	int v;
	char mark[50];
public:
	car();
	car(char*f, int p, int y, int s, int vv, char*m);
	int get_year() { return year; }
	char*get_mark() { return mark; }
	double recountprice();
	void print(ofstream&out);
	void print();
	car&operator=(car&c);
};

class bus : public vehicle
{
	int passengers;
	int v;
	char mark[50];
public:
	bus();
	bus(char*f, int p, int y, int pas, int vv, char*m);
	int get_year() { return year; }
	char*get_mark() { return mark; }
	double recountprice();
	void print(ofstream&out);
	void print();
	bus&operator=(bus&c);

};

