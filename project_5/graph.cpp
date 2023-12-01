#include "graph.h"

using namespace std;

Graph::Graph(){
    adjacencyLists = nullptr;
    numVertices = 0;
    numEdges = 0;
    source = 0;
    isDirected = 0;
}

Graph::~Graph(){
    if(adjacencyLists){
        for(int i = 0; i < numVertices; i++)
            free(adjacencyLists[i]);
    }
}

bool Graph::loadGraph(const string& filename, const string& direction)
{
    ifstream file(filename);
    string line;

    //Check if the file is successfully opened
    if(!(file.is_open()))
    {
        cout << "File was not opened - File check condition" << endl;
        return false;
    }

    if(getline(file, line)){
        
        int n, m;
        istringstream iss(line);
        if(iss >> n >> m)
        {
            numVertices = n + 1;
            numEdges = m;

            //This creates an array of type Edge* that can store the address of every edge
            //indexing is adjacencyLists[vertex][edge of vertex]
            adjacencyLists = new Edge*[numVertices];
            for(int i = 0; i < numVertices; i++)
                adjacencyLists[i] = nullptr;
            
            // Allocate memory for extractedVertices, relaxedVertices, predecessor, and distance
            extractedVertices = new double[numVertices];
            relaxedVertices = new double[numVertices];
            predecessor = new int[numVertices];
            distance = new double[numVertices];
            listSizes = new int[numVertices];
            
            for(int i = 0; i < numVertices; i++) {
                extractedVertices[i] = -1;
                relaxedVertices[i] = -1;
                listSizes[i] = 0;
            }
        }
        else {
            cerr << "Invalid Format for the first line in the input file" << endl;
            return false;
        }
    }

    //Make a full pass on the file to count the number of edges per vertex
    while (getline(file, line))
    {
        istringstream iss(line);
        int edgeId, startNode, endNode;
        double weight;
        if(iss >> edgeId >> startNode >> endNode >> weight) {
            //Converts to one based indexing
            startNode++;
            endNode++;
            
            listSizes[startNode]++;
            if (direction == "undirected")
                listSizes[endNode]++;
        }
    }

    //initialize all of the lists with the appropriate number of edges + 1
    for (int i = 0; i < numVertices; i++){
        Edge* emptyEdge = new Edge;
        emptyEdge->destination = 0;
        emptyEdge->weight = 0;

        int listLength = listSizes[i] + 1;

        adjacencyLists[i] = new Edge[listLength];

        for (int j = 0; j < listLength; j++)
            adjacencyLists[i][j] = *emptyEdge;
    }

    //This code will rewind to the beginning of the file and skip the first line
    file.clear();
    file.seekg(0, ios::beg);
    getline(file, line);

    //Start reading in the edges line by line
    while (getline(file, line))
    {   
        int edgeId, startNode, endNode;
        double weight;
        istringstream iss(line);

        if(iss >> edgeId >> startNode >> endNode >> weight){
            
            //Converts to one based indexing
            startNode++;
            endNode++;
            
            //perform checks to see if the edge is valid... do the nodes exist 1-n
            if (startNode > numVertices || endNode > numVertices || startNode < 1 || endNode < 1)
            {
                cout << "Invalid node IDs in the input file." << endl;
                return false;
            }
            
            //Create new edge
            Edge* edge = new Edge; 
            edge->destination = endNode;
            edge->weight = weight;

            //Find the next available slot in the adjacency List
            int j = 0;
            while(adjacencyLists[startNode][j].destination != 0)
                j++;
            
            //Insert into the adjacency list
            adjacencyLists[startNode][j] = *edge;

            if (direction == "undirected"){
                
                //Create new Reverse Edge
                Edge* reverseEdge = new Edge; 
                reverseEdge->destination = startNode;
                reverseEdge->weight = weight;
                
                //Find the next available slot in the adjacency List
                int j = 0;
                while(adjacencyLists[endNode][j].destination != 0)
                    j++;

                //insert into the adjacency list
                adjacencyLists[endNode][j] = *reverseEdge;
            }
        
        }
        else {
            cout << "Invalid Input" << endl;
            return false;
        }
    }
    
    //close the file
    file.close();

    return true;
}
    
void Graph::runDijkstra(int source, int destination, int flag){
    
}

void writePath(int source, int destination){

}

void Graph::printAdjacencyLists(){

    for (int i = 0; i < numVertices; i++)
    {
        cout << "Adjacency List for vertex " << i << ": ";

        if (adjacencyLists[i] != nullptr)
        {
            int j = 0;
            while (adjacencyLists[i][j].destination != 0)
            {
                cout << "(" << adjacencyLists[i][j].destination << ", " << adjacencyLists[i][j].weight << ") ";
                j++;
            }
            //cout << predecessor[i];
        }
        
        cout << endl;
    }
    
}