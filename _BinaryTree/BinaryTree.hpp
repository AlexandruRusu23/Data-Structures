#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cstdint>
#include <vector>

namespace DataStructures
{
    template <class Data>
    class BinaryTree;

    template <class Data>
    class TreeNode
    {
    private:
        TreeNode() = delete;
        TreeNode(Data data) : m_data(data) {}
        virtual ~TreeNode(){}

        friend class BinaryTree<Data>;
        
        Data m_data;
        TreeNode *m_parent = nullptr;
        TreeNode *m_left = nullptr;
        TreeNode *m_right = nullptr;
    };

    template <class Data>
    class BinaryTree
    {
    public:
        BinaryTree();
        virtual ~BinaryTree();

        uint64_t Size();

        void Insert(Data data);
        void Clear();

        const std::vector<Data> PreorderTraversal();
        const std::vector<Data> InorderTraversal();
        const std::vector<Data> PostorderTraversal();

    private:
        void Insert(Data data, TreeNode<Data> *node);
        void Clear(TreeNode<Data> *node);

        void Preorder(TreeNode<Data> *node, std::vector<Data>& output);
        void Inorder(TreeNode<Data> *node, std::vector<Data>& output);
        void Postorder(TreeNode<Data> *node, std::vector<Data>& output);

        TreeNode<Data> *m_root = nullptr;
        uint64_t m_size;
    };

    template <class Data>
    BinaryTree<Data>::BinaryTree()
        : m_size(0)
    {
    }

    template <class Data>
    BinaryTree<Data>::~BinaryTree()
    {
        Clear();
    }

    template <class Data>
    uint64_t BinaryTree<Data>::Size()
    {
        return m_size;
    }

    template <class Data>
    void BinaryTree<Data>::Insert(Data data)
    {
        if (m_root != nullptr)
            Insert(data, m_root);
        else
        {
            m_root = new TreeNode<Data>(data);
            m_size++;
        }
    }

    template <class Data>
    void BinaryTree<Data>::Clear()
    {
        if (m_root == nullptr)
            return;
        
        Clear(m_root);

        m_root = nullptr;
        m_size = 0;
    }

    template <class Data>
    const std::vector<Data> BinaryTree<Data>::PreorderTraversal()
    {
        std::vector<Data> output;
        Preorder(m_root, output);
        return output;
    }
    
    template <class Data>
    const std::vector<Data> BinaryTree<Data>::InorderTraversal()
    {
        std::vector<Data> output;
        Inorder(m_root, output);
        return output;
    }

    template <class Data>
    const std::vector<Data> BinaryTree<Data>::PostorderTraversal()
    {
        std::vector<Data> output;
        Postorder(m_root, output);
        return output;
    }

    template <class Data>
    void BinaryTree<Data>::Insert(Data data, TreeNode<Data> *node)
    {
        if (data < node->m_data)
        {
            if (node->m_left != nullptr)
                Insert(data, node->m_left);
            else
            {
                node->m_left = new TreeNode<Data>(data);
                node->m_left->m_parent = node;
                m_size++;
            }
        }
        else
        {
            if (node->m_right != nullptr)
                Insert(data, node->m_right);
            else
            {
                node->m_right = new TreeNode<Data>(data);
                node->m_right->m_parent = node;
                m_size++;
            }
        }
    }

    template <class Data>
    void BinaryTree<Data>::Clear(TreeNode<Data> *node)
    {
        if (node == nullptr)
            return;

        Clear(node->m_left);
        Clear(node->m_right);
        std::cout << node->m_data << std::endl;
        delete node;
    }

    template <class Data>
    void BinaryTree<Data>::Preorder(TreeNode<Data> *node, std::vector<Data>& output)
    {
        if (node == nullptr) return;
        output.push_back(node->m_data);
        Preorder(node->m_left, output);
        Preorder(node->m_right, output);
    }

    template <class Data>
    void BinaryTree<Data>::Inorder(TreeNode<Data> *node, std::vector<Data>& output)
    {
        if (node == nullptr) return;
        Inorder(node->m_left, output);
        output.push_back(node->m_data);
        Inorder(node->m_right, output);
    }

    template <class Data>
    void BinaryTree<Data>::Postorder(TreeNode<Data> *node, std::vector<Data>& output)
    {
        if (node == nullptr) return;
        Postorder(node->m_left, output);
        Postorder(node->m_right, output);
        output.push_back(node->m_data);
    }
}

#endif // BINARY_TREE_H

