#include "Complexity_Timer.hpp"
#include "Complexity_Recorder.hpp"
#include <climits>
#include <iostream>
#include <set>
#include <vector>
#include "graph.cpp"
#include "algorithms.cpp"
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
	// option 1
	vector<recorder<timer> > stats(10);	
	Djisktra algo1;
	for(int i = 0; i < 4; ++i) {
		stats[i].reset();
	}
	int counter = 0;
	vector< vector<Edge> > graph(10, vector<Edge>(10));// = { { {1,1}, {3,2} }, { {2,1} }, { {3,1} }, { } };

	for(int SIZE = 10; SIZE < 20; ++SIZE ) {
		cout << SIZE << endl;

		//initialize graph
		int node, to, length;
		for(int i = 0; i< SIZE; i++) {
			node = rand() % SIZE;
			to = rand() % SIZE;
			length = rand() % SIZE;
			cout << node << "   " << to << "   " << length << endl;
			//graph[node].push_back( to, length );
		}

		timer1.restart();
		cout << algo1.dijkstra(graph,0,(graph.size() - 1)) << endl;
		timer1.stop();

		stats[counter].record(timer1);

		++counter;
	}
	// option 2
	// maybe goes out of scope during algo run, and accesses bad memory? 
	//graph myGraph;
	//myGraph.addElement(0, 1, 1);
	//myGraph.addElement(0, 3, 2);
	//myGraph.addElement(0, 2, 1);
	//myGraph.addElement(0, 3, 1);
	// cout << dijkstra(myGraph.graph,0,3) << endl;
}
