#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>

using namespace std;

class Graph{
    public:
        Graph();
        ~Graph();

        bool loadGraph(const string& filename, const string& direction);
        void printAdjacencyLists();
    
    private:
        struct Edge {
            int destination;
            double weight;
        };

        int numVerticies;
        int numEdges;
        bool isDirected;
        int source;

        Edge** adjacencyLists;
};

#endif