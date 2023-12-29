// Best    O(n*log n)
// Worst   O(n*log n)
// Average O(n*log n)
// Space Complexity    O(n) //Not inplace 
// Stability   Yes

// Merge sort in C++ : https://www.programiz.com/dsa/merge-sort

// Merge Sort is one of the most popular sorting algorithms 
// that is based on the principle of Divide and Conquer Algorithm.

// Here, a problem is divided into multiple sub-problems. 
// Each sub-problem is solved individually. 
// Finally, sub-problems are combined to form the final solution.

#include <iostream>
using namespace std;

// Merge two subarrays L and M into arr

void merge(int arr[], int low, int mid, int high) 
{
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[low + i];
    }
      
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[mid + 1 + j];
    }

    // Maintain current index of sub-arrays and main array

    int i, j, k;
    i = 0;
    j = 0;
    k = low;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]


    while (i < n1 && j < n2) 
    {
        if (L[i] <= M[j]) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            //(n-i) -no. of inversion count in this step 
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them

void mergeSort(int arr[], int low, int high) 
{
    if(low>=high) return;

    // m is the point where the array is divided into two subarrays

    int mid = low + (high- low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Merge the sorted subarrays
    merge(arr, low, mid, high);
}

// Print the array
void printArray(int arr[], int size) 
{
    for(int i = 0;i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

// Driver program
int main() 
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: \n";
    printArray(arr, size);
    return 0;
}
