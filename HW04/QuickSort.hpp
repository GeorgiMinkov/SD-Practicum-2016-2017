#pragma once
#include <iostream>

template <typename Type>
void quickSort(Type *container, const int &size)
{
	if (size == 0 || size == 1)
	{
		return;
	}

	quickSort<Type>(container, 0, size - 1);
}

template <typename Type>
void quickSort(Type *container, const int leftBarrier, const int rightBarrier)
{
	if (leftBarrier < rightBarrier)
	{
		int partiotionIndex = getPartitionIndex(container, leftBarrier, rightBarrier);

		quickSort<Type>(container, leftBarrier, partiotionIndex - 1);
		quickSort<Type>(container, partiotionIndex + 1, rightBarrier);
	}
}

template <typename Type>
int getPartitionIndex(Type *container, const int &leftBarrier, const int &rightBarrier)
{
	Type pivot = container[rightBarrier];

	int partiotionIndex = leftBarrier;

	for (std::size_t index = leftBarrier; index < rightBarrier; ++index)
	{
		if (container[index] < pivot)
		{
			_swap<Type>(container[index], container[partiotionIndex]);
			++partiotionIndex;
		}
	}

	_swap<Type>(container[partiotionIndex], container[rightBarrier]);

	return partiotionIndex;
}

template <typename Type>
void _swap(Type &lhs, Type &rhs)
{
	Type tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}