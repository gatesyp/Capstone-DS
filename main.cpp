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
	//d.src = 0;
	d.createGraph();
	d.printGraph();
	d.algo();
	cout << "AFTER ALGO-------------" << endl;
	d.printSolution();
	
	cout << "DOING FLOYD NOW-------------" << endl;
	Floyd f;
	f.V = 9;
	f.createGraph();
	f.printGraph();
	f.algo();
	cout << "AFTER ALGO-------------" << endl;
	f.printGraph();


	return 0;


}
