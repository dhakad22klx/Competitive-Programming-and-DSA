// Best    O(n+k)//Size of input Array and Count array 
// Worst   O(n+k)
// Average O(n+k)
// Space Complexity    O(max)
// Stability   Yes


//Counting Sort GFG : https://www.geeksforgeeks.org/counting-sort/


//After Prefix sum : 
// Iterate from end of the input array 
// and because traversing input array from end preserves the order of equal elements,
// which eventually makes this sorting algorithm stable.

#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int>& inputArray)
{

    int N = inputArray.size();

    // Finding the maximum element of array inputArray[].
    int M = 0;

    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);

    // Initializing countArray[] with 0
    vector<int> countArray(M + 1, 0);

    // Mapping each element of inputArray[] as an index
    // of countArray[] array

    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;

    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    // Creating outputArray[] from countArray[] array
    vector<int> outputArray(N);

    for (int i = N - 1; i >= 0; i--)

    {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];

        countArray[inputArray[i]]--;
    }

    return outputArray;
}

// Driver code
int main()

{

    // Input array
    vector<int> inputArray = { 4, 3, 12, 1, 5, 5, 3, 9 };

    // Output array
    vector<int> outputArray = countSort(inputArray);

    for (int i = 0; i < inputArray.size(); i++)
        cout << outputArray[i] << " ";

    return 0;
}


