// Mateo Sanchez Sinche, CS 110C
// A C++ program that uses a Graph class to represent an airline route map and computes the shortest paths between cities using Dijkstra's algorithm.

#include "Graph.h"

int main()
{
    Graph airlineGraph;

    airlineGraph.printMatrix();
    airlineGraph.shortestPath();

    return 0;
}

/* SAMPLE OUTPUT:
Adjacency Matrix:
        SFO     LAX     LAS     PHX     DEN     JFK
SFO     0       120     150     INF     INF     500
LAX     120     0       INF     75      INF     350
LAS     150     INF     0       INF     250     INF
PHX     INF     75      INF     0       150     INF
DEN     INF     INF     250     150     0       INF
JFK     500     350     INF     INF     INF     0

Initialization:
vertexSet = { 0 }
weight array: 0 120 150 INF INF 500

Step 2:
v = 1 (LAX)
vertexSet = { 0 1 }
weight array: 0 120 150 195 INF 470

Step 3:
v = 2 (LAS)
vertexSet = { 0 1 2 }
weight array: 0 120 150 195 400 470

Step 4:
v = 3 (PHX)
vertexSet = { 0 1 2 3 }
weight array: 0 120 150 195 345 470

Step 5:
v = 4 (DEN)
vertexSet = { 0 1 2 3 4 }
weight array: 0 120 150 195 345 470

Step 6:
v = 5 (JFK)
vertexSet = { 0 1 2 3 4 5 }
weight array: 0 120 150 195 345 470

Lowest Cost Fares from SFO:
SFO to SFO: $0
SFO to LAX: $120
SFO to LAS: $150
SFO to PHX: $195
SFO to DEN: $345
SFO to JFK: $470
*/