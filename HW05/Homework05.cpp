// Homework05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MergeSort.hpp"

int main()
{
	int arr[] = { 1, 5, 9, 0, 5};

	mergeSort<int>(arr, 5);


	std::cout << *arr;
    return 0;
}

