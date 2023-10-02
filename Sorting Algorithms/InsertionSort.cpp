// Best    O(n)
// Worst   O(n2)
// Average O(n2)
// Space Complexity    O(1)
// Stability   Yes

/*
Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.

Insertion sort works similarly as we sort cards in our hand in a card game.

We assume that the first card is already sorted then, we select an unsorted card. 
If the unsorted card is greater than the card in hand, it is placed on the right otherwise, to the left. 
In the same way, other unsorted cards are taken and put in their right place.

A similar approach is used by insertion sort.
*/

//https://www.programiz.com/dsa/insertion-sort

// Insertion sort in C++

#include <iostream>
using namespace std;

// Function to print an array
void printArray(int array[], int size) 
{
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void insertionSort(int array[], int size) 
{
  for (int step = 1; step < size; step++) 
  {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

// Driver code
int main() {
  int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);
  insertionSort(data, size);
  cout << "Sorted array in ascending order:\n";
  printArray(data, size);
}
