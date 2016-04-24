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
	int to;
	int length;
	Edge() : to(), length()
	{}
	Edge(int d_to, double d_weight) : to(d_to), length(d_weight)
	{}
	// overloaded copy constructor
	Edge(const Edge &eSource)
	{
		to = eSource.to;
		length = eSource.length;
	}
};
// overload assignment operator
//Edge& Edge::operator= (const Edge &eSource)
//{
	//to = eSource.to;
	//length = eSource.length;
	//return *this;
//}
// maybe dont wrap graph in a class
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

};

#endif
