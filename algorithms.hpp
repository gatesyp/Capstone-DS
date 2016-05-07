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
	int V = 9;
	vector <int> dist;	 // The output array. dist[i] will hold the shortest
	vector < vector <int> > graph;
	// distance from src to i

	vector <bool> sptSet; // sptSet[i] will true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	Toolbox() : V() 
	{}	

	Toolbox(int d_size) : V(d_size) 
	{}	
	virtual int algorithm(int source, int target){ return source; }

	void createGraph(int choice)
	{
		sptSet.resize(V);
			dist.resize(9);
		if(choice == 0)
		{
			graph.resize(9);
			for(auto i : graph)
				i.resize(9);
			graph = {{9999999, 4, 999999, 999999, 999999, 999999, 999999, 8, 999999},
				{4, 999999, 8, 999999, 999999, 999999, 999999, 11, 999999},
				{999999, 8, 999999, 7, 999999, 4, 999999, 999999, 2},
				{999999, 999999, 7, 999999, 9, 14, 999999, 999999, 999999},
				{999999, 999999, 999999, 9, 999999, 1999999, 999999, 999999, 999999},
				{999999, 999999, 4, 999999, 1999999, 999999, 2, 999999, 999999},
				{999999, 999999, 999999, 14, 999999, 2, 999999, 1, 6},
				{8, 11, 999999, 999999, 999999, 999999, 1, 999999, 7},
				{999999, 999999, 2, 999999, 999999, 999999, 6, 7, 999999}
				};
		}
		else
		{
			graph.resize(9);
			for(auto i : graph)
				i.resize(9);
			graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
				{4, 0, 8, 0, 0, 0, 0, 11, 0},
				{0, 8, 0, 7, 0, 4, 0, 0, 2},
				{0, 0, 7, 0, 9, 14, 0, 0, 0},
				{0, 0, 0, 9, 0, 10, 0, 0, 0},
				{0, 0, 4, 0, 10, 0, 2, 0, 0},
				{0, 0, 0, 14, 0, 2, 0, 1, 6},
				{8, 11, 0, 0, 0, 0, 1, 0, 7},
				{0, 0, 2, 0, 0, 0, 6, 7, 0}
				};
		}
	}
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

struct Djisktra : public Toolbox 
{
	// A utility function to print the constructed distance array
	void printSolution()
	{
		printf("Vertex Distance from Source\n");
		for (int i = 0; i < V; i++)
			printf("%d \t\t %d\n", i, dist[i]);
	}
	int minDistance()
	{
		// Initialize min value
		int min = INT_MAX, min_index;

		for (int v = 0; v < V; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;

		return min_index;
	}

	// Funtion that implements Dijkstra's single source shortest path algorithm
	// for a graph represented using adjacency matrix representation
	void djisktra(int src)
	{

		// Initialize all distances as INFINITE and stpSet[] as false
		for (int i = 0; i < V; i++)
		{
				dist[i] = INT_MAX;
				sptSet[i] = false;
		}

		// Distance of source vertex from itself is always 0
		dist[src] = 0;

		// Find shortest path for all vertices
		for (int count = 0; count < V-1; count++)
		{
			// Pick the minimum distance vertex from the set of vertices not
			// yet processed. u is always equal to src in first iteration.
			int u = minDistance(); // TODO fix function call

			// Mark the picked vertex as processed
			sptSet[u] = true;

			// Update dist value of the adjacent vertices of the picked vertex.
			for (int v = 0; v < V; v++)

				// Update dist[v] only if is not in sptSet, there is an edge from 
				// u to v, and total weight of path from src to v through u is 
				// smaller than current value of dist[v]
				if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
						&& dist[u]+graph[u][v] < dist[v])
					dist[v] = dist[u] + graph[u][v];
		}
	}
};

struct Floyd : Toolbox
{
	void floyd()
	{
		for(int k = 0; k < V; k++)
			for(int i = 0; i < V; i++)
				for(int j = 0; j < V; j++)
					if(graph[i][j]>graph[i][k]+graph[k][j])
						graph[i][j]=graph[i][k]+graph[k][j];
	}
};
#endif
