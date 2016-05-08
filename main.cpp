#include "Complexity_Timer.hpp"
#include "Complexity_Recorder.hpp"
#include "algorithms.hpp"
#include <iostream>
#include <vector>

using namespace std;

//NOTE: UNCOMMENT THE TIMING CODE IF YOU WISH TO SEE TIMING RESULTS

//timer timer1;
//const int num_algos = 2;
//const int num_trials = 1;
//const char* headings[num_algos] = {"|	 DJISKTRA      ", "|	 Floyd-Warshall    |"};
int main() {
	//vector<recorder<timer> > stats(num_algos);
	//cout << "________";
	//for (int i = 0; i < num_algos; ++i)
		//cout << headings[i];
	//cout << endl;

	//cout << "  Range ";
	//for (int i = 0; i < num_algos; ++i)
		//cout << "	|      Time      ";
	//cout << endl;

	Dijsktra d;
	d.V = 9;
	d.src = 0;
	d.createGraph();
	d.printGraph();
	//timer1.restart();
	d.algo();
	cout << "AFTER ALGO-------------" << endl;
	d.printSolution();
	//timer1.stop();
	//stats[0].record(timer1);

	cout << "DOING FLOYD NOW-------------" << endl;
	Floyd f;
	f.V = 9;
	f.createGraph();
	f.printGraph();
	//timer1.restart();
	f.algo();
	cout << "AFTER ALGO-------------" << endl;
	f.printGraph();

	//timer1.stop();
	//stats[1].record(timer1);

	//stats[0].report(cout);
	//stats[1].report(cout);
	//cout << endl;
	//cout << endl;
	return 0;


}
