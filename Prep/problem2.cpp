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
    Park parkInfo[100];
    ifstream inFile(argv[1]);
    if (inFile.fail())
    {         
        cout << "Failed to open file." << endl;                                             // Check to see if correct file is inputed
    }
    else
    {
        string line, park, state, area;
        int count = 0;        
        while (getline(inFile, line))                                                       // Read the lines from the file
        {
            if (line != "")
            {
                stringstream ss(line);
                getline(ss, park, ',');
                getline(ss, state, ',');
                getline(ss, area, ',');
                state = state.substr(1, 2);
                area = area.substr(1, area.length());
                addPark(parkInfo, park, state, stoi(area),count);
                count++;
            }
        }
        inFile.close();
        printList(parkInfo,count);
        ofstream outFile(argv[2]);
        
        for (int i = 0; i < count; i++)
        {
            if (parkInfo[i].area > stoi(argv[3]))
            {
                outFile << parkInfo[i].parkname << ", " << parkInfo[i].state << ", " << parkInfo[i].area << endl;
            }
        }
        outFile.close();
    }
return 0;
}