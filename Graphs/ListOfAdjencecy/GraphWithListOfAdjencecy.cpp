// GraphWithListOfAdjencecy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"

int main()
{
	Graph test(4);

	test.addEdge(0, 1);
	test.addEdge(1, 0);
	test.addEdge(0, 2);
	test.addEdge(2, 0);
	test.addEdge(1, 2);
	test.addEdge(2, 1);

	test.addEdge(2, 3);
	test.addEdge(3, 2);
	test.addEdge(3, 3);

	std::cout << test.isReachable(0, 3) << std::endl;
	return 0;
}

