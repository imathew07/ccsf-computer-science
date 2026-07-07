// Mateo Sanchez Sinche, CS 110C

#ifndef GRAPH_H
#define GRAPH_H

#include <string>

using namespace std;

class Graph {
private:
    static const int SIZE = 6;
    static const int INF = 999999;

    int matrix[SIZE][SIZE];
    string cityNames[SIZE];

public:
	Graph(); // Constructor to initialize the graph

	void shortestPath(); // Method to compute the shortest paths using Dijkstra's algorithm
	void printMatrix() const; // Method to print the adjacency matrix
};

#endif