#include "vehicle.h"


vehicle::vehicle():founder("no member"), year(0), price(0)
{
}

vehicle::vehicle(char * f, int p, int y): year(y), price(p)

{
	strcpy(founder, f);
}

void vehicle::changefounder(char * f)
{
	strcpy(founder, f);
}

void vehicle::changeyear(int y)
{
	year = y;
}

car::car() :vehicle::Vehicle(), speed(0), v(0),mark("no mark")
{
}

car::car(char * f, int p, int y, int s, int vv, char * m):vehicle::Vehicle(f,p,y), speed(s), v(vv)
{
	strcpy(mark, m);
}

double car::recountprice()
{
	double k, a, b;
	if (year >= 2010)a = 1.4;
	else
	{
		if (year >= 2000) a = 1.2;
		else a = 0.8;
	}
	if (v >= 250)b = 1.4;
	else
	{
		if (v >= 150) b = 1.2;
		else b = 0.8;
	}
	k = a*b;
	return static_cast<double>(price*k);
}

void car::print(ofstream&out)
{
	out << "Car:   " << endl;
	out << "Founder: " << founder << endl
		<< "Price: " << price << endl
		<< "Year: " << year << endl
		<< "Max speed: " << speed << endl
		<< "Volume: " << v << endl
		<< "Mark: " << mark << endl;

}

car & car::operator=(car & c)
{
	strcpy(mark, c.mark);
	strcpy(founder, c.founder);
	price = c.price;
	year = c.year;
	speed = c.speed;
	v = c.v;
	return *this;
}

bus::bus() :vehicle::Vehicle(), passengers(0), v(0), mark("no mark")
{
}

bus::bus(char * f, int p, int y, int pas, int vv, char * m) : vehicle::Vehicle(f, p, y), passengers(pas), v(vv)
{
	strcpy(mark, m);
}

double bus::recountprice()
{
	double k, a, b;
	if (year >= 2010)a = 1.4;
	else
	{
		if (year >= 2000) a = 1.2;
		else a = 0.8;
	}
	if (passengers >= 200)b = 1.4;
	else
	{
		if (passengers >= 100) b = 1.2;
		else b = 0.8;
	}
	k = a*b;
	return static_cast<double>(price*k);
}

void bus::print(ofstream&out)
{
	out << "Bus:   " << endl;
	out << "Founder: " << founder << endl
		<< "Price: " << price << endl
		<< "Year: " << year << endl
		<< "Max amount of passengers: " << passengers << endl
		<< "Volume: " << v << endl
		<< "Mark: " << mark << endl;
}

bus & bus::operator=(bus& c)
{
	strcpy(mark, c.mark);
	strcpy(founder, c.founder);
	price = c.price;
	year = c.year;
	passengers = c.passengers;
	v = c.v;
	return *this;
}
