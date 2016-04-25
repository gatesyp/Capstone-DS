#include "Complexity_Timer.hpp"
#include "Complexity_Recorder.hpp"
#include "algorithms.hpp"
#include <climits>
#include <iostream>
#include <set>
#include <vector>
#include "graph.hpp"
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
// throws Seg Fault when using option 2

timer timer1;
int main() {
	Test c;
	//Toolbox tools;
	Edge e;
	// option 1
	vector<recorder<timer> > stats(10);	
	for(int i = 0; i < 4; ++i) {
		stats[i].reset();
	}
	int counter = 0;
	// initialize graph space
	//Edge e;
	//vector< vector<Edge> > graph(10, vector<Edge>(10));// = { { {1,1}, {3,2} }, { {2,1} }, { {3,1} }, { } };
	//int SIZE = 10;
	//cout << SIZE << endl;

	//initialize graph
	//int node, to, length;

	timer1.restart();
	//cout << algo1.dijkstra(graph,0,(graph.size() - 1)) << endl;
	timer1.stop();

	stats[counter].record(timer1);

	++counter;
}
