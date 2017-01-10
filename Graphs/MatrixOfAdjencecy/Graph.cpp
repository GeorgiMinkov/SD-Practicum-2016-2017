#include "stdafx.h"
#include "Graph.h"

Graph::Graph(int vertexCount)
{
	this->vertexCount = vertexCount;

	this->adjencyMatrix = new bool*[vertexCount];

	for (std::size_t index = 0; index < vertexCount; ++index)
	{
		this->adjencyMatrix[index] = new bool[vertexCount];
		

		for (std::size_t col = 0; col < vertexCount; ++col)
		{
			this->adjencyMatrix[index][col] = false;
		}
	}

}

Graph::~Graph()
{
	for (std::size_t index = 0; index < this->vertexCount; ++index)
	{
		delete[] this->adjencyMatrix[index];
	}
	delete[] this->adjencyMatrix;
}

void Graph::addEdge(int from, int to)
{
	if (from >= 0 && from < this->vertexCount && to >= 0 && to < this->vertexCount)
	{
		this->adjencyMatrix[from][to] = true;
		this->adjencyMatrix[to][from] = true;
	}
}

void Graph::removeEdge(int from, int to)
{
	if (from >= 0 && from < this->vertexCount && to >= 0 && to < this->vertexCount)
	{
		this->adjencyMatrix[from][to] = false;
		this->adjencyMatrix[to][from] = false;
	}
}

bool Graph::isEdge(int from, int to)
{
	if (from >= 0 && from < this->vertexCount && to >= 0 && to < this->vertexCount)
		return this->adjencyMatrix[from][to];
	else
		return false;
}

void Graph::DFS(int start)
{
	bool *visited = new bool[this->vertexCount];

	for (std::size_t index = 0; index < this->vertexCount; ++index)
	{
		visited[index] = false;
	}

	run_DFS(start, visited);
}

void Graph::run_DFS(int start, bool * visited)
{
	std::cout << start << ' ';
	visited[start] = true;

	for (std::size_t index = 0; index < this->vertexCount; ++index)
	{
		if (isEdge(start, index) && !visited[index])
		{
			visited[index] = true;
			run_DFS(index, visited);
		}
	}
}

void Graph::BFS(int start)
{
	bool *visited = new bool[this->vertexCount];

	for (std::size_t index = 0; index < this->vertexCount; ++index)
	{
		visited[index] = false;
	}

	run_BFS(start, visited);
}

void Graph::run_BFS(int start, bool *visited)
{
	if (start > this->vertexCount)
	{
		return;
	}


	queue<int> q;

	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int tmp = q.front();

		std::cout << tmp << ' ';

		for (std::size_t index = 0; index < this->vertexCount; ++index)
		{
			if (isEdge(tmp, index) && !visited[index])
			{
				q.push(index);
				visited[index] = true;
			}
		}

		q.pop();
	}
}
