// Data Structures & Algorithms prep
// Assignment 1 -- Problem 2
// Bach Nguyen

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct wordItem
{
    string word;
    int count;
};
void getStopWords(const char *ignoreWordFileName, string ignoreWords[])         // Function to read in from a file
{                                                                               // And store them into an array
    ignoreWords[50];                                                            // Declare array of size 50
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
bool isStopWord(string word, string ignoreWords[])                              // Function to evaluate if a word is found in a filled array
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

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)              // Function to count the number of unique words from text file
{
    int sum = 0;

    for (int i = 0; i < length; i++)                                
    {
        sum += uniqueWords[i].count;                                            // Sum up the count
    }
return sum;                                                                     // Return the count
}

void arraySort(wordItem uniqueWords[], int length)
{

return;
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords)
{
    int probability = 0;
    cout << "Probability of the next 10 words from rank " << N << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = N; i < (N+10); i++)
    {
        probability = (float) uniqueWords[i].count / totalNumWords;
        cout << probability << " - " << uniqueWords[i].word << endl;
    }

return;
}

int main(int argc, char const *argv[])
{
    int size = 100, unique_count = 0;
    string ignore[50];
    wordItem *dyArray;
    dyArray = new wordItem[size];

    getStopWords(argv[3], ignore);

    ifstream inFile(argv[2]);

    if(inFile.fail())
    {
        cout << "Failed to open." << endl;
    }
    else
    {
        string ind_word;
        while(inFile.good())
        {
            inFile >> ind_word;
            if (!isStopWord(ind_word, ignore))
            {
                for (int i = 0; i < unique_count; i++)
                {
                    if (ind_word == dyArray[i].word)
                    {
                        dyArray[i].count++;
                    }
                    else
                    {
                        dyArray[i].word = ind_word;
                        dyArray[i].count = 1;
                        unique_count++;
                    }
                }
            }
        }
    }

return 0;
}