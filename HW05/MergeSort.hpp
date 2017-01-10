#pragma once
#include <iostream>

template <typename Type>
void mergeSort(Type *container, const std::size_t &size)
{
	mergeSort<Type>(container, 0, size - 1);
}

template <typename Type>
void mergeSort(Type *container, const std::size_t &left, const std::size_t &right)
{
	if (left < right)
	{
		const std::size_t middle = left + (right - left) / 2;

		mergeSort<Type>(container, left, middle);
		mergeSort<Type>(container, middle + 1, right);

		merge<Type>(container, left, right, middle);
	}

	return;
}

template <typename Type>
void merge(Type *container, const std::size_t &left, const std::size_t &right, const std::size_t &middle)
{
	std::size_t mergedIndex = 0, sizeLeftHalf = middle - left + 1, sizeRightHalf = right - middle;

	Type *leftHalf = new Type[sizeLeftHalf];
	Type *righHalf = new Type[sizeRightHalf];

	copy<Type>(leftHalf, container, left, sizeLeftHalf);

	copy<Type>(righHalf, container, middle + 1, sizeRightHalf);

	reorder<Type>(container, leftHalf, sizeLeftHalf, righHalf, sizeRightHalf, left); // left is for starting point for container

}


template <typename Type>
void copy(Type *lhs, Type *rhs, const std::size_t &start, const std::size_t &size)
{
	for (std::size_t index = 0; index < size; ++index)
	{
		lhs[index] = rhs[index + start];
	}

}

template<typename Type>
void reorder(Type *container, Type *leftHalf, const std::size_t &leftSize, Type *righHalf, const std::size_t &rightSize, std::size_t start)
{
	std::size_t indexLeft = 0, indexRight = 0;

	while (indexLeft < leftSize && indexRight < rightSize)
	{
		if (leftHalf[indexLeft] < righHalf[indexRight])
		{
			container[start++] = leftHalf[indexLeft++];
		}
		else
		{
			container[start++] = righHalf[indexRight++];
		}
	}

	while (indexLeft < leftSize)
	{
		container[start++] = leftHalf[indexLeft++];
	}

	while (indexRight < rightSize)
	{
		container[start++] = righHalf[indexRight++];
	}
	
}