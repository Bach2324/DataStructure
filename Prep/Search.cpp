#include <iostream>
#include <array>
#include <string>
#include <cmath>

using namespace std;

/*
                        ==== Search in C++ ====

- Searching in C++ is the process of sorting through a container to find a specific object
- Depending on what you are looking for and the structure of the list given, there are multiple ways to search
- The two most common ones are:

    * Linear search
    * Binary search

- Linear search is the process of traversing through the list from beginning to end or vice versa
- Linear search are really useful if your list is not sorted/ordered (values are not ascending or descending)
- However, if you use linear searching in a sorted list, the time complexity might be greater depending on where search value is located

- Binary search is the process of determining the mid value of a section of the list and deciding if the value is in it or not
- Binary search can only work on a sorted list, meaning that if the values are unordered, it will not work

    1) Determine a low, mid, and high point. Usually can be denoted as left, middle, right
        - Low point will usually start the beginning element of the array, mid point is the middle, and high point is the last element of the array
    
    2) Given a value to search for, the program will look at the mid point and determine if the value is greater than or less than the value
    3) Depending on the result, the program will then divide the array and only look for the element in that particular subsection
    4) For example, if the initial mid-point element is greater than the value given, that means that the section that is less than is ignored
    5) The program will keep doing this "divide and conquer" method until the value is found

    visually we can look at it like this - Given an array of pre-filled integers below:

    array[] = {1,2,3,4,5,6,7,8,9,10,11}
    search_value = 8;

    - In the array above, the initial low points is index 0, mid point is index 5, and high point is index 10
    - Since our search value is 8, the program will look at initial mid index value, which is index, 5, and determine if it's greater than or less than
    - The value at index 5 is 6, which is less than 8. This means that the new low point one index above the original mid point, and the high point will stay the same
    - Now the search code will only look at values between the index of 6 to 10
    - From 6 to 10, the new mid point is index 8. Code looks at the value at index 8 and determine that it's greater than search value
    - This means the low point will stay the same, and the high point will be one position below than the previous mid-point
    - Program will repeat this process until the search value is found
*/


int linearSearch(int arr[], int size, int value);
int binarySearch(int arr[], int low, int high, int value);
int binarySearchRecursive(int arr[], int low, int high, int value);

int main()
{
    int numList[] = {1, 4, 6, 8, 10, 12, 19, 20, 40, 90, 100, 200};
    int n = sizeof(numList) / sizeof(numList[0]);

    cout << "Binary search result: " << binarySearch(numList, 0, n - 1, 90) << endl;
    cout << "Linear search result: " << linearSearch(numList, sizeof(numList), 90)<< endl;


return 0;
}

int linearSearch(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
return -1;
}
int binarySearch(int arr[], int low, int high, int value)
{
    while (low <= high)                 // Traversing through the array while the low point is less than or equal to the high point
    {               
        int mid = (low + high) / 2;     // Setting our mid point based off of the subsection that we are looking at

        if (arr[mid] == value)          // Return the position at which teh search value was found
        {
            return mid;
        }
        if (arr[mid] < value)           // If the value at the mid point is less than the search value
        {
            low = mid + 1;              // The new low point will be 1 position above the original mid point
        }
        else                            // Evaluate if the value at the mid point is greater than the search value
        {
            high = mid - 1;             // If so, the the new high point is one position less
        }
    }
return -1;
}
int binarySearchRecursive(int arr[], int low, int high, int value)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == value)                                                  // Return the position at which teh search value was found
        {
            return mid;
        }
        if (arr[mid] < value)                                                   // If the value at the mid point is less than the search value
        {
            return binarySearchRecursive(arr, low, mid - 1, value);             // The new low point will be 1 position above the original mid point
        }
        else                                                                    // Evaluate if the value at the mid point is greater than the search value
        {
            return binarySearchRecursive(arr, low, mid + 1, value);             // If so, the the new high point is one position less
        }
    }
return -1;
}