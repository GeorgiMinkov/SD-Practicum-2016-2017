// GraphMatrixOfAdjecency.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"

int main()
{
	int size = 4;

	Graph test(6);

	test.addEdge(1, 2);
	test.addEdge(1, 3);
	test.addEdge(2, 5);
	test.addEdge(2, 4);
	test.addEdge(3, 5);

	test.BFS(2);
    return 0;
}

