#pragma once

#include <iostream>
#include <vector>
#include <string>

using std::vector;

struct Vortex
{
	int id_vertex;
	std::string payload;

	Vortex(const int &id_vertex = 0, const std::string &payload = "") : id_vertex(id_vertex), payload(payload) { }
};

class Graph
{
	vector<vector<Vortex>> adjencecy;

	std::size_t size;

public:
	Graph(const std::size_t &size);

	void addEdge(Vortex from, Vortex to);
	void addVortex(Vortex from);

	void DFS(Vortex start);
	void run_DFS(Vortex start, bool *visited);
};