
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"StudentS(1-2).h"
#include<typeinfo>
	using namespace std;
	int main() {
		char a[20];
		cout << "Enter Student's Name: ";
		cin.getline(a, 20);
		cout << endl;
		int g;
		cout << "Enter Student's Group:";
		cin >> g;
		double m[4];
		double mas[4];
		cout << "Enter Student's Marks For The First Session :";
		for (int i = 0; i < 4; i++) {
			cin >> m[i];
		}
		cout << endl;
		cout << "Enter Student's Marks For The Second Session :";
		for (int i = 0; i < 4; i++) {
			cin >> mas[i];
		}
		cout << endl;
		system("cls");
		SecondSession B(a, g, m, mas);
		B.Show();
		cout << "First Session Average = " << B.FirstSession::Average() << endl;
		cout << "Second Session Average = " << B.SecondSession::Average() << endl;
		cout << "Overall Average = " << B.OverallAverage() << endl;
		double array[4] = { 10,10,9,10 };
		double array1[4] = { 9,10,9,8 };
		Student St1("Charley", 6), St2("Ivan", 4);
		FirstSession FS1("Mark", 4, array), FS2("Mark", 4, array);
		SecondSession SS1("Lee", 4, array, array1), SS2("Lee", 4, array, array1);
		Student*M[6] = { &St1,&St2,&FS1,&FS2,&SS1,&SS2 };
		Student*S[6];
		FirstSession*FS[6];
		SecondSession *SS[6];
		
		int c = 0, c1 = 0, c2 = 0;
		for (int i = 0; i < 6; i++) {
			if (dynamic_cast<Student*>(M[i])) {
				S[c] = M[i];
				c++;

			}

			else if (dynamic_cast<FirstSession*>(M[i])) {
				FS[c1] = static_cast<FirstSession*>(M[i]);
				c1++;
			}
			else if (dynamic_cast<SecondSession*>(M[i]))  {
				SS[c2] = static_cast<SecondSession*>(M[i]);
				c2++;
			}
		}
		for (int i = 0; i < 6; i++) {
			cout << typeid(*M[i]).name() << endl;
		}
		cout << c << c1 << c2;
		FS1.Show();
		(*M[3]).Show();


		system("pause");
		return 0;
	}


	