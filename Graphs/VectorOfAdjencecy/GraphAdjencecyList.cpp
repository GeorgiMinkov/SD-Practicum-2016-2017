// GraphAdjencecyList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"

int main()
{
	Vortex t1(1, "One");
	Vortex t2(2, "Two");
	Vortex t3(3, "Three");
	Vortex t4(4, "Four");

	Graph test(0);

	test.addEdge(t1, t2);
	test.addEdge(t1, t3);
	test.addEdge(t2, t3);
	test.addEdge(t3, t4);
	test.addVortex(t4);

	test.DFS(t1);

    return 0;
}

