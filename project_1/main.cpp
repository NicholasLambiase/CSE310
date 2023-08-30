#include <iostream>
using namespace std;


long long* bubbleSort(long long array[], int arr_size){
    long long placeholder;

    for (int i = 0; i < arr_size; i++)
    {
        for (int j = arr_size-1; j > i; j--)
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

void printArray(long long array[], int arr_size){
    for (int i = 0; i < arr_size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main(){
    int arr_size;

    //Take user input
    cin >> arr_size;

    //instantiating long long array with a ptr to it
    long long* elements = new long long[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        cin >> elements[i];
    }
    
    //Sort the elements of the Long Long array using the bubblesort algorithm
    long long* ans = bubbleSort(elements, arr_size);

    printArray(ans, arr_size);

    return 0;
}