#include "DetectPlatform.h"

#include "testList.hpp"
#include "testBinaryTree.hpp"

int main()
{
    testList();
    testBinaryTree();

	if (Platform::GetPlatformName() == "windows")
		system("pause");

    return 0;
}

