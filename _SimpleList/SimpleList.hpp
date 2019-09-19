#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

#include <cstdint>
#include <ostream>

namespace DataStructures
{
    template<typename Data>
    class SimpleList;

    template<typename Data>
    class Node
    {
    private:
        Node() = delete;
        Node(Data data) : m_data(data) {}
		virtual ~Node() {}

		friend class SimpleList<Data>;
		friend std::ostream& operator<<<>(std::ostream &os, const SimpleList<Data>& simpleList);

		Data m_data;
		Node *m_next = nullptr;
    };

    template<typename Data>
    class SimpleList
    {
    public:
        List() : m_size(0) {}
		virtual ~List() {}
		
        uint64_t size() const { return m_size; }
        
    private:
        Node<Data> *m_head = nullptr;
		uint64_t m_size;
    };
}

#endif

