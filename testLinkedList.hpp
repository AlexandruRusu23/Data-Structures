#include <iostream>

#include "_LinkedList/LinkedList.h"

using namespace DataStructures;

void testLinkedList()
{
	std::cout << "[START] LinkedList test" << std::endl << std::endl;

	LinkedList<int> myIntegerList;
	LinkedList<double> myDoubleList;
	myIntegerList.append(10);
	myIntegerList.append(20);
	myIntegerList.append(30);
	myIntegerList.append(40);
	myIntegerList.append(50);
	myIntegerList.append(60);
	myIntegerList.append(70);
	myIntegerList.append(80);
	myIntegerList.append(90);
	myDoubleList.append(10.443);
	myDoubleList.append(235.23);
	myDoubleList.append(124.1286);
	std::cout << myIntegerList.size() << std::endl;
	std::cout << myDoubleList.size() << std::endl;
	std::cout << myIntegerList.getDataAt(2) << std::endl;
	std::cout << myIntegerList.getDataAt(6) << std::endl;
	std::cout << myIntegerList.indexOf(40) << std::endl;

	std::cout << myIntegerList << std::endl;
	std::cout << myIntegerList.size() << std::endl;
	myIntegerList.remove(40);
	std::cout << myIntegerList.size() << std::endl;
	std::cout << myIntegerList << std::endl;
	myIntegerList.removeAt(0);
	std::cout << myIntegerList.size() << std::endl;
	std::cout << myIntegerList << std::endl;

	while (myIntegerList.size())
	{
		myIntegerList.removeAt(0);
		std::cout << myIntegerList.size() << std::endl;
		std::cout << myIntegerList << std::endl;
	}

	std::cout << "[END] LinkedList test" << std::endl << std::endl;
}

