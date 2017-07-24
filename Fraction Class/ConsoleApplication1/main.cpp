#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include "frac.h"

using namespace std;
int main()
{
	frac a, b, c;
	frac arr[5];
	cout << "Enter 2 fractions: \n";
	cin >> a;
	cin >> b;
	cout << a << b << endl;
	c = a + b;
	cout << a << "+" << b << " = " << c << endl; 
	c = a - b;
	cout << a << "-" << b << " = " << c << endl;
	cout << a << "*" << b << " = " << a*b << endl;

	if (a <= b) cout << a << " <= " << b << endl;
	else cout << a << " > " << b << endl;
	if(a>=b) cout << a << " >= " << b << endl;
	else cout << a << " < " << b << endl;
	cout << endl << endl;
	cout << "Enter 5 fractions \n";
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout<<arr[i];
	cout << "Sum: ";
	for (int i = 1; i < 5; i++)
		arr[0] += arr[i];
	cout << arr[0] << endl;



	return 0;
}