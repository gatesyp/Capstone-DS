#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <set>
#include <iostream>
#include <vector>
#include "graph.cpp"
using namespace std;
// define the base algorithm class
// will have MST algos, shortest path algo, and dfs/bfs
struct algorithm
{
	int INT_MAX = 0;
	// stuff	
};


struct Djisktra : algorithm
{
	int getPath(const vector< vector<Edge> > &graph, int source, int target)
	{
	vector<int> min_distance( graph.size(), INT_MAX);
	min_distance[source] = 0;
	set< pair<int,int> > active_vertices;
	active_vertices.insert( {0, source} );
	while (!active_vertices.empty()) {
		int where = active_vertices.begin()->second;
		if (where == target) return min_distance[where];
		active_vertices.erase( active_vertices.begin() );
		for (auto Edge : graph[where]) 
			if (min_distance[Edge.to] > min_distance[where] + Edge.length) {
				active_vertices.erase( { min_distance[Edge.to], Edge.to } );
				min_distance[Edge.to] = min_distance[where] + Edge.length;
				active_vertices.insert( { min_distance[Edge.to], Edge.to } );
			}
	}
	return INT_MAX;
	}

};

#endif
