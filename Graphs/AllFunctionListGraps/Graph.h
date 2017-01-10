#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <list>

using std::list;
using std::queue;
using std::string;

struct Vortex
{
	int idVorterx;
	string payload; // can be any type

	Vortex(int idVortex, string payload) : idVorterx(idVortex), payload(payload) { }
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
};