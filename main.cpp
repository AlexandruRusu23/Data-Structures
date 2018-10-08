#include "DetectPlatform.h"

#include "testLinkedList.hpp"
#include "testBinaryTree.hpp"

int main()
{
    //testLinkedList();
    testBinaryTree();

	if (Platform::GetPlatformName() == "windows")
		system("pause");

    return 0;
}

