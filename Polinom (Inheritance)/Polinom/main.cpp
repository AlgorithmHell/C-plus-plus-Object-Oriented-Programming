#include <iostream>
#include <cmath>
#include <stdexcept>
#include <typeinfo>
#include "polinoms.h"
using namespace std;

int main()
{
	try 
	{
		arrayy a1(10,1);
		arrayy a2(a1), a6;
		arrayy a4(12, 6);
		arrayy a3 = a1 + a4;
		cout << a1 << endl << a2 << endl << a4 << endl << a3 << endl;
		cout << a3[10] << endl;
		polinoms p1(3, 2);
		polinoms p2(3, 2);
		polinoms p3=p1+p2;
		
		cout << p1 << endl << p2 << endl;
		cout << p3 << endl;
		p3 = p1*p2;
		cout << p3 << endl;
		cout << p3.calculation(2) << endl;
		
		




	}
	catch (arrayy::too_big) { cout << "caught an exception\ntoo big size is required\n"; }
	catch(arrayy::neg_size){ cout << "caught an exception\nnegative size is required\n"; }
	catch (arrayy::wrong_index(er)) { cout << "caught an exception\n index '" << er.index << "' doesn't exist\n"; }

	return 0;
}