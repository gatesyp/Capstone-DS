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

#endif
