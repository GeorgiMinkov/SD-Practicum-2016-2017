#include "stdafx.h"
#include "Graph.h"

Graph::Graph(const std::size_t & size)
{
	this->size = size;
	this->currentId = 0;

	this->adjencecy = new list<Vortex>[size];
}

void Graph::addVortex(const string & payload)
{
	Vortex newV(this->currentId, payload);

	this->adjencecy[this->currentId].push_back(newV);

	this->currentId++;
}

void Graph::addEdge(const Vortex & from, const Vortex & to)
{
	this->adjencecy[from.idVorterx].push_back(to);
}

void Graph::BFS(const Vortex & start)
{
	bool *visited = new bool[this->size];

	for (std::size_t index = 0; index < this->size; ++index)
	{
		visited[index] = false;
	}

	run_BFS(start, visited);
}

void Graph::run_BFS(const Vortex & start, bool * visited)
{	
	if (start.idVorterx > this->size - 1)
	{
		std::cout << start.idVorterx << ' ' << start.payload << std::endl;

		return;
	}

	queue<Vortex> q;
	q.push(start);
	visited[start.idVorterx] = true;

	while (!q.empty())
	{
		Vortex tmp = q.front();
		
		std::cout << tmp.idVorterx << ' ' << tmp.payload << std::endl;

		list<Vortex>::iterator it = this->adjencecy[tmp.idVorterx].begin();
		for (; it != this->adjencecy[tmp.idVorterx].end(); ++it)
		{
			if (!visited[it->idVorterx])
			{
				visited[it->idVorterx] = true;
				q.push(*it);
			}
		}

		q.pop();
	}
}

void Graph::DFS(const Vortex & start)
{
	bool *visited = new bool[this->size];

	for (std::size_t index = 0; index < this->size; ++index)
	{
		visited[index] = false;
	}

	run_DFS(start, visited);
}

void Graph::run_DFS(const Vortex & start, bool * visited)
{
	std::cout << start.idVorterx << ' ' << start.payload << std::endl;

	if (start.idVorterx > this->size - 1)
	{
		return;
	}

	visited[start.idVorterx] = true;
	list<Vortex>::iterator it = this->adjencecy[start.idVorterx].begin();

	for (; it != this->adjencecy[start.idVorterx].end(); ++it)
	{
		if (!visited[it->idVorterx])
		{
			visited[it->idVorterx] = true;

			run_DFS(*it, visited);
		}
	}
}

