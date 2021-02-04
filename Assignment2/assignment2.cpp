// CSCI 2270 -- Data Structures
// Assignment 1 -- Problem 1
// Bach Nguyen

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct wordRecord
{
    string word;
    int count;

};
void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[]);
bool isIgnoreWord(string word, string ignoreWords[]);
int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length);
void swap_by_pointers(wordRecord *n1, wordRecord *n2);
void reverseArray(wordRecord array[], int array_size);
void sortArray(wordRecord distinctWords[], int length);
void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords);
void DoublingArray(wordRecord *& Arr, int &size);

int main(int argc, char const *argv[])
{

    int count = 0, doubling_count = 0, unique_count = 1, size = 100;

    ifstream inFile(argv[2]);                                               // stream for open and reading in file
    string ignoreWords[50];                                                 // Declare an array in main to store ignore word
    wordRecord *uniqueWords;
    uniqueWords = new wordRecord[size];

    getIgnoreWords(argv[3], ignoreWords);                                   // Call getIgnoreWords function to grab the information from text file

    string word;
    if (inFile.fail())
    {
        cout << "Failed to open file." << endl;
    }
    else
    {
        while(inFile.good())                                                        // Read in each word from the text file
        {
            int word_added = 0;
            inFile >> word;
            if(!isIgnoreWord(word, ignoreWords))                                    // If the word being read in is not an ignore word
            {
                for (int i = 0; i < unique_count; i++)                              // Traverse through the current length of the number of unique words so for
                {
                    if (word == uniqueWords[i].word)                                // Evaluate if the word being read in has already been read in
                    {
                        uniqueWords[i].count++;                                     // We will increment the occurance counter
                        word_added++;
                    }
                    else if (i == unique_count - 1 && word_added == 0)              // If the word is being read in for the very first time
                    {
                        uniqueWords[i].word = word;                                 // We will store it into the array of struct word 
                        uniqueWords[i].count = 1;                                   // Set it's occurance to 1 (first time being read in)
                        unique_count++;
                        word_added++;
                    }
                }
                count++;
            }
            if (unique_count == size)                                       // Evaluate if we have stored enough words the current size of the array
            {
                DoublingArray(uniqueWords, size);                           // Double the size of the array
                doubling_count++;                                           // count the times that the array has been doubled
            }
        }
        int total = getTotalNumberNonIgnoreWords(uniqueWords, unique_count);
        sortArray(uniqueWords,unique_count);
        cout << "Array doubled: " << doubling_count << endl;
        cout << "Distinct non-common words: " << unique_count << endl;
        cout << "Total non-common words: " << total - 1 << endl;
        cout << "Probability of next 10 words from rank " << argv[1] << endl;
        cout << "---------------------------------------" << endl;
        printTenFromN(uniqueWords, stoi(argv[1]), total);
    }
inFile.close();                                                             // close the file
return 0;
}
void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[])
{
    ifstream inFile(ignoreWordFileName);                                        // To read in file    
    if (inFile.fail())                                                          // Check to see if file opens correctly
    {
        cout << "Failed to open " << ignoreWordFileName << endl;        
    }
    else
    {   
        string line;
        int count = 0;                                                          // Count variable use for indexing the array
        while(getline(inFile, line))
        {
            if (line != "")                                                     // Ignore empty lines
            {
                count++;
                ignoreWords[count - 1] = line;                                  // Store the words into the array
            }
        }
    }
inFile.close();                                                                 // Close file
return;
}
bool isIgnoreWord(string word, string ignoreWords[])                            // Function to evaluate if a word is found in a filled array
{
    for (int i = 0; i < 50; i++)                                                // Traverse through the array
    {
        if (word == ignoreWords[i])                                             // return true if word is found in the array
        {
            return true;
        }
    }
return false;                                                                   // Return false otherwise
}
int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length)        // Function to compute total number of words in the entire read in file
{
    int sum = 0;                                                                // Declare a sum variable
    for (int i = 0; i < length;i++)                                             // For loop to traverse through the length of the array
    {
        sum = sum + distinctWords[i].count;                                     // Sum up the count
    }
return sum;                                                                     // Return the total sum once finish
}
void swap_by_pointers(wordRecord *n1, wordRecord *n2)                           // Function to swap pointers          
{
    wordRecord temp = *n1;                                      // Assign temp to the value that the pointer n1 is pointing to (dereferencing)
    *n1 = *n2;                                                  // Swap the values that each pointer is pointing to
    *n2 = temp;                                                 // Update the value that pointer n2 is pointing to, 
                                                                // to what we stored in temp (previous value n1 is pointing to)
}
void reverseArray(wordRecord array[], int array_size)                           // Function to reverse the array through pointers               
{
    wordRecord *pointer1 = array;                               // pointer1 pointing at the beginning of the array

    wordRecord *pointer2 = array + array_size - 1;              // pointer2 pointing at end of the array

    while (pointer1 < pointer2)
    {
    swap_by_pointers(pointer1, pointer2);                       // Use swap function
    pointer1++;                                                 // Updating our pointers
    pointer2--;
    }
}
void sortArray(wordRecord distinctWords[], int length)                          // Function to sort distinct words array
{
    for (int i = 0; i < length - 1; i++)                                        // Using bubble sort alogrithm
    {                                                                           // outter loop to traverse through one less the length of array
        for (int j = 0; j < length - i - 1; j++)                                // Nested loop to check between two values
        {
            if (distinctWords[j].count > distinctWords[j+1].count)              // Evaluate if the current element is greater than the element to the right of it
            {

                wordRecord temp = distinctWords[j];                             // Assign current element to a temp variable for swapping  
                distinctWords[j] = distinctWords[j + 1];                        // Swap the current element with the one to the right of it
                distinctWords[j + 1] = temp;                                    // Assign the current element being stored in temp to where the previ
            }
        }
    }
    reverseArray(distinctWords, length);                                        // Using the reverseArray function to put most frequent words at the beginning         
}
void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords)        // Function to print out the next 10 words from N
{
    float probability = 0;                                                      // Declare variable to compute probability

    for (int i = N; i < N+10; i++)                                              // Look to traverse from N to the next 10th place
    {
        probability = (float)distinctWords[i].count / totalNumWords;            // Compute the probability of that word
        cout << setprecision(5) << fixed << probability << " - " << distinctWords[i].word << endl;          
    }                                                                           // Print out the next probability and the corresponding
}
void DoublingArray(wordRecord *& Arr, int &size)
{
    wordRecord *temp = new wordRecord[2*size];                                  // Temp array & Doubling the size by 2
    
    for (int i = 0; i < size ; i++)                                           // For loop to traverse through the original size of the array
    {
        temp[i] = Arr[i];                                                       // Copy everything over
    }
    delete[] Arr;                                                               // Delete the array to allocate memory
    Arr = temp;
    size = size * 2;                                                             
}