#pragma once
#include <iostream>
#include <queue>

using std::queue;

class Graph
{
	bool **adjencyMatrix;
	int vertexCount;

public:
	Graph()
	{
		adjencyMatrix = NULL;
	}
	Graph(int vertexCount);
	~Graph();


	void addEdge(int from, int to);
	void removeEdge(int from, int to);

	bool isEdge(int from, int to);

	void DFS(int start);
	void run_DFS(int start, bool* visited);

	void BFS(int start);
	void run_BFS(int start, bool *visited);
};