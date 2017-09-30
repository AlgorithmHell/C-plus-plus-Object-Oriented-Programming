#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <sstream>
#include <typeinfo>
using namespace std;

string ToString()
{
	return string("");
}

string ToString(char*a)
{
	return string("");
}
double sum()
{
	return 0.;
}
double min()
{
	return _MAX_INT_DIG;
}
tuple<int, double> TupleSum()
{
	return make_tuple(0, 0.);
}
template<typename ...T, typename U>
double sum(U first, T...tail)
{
	
	return [first, tail...]() mutable 
	{
		return (first += sum(tail...));
	}();	
	
	
}
template <class...Args,typename T>
double min(T first,Args...args)
{
	
	return [first, args...]()mutable
	{
		double buf = min(args...);
		double Min = first<buf ? first : buf;
	    return double(Min);
	}();
	
	
};

template <class...Args,typename T>
tuple<int, double>TupleSum(T first, Args...tail)
{
	
	auto tupleSum = [first, tail...]()
	{
		tuple<int, double> ab = TupleSum(tail...);
		if (typeid(first) == typeid(int))
		{
			get<0>(ab) += first;
		}
		if (typeid(first) == typeid(double))
		{
			get<1>(ab) += first;
		}

		return ab;
	};
	return tupleSum();
};

template <class...Args,typename T>
string ToString(char*first, T second, Args...tail)
{
	
	return [first, second, tail...]()mutable
	{
		string res = ToString(first, tail...);
		ostringstream ost;
		ost << second;
		string buf(ost.str() + first);
		buf += res;
		return buf;
	}();
	
}
int main()
{
		
	double Func1 = sum(1, 3,2.5,'q');
	double Func2 = min(1, 3, 2.5, 'q',-1);
	tuple<int,double> Func3 = TupleSum(1, 2, 3.3, 4, 3.4,'m');
	string Func4 = ToString(";", 2, 3, 43, 4.4, 0.0);
	cout << Func1 << endl;
	cout << Func2 << endl;
	cout << get<0>(Func3) << ends << get<1>(Func3) << endl;
	cout << Func4 << endl;

	return 0;
}