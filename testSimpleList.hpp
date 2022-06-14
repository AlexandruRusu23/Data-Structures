#ifndef TEST_SIMPLE_LIST_H
#define TEST_SIMPLE_LIST_H


#include <iostream>

#include "_SimpleList/SimpleList.hpp"

using namespace DataStructures;

void testSimpleList()
{
	std::cout << "[START] SimpleList test" << std::endl << std::endl;

	SimpleList<int> integerList;
	integerList.insert(3);
	integerList.insert(7);
	integerList.insert(2);
	integerList.insert(9);
	integerList.insert(5);
	integerList.insert(8);
	std::cout << integerList.size() << std::endl;
	std::cout << integerList << std::endl;
	integerList.reverse();
	std::cout << integerList.size() << std::endl;
	std::cout << integerList << std::endl;
	integerList.reverse();
	std::cout << integerList.size() << std::endl;
	std::cout << integerList << std::endl;

	std::cout << std::endl << "[END] SimpleList test" << std::endl << std::endl;
}

#endif // TEST_SIMPLE_LIST_H

