#include "min_heap.h"

using namespace std;

//Constructor and Destructor

MinHeap::MinHeap(){
    minHeap = nullptr;
    capacity = 0;
    size = 0;
}

MinHeap::~MinHeap(){
    delete(minHeap);
}

//Public Member Function Definitions

void MinHeap::init(int desiredSize){
    capacity = desiredSize;
    minHeap = new Edge[capacity];
}  

void MinHeap::push(Edge pushEdge){
    if (size + 1 <= capacity)
    {
        minHeap[size] = pushEdge;
        size++;

        int pushEdgeIndex = size-1;
        heapifyUp(pushEdgeIndex);
    }
}

Edge MinHeap::pop(){
    if (size != 0)
    {
        // //Debug
        // cout << "size is greater than 0" << endl;
        // cout << "The current root is: (" << minHeap->destination << ", " << minHeap->weight << ")" << endl;
        
        int root = 0;
        Edge poppedEdge = minHeap[root];
        
        //replace root with last edge in array and decrease size
        minHeap[root] = minHeap[size-1];
        size--;
        
        if (size > 1)
            heapifyDown(root);
        
        return poppedEdge;
    }
    else {
        Edge nullEdge;
        nullEdge.destination = 0;
        nullEdge.weight = 0;
        return nullEdge;
    }
}

bool MinHeap::empty() const{
    return size == 0;
}

//Private Member Funtion Definitions

void MinHeap::heapifyUp(int index){
    int indexParent = heapParent(index);
    while (index > 0 && minHeap[indexParent].weight > minHeap[index].weight)
    {
        swap(index, indexParent);
        index = indexParent;
        indexParent = heapParent(index);
    }
}

void MinHeap::heapifyDown(int index){
    int smallestEdgeIndex;
    int leftEdgeIndex = heapLeftChild(index);
    int rightEdgeIndex = heapRightChild(index);

    if (leftEdgeIndex < size && minHeap[leftEdgeIndex].weight < minHeap[index].weight)
        smallestEdgeIndex = leftEdgeIndex;
    else
        smallestEdgeIndex = index;

    if (rightEdgeIndex < size && minHeap[rightEdgeIndex].weight < minHeap[smallestEdgeIndex].weight)
        smallestEdgeIndex = rightEdgeIndex;

    if (smallestEdgeIndex != index)
    {
        swap(smallestEdgeIndex, index);
        heapifyDown(smallestEdgeIndex);
    }
}

void MinHeap::swap(int i, int j){
    Edge tempEdge = minHeap[i];
    minHeap[i] = minHeap[j];
    minHeap[j] = tempEdge;
}

//Heap Family Calculations
int MinHeap::heapParent(int index){
    return (index-1)/2;
}

int MinHeap::heapLeftChild(int index){
    return (2*index)+1;
}

int MinHeap::heapRightChild(int index){
    return (2*index)+2;
}

//MinHeap Printing methods

void MinHeap::printMinHeap(){
    for (int i = 0; i < size; i++){
        printEdge(minHeap[i]);
        cout << " ";
    }
    cout << endl;
}

void MinHeap::printEdge(Edge printEdge){
    cout << "(" << printEdge.destination << ", " << printEdge.weight << ")";
}