#include "stdafx.h"
#include "Graph.h"

Graph::Graph(const int & numVortex)
{
	this->numVortex = numVortex;

	this->adjecency = new list<int>[numVortex];
}

void Graph::addEdge(const int & from, const int & to)
{
	this->adjecency[from].push_back(to);
}

bool Graph::isReachable(const int & from, const int & to)
{
	if (from == to)
	{
		return true;
	}

	bool *visited = new bool[this->numVortex];

	for (std::size_t index = 0; index < this->numVortex; ++index)
	{
		visited[index] = false;
	}

	queue<int> q;

	q.push(from);
	visited[from] = true;

	list<int>::iterator it;

	while (!q.empty())
	{
		int tmp = q.front();

		for (it = this->adjecency[tmp].begin(); it != this->adjecency[tmp].end(); ++it)
		{
			if (*it == to)
			{
				return true;
			}

			if (!visited[*it])
			{
				visited[*it] = true;
				q.push(*it);
			}
		}

		q.pop();
	}

	return false;
}
