// Data Structures & Algorithms prep
// Assignment 1 -- Problem 1
// Bach Nguyen

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void printArray(int arr[], int size);
int insertIntoSortedArray(int myArray[], int numEntries, int newValue);

int main(int argc, char const *argv[])
{
    const int size = 100;
    int numArray[size];
    int count = 0;

    ifstream inFile(argv[1]);
    if (inFile.fail())
    {         
        cout << "Failed to open file." << endl;                                             // Check to see if correct file is inputed
    }
    else
    {
        string line;            
        while (getline(inFile, line))                                                       // Read the lines from the file
        {
            if (line.length() != 0)                                                         // Counter will increase if line is not empty (count the elements to store)
            {
                count++;
            }
            insertIntoSortedArray(numArray, count, stoi(line));                             // Insert into sorted array
        }
    inFile.close();
    }
return 0;
}
void printArray(int arr[], int size)
{                                                                                           // Function to print out the array in a half pyramid
    for (int i = 0; i < size; i++)                                                          // Traverse through the current length of the array
    {
        if (i == 0)                                                                         // Print out the first element of the array by itself with no comma
        {
            cout << arr[i];
        }
        else                                                                                // Print out the rest with a comma seperating each elements
        {
            cout << ", " << arr[i];
        }
    }
    cout << endl;                                                                           // End line whenever the the last element of the current size is printed
return;
}
int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{                                                                                           // Function to insert a value from a text file into a sorted array
    if (numEntries > 0)                                                                     // Make sure numEntries is greater than 0 to avoid seg faults
    {
        for (int j = (numEntries - 1); j >= 0; j--)                                         // For loop to traverse from the end of the array to the beginning
        {                                                                                   // Almost the same code as a problem that was completed in CSCI 1300
            if (newValue <= myArray[j])                                                     // Evaluate if the given value is less than or equal to an element in the array
            {
                myArray[j + 1] = myArray[j];                                                // Shift every value from that position and on up by 1 
                myArray[j] = newValue;                                                      // insert the value into the vacant position
            }
            else if (newValue > myArray[numEntries - 1])                                    // Evaluate if value is greater than the last element in the sorted array
            {
                myArray[numEntries] = newValue;                                             // Insert the value at the end of the array
            }
        }
    printArray(myArray, numEntries);                                                        // Use the print function created to print out the elements as they're inserted
    }
return numEntries;
}