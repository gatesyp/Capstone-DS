#include "Complexity_Timer.hpp"
#include "Complexity_Recorder.hpp"
#include "algorithms.hpp"
#include <climits>
#include <iostream>
#include <set>
#include <vector>
#include "graph.hpp"

using namespace std;

timer timer1;
// add in timer logic
int main() {
	Djisktra d;
	d.V = 9;
	d.createGraph(2);
	d.printGraph();
	d.djisktra(0);
	d.printSolution();
	
	Floyd f;
	f.V = 9;
	f.createGraph(0);
	f.floyd();
	f.printGraph();


	return 0;


}
