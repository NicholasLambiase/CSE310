#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>

using namespace std;

struct Edge {
            int destination;
            double weight;
        };

class Graph{
    public:
        Graph();
        ~Graph();

        bool loadGraph(const string& filename, const string& direction);
        void runDjikstra(int source, int destination, int flag);
        void writePath(int source, int destination);
        void printAdjacencyLists();

    private:

        //Struct def of edge was here

        int numVerticies;
        int numEdges;
        bool isDirected;
        int source;

        Edge** adjacencyLists;
};

#endif