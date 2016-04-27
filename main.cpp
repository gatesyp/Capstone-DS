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
	// completely working Djisktra
	//Djisktra algo;
	//algo.createGraph(4);
	//cout << algo.algorithm(0, 3) << endl;
	// floyd warshal


	Floyd algo1;
	algo1.createGraph(4);
	//cout << algo1.algorithm(0, 3) << endl;
algo1.algorithm(0, 3);


}
