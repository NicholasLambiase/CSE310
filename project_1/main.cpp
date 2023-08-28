#include <iostream>
using namespace std;


int* bubbleSort(int array[]){
    int placeholder;
    for (int i = 0; i < sizeof(*array); i++)
    {
        for (int j = sizeof(*array); j > i; j--)
        {
            if (array[j] < array[j-1])
            {
                placeholder = array[j];
                array[j] = array[j-1];
                array[j-1] = placeholder;
            }
        }
    }
    return array;
}

void printArray(int array[], int arr_size){
    for (int i = 0; i < arr_size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr_size;

    //Take user input
    cin >> arr_size;

    //instantiating an empty int array of size arr_size
    int* elements = new int[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        cin >> elements[i];
    }
    
    //Sort the elements of the int array using the bubblesort algorithm
    int* ans = bubbleSort(elements);

    printArray(ans, arr_size);

    return 0;
}