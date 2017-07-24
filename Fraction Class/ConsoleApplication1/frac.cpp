#include "frac.h"

frac::frac():r(0),z(0)
{
	
}

frac::frac(int zt, int rt) :z(zt), r(rt)
{
}

int frac::getz()
{
	return z;
}

int frac::getr()
{
	return r;
}

bool frac::operator<=(frac &a)
{
	char x[10], y[10];
	if (z == a.z&&r == a.r)return false;
	if (z > a.z)return false;
	if (r < a.r)
	{
		int a1 = r*pow(10, strlen(_itoa(a.r, y, 10)) - strlen(_itoa(r, x, 10)));
		if (a1 > a.r) return false;
		else return true;
	}
	if (r > a.r)
	{
		int a1 = a.r*pow(10, strlen(_itoa(r, y, 10)) - strlen(_itoa(a.r, x, 10)));
		if (a1 > r) return false;
		else return true;
	}
}

bool frac::operator>=(frac &a)
{
	char x[10], y[10];
	if (z == a.z&&r == a.r)return true;
	if (z > a.z)return true;
	if (r < a.r)
	{	int a1 = r*pow(10, strlen(_itoa(a.r, y, 10)) - strlen(_itoa(r, x, 10)));
		if (a1 > a.r) return true;
		else return false;		
	}
	if (r > a.r)
	{
		int a1 = a.r*pow(10, strlen(_itoa(r, y, 10)) - strlen(_itoa(a.r, x, 10)));
		if (a1 > r) return true;
		else return false;
	}
}

frac & frac::operator=(frac & a)
{
	z = a.z;
	r = a.r;
	return *this;
}

 frac frac::operator*( frac & a)
{
	char x[10], y[10];
	frac temp;
	int  a1 = 0, b1 = 0;
	int c=0;
	a1 = z*pow(10, strlen(_itoa(r, x, 10))) + r;
	b1= a.z*pow(10, strlen(_itoa(a.r, y, 10))) + a.r;
	c = a1*b1; 
	temp.z=c/ pow(10, strlen(x) + strlen(y));
	temp.r = c % static_cast<int>(pow(10, strlen(x) + strlen(y)));
	return temp;
}

/*frac frac::operator+(frac & a)
{
	char x[10];
	char y[10];
	frac temp;
	temp.z = a.z+z;
	if (strlen(_itoa(r, x, 10)) < strlen(_itoa(a.r, y, 10)))
	{
		temp.r = a.r + r*pow(10, strlen(y) - strlen(x));
		if (temp.r >= pow(10, strlen(y) - strlen(x)))
		{
			z += temp.r / pow(10, strlen(y) - strlen(x));
			temp.r -= pow(10, strlen(y) - strlen(x));
		}return frac(temp);
	}
	if (strlen(_itoa(r, x, 10)) > strlen(_itoa(a.r, y, 10)))
	{
		temp.r = r + a.r*pow(10, strlen(x) - strlen(y));
		if (temp.r >= pow(10, strlen(x) - strlen(y)))
		{
			z += temp.r / pow(10, strlen(x) - strlen(y));
			temp.r -= pow(10, strlen(x) - strlen(y));
		}return frac(temp);
	}
	if (strlen(_itoa(r, x, 10)) == strlen(_itoa(a.r, y, 10)))
	{

		temp.r = r + a.r;
		if (temp.r >= pow(10,strlen(x)))
		{
			temp.z += temp.r / pow(10, strlen(x));
			temp.r -= pow(10, strlen(x));
		}return frac(temp);
	}
	
}

frac frac::operator-(frac & a)
{
	frac temp;
	int a1, b1,c;
	char x[10], y[10];
	a1 = r + z*pow(10, strlen(_itoa(r, x, 10)));
	b1= a.r + a.z*pow(10, strlen(_itoa(a.r, y, 10)));
	c = a1 - b1;
	if (strlen(x) >= strlen(y))
	{
		temp.z = c / pow(10,strlen(x));
		temp.r = c%static_cast<int>(pow(10,strlen(x))); return frac(temp);
	}
	if (strlen(y) > strlen(x))
	{
		temp.z = c / pow(10, strlen(y));
		temp.r = c%static_cast<int>(pow(10, strlen(y))); return frac(temp);
	}
	
	
}

void frac::operator+=(frac & a)
{
	z += a.z;
	
	char x[10];
	char y[10];
	
	if (strlen(_itoa(r, x, 10)) < strlen(_itoa(a.r, y, 10)))
	{
		r = a.r + r*pow(10, strlen(y) - strlen(x));
		if (r >= pow(10, strlen(y) - strlen(x)))
		{
			z += r / pow(10, strlen(y) - strlen(x));
			r -= pow(10, strlen(y) - strlen(x));
		}
		return;
	}
	if (strlen(_itoa(r, x, 10)) > strlen(_itoa(a.r, y, 10)))
	{
		r = r + a.r*pow(10, strlen(x) - strlen(y));
		if (r >= pow(10, strlen(x) - strlen(y)))
		{
			z += r / pow(10, strlen(x) - strlen(y));
			r -= pow(10, strlen(x) - strlen(y));
		}
		return;
	}
	if (strlen(_itoa(r, x, 10)) == strlen(_itoa(a.r, y, 10)))
	{
		r += a.r;
		if (r >= pow(10, strlen(x)))
		{
			z += r / pow(10, strlen(x));
			r -= pow(10, strlen(x));
		}return;
	}
}*/


frac frac::operator+(frac&a)
{
	char x[10];
	char y[10];
	frac temp;
	temp.z =  this->z+a.z;
	if (strlen(_itoa(this->r, x, 10)) > strlen(_itoa(a.r, y, 10)))
	{
		temp.r = this->r + a.r * 10;
	}
	if (strlen(_itoa(this->r, x, 10)) < strlen(_itoa(a.r, y, 10)))
	{
		temp.r = this->r * 10 + a.r;
	}
	if (strlen(_itoa(this->r, x, 10)) == strlen(_itoa(a.r, y, 10)))
	{
		temp.r = this->r + a.r;
	}
	if (temp.r >= 100)
	{
		temp.z += temp.r / 100;
		temp.r %= 100;
	}


	return frac(temp);
}
frac frac::operator-(frac&a)
{
	char x[10], x1[10];
	char y[10], y1[10];
	frac temp;
	double buf;

	strcpy(x1, _itoa(this->z, x, 10));
	strcat(x1, ".");
	strcat(x1, _itoa(this->r, x, 10));
	strcpy(y1, _itoa(a.z, y, 10));
	strcat(y1, ".");
	strcat(y1, _itoa(a.r, y, 10));
	buf = atof(x1) - atof(y1);
	temp.z = atoi(_itoa(buf, x1, 10));
	temp.r =static_cast<int>(buf*100-temp.z*100);
	

	return frac(temp);
}
frac frac::operator+=(frac&a)
{
	char x[10];
	char y[10];
	frac temp;
	 this->z += a.z;
	if (strlen(_itoa(this->r, x, 10)) > strlen(_itoa(a.r, y, 10)))
	{
		this->r += a.r * 10;
	}
	if (strlen(_itoa(this->r, x, 10)) < strlen(_itoa(a.r, y, 10)))
	{
		temp.r = this->r * 10 + a.r;
		this->r = temp.r;
	}
	if (strlen(_itoa(this->r, x, 10)) == strlen(_itoa(a.r, y, 10)))
	{
		temp.r = this->r + a.r;
		this->r = temp.r;
	}
	if (this->r >= 100)
	{
		this->z += temp.r / 100;
		this->r %= 100;
	}


	return *this;
}

ostream & operator<<(ostream & print, frac & a)
{
	return print << a.z << "." << a.r<<" ";
}

istream & operator >> (istream & read, frac & a)
{
	return read >> a.z >> a.r;
}
