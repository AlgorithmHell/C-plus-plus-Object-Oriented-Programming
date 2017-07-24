#include "list.h"
#include <string>
template <class T>
void TryArrayFunctions(larray<T>&);
template <class T>
void TryArrayClear(larray<T>&);
template <class T>
void TryArrayAtFunction(larray<T>&);
int main()
{
	
	larray<int> l;
	TryArrayFunctions(l);
	TryArrayClear(l);
	TryArrayAtFunction(l);
	larray<string> s;
	
	string a[]={"string zero","string one","string two"};
	s.push_back(a[0]);
	s.push_front(a[1]);
	s.push_front(a[2]);
	s.pop_back();
	cout << s[0] << " " << s[1] << endl;


	
	return 0;
}
template <class T>
void TryArrayFunctions(larray<T>&l)
{

	for (int i = 0; i < 10; i++)
		l.push_back(i + 1);
	for (int i = 11; i < 21; i++)
		l.push_front(i);
	cout << "l.Push_back(val), l.push_front()val ,l.size() and overloaded << and [ ] " << endl;
	for (int i = 0; i < l.size(); i++)
		cout << l[i] << ends;
	cout << endl;
}
template <class T>
void TryArrayClear(larray<T>&l)
{
	l.clear();
	cout << "l.size() : " << l.size() << endl;
}
template <class T>
void TryArrayAtFunction(larray<T>&l)
{
	for (int i = 34; i < 48; i += 2)
		l.push_back(i);
	for (int i = 11; i < 18; i++)
		l.push_front(i);
	cout << "l.Push_back(val), l.push_front()val ,l.size() and overloaded << and l.at(index) " << endl;
	for (int i = 0; i < l.size(); i++)
		cout << l.at(i) << ends;
	cout << endl;
}