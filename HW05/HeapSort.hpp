#pragma once
#include <iostream>

template <typename Type>
void _swap(Type &lhs, Type &rhs)
{
	Type tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

// правя MaxHeap след това ще взимам винаги корена и го слагам най - отзад на масива и пускам heapify (за да намери новия елемент за корен) за да направя 
// подадения ми масив във възходящ ред
template <typename Type>
void heapify(Type *container, const std::size_t &size, const std::size_t &index)
{
	std::size_t leftChildIndex = 2 * index + 1, rightChildIndex = 2 * index + 2, largest = index;

	if (leftChildIndex < size && container[leftChildIndex] > container[largest])
	{
		largest = leftChildIndex;
	}

	if (rightChildIndex < size && container[rightChildIndex] > container[largest])
	{
		largest = rightChildIndex;
	}

	if (largest != index)
	{
		_swap<Type>(container[largest], container[index]);

		heapify<Type>(container, size, largest);
	}
}

template <typename Type>
void heapSort(Type *container, const std::size_t &size)
{
	for (int index = size / 2 - 1; index >= 0; --index)
	{
		heapify<Type>(container, size, index);
	}

	for (int index = size - 1; index >= 0; --index)
	{
		_swap<Type>(container[0], container[index]);

		heapify<Type>(container, index, 0);
	}
}