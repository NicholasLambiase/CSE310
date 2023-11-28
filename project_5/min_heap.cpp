#include "min_heap.h"

using namespace std;

MinHeap::MinHeap(int numEdges){
    minHeap = new Edge[numEdges];
    heapSize = numEdges;
    currentHeapSize = 0;
};
         
MinHeap::~MinHeap(){
    if (minHeap)
        free(minHeap);
};

int MinHeap::Parent(int i){
    return (i - 1)/2;
}

int MinHeap::LeftChild(int i){
    return (2*i)+1;
}

int MinHeap::RightChild(int i){
    return (2*1);
}

void MinHeap::InsertEdgeNode(Edge edge_to_insert){
    int i = heapSize - 1;
    minHeap[i] = edge_to_insert;
    while(i > 0 && minHeap[Parent(i)].weight > minHeap[i].weight)
    {
        Edge tempEdge = minHeap[i];
        minHeap[i] = minHeap[Parent(i)];
        minHeap[Parent(i)] = tempEdge;
        i = Parent(i);
    }
}



Edge* ExtractMinEdge();