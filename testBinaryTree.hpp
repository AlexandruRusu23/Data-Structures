#include <iostream>

#include "_BinaryTree/BinaryTree.h"

using namespace DataStructures;

void testBinaryTree()
{
    std::cout << "[START] BinaryTree test" << std::endl << std::endl;

    BinaryTree<int> intBinaryTree;
    intBinaryTree.Insert(10);
    intBinaryTree.Insert(15);
    intBinaryTree.Insert(7);
    intBinaryTree.Insert(33);
    intBinaryTree.Insert(18);
    intBinaryTree.Insert(22);
    intBinaryTree.Insert(5);
    intBinaryTree.Clear();

    std::cout << "[END] BinaryTree test" << std::endl << std::endl;
}