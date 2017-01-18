#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <stack>

using std::stack;
using std::list;
using std::queue;
using std::string;

struct Vortex
{
	int idVorterx;
	string payload; // can be any type

	Vortex(int idVortex, string payload) : idVorterx(idVortex), payload(payload) { }

	bool operator==(const Vortex &rhs) const { return this->idVorterx == rhs.idVorterx && this->payload == rhs.payload; }
};

class Graph
{
	list<Vortex> *adjencecy;

	std::size_t size;
	std::size_t currentId;
public:
	Graph(const std::size_t &size);

	void addVortex(const string &payload);
	void addEdge(const Vortex &from, const Vortex &to);

	list<Vortex> getListOfAdj(int i)
	{
		return adjencecy[i];
	}

	void BFS(const Vortex &start);
	void run_BFS(const Vortex &start, bool *visited);

	void DFS(const Vortex &start);
	void run_DFS(const Vortex &start, bool *visited);

	bool isReachable(const Vortex &from, const Vortex &to);
	bool isReachableDFS();

	bool isPatcAndShowPath(const Vortex &from, const Vortex &to, stack<Vortex> &path);
	bool isPatcAndShowPath(const Vortex &from, const Vortex &to, stack<Vortex> &path, bool *visited);
	void isPathAllPath(const Vortex &from, const Vortex &to, stack<stack<Vortex>> &allPathec);
	void isPathAllPath(const Vortex &from, const Vortex &to, stack<Vortex> &path, stack<stack<Vortex>> &allPathes, bool *visited);
};