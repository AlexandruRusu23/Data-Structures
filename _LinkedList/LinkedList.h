#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstdint>
#include <string>

namespace DataStructures
{
	template <class Data>
	class LinkedList;

	template <class Data>
	std::ostream& operator<<(std::ostream &os, const LinkedList<Data>& list);

	template <class Data>
	class ListNode
	{
	private:
		ListNode() = delete;
		ListNode(Data data) : m_data(data) {}
		virtual ~ListNode() {}

		friend class LinkedList<Data>;
		friend std::ostream& operator<<<>(std::ostream &os, const LinkedList<Data>& list);

		Data m_data;
		ListNode *m_next = nullptr;
		ListNode *m_prev = nullptr;
	};

	template <class Data>
	class LinkedList
	{
	public:
		LinkedList() : m_size(0) {}
		virtual ~LinkedList() { removeAll(); }

		uint64_t size() const { return m_size; }
		bool contains(Data data) const;
		Data getDataAt(int64_t index) const;
		int64_t indexOf(Data data) const;

		void insertFirst(Data data);
		void append(Data data);
		void append(const LinkedList<Data>& list);
		void appendAfter(Data beforeData, Data data);

		void removeAll();
		bool removeAt(int64_t index);
		bool remove(Data data);

		friend std::ostream& operator<<<>(std::ostream &os, const LinkedList<Data>& list);

	private:
		Data findDataAscending(int64_t index) const;
		Data findDataDescending(int64_t index) const;

		ListNode<Data> *m_head = nullptr;
		ListNode<Data> *m_tail = nullptr;
		uint64_t m_size;
	};

	template <class Data>
	inline bool LinkedList<Data>::contains(Data data) const
	{
		ListNode<Data> *iterator = m_head;

		while (iterator != nullptr)
		{
			if (iterator->m_data == data)
				return true;

			iterator = iterator->m_next;
		}

		return false;
	}

	template <class Data>
	Data LinkedList<Data>::findDataAscending(int64_t index) const
	{
		ListNode<Data> *iterator = m_head;
		while (iterator != nullptr)
		{
			if (index <= 0)
				return iterator->m_data;

			iterator = iterator->m_next;
			index--;
		}

		return Data();
	}

	template <class Data>
	Data LinkedList<Data>::findDataDescending(int64_t index) const
	{
		ListNode<Data> *iterator = m_tail;
		index = size() - 1 - index;
		while (iterator != nullptr)
		{
			if (index <= 0)
				return iterator->m_data;

			iterator = iterator->m_prev;
			index--;
		}

		return Data();
	}

	template <class Data>
	inline Data LinkedList<Data>::getDataAt(int64_t index) const
	{
		if (index < 0 || static_cast<uint64_t>(index) >= size())
			return Data();

		if (static_cast<uint64_t>(index) < size() / 2)
			return findDataAscending(index);
		else
			return findDataDescending(index);
	}

	template <class Data>
	inline int64_t LinkedList<Data>::indexOf(Data data) const
	{
		ListNode<Data> *ascIterator = m_head;
		ListNode<Data> *descIterator = m_tail;
		int64_t ascCounter = 0;
		int64_t descCounter = size() - 1;

		while (ascIterator != nullptr && descIterator != nullptr)
		{
			if (ascIterator->m_data == data)
				return ascCounter;

			if (descIterator->m_data == data)
				return descCounter;

			ascIterator = ascIterator->m_next;
			descIterator = descIterator->m_prev;
			ascCounter++;
			descCounter--;
		}

		while (ascIterator != nullptr)
		{
			if (ascIterator->m_data == data)
				return ascCounter;

			ascIterator = ascIterator->m_next;
			ascCounter++;
		}

		while (descIterator != nullptr)
		{
			if (descIterator->m_data == data)
				return descCounter;

			descIterator = descIterator->m_prev;
			descCounter--;
		}

		return -1;
	}

	template <class Data>
	void LinkedList<Data>::insertFirst(Data data)
	{
		if (!m_head)
		{
			append(data);
			return;
		}

		ListNode<Data> *newListNode = new ListNode<Data>(data);
		newListNode->m_next = m_head;
		m_head->m_prev = newListNode;
		m_head = newListNode;
	}

	template <class Data>
	void LinkedList<Data>::append(Data data)
	{
		if (m_head == nullptr)
		{
			m_head = new ListNode<Data>(data);
			m_tail = m_head;
			m_size++;
			return;
		}

		ListNode<Data> *newListNode = new ListNode<Data>(data);
		newListNode->m_prev = m_tail;
		m_tail->m_next = newListNode;
		m_tail = newListNode;
		m_size++;
	}

	template <class Data>
	void LinkedList<Data>::append(const LinkedList<Data>& list)
	{
		ListNode<Data> *iterator = list.m_head;

		while (iterator != nullptr)
		{
			append(iterator->m_data);
			iterator = iterator->m_next;
		}
	}

	template <class Data>
	void LinkedList<Data>::appendAfter(Data afterData, Data data)
	{
		ListNode<Data> *iterator = m_head;
		while (iterator != nullptr)
		{
			if (iterator->m_data == afterData)
			{
				ListNode<Data> *newListNode = new ListNode<Data>(data);
				newListNode->m_next = iterator->m_next;
				newListNode->m_prev = iterator;
				iterator->m_next = newListNode;
				if (iterator->m_next != nullptr)
					iterator->m_next->m_prev = newListNode;
				return;
			}
			iterator = iterator->m_next;
		}

		append(data);
	}

	template <class Data>
	void LinkedList<Data>::removeAll()
	{
		ListNode<Data> *iterator = m_head;

		while (iterator != nullptr)
		{
			m_head = iterator->m_next;
			delete iterator;
			iterator = m_head;
		}

		m_size = 0;
	}

	template <class Data>
	bool LinkedList<Data>::removeAt(int64_t index)
	{
		if (!m_head)
			return false;

		if (index <= 0)
		{
			ListNode<Data> *iterator = m_head;
			m_head = iterator->m_next;
			delete iterator;
			m_size--;
			return true;
		}
		else if (static_cast<uint64_t>(index) > size())
			return false;

		ListNode<Data> *iterator = m_head->m_next;
		int64_t counter = 1;

		while (iterator != nullptr)
		{
			if (counter == index)
			{
				iterator->m_prev->m_next = iterator->m_next;
				m_size--;
				delete iterator;
				return true;
			}

			iterator = iterator->m_next;
			counter++;
		}

		return false;
	}

	template <class Data>
	bool LinkedList<Data>::remove(Data data)
	{
		if (!m_head)
			return false;

		if (m_head->m_data == data)
		{
			ListNode<Data> *head = m_head;
			m_head = m_head->m_next;
			delete head;
			m_size--;
			return true;
		}

		ListNode<Data> *iterator = m_head->m_next;
		while (iterator != nullptr)
		{
			if (iterator->m_data == data)
			{
				iterator->m_prev->m_next = iterator->m_next;
				delete iterator;
				m_size--;
				return true;
			}

			iterator = iterator->m_next;
		}

		return false;
	}

	template <class Data>
	std::ostream& operator<<(std::ostream &os, const LinkedList<Data>& list)
	{
		ListNode<Data> *iterator = list.m_head;

		while (iterator != nullptr)
		{
			os << iterator->m_data << ' ';
			iterator = iterator->m_next;
		}

		return os;
	}
}

#endif

