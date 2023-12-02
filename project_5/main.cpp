#include "graph.h"

using namespace std;

int main(int argc, char* argv[]){
    string graphFilename = argv[1];
    string direction = argv[2];

    //Create a new graph object
    Graph* graph = new Graph();

    //Load the Graph
    if(!(graph->loadGraph(graphFilename, direction))){
        cerr << "Failed to load the graph";
        return 1;
    }

    // //print the adjacency list
    // graph->printAdjacencyLists();
    // cout << endl << endl << "Djikstra Test Run:" << endl;

    // //test dijkstra
    // graph->runDijkstra(1, 3, 1);
    
    string querey, quereytwo;
    int source, destination, flag;
    cin >> querey;

    while (querey != "stop")
    {
        if (querey == "find")
        {
            cin >> source >> destination >> flag;

            // //debug
            // cout << "Command is " << querey << " " << source << " " << destination << " " << flag << endl;

            graph->runDijkstra(source, destination, flag);
        }
        else if (querey == "write")
        {
            cin >> quereytwo >> source >> destination;

            // //debug
            // cout << "Command is " << querey << " " << source << " " << destination << endl;

            graph->writePath(source, destination);
        }
        else
            cout << "Invalid query. Please use 'find', 'write', or 'stop'." << endl;

        cin >> querey;
    }

    delete graph;

    return 0;
}