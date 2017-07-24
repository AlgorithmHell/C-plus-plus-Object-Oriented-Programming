#include "SLE.h"

void Liner::set_Series()
{
	arr[0] = a1;
	for (int i(1); i <amount; i++)
	{
		arr[i] = arr[i - 1] + d;
	}

}

int Liner::get_element(const int & num)
{
	return arr[num - 1];
}

double Liner::Sum()
{
	double k = d*(amount - 1);
	double sum = ((2 * a1 + k)) * amount / 2;
	return sum;
}

void Exponential::set_Series()
{
	arr[0] = a1;
	for (int i(1); i < amount; i++)
		arr[i] = arr[i - 1] * d;

}

int Exponential::get_element(const int & num)
{
	return arr[num - 1];
}
double Exponential::Sum()
{
	double sum = (arr[amount - 1] * d - a1) / (d - 1);
	return sum;
}

void Series::print()
{
	ofstream of("execution.txt", ios::app);
	for (int i(0); i < amount; i++)
		of << arr[i] << " ";
	of << endl;
}
