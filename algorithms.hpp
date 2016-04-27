#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <set>
#include <iostream>
#include <vector>
#include "graph.hpp"
using namespace std;
// define the base algorithm class
struct Toolbox
{
	vector< vector<Edge> > graph;
	set< pair<int,int> > active_vertices;
	int size, max;

	Toolbox() : graph() 
	{}
	Toolbox(int d_size, int d_max) : size(d_size), max(d_max)
	{}	

	virtual int algorithm(int source, int target){ return source; }

	void createGraph(int choice)
	{
		if(choice == 0)
		{
			graph.resize(5);
			for(int i = 0; i < 5; ++i)
				graph[i].resize(5);
		}
		else
		{
			graph.resize(5);
			graph[0].push_back( {1,1});
			graph[0].push_back({3,2});
			graph[1].push_back( {3,2});
			graph[2].push_back( {2,1}); 
			graph[3].push_back( {3,1});
			graph[4].push_back( { }) ;
		}
	}
};

struct Djisktra : Toolbox 
{
	int algorithm(int source, int target) {
		vector<int> min_distance(graph.size(), INT_MAX);
		min_distance[ source ] = 0;
		active_vertices.insert( {0,source} );
		while (!active_vertices.empty()) 
		{
			int where = active_vertices.begin()->second;
			if (where == target) 
				return min_distance[where];
			active_vertices.erase( active_vertices.begin() );

			for (auto Edge : graph[where])
				if (min_distance[Edge.to] > min_distance[where] + Edge.length) 
				{
					active_vertices.erase( { min_distance[Edge.to], Edge.to } );
					min_distance[Edge.to] = min_distance[where] + Edge.length;
					active_vertices.insert( { min_distance[Edge.to], Edge.to } );
				}
		}

		return INT_MAX;
	}

};

struct Floyd : Toolbox
{

	int algorithm(int source, int target)
	{
	int neighbours[graph.size()][graph.size()];
		// copy over the neighbour matrix
		for(int i = 0; i < graph.size(); i++)
		{
			for(int j = 0; j < graph[i].size(); j++)
			{
			neighbours[i][graph[i][j].to] = graph[i][j].length;
			}
		}
		for(int i = 0; i < graph.size(); i++)
		{
			for(int j = 0; j < graph[i].size(); j++)
			{
			cout << neighbours[i][i];
			}
			cout << " " << endl;
		}
		return INT_MAX;
	}
};
#endif
