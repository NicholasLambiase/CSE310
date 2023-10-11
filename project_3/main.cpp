#include <iostream>
#include <string>

using namespace std;

struct cmd
{
    int type = 0;
    int data = 0;
};

cmd parseCommand(string cmd){
    int type = 0;
    int data = 0;

    //make sure the command is all caps

    if (cmd == "PRINT")
    {
        type = 3;
    }
    else
    {
        string commandType;
        string commandData;
        char* delimiter = " ";

        int delimeterIndex = cmd.find(delimiter);
        commandType = cmd.substr(0, delimeterIndex);
        commandData = cmd.substr(delimeterIndex+1, cmd.length());

        if (commandType == "INSERT")
        {
            type = 1;
            data = stoi(commandData);
        }
        else if(commandType == "DELETE")
        {
            type = 2;
        }

    }

    //make the cmd struct
    struct cmd commandToReturn;
    commandToReturn.type = type;
    commandToReturn.data = data;

    return commandToReturn;
}

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

    
    string command;
    //to ignore the first return character we will increase the for loop count by 1
    for (int i = 0; i < number_of_queries; i++)
    {
        getline(cin, command);

        struct cmd processedCommand = parseCommand(command);

        switch (processedCommand.type)
        {
        case 1:
            //Insert
            currentHeapSize++;
            insertNode(maxHeap, processedCommand.data, currentHeapSize);
            break;

        case 2:
            //Delete
            deleteMax(maxHeap, currentHeapSize);
            currentHeapSize--;
            break;
        
        case 3:
            //Print
            if (currentHeapSize < 1)
                cout << endl;
            else
                cout << maxHeap[0] << endl;
            break;
        default:
            break;
        }

        //Debugging
        // cout << "Tree: ";
        // for (int i = 0; i < currentHeapSize; i++)
        //     cout << maxHeap[i] << ", ";
        // cout << endl;

    }

    return 0;
}