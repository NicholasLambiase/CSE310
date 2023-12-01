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

    //print the adjacency list
    graph->printAdjacencyLists();

    //get first command
    // string line;
    // getline(cin, line);
    // istringstream iss(line);

    // if (iss << )
    // {
    //     /* code */
    // }
    

    //while the command is not exit
    //use a switch case to execute given command
    //read next command

    return 0;
}