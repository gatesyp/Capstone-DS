# Capstone-DS

Pairing Graphs Traversals with Template Methods
Implement all of the algorithms discussed in OpenDSA, or just a subset?
# TODO
- implement random-graph creation
- research graph specifics (acyclic vs cyclic)
- Organize the templated methods better, stub out code
Template Methods with Graph Traversals

Make on base class, and then derive from it. 

Fit each graph traversal method into one base class, and have each specific algo derive and change certain aspects

Ex. 

Base
{
// vars
// core algorithm
}

// shortest path
Djisktra:Base
{
// keep vars the same
// different core algorithm now
}

// minimally spanning tree
Prim:Base
{
// keep vars the same
// different core algorithm now
}

// kruskals MSP
Kruskal:Base
{
}
// depth first search
DFS:Base
{
}
// breadth first search
BFS:Base
{
}

Topological sorts using DFS/BFS (or queue based)





