#include "vehicle.h"

int main()
{

	cout << "Checking the work of methods: " << endl;
	cout << "Cars " << endl << endl;
	Car a("founder", 9000, 2014, 250, 270, "Volvo");
	Car a1 = a;
	a.print();
	cout << endl << "a1=a" << endl;
	a1.print();
	cout << "recounted price: " << a1.recountprice() << " $ " << endl << endl;
	cout << "changing somethig" << endl << endl;
	a.changefounder("I have changed founder");
	a.changeyear(1998);
	a.print();
	cout << endl << endl << "Buses " << endl << endl;
	bus s("founder", 9000, 2008, 250, 270, "Wolksvagen");
	bus s1 = s;
	s.print();
	cout << endl << "s1=s" << endl;
	s1.print();
	cout << "recounted price: " << s1.recountprice() << " $ " <<endl<< endl;
	cout << "changing somethig" << endl << endl;
	s.changefounder("I have changed founder");
	s.changeyear(2000);
	s.print();
	cout << endl << "enter '0' something to clean the screen" << endl;
	int b;
	cin >> b;
	system("cls");
	ofstream out("out.txt");
	ifstream fin("fin.txt");


	vehicle*arr[7];
	Car c1, c3, c5, c7;
	int i = 0;
	while (!fin.eof())
	{
		int p, y, s, v;
		char*f = new char[30];
		char*m = new char[30];
		char type;
		fin >> type;
		if (type == 'c')
		{
			fin >> f >> p >> y >> s >> v >> m;
			arr[i++] = new Car(f, p, y, s, v, m);
		}
		if (type == 'b')
		{
			fin >> f >> p >> y >> s >> v >> m;
			arr[i++] = new bus(f, p, y, s, v, m);
		}
		delete[]f;
		delete[]m;
	}
	for (int i(0); i < 7; i++)
	{
		(*arr[i]).print(out);
		out << endl;
	}

	Car*t = nullptr;
	int*year;
	int yea;
	cout << "Enter the particular year:(better to enter 2015) " << endl;
	cin >> yea;
	year = new int[yea];
	int x = 0;
	for (int i(0); i < 7; i++)
	{
		t = dynamic_cast<Car*>(arr[i]);
		if (t && (*arr[i]).get_year() == yea)
		{
			cout << "Recounted price of Vehicle " << i + 1
				<< " is " << arr[i]->recountprice() << endl;
		}
	}
	cout << endl;



	string mark[7];
	for (int i(0); i < 7; i++)
		mark[i] = arr[i]->get_mark();


	for (int i = 6; i>0; i--)
		for (int j = 0; j < i; j++)
		{
			if (mark[j]>mark[j + 1])
			{

				string buf = mark[j];
				mark[j] = mark[j + 1];
				mark[j + 1] = buf;

			}
		}
	int q;
	for (q=-1; q < 6;)
	{
		int count = 0;
		do {
			count++; q++;
		} while (mark[q] == mark[q + 1]);
		cout << count << " Cars and buses have mark:  " << mark[q] << endl;
	}


	
	return 0;
}