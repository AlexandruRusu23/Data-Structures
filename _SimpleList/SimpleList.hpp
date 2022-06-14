#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

#include <cstdint>
#include <ostream>

namespace DataStructures
{
    template<typename Data>
    class SimpleList;

    template <class Data>
    std::ostream& operator<<(std::ostream& os, const SimpleList<Data>& list);

    template<typename Data>
    class SimpleNode
    {
    private:
        SimpleNode() = delete;
        SimpleNode(Data data) 
            : m_data(data)
            , m_next(nullptr)
        {}
		virtual ~SimpleNode() {}

		friend class SimpleList<Data>;
		friend std::ostream& operator<<<>(std::ostream &os, const SimpleList<Data>& simpleList);

		Data m_data;
        SimpleNode *m_next;
    };

    template<typename Data>
    class SimpleList
    {
    public:
        SimpleList() : m_size(0) {}
		virtual ~SimpleList() {}
		
        uint64_t size() const { return m_size; }

        void insert(Data data);
        void reverse();
        
        friend std::ostream& operator<<<>(std::ostream& os, const SimpleList<Data>& simpleList);

    private:
        SimpleNode<Data>* m_head = nullptr;
        SimpleNode<Data> *m_tail = nullptr;
		uint64_t m_size;
    };

    template <class Data>
    std::ostream& operator<<(std::ostream& os, const SimpleList<Data>& list)
    {
        SimpleNode<Data>* iterator = list.m_head;

        while (iterator != nullptr)
        {
            os << iterator->m_data << ' ';
            iterator = iterator->m_next;
        }

        return os;
    }

    template <class Data>
    void SimpleList<Data>::insert(Data data)
    {
        m_size++;

        if (m_tail == nullptr)
        {
            m_tail = new SimpleNode<Data>(data);
            m_head = m_tail;
            return;
        }

        m_tail->m_next = new SimpleNode<Data>(data);
        m_tail = m_tail->m_next;
    }

    //head                          tail
    // [] <- [] -> [] -> [] -> [] -> []
    //tail              
    //            head
    template <class Data>
    void SimpleList<Data>::reverse()
    {
        m_tail = m_head;
        SimpleNode<Data>* first = m_head;
        SimpleNode<Data>* second = m_head->m_next;
        m_tail->m_next = nullptr;

        while (second != nullptr)
        {
            m_head = second;
            second = m_head->m_next;
            m_head->m_next = first;
            first = m_head;
        }
    }
}

#endif // SIMPLE_LIST_H

