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
	//test.addEdge(t1, t0);
	//test.addEdge(t2, t0);
	//test.addEdge(t2, t1);
	//test.addEdge(t3, t2);
	// test.DFS(Vortex(0, "One"));
	// test.BFS(Vortex(1, "Two"));
	
	stack<Vortex> path, reverse;
	stack<stack<Vortex>> all;

	/*std::cout << test.isPatcAndShowPath(t1, t3, path);


	while (!path.empty())
	{
		reverse.push(path.top());

		path.pop();
	}

	while (!reverse.empty())
	{
		std::cout << reverse.top().idVorterx << ' ';
		reverse.pop();
	}*/

	test.isPathAllPath(t0, t3, all);

	while (!all.empty())
	{
		path = all.top();

		while (!path.empty())
		{
			reverse.push(path.top());

			path.pop();
		}

		while (!reverse.empty())
		{
			std::cout << reverse.top().idVorterx << ' ';
			reverse.pop();
		}
		std::cout << std::endl;
		all.pop();
	}
	return 0;
}

