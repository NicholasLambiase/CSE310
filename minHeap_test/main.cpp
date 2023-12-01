#include <iostream>
#include <string>
#include "min_heap.h"

using namespace std;

int main(){

    // Number of elements in array
    int heapCapacity;
    cout << "Enter Capacity of Heap: ";
    cin >> heapCapacity;
    
    //instantiate a minHeap object
    MinHeap minHeap;
    minHeap.init(heapCapacity);

    string command;
    int destination;
    double weight;

    //Grab first command
    cout << "Command: ";
    cin >> command;

    while (command != "stop")
    {
        if (command == "push")
        {
            cin >> destination >> weight;
            Edge* pushEdge = new Edge;
            pushEdge->destination = destination;
            pushEdge->weight = weight;
            minHeap.push(*pushEdge);
        }
        else if (command == "pop")
        {
            Edge poppedEdge = minHeap.pop();
            if (poppedEdge.destination == 0)
                cout << "Popped NULL Edge - Therefore Heap was empty" << endl;
            else {
                cout << "Popped Edge was: ";
                minHeap.printEdge(poppedEdge);
                cout << endl;
            }
        }
        minHeap.printMinHeap();
        cout << endl << "Command: ";
        cin >> command;
    }

    cout << "Program Exited..." << endl << "Final Heap: ";
    minHeap.printMinHeap();
    cout << endl;

    return 0;
}

