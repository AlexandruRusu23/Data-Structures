#ifndef TEST_AVL_TREE_H
#define TEST_AVL_TREE_H

#include <iostream>

#include "_AVLTree/AVLTree.hpp"

using namespace DataStuctures;

void testAVLTree()
{
    Solution solution;

    solution.insert(10);
    solution.insert(30);
    solution.insert(20);
    solution.insert(70);
    solution.insert(40);
    solution.insert(50);

    solution.print();

    return 0;
}

#endif // AVL_TREE_H

