#include <iostream>
#include <vector>
#include "graph.cpp"
#include "algorithms.cpp"
#include "Complexity_Timer.hpp"
#include "Complexity_Recorder.hpp"
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
	graph myGraph;
	// create a random graph
	myGraph.addElement(0, 1, 0);
	myGraph.addElement(1, 2, 2);
	myGraph.addElement(0, 2, 1);
	Djisktra d;
	int max = d.getPath(myGraph.graph, 0, 2);
	cout << max;

}
