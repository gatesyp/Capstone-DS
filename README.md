# Capstone-DS

Pairing Graphs Traversals with Template Methods (shortest path)
<br>
Solve a problem using Graph traversals. 
- Shortest path problems
- City planner adding new vertex, or adjusting traffic plans, to see how it affects the cost of traversing the entire city (Floyd-Warshall)
- Google maps telling you the time it will take to go to a destination (Dijkstra)

#To Run
```
g++ -std=c++11 main.cpp -o algo
./algo
```
#To Modify Graph
algorithms.hpp -> change the graph creating in createGraph() for the derived classes


# TODO
1. Random graph creation?
  1. maybe create a pure random graph and have one path be hardcoded from src to target

# References
Implementation Tips & Introduction 
- slide 26+ >> https://ece.uwaterloo.ca/~cmoreno/ece250/2012-03-26--graphs-implementation.pdf
- http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm
- https://blog.cedric.ws/c-floyd-warshall-shortest-distance-explanation-code
- https://sourcemaking.com/design_patterns/template_method/cpp/1
- https://sourcemaking.com/design_patterns/template_method/cpp/2
- https://en.wikipedia.org/wiki/Template_method_pattern


