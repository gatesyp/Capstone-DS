#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

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



#endif
