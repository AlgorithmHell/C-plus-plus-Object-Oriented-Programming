#include <iostream>
#include <cstring>
#include <cassert>
#include "ASQ.h"
using namespace std;
int main()
{
	//check work of arrayy
	cout << "check work of array,input 10 numbers " << endl;
	arrayy a1(10);
	cin >> a1;
	system("cls");
	cout <<"array: "<< a1 << endl;
	arrayy a2 = a1;
	cout <<"a2=a1: "<< a2;
	cout << endl;
	
	//check work of stackk
	cout << "check work of stack: " << endl;
	stackk st(10), st2;
	for (int i(0); i < 10; i++)
	    st.push(i + 1);
	cout << st << endl;
	st.pop();
	st.pop();
	st.print();
	cout << endl;
	st2 = st;
	st2.push(25);
	st2.push(26);
	st2.pop();
	st2.print();
	cout << endl;
	
	//check work of queue
	cout << "check work of queue: " << endl;
	queuee q1(10);
	for (int i(0); i < 5; i++)
		q1.push(i + 1);
	q1.print();
	q1.pop(); q1.pop();
	q1.print();
	q1.pop();
	q1.push(6); q1.push(7);
	q1.print();
	
	
	return 0;
}