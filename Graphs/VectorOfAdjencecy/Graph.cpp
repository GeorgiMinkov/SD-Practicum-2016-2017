#include "stdafx.h"
#include "Graph.h"

Graph::Graph(const std::size_t & size)
{
	this->size = size;

	// this->adjencecy.resize(size);
}

void Graph::addEdge(Vortex from, Vortex to)
{
	if (this->adjencecy.size() == 0)
	{
		vector<Vortex> newV;
		newV.push_back(from);
		newV.push_back(to);

		this->adjencecy.push_back(newV);

		this->size++;
	}
	else
	{
		for (std::size_t index = 0; index < this->size; ++index)
		{
			if (from.id_vertex == this->adjencecy[index][0].id_vertex)
			{
				this->adjencecy[index].push_back(to);

				return;
			}
		}

		vector<Vortex> newV;
		newV.push_back(from);
		newV.push_back(to);

		this->adjencecy.push_back(newV);

		this->size++;
	}
}

void Graph::addVortex(Vortex from)
{
	vector<Vortex> newV;
	newV.push_back(from);

	this->adjencecy.push_back(newV);
	this->size++;
}

void Graph::DFS(Vortex start)
{
	bool *visited = new bool[this->size];

	for (std::size_t index = 0; index < this->size; ++index)
	{
		visited[index] = false;
	}

	run_DFS(start, visited);
}

void Graph::run_DFS(Vortex start, bool * visited)
{
	std::cout << start.id_vertex << ' ' << start.payload << std::endl;

	visited[start.id_vertex - 1] = true;

	for (auto it = this->adjencecy[start.id_vertex - 1].begin(); it != this->adjencecy[start.id_vertex - 1].end(); ++it)
	{
		if (!visited[it->id_vertex - 1])
		{
			visited[it->id_vertex - 1] = true;
			run_DFS(*it, visited);
		}
	}
}
