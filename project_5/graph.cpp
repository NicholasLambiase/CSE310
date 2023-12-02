#include "graph.h"

using namespace std;

Graph::Graph(){
    numVertices = 0;
    numEdges = 0;
    isDirected = false;
    source = 0;
    graphTraversed = false;
    fullTraversal = false;

    adjacencyLists = nullptr;
    extractedVertices = nullptr;
    relaxedVertices = nullptr;
    predecessor = nullptr;
    distance = nullptr;
    listSizes = nullptr;
}

Graph::~Graph(){
    if(adjacencyLists){
        for(int i = 0; i < numVertices; i++)
            delete adjacencyLists[i];
    }
    
    delete[] adjacencyLists;
    delete[] extractedVertices;
    delete[] relaxedVertices;
    delete[] predecessor;
    delete[] distance;
    delete[] listSizes;
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
    
void Graph::runDijkstra(int newSource, int destination, int flag){
    //initialize variables and data structure
    int heapCapacity = numVertices;
    source = newSource;
    graphTraversed = true;
    fullTraversal = true;

    //Initialize all Dijkstra Arrays and data
    const double DOUBLE_MAX = 9999999999.0;
    bool* extracted = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        extracted[i] = false;
        extractedVertices[i] = -1;
        relaxedVertices[i] = -1;
        predecessor[i] = -1;
        distance[i] = DOUBLE_MAX;
    }

    //Mark the source node as extracted
    extracted[source] = true;
    
    //initialize MinHeap
    MinHeap minHeap;
    minHeap.init(heapCapacity);
    distance[source] = 0;
    
    Edge* sourceEdge = new Edge;
    sourceEdge->destination = newSource;
    sourceEdge->weight = 0;

    minHeap.push(*sourceEdge);

    //If flag is set, print initial insertion
    if (flag == 1)
        printf("Insert vertex %d, key=%12.4f\n", sourceEdge->destination, sourceEdge->weight);

    //Main Dijkstra Loop
    while (!minHeap.empty())
    {
        Edge extractedEdge = minHeap.pop();
        int currVert = extractedEdge.destination;
        double currWeight = distance[extractedEdge.destination];

        //Mark the vertex as extracted - officially visited
        extracted[currVert] = true;
        //Copy the current shortest distance from source to extracted vertex to extractedVerticies array
        extractedVertices[currVert] = distance[currVert];

        //if flag is set print deletion of vertex
        if (flag == 1)
            printf("Delete vertex %d, key=%12.4f\n", currVert, currWeight);

        //if the destination is reached exit the loop
        if (currVert == destination) {
            // //debug
            // cout << "Destination found!" << endl;
            break;
        }
        
        //Loop through adjacency list of current vertex
        if (adjacencyLists[currVert])
        {
            int j = 0;
            while (adjacencyLists[currVert][j].destination != 0)
            {   
                //Extract neightbor vertecies information
                int currAdjDestination = adjacencyLists[currVert][j].destination;
                double currAdjWeight = adjacencyLists[currVert][j].weight;

                //if neighbor is not extracted and relaxation is possible
                if (!extracted[currAdjDestination] && ((distance[currVert] + currAdjWeight) < distance[currAdjDestination]))
                {
                    //perform relaxation
                    double oldDistance = distance[currAdjDestination];
                    distance[currAdjDestination] = distance[currVert] + currAdjWeight;
                    predecessor[currAdjDestination] = currVert;
                    relaxedVertices[currAdjDestination] = distance[currAdjDestination];

                    //if flag is set
                    if (oldDistance != DOUBLE_MAX && flag == 1)
                        printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", currAdjDestination, oldDistance, distance[currAdjDestination]);

                    //push neighbor into minHeap
                    Edge* pushEdge = new Edge;
                    pushEdge->destination = currAdjDestination;
                    pushEdge->weight = distance[currAdjDestination];
                    minHeap.push(*pushEdge);

                    if (flag == 1)
                        printf("Insert vertex %d, key=%12.4f\n", currAdjDestination, distance[currAdjDestination]);
                }
                j++;
            }
            
        }

        // //debugging
        // minHeap.printMinHeap();
        // cout << endl;

    }

    while (!minHeap.empty())
    {
        Edge leftOverEdge = minHeap.pop();
        if (!extracted[leftOverEdge.destination])
            fullTraversal = false;
    }
    
    delete[] extracted;

}

void Graph::writePath(int s, int d){

    //check to see if the computation has even occured yet
    if (!graphTraversed) {
        cout << "Error: no path computation done" << endl;
        return;
    }
    
    //Check to see if the write path is a valid source destination pair
    if (s != source || d < 1 || d >= numVertices) {
        cout << "Error: invalid source destination pair" << endl;
        return;
    }
    
    if (extractedVertices[d] != -1)
    {
        //Create new array to store the path
        int* path = new int[numVertices];
        int current = d;
        int pathsize = 0;

        //Reconstruct the path
        while (current != s)
        {
            path[pathsize] = current;
            current = predecessor[current];
            pathsize++;
        }

        path[pathsize] = s;

        //Print the shortest path
        cout << "Shortest path: ";
        for (int i = pathsize; i >= 0; i--)
            cout << path[i] << " ";
        cout << endl;

        //Print path weight
        printf("The path weight is: %12.4f\n", distance[d]);

        delete[] path;
        
    }
    else if (relaxedVertices[d] != -1)
    {
        //Create new array to store the path
        int* path = new int[numVertices];
        int current = d;
        int pathsize = 0;

        //Reconstruct the path
        while (current != s)
        {
            path[pathsize] = current;
            current = predecessor[current];
            pathsize++;
        }

        path[pathsize] = s;

        //Print the shortest path
        cout << "Path not known to be shortest: ";
        for (int i = pathsize; i >= 0; i--)
            cout << path[i] << " ";
        cout << endl;

        //Print path weight
        printf("The path weight is: %12.4f\n", distance[d]);

        delete[] path;
        
    }
    // there is still a node left in the network
    else if (fullTraversal == false)
        cout << "No " << s << "-" << d << " path has been computed, yet." << endl;
    // traversed as far as possible. did not see the d in extracted or relaxed
    else
        cout << "No " << s << "-" << d << " path exists." << endl;
    
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