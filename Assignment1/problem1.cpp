// CSCI 2270 -- Data Structures
// Assignment 1 -- Problem 1
// Bach Nguyen

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void printArray(float arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            cout << arr[i];
        }
        else
        {
            cout << "," << arr[i];
        }
    }
    cout << endl;
return;
}
int addToArrayAsc(float sortedArray[], int numElements, float newValue)
{
    for (int j = (numElements - 1); j >= 0; j--)
    {
        if (newValue <= sortedArray[j])
        {
            sortedArray[j + 1] = sortedArray[j];
            sortedArray[j] = newValue;
        }
        else if (newValue > sortedArray[numElements - 1])
        {
            sortedArray[numElements - 1] = newValue;
        }
    }        
    printArray(sortedArray, numElements);
return numElements;
}

int main(int argc, const char *argv[])
{
    float arr[100];
    int count = 0;
    ifstream inFile(argv[1]);

    if (!inFile.good())
    {
        cout << "Failed to open the file." << endl;
    }
    else
    {   
        string line;
        while(getline(inFile, line))
        {
            if (line.length() != 0)
            {
                count++;
            }
            addToArrayAsc(arr, count, stof(line));
        }
    }
inFile.close();
return 0;
}