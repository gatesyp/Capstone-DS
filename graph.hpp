#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
using namespace std;
// adjacency list implementation
// for a directed graph


// define the edges struct
struct Edge
{
	int vertex;
	double weight;
	Edge() : vertex(), weight()
	{}
	Edge(int d_vertex, double d_weight) : vertex(d_vertex), weight(d_weight)
	{}

};

struct graph
{
	int size = 0;
	vector< vector<Edge> > graph;
	// u = origin node
	// v = out direction node we end at
	// w = weight of the edge
	void addElement(int u, int v, int w)
	{
		Edge e = Edge(v, w);
		graph[u].push_back(e);
		++size;
	}
// function to make easy traversals? 

	void goToNext()
	{
	}
	void goToPrev()
	{
	}


};


#endif
