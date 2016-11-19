#pragma once
#include <iostream>

namespace GM{
	template<typename Type>
	class List
	{
		struct Node;
		class Iterator;

	private:
		std::size_t size;
		Node *head;
		Node *tail;

		void destroy();
		void copy(const List<Type> &other);

	public:
		List();
	
		List(const Node *head, const Node *tail, const std::size_t &size = 0) : head(head), tail(tail), size(size) {}
		List(const List<Type> &other);
		~List();

		Type &operator=(const List<Type> &other);

		// Capaity
		bool empty() const;
		std::size_t getSize() const;

		Iterator front()
		{
			return Iterator(head);
		}
		Iterator back()
		{
			return Iterator(tail);
		}

		// Modifier
		void push_front(const Type &element); // insert at begining work
		void pop_front(); // delete first element work
		void push_back(const Type &element); // 
		void pop_back(); // 
		void insert(const std::size_t &position, const Type &element);
		void clear(); // 

		// Operations
		void remove(const Type &elementData);
		void unique();
		void merge(List<Type> &rhs);
		void sort();
		void reverse();
	};

	template<typename Type>
	struct List<Type>::Node
	{
		Type data;
		Node *next;
		Node *previous;

		Node(Type _data = Type(), Node *_next = nullptr, Node *_previous = nullptr) : data(_data), next(_next), previous(_previous) {};
	};

	template<typename Type>
	class List<Type>::Iterator
	{
		Node *current;

	public:
		Iterator(Node *current = nullptr) : current(current) {};

		Iterator &operator++();
		Iterator &operator++(int);

		Iterator &operator--();
		Iterator &operator--(int);

		bool operator!= (const Iterator &rhs) const;

		Type &operator*();

		Node *getCurrent() { return this->current; }
	};

	// ***********************************************operations for Iterator***********************************************
	template<typename Type>
	typename List<Type>:: Iterator & List<Type>::Iterator::operator++()
	{
		// Up current plus 1 position (go to next)
		if (current->next == nullptr)
		{
			throw "Out of range";
		}
		
		this->current = this->current->next;

		return *this;
	}

	template<typename Type>
	typename List<Type>:: Iterator & List<Type>::Iterator::operator++(int)
	{
		// Postfix ++
		if (current->next == nullptr)
		{
			throw "Out of range";
		}

		Iterator old = *this;

		++this->current;

		return old;
	}

	template<typename Type>
	typename List<Type>::Iterator & List<Type>::Iterator::operator--()
	{
		if (current->previous == nullptr)
		{
			throw "Out of range";
		}

		this->current = this->current->previous;

		return *this;
	}

	template<typename Type>
	typename List<Type>::Iterator & List<Type>::Iterator::operator--(int)
	{
		if (current->previous == nullptr)
		{
			throw "Out of range";
		}

		Iterator old = *this;

		--this->current;

		return old;
	}

	template<typename Type>
	inline bool List<Type>::Iterator::operator!=(const Iterator & rhs) const
	{
		return this->current != rhs.current;
	}

	template<typename Type>
	inline Type & List<Type>::Iterator::operator*()
	{
		// access value

		return this->current->data;
	}


	// ***********************************************operations for LIST ***********************************************
	template<typename Type>
	inline void List<Type>::destroy()
	{
		for (List<Type>::Iterator it = this->front(); it != this->back(); ++it)
		{
			this->pop_back();
		}
	}

	template<typename Type>
	inline void List<Type>::copy(const List<Type>& other)
	{
		for (Iterator<Type> it = other.front(); it != other.back(); ++it)
		{
			this->push_back(*it);
		}
	}

	template<typename Type>
	inline List<Type>::List()
	{
		head = new Node;
		tail = new Node;
		size = 0;

		head->next = tail;
		head->previous = nullptr;

		tail->previous = head;
		tail->next = nullptr;
	}

	template<typename Type>
	inline List<Type>::List(const List & other)
	{
		this->copy(other);
	}

	template<typename Type>
	inline List<Type>::~List()
	{
		this->destroy();
	}

	template<typename Type>
	inline Type & List<Type>::operator=(const List<Type>& other)
	{
		// DO: operation =
		if (this != &other)
		{
			this->destroy();
		
			this->copy(other);
		}

		return *this;
	}

	template<typename Type>
	inline bool List<Type>::empty() const
	{
		return (this->head->next == this->tail);
	}

	template<typename Type>
	inline std::size_t List<Type>::getSize() const
	{
		return this->size;
	}

	template<typename Type>
	inline void List<Type>::push_front(const Type & element)
	{
		Node *newNode = new Node;
		newNode->data = element;

		newNode->next = this->head->next;
		newNode->previous = head;
		this->head->next->previous = newNode;
		this->head->next = newNode;
		this->size++;
	}

	template<typename Type>
	inline void List<Type>::pop_front()
	{
		if (this->empty())
		{
			throw "EmptyLisExseption\n";
		}

		Node *tmp = new Node;
		tmp = head->next;

		tmp->previous->next = tmp->next;
		tmp->next->previous = tmp->previous;
		
		--this->size;
		delete tmp;
	}

	template<typename Type>
	inline void List<Type>::push_back(const Type & element)
	{
		Node *newNode = new Node;
		newNode->data = element;

		newNode->previous = this->tail->previous;
		newNode->next = tail;
		this->tail->previous->next = newNode;
		this->tail->previous = newNode;
		this->size++;
	}

	template<typename Type>
	inline void List<Type>::pop_back()
	{
		if (this->empty())
		{
			throw "EmptyLisExseption\n";
		}

		Node *tmp = new Node;
		tmp = tail->previous;

		tmp->next->previous = tmp->previous;
		tmp->previous->next = tmp->next;

		--this->size;
		delete tmp;
	}

	template<typename Type>
	inline void List<Type>::insert(const std::size_t & position, const Type & element)
	{
		if (position > this->getSize())
		{
			throw "Exseption";
		}

		size_t curPosition = 0;
		
		List<Type>::Iterator it;
		for (it = this->front(); curPosition < position; ++it, ++curPosition);
		
		Node *newNode = new Node;
		newNode->data = element;

		newNode->previous = it.getCurrent()->previous;
		newNode->next = it.getCurrent();
		it.getCurrent()->previous->next = newNode;
		it.getCurrent()->previous = newNode;

		this->size++;

	}

	template<typename Type>
	inline void List<Type>::clear()
	{
		this->destroy();
	}

	template<typename Type>
	inline void List<Type>::remove(const Type & elementData)
	{
		if (this->empty())
		{
			return;
		}

		Node *current = this->head->next;

		while (current != this->tail)
		{
			if (current->data == elementData)
			{
				Node *tmp = new Node;
				tmp = current;

				tmp->previous->next = tmp->next;
				tmp->next->previous = tmp->previous;

				--this->size;
			}
			current = current->next;

			delete tmp;
		}
	}

	template<typename Type>
	inline void List<Type>::unique()
	{
		Node *current = this->front;

		while (current != this->tail && current != nullptr)
		{
			this->remove(current->data);
			
			current = current->next;
		}
	}

	template<typename Type>
	inline void List<Type>::merge(List<Type>& rhs)
	{
		this->tail->previous->next = rhs.*(head).next;
		this->tail->previous->next->previous = this->tail->previous; // same as rhs.*(head).*(next).previous

		Node *tmp = new Node;
		tmp = rhs.head;

		delete tmp;

		this->tail = rhs.tail;
	}

	template<typename Type>
	inline void List<Type>::sort()
	{
		Node *ptr, *dummy = new Node();

		if (this->empty()) return;
		if (this->head->next->next == this->tail) return;

		int swapped = 1;
		while (swapped) 
		{
			swapped = 0;

			ptr = head->next;
			while (ptr->next != this->tail) {
				if (ptr->data < ptr->next->data) 
				{
					swapped = 1;

					dummy->data = ptr->data;
					ptr->data = ptr->next->data;
					ptr->next->data = dummy->data;
				}
				ptr = ptr->next;
			}
		}
	}

	template<typename Type>
	inline void List<Type>::reverse()
	{
		Node *temp = nullptr;
		Node *current = this->head->next;

		// swap two pointers previous and next
		while (current != this->tail)
		{
			temp = current->previous;
			current->previous = current->next;
			current->next = temp;
			current = current->prev;
		}

		// swap head and tail
		tmp = this->head;
		this->head = this->tail;
		this->tail = tmp;
	}
}