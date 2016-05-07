#include "Complexity_Timer.hpp"
#include "Complexity_Recorder.hpp"
#include "algorithms.hpp"
#include <iostream>
#include <vector>

using namespace std;

timer timer1;
// add in timer logic
int main() {
	Djisktra d;
	d.V = 9;
	d.createGraph(1);
	d.printGraph();
	d.djisktra(0);
	//d.printSolution();
	
	Floyd f;
	f.V = 9;
	f.createGraph(0);
	f.printGraph();
	f.floyd();
	cout << "AFTER ALGO-------------" << endl;
	f.printGraph();


	return 0;


}
