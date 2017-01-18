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

bool Graph::isReachable(const Vortex & from, const Vortex & to)
{
	if (from.idVorterx > this->size - 1)
	{
		return false;
	}

	bool *visited = new bool[this->size];

	for (std::size_t index = 0; index < this->size; ++index)
	{
		visited[index] = false;
	}

	queue<Vortex> q;

	q.push(from);
	visited[from.idVorterx] = true;

	while (!q.empty())
	{
		Vortex tmp = q.front();

		list<Vortex>::iterator it = this->adjencecy[tmp.idVorterx].begin();
		// ++it;

		for (; it != this->adjencecy[tmp.idVorterx].end(); ++it)
		{
			if (*it == to)
			{
				return true;
			}

			if (!visited[it->idVorterx])
			{
				visited[it->idVorterx] = true;
				q.push(*it);
			}
		}
		q.pop();
	}

	return false;
}

bool Graph::isPatcAndShowPath(const Vortex & from, const Vortex & to, stack<Vortex> &path) // with DFS
{
	bool *visited = new bool[this->size];

	for (std::size_t index = 0; index < this->size; ++index)
	{
		visited[index] = false;
	}

	return isPatcAndShowPath(from, to, path, visited);
}

bool Graph::isPatcAndShowPath(const Vortex & from, const Vortex & to, stack<Vortex>& path, bool * visited)
{
	visited[from.idVorterx] = true;
	path.push(from);

	if (from.idVorterx == to.idVorterx) // from.operator==(to))
	{
		return true;
	}
	else
	{
		list<Vortex>::iterator it = this->adjencecy[from.idVorterx].begin();
		++it;

		for (; it != this->adjencecy[from.idVorterx].end(); ++it)
		{
			if (!visited[it->idVorterx])
			{
				if (isPatcAndShowPath(*it, to, path, visited))
				{
					return true;
				}
			}
		}
		path.pop();
	}

	return false;
}

void Graph::isPathAllPath(const Vortex & from, const Vortex & to, stack<stack<Vortex>>& allPathec)
{
	bool *visited = new bool[this->size];

	for (std::size_t index = 0; index < this->size; ++index)
	{
		visited[index] = false;
	}

	stack<Vortex> path;

	return isPathAllPath(from, to, path, allPathec, visited);
}

void Graph::isPathAllPath(const Vortex & from, const Vortex & to, stack<Vortex>& path, stack<stack<Vortex>>& allPathes, bool * visited)
{
	visited[from.idVorterx] = true;

	path.push(from);

	if (from.idVorterx == to.idVorterx)
	{
		allPathes.push(path);
	}
	else
	{
		list<Vortex>::iterator it = this->adjencecy[from.idVorterx].begin();
		++it;

		for (; it != this->adjencecy[from.idVorterx].end(); ++it)
		{
			if (!visited[it->idVorterx])
			{
				isPathAllPath(*it, to, path, allPathes, visited);
			}
		}
	}
	path.pop();
	visited[from.idVorterx] = false;
}

