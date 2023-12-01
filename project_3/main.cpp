#include <iostream>
#include <string>

using namespace std;

int parent(int index){
    return (index-1)/2;
}

int leftChild(int index){
    return (2*index)+1;
}

int rightChild(int index){
    return (2*index)+2;
}

void maxHeapify(int maxHeap[], int i, int heapSize){
    int largest;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l <= heapSize && maxHeap[l] > maxHeap[i])
        largest = l;
    else
        largest = i;

    if (r <= heapSize && maxHeap[r] > maxHeap[largest])
        largest = r;

    if (largest != i)
    {
        //exchange of largest and index
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = temp;

        maxHeapify(maxHeap, largest, heapSize);
    }
}

void deleteMax(int maxHeap[], int heapSize){
    if (heapSize > 0)
    {
        maxHeap[0] = maxHeap[heapSize-1];
        maxHeapify(maxHeap, 0, heapSize-1);
    }
}

void insertNode(int maxHeap[], int val, int heapSize){
    int i = heapSize-1;
    maxHeap[i] = val;
    while (i > 0 && maxHeap[parent(i)] < maxHeap[i])
    {
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[parent(i)];
        maxHeap[parent(i)] = temp;
        i = parent(i);
    }
    
}


int main(){

    // Number of elements in array
    int number_of_queries;
    cin >> number_of_queries;

    //heap setup
    int* maxHeap = new int[number_of_queries];
    int currentHeapSize = 0;

    int* printOutput = new int[number_of_queries];
    int outputIndex = 0;

    int currentQueries = 0;
    string command;
    int value;
    while (currentQueries < number_of_queries)
    {
        cin >> command;

        if (command == "INSERT")
        {
            cin >> value;
            currentHeapSize++;
            insertNode(maxHeap, value, currentHeapSize);
        }
        else if (command == "DELETE")
        {
            if (currentHeapSize > 0)
            {
                deleteMax(maxHeap, currentHeapSize);
                currentHeapSize--;
            } 
        }
        else if (command == "PRINT")
        {
            if (currentHeapSize > 0)
                printOutput[outputIndex] = maxHeap[0];
            else
                printOutput[outputIndex] = -1;
            outputIndex++;    
        }
        currentQueries++;

        // //Debugging Heap Operations
        // for (int i = 0; i < currentHeapSize; i++)
        //     cout << maxHeap[i] << ", "; 
        // cout << endl << endl;

    }

    for (int i = 0; i < outputIndex; i++)
    {
        if (printOutput[i] != -1)
            cout << printOutput[i] << endl;
        else
            cout << endl;
    }
        
}
    
    