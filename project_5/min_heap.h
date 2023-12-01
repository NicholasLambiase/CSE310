#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>

struct Edge {
        int destination;
        double weight;
    };

class MinHeap {
public:
    MinHeap();
    ~MinHeap();
    void init(int desiredSize);  // Initialize the min-heap with a given size
    void push(Edge pushEdge);
    Edge pop();
    bool empty() const;

    //MinHeap Printing methods
    void printMinHeap();
    void printEdge(Edge printEdge);

private:
    Edge* minHeap;// Array to store edges of Min Heap
    int capacity; // Maximum size of the heap
    int size;     // Current number of elements in the heap

    void heapifyUp(int index);
    void heapifyDown(int index);
    void swap(int i, int j);

    //Heap Family Calculations
    int heapParent(int index);
    int heapLeftChild(int index);
    int heapRightChild(int index);
};

#endif
