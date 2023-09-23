//#include <bits/stdc++.h>
using namespace std;

void merge_two_sorted_arrays(long long int array[], int const left, int const mid, int const right) 
{
    // Sub-array sizes
	int const sub_array_one = mid - left + 1;
	int const sub_array_two = right - mid;

	// Create temp arrays
	long long int *left_array = new long long int[sub_array_one];
	long long int *right_array = new long long int[sub_array_two];

	/* Copy data to temp arrays leftArray[] and rightArray[] */
        // Your code here
	for(int left_to_mid = 0; left_to_mid < sub_array_one; left_to_mid++){
		left_array[left_to_mid] = array[left + left_to_mid];
	}

	for(int mid_to_right = 0; mid_to_right < sub_array_two; mid_to_right++){
			right_array[mid_to_right] = array[mid + mid_to_right];
		}

    /* Indices of the left, right and merged array*/
        // Your code here
	int smallest_left = 0;
	int smallest_right = 0;
	int index_to_fill = 0;

	/* Merge the temp arrays back into array[left..right] */
        // Your code here
	while(smallest_left < sub_array_one && smallest_right < sub_array_two){
		if (left_array[smallest_left] > right_array[smallest_right])
		{
			array[index_to_fill] = left_array[smallest_left];
			smallest_left++;
		}
		else
		{
			array[index_to_fill] = right_array[smallest_right];
			smallest_right++;
		}
		index_to_fill++;
	}

	/* Copy the remaining elements of
	   left[], if there are any */
        // Your code here

	while(smallest_left < sub_array_one){
		array[index_to_fill] = left_array[smallest_left];
		smallest_left++;
		index_to_fill++;
	}

	/* Copy the remaining elements of
	   right[], if there are any */
       // Your code here
	while(smallest_right < sub_array_two){
		array[index_to_fill] = right_array[smallest_right];
		smallest_right++;
		index_to_fill++;
	}

	// Delete left and right sub-arrays
    delete[] left_array;
    delete[] right_array;
}

void merge_sort(long long int array[], int const begin, int const end)
{
    /* Recursive calls of merge_sort and merge_two_sorted_arrays */
        // Your code here
	if (begin >= end)
		return;
	int const middle = (begin + end)/2;
	merge_sort(array, begin, middle);
	merge_sort(array, middle + 1, end);
	merge_two_sorted_arrays(array, begin, middle, end);
}
