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
	int size, max;
	vector <int> dist[];	 // The output array. dist[i] will hold the shortest
	vector < vector <int> > graph;
	// distance from src to i

	vector <bool> sptSet(); // sptSet[i] will true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized


	Toolbox(int d_size, int d_max) : size(d_size), max(d_max)
	{}	

	virtual int algorithm(int source, int target){ return source; }

	void createGraph(int choice)
	{
		sptSet.resize(V);
		if(choice == 0)
		{
			//graph.resize(5);
			for(int i = 0; i < 5; ++i)
				graph[i].resize(5);
		}
		else
		{
			//graph.resize(5);
			//graph[0].push_back( {1,1});
			//graph[0].push_back({3,2});
			//graph[1].push_back( {3,2});
			//graph[2].push_back( {2,1}); 
			//graph[3].push_back( {3,1});
			//graph[4].push_back( { }) ;
		}
	}
	// A utility function to find the vertex with minimum distance value, from
	// the set of vertices not yet included in shortest path tree
	int minDistance(int dist[], bool sptSet[])
	{
		// Initialize min value
		int min = INT_MAX, min_index;

		for (int v = 0; v < V; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;

		return min_index;
	}

	// A utility function to print the constructed distance array
	int printSolution(int dist[], int n)
	{
		printf("Vertex Distance from Source\n");
		for (int i = 0; i < V; i++)
			printf("%d \t\t %d\n", i, dist[i]);
	}
};

struct Djisktra : Toolbox 
{



	// Funtion that implements Dijkstra's single source shortest path algorithm
	// for a graph represented using adjacency matrix representation
	void dijkstra()
	{
		 //[V][V];
		int src;

		// Initialize all distances as INFINITE and stpSet[] as false
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				dist[i].push_back(INT_MAX);
				sptSet[i].push_back(false);
			}
		}

		// Distance of source vertex from itself is always 0
		dist[src][src] = 0;

		// Find shortest path for all vertices
		for (int count = 0; count < V-1; count++)
		{
			// Pick the minimum distance vertex from the set of vertices not
			// yet processed. u is always equal to src in first iteration.
			//int u = minDistance(dist, sptSet); // TODO fix function call

			// Mark the picked vertex as processed
			//sptSet[u][u] = true;

			// Update dist value of the adjacent vertices of the picked vertex.
			for (int v = 0; v < V; v++)

				// Update dist[v] only if is not in sptSet, there is an edge from 
				// u to v, and total weight of path from src to v through u is 
				// smaller than current value of dist[v]
				//if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
						//&& dist[u]+graph[u][v] < dist[v])
					//dist[v] = dist[u] + graph[u][v];
		}

		// print the constructed distance array
		//printSolution(dist, V); // TODO fix function call
	}
};

struct Floyd : Toolbox
{
	void floyd()
	{

		// Initialize 
		int vertices = 5;
		vector < vector <int> > a(vertices, vector<int>(vertices,999999999));

		// initialize diagonal
		for(int i=0; i < vertices; i++)
			a[i][i]=0;

		// initialize distances
		a[0][1]=20;
		a[0][2]=10;
		a[0][4]=5;
		a[2][3]=10;
		a[3][1]=3;
		a[4][2]=2;
		a[4][3]=4;

		// Floyd-Warshall
		// Add nodes between (first 1 then 2, 3 till n) and look if
		// distance is shorter
		for(int k = 0; k < vertices; k++)
			for(int i = 0; i < vertices; i++)
				for(int j = 0; j < vertices; j++)
					if(a[i][j]>a[i][k]+a[k][j])
						a[i][j]=a[i][k]+a[k][j];

		// Print out final distance matrix
		for(int i = 0; i < vertices; i++){
			for(int j = 0; j < vertices; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
	}
};
#endif
