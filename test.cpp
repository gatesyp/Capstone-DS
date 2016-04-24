#include <climits>
#include <iostream>
#include <set>
#include <vector>
#include "graph.cpp"
#include "algorithms.cpp"

using namespace std;
// throws Seg Fault when using option 2


int main() {
	// option 1
	vector< vector<Edge> > graph = { { {1,1}, {3,2} }, { {2,1} }, { {3,1} }, { } };
	Djisktra algo1;
	cout << algo1.dijkstra(graph,0,3) << endl;

	// option 2
	// maybe goes out of scope during algo run, and accesses bad memory? 
	//graph myGraph;
	//myGraph.addElement(0, 1, 1);
	//myGraph.addElement(0, 3, 2);
	//myGraph.addElement(0, 2, 1);
	//myGraph.addElement(0, 3, 1);
	// cout << dijkstra(myGraph.graph,0,3) << endl;
}
