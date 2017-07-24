#pragma once
#pragma once
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Student {

public:
	int group;
	char *name;
	Student() {
		name = new char[8];
		name = "Unknown";
		group = 1;
	}
	Student(char *n, int gr) {
		group = gr;
		name = new char[strlen(n) + 1];
		name = n;
	}
	/*~Student() {
	delete [] name;
	}*/
	virtual void Show() {
		cout << "Student name:" << name << endl << "Group:" << group;
	}


};
class FirstSession : public  Student {
public:
	int group;
	char *name;
	double *marks[4];
	FirstSession() :Student() {
		for (int i = 0; i < 4; i++) {
			marks[i] = 0;
		}
	}
	FirstSession(char *n, int gr, double *m) : Student(n, gr) {
		group = gr;
		name = new char[strlen(n) + 1];
		name = n;
		for (int i = 0; i < 4; i++) {
			marks[i] = &m[i];
		}

	}
	/*~FirstSession() {
	delete[] name;
	}*/
	virtual void Show() {
		Student::Show();
		cout << endl;
		cout << "First Session :" << endl;
		for (int i = 0; i < 4; i++) {
			cout << *marks[i] << endl;
		}
	}
	double Average() {
		double summ = 0.0;
		double average;

		for (int i = 0; i < 4; i++) {
			this->marks[i] = marks[i];
			summ += *marks[i];
		}
		average = summ / 4;
		return average;
	}


};
class SecondSession :public FirstSession {
public:
	int group;
	char *name;
	double *marks[4];
	double *arr[4];

	SecondSession() :FirstSession() {
		for (int i = 0; i < 4; i++) {
			marks[i] = 0;
			arr[i] = 0;
		}
	}
	SecondSession(char *n, int gr, double *m, double *l) : FirstSession(n, gr, m) {
		group = gr;
		name = new char[strlen(n) + 1];
		name = n;
		for (int i = 0; i < 4; i++) {
			marks[i] = &m[i];
			arr[i] = &l[i];
		}

	}
	/*~SecondSession() {
	delete[] name;
	}*/
	void SecondSession::Show() {
		FirstSession::Show();
		cout << "Second Session :" << endl;
		for (int i = 0; i < 4; i++) {
			cout << *arr[i] << endl;
		}

	}
	double SecondSession::Average() {
		FirstSession::Average();
		double average = FirstSession::Average();
		double summ = average * 4;

		double summ1 = 0.0;
		double average1;
		for (int i = 0; i < 4; i++) {
			this->arr[i] = arr[i];
			summ1 += *arr[i];
		}
		average1 = summ1 / 4;
		return average1;
	}

	double OverallAverage() {
		double oa = (FirstSession::Average() * 4 + SecondSession::Average() * 4) / 8;
		return oa;
	}


};