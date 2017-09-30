#include <iostream>
#include "KQueue.h"
#include "Visitor.h"
#include <vector>

int main()
{
	KQueue<int> Queue1 =std::initializer_list<int> { 1,3,5,4,7 };
	KQueue<int>Queue2 = Queue1;
	QueueIterator<int> Iter1(Queue1);
	QueueIterator<int> Iter2(Queue2);
	
	for (Iter1.first(); !Iter1.isDone(); Iter1.next())
	{
		(*Iter1)++;
	}
	KQueue<int> Queue3= Queue1 + Queue2;
	QueueIterator<int> Iter3(Queue3);
	for (Iter2.first(); ! Iter2.isDone(); Iter2.next())
	{
		std::cout<<*Iter2<<std::ends;

	}
	std::cout << std::endl;
	for (Iter3.first(); !Iter3.isDone(); Iter3.next())
	{
		std::cout << *Iter3 << std::ends;

	}
	std::cout << std::endl;
	std::cout << std::boolalpha << (Queue3 == Queue2 )<< std::ends<< (Queue3 != Queue2)<<std::endl;
	Queue3 = Queue2;
	std::cout << std::boolalpha << (Queue3 == Queue2) << std::ends << (Queue3 != Queue2) << std::endl;

	Queue3 += Queue1;
	for (Iter3.first(); !Iter3.isDone(); Iter3.next())
	{
		std::cout << *Iter3 << std::ends;
	}
	Queue1.Clear();
	Queue1.Append(std::initializer_list<int>{2, 6, 4, 3});
	std::vector<KQueue<int> > vectorOfQueues = { Queue1,Queue2,Queue3 };
	CountOperation<int> countOperation;
	MultiplicationOperation<int> multiplicationOperation;
	
	for (auto iter : vectorOfQueues)
	{
		std::cout << iter << std::ends;
		iter.accept(&countOperation);
		std::cout << "Count : " <<countOperation << std::ends;
		iter.accept(&multiplicationOperation);
		std::cout << "Multiplication : " << multiplicationOperation << std::endl;
		countOperation.reset();
		multiplicationOperation.reset();
	}
	

	return 0;
}