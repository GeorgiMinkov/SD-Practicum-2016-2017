#pragma once
#include <vector>
#include <algorithm>

template<class Type, class Container = std::vector<Type>, class Compare = std::less<Type>> // class заради екплицитния конструктор, който позволява екслпицитно заделяне
class PriorityQueue
{
protected:
	Container contain;
	Compare condition;

public:
	explicit PriorityQueue(Container &contain = Container(), Compare &condition = Compare()) : contain(contain), condition(condition)
	{
		std::make_heap(contain.begin(), contain.end(), condition);
	}

	bool empty() const;

	std::size_t size() const;

	const Type &top() const;

	void push(const Type &element);

	void pop();

};

template<class Type, class Container, class Compare>
inline bool PriorityQueue<Type, Container, Compare>::empty() const
{
	return this->contain.empty();
}

template<class Type, class Container, class Compare>
inline std::size_t PriorityQueue<Type, Container, Compare>::size() const
{
	return this->contain.size();
}

template<class Type, class Container, class Compare>
inline const Type & PriorityQueue<Type, Container, Compare>::top() const
{
	// DO: get top element
	if (!(this->contain.size()))
	{
		throw "EmptyQueueExseption";
	}

	return this->contain.front();
}

template<class Type, class Container, class Compare>
inline void PriorityQueue<Type, Container, Compare>::push(const Type & element)
{
	contain.push_back(element);
	std::push_heap(contain.begin(), contain.end(), condition);
}

template<class Type, class Container, class Compare>
inline void PriorityQueue<Type, Container, Compare>::pop()
{
	std::pop_heap(contain.begin(), contain.end(), condition);
	contain.pop_back();
}