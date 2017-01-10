#pragma once

//current graph will work on static number of vortex, to be dynamic
//we just need to create function resize

#include <iostream>
#include <list>
#include <queue>

using std::queue;
using std::list;

class Graph
{
	list<int> *adjecency;
	int numVortex;

public:
	Graph(const int &numVortex);

	void addEdge(const int &from, const int &to);
	bool isReachable(const int &from, const int &to);
};