#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <cstdint>

namespace DataStructures
{
    class TreeNode
    {
    public:
        int val;
        int height;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int val) : val(val), height(1), left(nullptr), right(nullptr) {}
        TreeNode(int val, int height) : val(val), height(height), left(nullptr), right(nullptr) {}
        TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), height(1), left(left), right(right) {}
    };

    class Solution
    {
    public:
        TreeNode *root = nullptr;

        void printInorder(TreeNode *root)
        {
            if (root == nullptr)
                return;

            printInorder(root->left);
            std::cout << root->val << "(" << getHeight(root) << ") ";
            printInorder(root->right);
        }

        void print()
        {
            printInorder(root);
            std::cout << std::endl;
        }

        int getHeight(TreeNode *node)
        {
            if (node == nullptr)
                return 0;

            return node->height;
        }

        int getBalance(TreeNode *node)
        {
            if (node == nullptr)
                return 0;

            return getHeight(node->left) - getHeight(node->right);
        }

        TreeNode *leftRotate(TreeNode *node)
        {
            TreeNode *newRoot = node->right;
            TreeNode *temp = newRoot->left;

            newRoot->left = node;
            node->right = temp;

            node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
            newRoot->height = std::max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

            return newRoot;
        }

        TreeNode *rightRotate(TreeNode *node)
        {
            TreeNode *newRoot = node->left;
            TreeNode *temp = newRoot->right;

            newRoot->right = node;
            node->left = temp;

            node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
            newRoot->height = std::max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

            return newRoot;
        }

        void insert(int value)
        {
            root = insert(root, value);
        }

        TreeNode *insert(TreeNode *root, int val)
        {
            if (!root)
            {
                return new TreeNode(val);
            }
            else if (val < root->val)
            {
                root->left = insert(root->left, val);
            }
            else
            {
                root->right = insert(root->right, val);
            }

            root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;

            int balance = getBalance(root);

            if (balance > 1 && val < root->left->val)
                return rightRotate(root);
            if (balance < -1 && val > root->right->val)
                return leftRotate(root);

            if (balance > 1 && val > root->left->val)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && val < root->right->val)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
        }
    };
}

#endif // AVL_TREE_H

