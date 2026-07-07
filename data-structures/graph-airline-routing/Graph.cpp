// Mateo Sanchez Sinche, CS 110C

#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph()
{
    cityNames[0] = "SFO";
    cityNames[1] = "LAX";
    cityNames[2] = "LAS";
    cityNames[3] = "PHX";
    cityNames[4] = "DEN";
    cityNames[5] = "JFK";

    // Initialize matrix
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = INF;
        }
    }

    // Add edges
    matrix[0][1] = matrix[1][0] = 120;
    matrix[0][2] = matrix[2][0] = 150;
    matrix[0][5] = matrix[5][0] = 500;
    matrix[1][3] = matrix[3][1] = 75;
    matrix[1][5] = matrix[5][1] = 350;
    matrix[2][4] = matrix[4][2] = 250;
    matrix[3][4] = matrix[4][3] = 150;
}

void Graph::printMatrix() const
{
    cout << "Adjacency Matrix:\n";
    cout << "\t";

    for (int j = 0; j < SIZE; j++)
        cout << cityNames[j] << "\t";

    cout << "\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << cityNames[i] << "\t";

        for (int j = 0; j < SIZE; j++)
        {
            if (matrix[i][j] == INF)
                cout << "INF\t";
            else
                cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
	cout << endl;
}

void Graph::shortestPath()
{
    int weight[SIZE];
    bool vertexSet[SIZE] = { false };

    // Step 1: Initialization
    vertexSet[0] = true;

    for (int v = 0; v < SIZE; v++)
        weight[v] = matrix[0][v];

    // Print Initialization
    cout << "Initialization:\n";
    cout << "vertexSet = { 0 }\n";

    cout << "weight array: ";
    for (int i = 0; i < SIZE; i++)
    {
        if (weight[i] >= INF)
            cout << "INF ";
        else
            cout << weight[i] << " ";
    }
    cout << "\n\n";

    // Steps 2 through n
    for (int step = 2; step <= SIZE; step++)
    {
        int minWeight = INF;
        int v = -1;

        // Find smallest weight[v] not in vertexSet
        for (int i = 0; i < SIZE; i++)
        {
            if (!vertexSet[i] && weight[i] < minWeight)
            {
                minWeight = weight[i];
                v = i;
            }
        }

        if (v == -1)
            break;

        vertexSet[v] = true;

        // Update weight[u]
        for (int u = 0; u < SIZE; u++)
        {
            if (!vertexSet[u] &&
                weight[u] > weight[v] + matrix[v][u])
            {
                weight[u] = weight[v] + matrix[v][u];
            }
        }

        // Debug Trace Output
        cout << "Step " << step << ":\n";
        cout << "v = " << v << " (" << cityNames[v] << ")\n";

        cout << "vertexSet = { ";
        for (int i = 0; i < SIZE; i++)
        {
            if (vertexSet[i])
                cout << i << " ";
        }
        cout << "}\n";

        cout << "weight array: ";
        for (int i = 0; i < SIZE; i++)
        {
            if (weight[i] >= INF)
                cout << "INF ";
            else
                cout << weight[i] << " ";
        }
        cout << "\n\n";
    }

    // Final Output
    cout << "Lowest Cost Fares from SFO:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "SFO to " << cityNames[i] << ": $" << weight[i] << endl;
    }
}