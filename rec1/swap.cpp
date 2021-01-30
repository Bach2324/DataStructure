// CSCI 2270 -- Data Structures
// Recitation 1 Assignment
// Bach Nguyen

#include <iostream>
#include "swap.h"

using namespace std;

// Function definitions
// Pass By Value

void swap(int n1, int n2)
{
  int temp;
  temp = n1;
  n1 = n2;
  n2 = temp;
}
// Pass By Pointer
void swap_by_pointers(int *n1, int *n2)
{
  int temp = *n1; // Assign temp to the value that the pointer n1 is pointing to (dereferencing)
  *n1 = *n2;    // Swap the values that each pointer is pointing to
  *n2 = temp;   // Update the value that pointer n2 is pointing to, to what we stored in temp (previous value n1 is pointing to)
}
// Function to reverse the array through pointers
void reverse(int array[], int array_size)
{
  // pointer1 pointing at the beginning of the array
  int *pointer1 = array;

  // pointer2 pointing at end of the array
  int *pointer2 = array + array_size - 1;
  // TODO Use the above swap function and update pointers to reverse your array
  while (pointer1 < pointer2)
  {
    swap_by_pointers(pointer1, pointer2); // Use swap function
    pointer1++;   // Updating our pointers
    pointer2--;
  }
}
// GOLD problem
// Function to do cumulative sum of the array
void cumulative_sum(int arr[], int array_size)
{
    int *pointer1 = arr; // Pointer pointing at the beginning of the array
    int i = 1, sum = 0; // Declare iteration variable and sum variable

    while (i <= array_size)  // While loop to traverse the length of the array
    {
      sum = sum + *pointer1;  // Sum up array but adding each element with the last iteration (dereferencing pointer1 to get the value it is pointing to)
      *pointer1 = sum;  // *insert the total sum at that iteration into the array
      pointer1++; // Increment pointer
      i++; // Increment i
    }

}
