// AllFunctionGraphWithListAdjencecy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"

int main()
{
	Graph test(4);

	test.addVortex("One");
	test.addVortex("Two");
	test.addVortex("Three");
	test.addVortex("Four");

	list<Vortex> t = test.getListOfAdj(1);

	Vortex t0(0,"One"), t1(1, "Two"), t2(2, "Three"), t3(3, "Four");
	// Directed Graph
	test.addEdge(t0, t1);
	test.addEdge(t0, t2);
	test.addEdge(t1, t2);
	test.addEdge(t2, t3);

	// Undirected Graph
	// test.DFS(Vortex(0, "One"));
	test.BFS(Vortex(1, "Two"));
	
	return 0;
}

