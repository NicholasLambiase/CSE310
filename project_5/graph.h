#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

#include "min_heap.h"

class Graph {
public:
    Graph();
    ~Graph();

    bool loadGraph(const std::string& filename, const std::string& direction);
    void runDijkstra(int source, int destination, int flag);
    void writePath(int source, int destination);
    void printAdjacencyLists();

private:

    int numVertices;
    int numEdges;
    bool isDirected;
    int source;
    bool graphTraversed;
    bool fullTraversal;

    Edge** adjacencyLists;      // Dynamic array of adjacency lists
    double* extractedVertices;  // Dynamic array for extracted vertices
    double* relaxedVertices;    // Dynamic array for relaxed vertices
    int* predecessor;           // Dynamic array for predecessors
    double* distance;           // Dynamic array for distances
    int* listSizes;             // Dynamic array for vertex edges frequency

    MinHeap* minHeap;
};

#endif