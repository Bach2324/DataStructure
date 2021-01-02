// Data Structures & Algorithms prep
// Assignment 1 -- Problem 2
// Bach Nguyen

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Park
{
    string parkname;
    string state;
    int area;
};

void addPark(Park parks[], string parkname, string state, int area, int length)
{
    parks[length].parkname = parkname;
    parks[length].state = state;
    parks[length].area = area;
}
void printList(const Park parks[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << parks[i].parkname << " [" << parks[i].state << "] area: " << parks[i].area << endl;
    }
}

int main(int argc, char const *argv[])
{   
    stringstream ss;

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
            if (line != "")
            {
                
            }
        }
    inFile.close();
    }
return 0;
}