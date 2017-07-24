#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include "Set.h"
using namespace std;



int main()
{

	sett s1,s2,s3,s4,s5;
	s3 = s1;
	cin >> s1 >> s2 >> s3 >> s5;
	cout << endl;	
	cout << s1;
	cout << s2 << s3 << s5;
	
	if (s1 == s3) cout << "equal" << endl;
	else cout << "no"<<endl;
	if (s2 < s1)cout << "Yes" << endl;
	else cout << "No" << endl;
	 	
	 s4 = s1-s2;
	cout << s4;
	cout << endl;
	 s4 = s1 * s2;
	cout << s4;
	cout << endl;
	 s4 = s1 + s2;
	cout << s4;
	cout << endl;
	
	
	
	
	



	
	return 0;
}