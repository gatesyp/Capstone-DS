#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;
// define the base algorithm class
struct Toolbox
{
	// define how many vertices exist in the graph
	int V = 9;
	// create empty adjacency matrix
	vector < vector <int> > graph;

	Toolbox() : V() 
	{}	

	Toolbox(int d_size) : V(d_size) 
	{}	

	// the two pure virtual functions that MUST be defined in any derived class
	virtual void createGraph() = 0;
	virtual void algo() = 0;

	// a utility function to print the graph
	void printGraph()
	{
		for(auto i : graph)
		{
			for(auto j : i)
				cout << j << " ";
			cout << endl;
		}
	}
};



struct Djisktra : Toolbox 
{
	int src = 0;
	// vector which contains information on if a vertex is included in the path
	vector <bool> sptSet; 
	// the solutions array. holds the distance from the source node to each other node
	vector <int> dist;	 

	// redefine the createGraph virtual function
	void createGraph()
	{
		// initialize the required structures before performing algorithm
		sptSet.resize(V);
		dist.resize(V);
		graph.resize(V);

		// Initialize all distances as INFINITE and stpSet[] as false
		for (int i = 0; i < V; i++)
		{
			dist[i] = INT_MAX;
			sptSet[i] = false;
		}

		// create the graph
		for(auto i : graph)
			i.resize(9);
		graph = {{0, 7, 6, 0, 0, 0, 8, 0, 0},
			{7, 0, 0, 10, 9, 0, 0, 0, 0},
			{6, 0, 0, 0, 3, 0, 0, 0, 0},
			{0, 10, 0, 0, 2, 0, 0, 0, 0},
			{0, 9, 3, 2, 0, 0, 0, 5, 1},
			{0, 0, 0, 0, 0, 0, 11, 2, 0},
			{8, 0, 0, 0, 0, 11, 0, 0, 0},
			{0, 0, 0, 0, 5, 2, 0, 0, 0},
			{0, 0, 0, 0, 1, 0, 0, 0, 0}
		};
		// an alternate graph that can be commented out (another test case which is not discussed in paper)
		//graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
			//{4, 0, 8, 0, 0, 0, 0, 11, 0},
			//{0, 8, 0, 7, 0, 4, 0, 0, 2},
			//{0, 0, 7, 0, 9, 14, 0, 0, 0},
			//{0, 0, 0, 9, 0, 10, 0, 0, 0},
			//{0, 0, 4, 0, 10, 0, 2, 0, 0},
			//{0, 0, 0, 14, 0, 2, 0, 1, 6},
			//{8, 11, 0, 0, 0, 0, 1, 0, 7},
			//{0, 0, 2, 0, 0, 0, 6, 7, 0}
		//};

	}
	// find the min distance between a vertex
	// from set of vertices not yet includest in shortest path tree
	int minDistance()
	{
		// Initialize min value
		int min = INT_MAX, min_index;

		for (int v = 0; v < V; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;
		return min_index;
	}

	// redefine algo pure virtual function. Djisktra implementation
	void algo()
	{
		// initialize source vertex distance
		dist[src] = 0;

		for (int i = 0; i < V-1; i++)
		{
			// Pick the minimum distance vertex from the set of vertices not processed yet
			int u = minDistance(); 

			// Mark the picked vertex 
			sptSet[u] = true;

			// Update dist value of the adjacent vertices of the picked vertex.
			for (int v = 0; v < V; v++)
				// update distance if is not in sptSet, there is an edge from 
				// u to v, and total weight of path from src to v through u is 
				// smaller than the current distance
				if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
					dist[v] = dist[u] + graph[u][v];
		}
	}
	// print the solution
	void printSolution()
	{
		printf("Vertex Distance from Source\n");
		for (int i = 0; i < V; i++)
			printf("%d \t\t %d\n", i, dist[i]);
	}
};

struct Floyd : Toolbox
{
	void createGraph()
	{
		// for floyd, intialize variables
		graph.resize(9);
		for(auto i : graph)
			i.resize(9);

		graph = {{999999, 7, 6, 999999, 999999, 999999, 8, 999999, 999999},
			{7, 999999, 999999, 1999999, 9, 999999, 999999, 999999, 999999},
			{6, 999999, 999999, 999999, 3, 999999, 999999, 999999, 999999},
			{999999, 1999999, 999999, 999999, 2, 999999, 999999, 999999, 999999},
			{999999, 9, 3, 2, 999999, 999999, 999999, 5, 1},
			{999999, 999999, 999999, 999999, 999999, 999999, 11, 2, 999999},
			{8, 999999, 999999, 999999, 999999, 11, 999999, 999999, 999999},
			{999999, 999999, 999999, 999999, 5, 2, 999999, 999999, 999999},
			{999999, 999999, 999999, 999999, 1, 999999, 999999, 999999, 999999}
		};
		// an alternative graph used in initial testing. not discussed in paper. can be uncommented 
		//graph = {{9999999, 4, 999999, 999999, 999999, 999999, 999999, 8, 999999},
		//
			//{4, 999999, 8, 999999, 999999, 999999, 999999, 11, 999999},
			//{999999, 8, 999999, 7, 999999, 4, 999999, 999999, 2},
			//{999999, 999999, 7, 999999, 9, 14, 999999, 999999, 999999},
			//{999999, 999999, 999999, 9, 999999, 1999999, 999999, 999999, 999999},
			//{999999, 999999, 4, 999999, 1999999, 999999, 2, 999999, 999999},
			//{999999, 999999, 999999, 14, 999999, 2, 999999, 1, 6},
			//{8, 11, 999999, 999999, 999999, 999999, 1, 999999, 7},
			//{999999, 999999, 2, 999999, 999999, 999999, 6, 7, 999999}
		//};
		// make the diagonals 0
		for(int i = 0; i < V; i++)
			graph[i][i] = 0;
	}
	// define the pure virtual function for Floyd-Warshall algorithm
	void algo()
	{
		// advanced analysis of algorithm is in paper
		for(int k = 0; k < V; k++)
			for(int i = 0; i < V; i++)
				for(int j = 0; j < V; j++)
					// update the graph if the distance for the sub problem is more optimized
					if(graph[i][j]>graph[i][k]+graph[k][j])
						graph[i][j]=graph[i][k]+graph[k][j];
	}
};
#endif
