#include "SLE.h"
#include <iostream>
#include<cmath>
#include <fstream>



using namespace std;
int main()
{
	Series*ptr;
	ofstream of("execution.txt",ios::app);


	Liner l1(10, 1, 2);
	l1.set_Series();
	l1.print();
	ptr = dynamic_cast<Liner*>(&l1);
	of << "Liner: " << endl;
	of << "Sum: " << ptr->Sum() << endl;
	of << "5th element: " << ptr->get_element(5) << endl;


	Exponential e1(10, 1, 2);	
	e1.set_Series();
	ptr = dynamic_cast<Exponential*>(&e1);	
	ptr->print();
	of << "Exponential: " << endl;
	of << "Sum: " << ptr->Sum() << endl;
	of << "5th element: " << ptr->get_element(5) << endl;
	

	return 0;
}