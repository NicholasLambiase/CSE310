#include <string>
#include "graph.h"

using namespace std;

class MinHeap{
    public:
        MinHeap(int numEdges);
        ~MinHeap();

        void InsertEdgeNode(Edge edge_to_insert);
        Edge* ExtractMinEdge();

    private:

        //this will point to an array of type Edge
        Edge* minHeap;
        int heapSize;
        int currentHeapSize;
        
        void MinHeapify();
        int Parent(int i);
        int LeftChild(int i);
        int RightChild(int i);

};
