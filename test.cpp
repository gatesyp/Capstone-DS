#include <climits>
#include <iostream>
#include <set>
#include <vector>
#include "graph.cpp"
using namespace std;
// throws Seg Fault when using option 2

int dijkstra(const vector< vector<Edge> > &graph, int source, int target) {
	vector<int> min_distance( graph.size(), INT_MAX );
	min_distance[ source ] = 0;
	set< pair<int,int> > active_vertices;
	active_vertices.insert( {0,source} );
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

int main() {
	// option 1
	vector< vector<Edge> > graph = { { {1,1}, {3,2} }, { {2,1} }, { {3,1} }, { } };
	cout << dijkstra(graph,0,3) << endl;

	// option 2
	// maybe goes out of scope during algo run, and accesses bad memory? 
	//graph myGraph;
	//myGraph.addElement(0, 1, 1);
	//myGraph.addElement(0, 3, 2);
	//myGraph.addElement(0, 2, 1);
	//myGraph.addElement(0, 3, 1);
	// cout << dijkstra(myGraph.graph,0,3) << endl;
}
