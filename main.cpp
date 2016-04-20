#include <iostream>
#include <vector>
#include "graph.cpp"
// use  case: 
//
// vector< vector<Edge> > adjacancies;
//
//
// add an edge (u,v) with weight w
//
// adjacancies[u].push_back(Edge(v,w));
//
//
// get out-degree of a vertex
//
// adjacancies[u].size;
//

using namespace std;

int main()
{
	Edge myEdge(3, 5);

	vector< vector<Edge> > graph;
	graph[5].push_back(myEdge);

}
