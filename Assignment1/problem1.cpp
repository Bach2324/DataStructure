// CSCI 2270 -- Data Structures
// Assignment 1 -- Problem 1
// Bach Nguyen

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// ++++++++++ Function Prototyping ++++++++++ // 
void printArray(float arr[], int size);
int addToArrayAsc(float sortedArray[], int numElements, float newValue);

int main(int argc, const char *argv[])                  // Passing in command line arguments
{
    float arr[100];                                     // Declaring our array and variables to use
    int count = 0;
    ifstream inFile(argv[1]);                           // To open the file using the 2nd command line argument

    if (!inFile.good())                                 // Print out a message if file fails to open
    {
        cout << "Failed to open the file." << endl;
    }
    else
    {   
        string line;            
        while(getline(inFile, line))                    // Grabbing each line from the read in file
        {
            if (line.length() != 0)                     // Only evaluate if line is not empty
            {
                count++;                                // Increment the number of data read in (number or elements to be insert)
            }
            addToArrayAsc(arr, count, stof(line));      // Convert the element into a float and add it into the array (sorted)
        }
    }
inFile.close();                                         // When done, file will close
return 0;
}
void printArray(float arr[], int size)                  // Function to print the array in a half pyramid
{
    for (int i = 0; i < size; i++)                      // Traverse through the length of the array
    {
        if (i == 0)                                     // Enter the condition if it's the first element to be printed
        {
            cout << arr[i];                             // Don't print with the delimiter at the end
        }
        else                                            // Otherwise, print the elements with a delimiter to seperate them
        {
            cout << "," << arr[i];
        }
    }
    cout << endl;                                       // End the line whenever the code 
                                                        // finish printing up the number of elements currently stored
return;
}
int addToArrayAsc(float sortedArray[], int numElements, float newValue)     // Function to add element into the array and sort it
{
    for (int j = (numElements - 1); j >= 0; j--)                            // Traverse through the (current) length of the array
    {                                                                       // Backwards (from end to beginning)
        if (newValue <= sortedArray[j])                                     // Evaluate if loop finds an element that already exists in the array
        {                                                                   // To be bigger or equal to the new value that will be inserted
            sortedArray[j + 1] = sortedArray[j];                            // Shift the current element up by one position
            sortedArray[j] = newValue;                                      // The new value will be inserted into the open slot of the array
        }
        else if (newValue > sortedArray[numElements - 1])                   // Evaluate if the new value is greater than the current biggest value into the array
        {
            sortedArray[numElements - 1] = newValue;                        // Inserted into the last position of the array (ascending order)
        }
    }    
    printArray(sortedArray, numElements);                                   // Call print function to display the sorting
return numElements;                                                         // Return the numbers of elements that got inserted
}