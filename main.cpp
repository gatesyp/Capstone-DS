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
	int V = 9;
	Djisktra d;
	d.createGraph(2);
	//d.printGraph();
	d.djisktra(0);


	return 0;


}
