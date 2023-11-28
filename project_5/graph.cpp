#include "graph.h"

using namespace std;

Graph::Graph(){
    adjacencyLists = nullptr;
    numVerticies = 0;
    numEdges = 0;
    source = 0;
    isDirected = 0;
}

Graph::~Graph(){
    if(adjacencyLists){
        for(int i = 0; i < numVerticies; i++)
            free(adjacencyLists[i]);
    }
}

bool Graph::loadGraph(const string& filename, const string& direction)
{
    ifstream file(filename);
    string line;
    if(getline(file, line))
    {
        int n, m;
        istringstream iss(line);
        if(iss >> n >> m)
        {
            numVerticies = n + 1;
            numEdges = m;

            //This creates an array of type Edge* that can store the address of every edge
            //indexing is adjacencyLists[vertex][edge of vertex]
            adjacencyLists = new Edge*[numVerticies];
        }
    }
    else{
        cerr << "Invalid Input" << endl;
    }

    return true;
}
        
void Graph::printAdjacencyLists(){
    int edgeId, startNode, endNode;
    double weight;
    string line;
    istringstream iss(line);
    if(iss >> edgeId >> startNode >> endNode >> weight){
        startNode++;
        endNode++;
        //perform checks to see if the edge is valid... do the nodes exist 1-n

        Edge* edge = new Edge; 
        edge->destination = endNode;
        edge->weight = weight;

        if(!adjacencyLists[startNode]){
            //precompute the number of edges that will be at this index for memory efficency
            adjacencyLists[startNode] = new Edge[numEdges];
        }

        int j;
        while(adjacencyLists[startNode][j].destination != 0){
            j++;
        }
        adjacencyLists[startNode][j] = *edge;

        if (!isDirected){
            Edge* reverseEdge = new Edge;
            edge->destination = startNode;
            edge->weight = weight;

            if(!adjacencyLists[endNode]){
            //precompute the number of edges that will be at this index for memory efficency
            adjacencyLists[endNode] = new Edge[numEdges];
        }

        int j;
        while(adjacencyLists[endNode][j].destination != 0){
            j++;
        }
        adjacencyLists[endNode][j] = *edge;
        }
    
    }
    else {
        cerr << "Invalid Input" << endl;
    }
}