#pragma once
#include <iostream>

template<typename Type> 
void insertionSort(Type *container, const std::size_t &size, const char symbol)
{
	for (int index = 1; index < size; ++index)
	{
		int tmp = index;

		while (tmp > 0 && compare(container[tmp], container[tmp - 1], symbol))
		{
			swap<Type>(container[tmp], container[tmp - 1]);

			--tmp;
		}
	}
}

template <typename Type>
void swap(Type &lhs, Type &rhs)
{
	Type tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template<typename Type>
bool compare(const Type &lhs, const Type &rhs, const char &order)
{
	return (order == '<') ? lhs < rhs : rhs < lhs;
}