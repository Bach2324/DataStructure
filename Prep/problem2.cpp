// Data Structures & Algorithms prep
// Assignment 1 -- Problem 2
// Bach Nguyen

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


struct Park                         // Create a struct objects to store the information about a specific park
{
    string parkname;                // It's name
    string state;                   // The State that the park is in (in the U.S)
    int area;                       // Overall area of the park
};

void addPark(Park parks[], string parkname, string state, int area, int length)         // A function to add the struct to the parks array
{
    parks[length].parkname = parkname;                                                  // Add the name
    parks[length].state = state;                                                        // Add the state
    parks[length].area = area;                                                          // Add the area
}
void printList(const Park parks[], int length)                                          // A function to print out the park's info in a specific format
{
    for (int i = 0; i < length; i++)                                                    // Travese through the number of parks read and stored
    {
        cout << parks[i].parkname << " [" << parks[i].state << "] area: " << parks[i].area << endl;
    }
}

int main(int argc, char const *argv[])                                                  // Commmand line arguments
{   
    Park parkInfo[100];                                                                 // Initialize the park array of capacity 100
    ifstream inFile(argv[1]);                                                           // Open file using the 2nd command line argument
    if (inFile.fail())                                                                  // File failed to open
    {         
        cout << "Failed to open file." << endl;                                         // Check to see if correct file is inputed
    }
    else
    {
        string line, park, state, area;                                                 // Declare all the variables to use
        int count = 0;
        while (getline(inFile, line))                                                   // Read the lines from the file
        {
            if (line != "")                                                             // Only evaluate the condition if the line that's being read is NOT empty
            {
                stringstream ss(line);                                                  // Using stringstream
                getline(ss, park, ',');                                                 // Read up to the first comma, and store the string into the park variable
                getline(ss, state, ',');                                                // Read from first comma to the 2nd comma, and store the string into the state variable
                getline(ss, area, ',');                                                 // Read up to the 2nd comma to the end, and store that into area variable
                state = state.substr(1, 2);                                             // Using subtrings to elimanate the white space at the beginning of the string
                area = area.substr(1, area.length());                                  
                addPark(parkInfo, park, state, stoi(area),count);                       // Add the info into our Parks array
                count++;                                                                // Count the number of parks read
            }
        }
        inFile.close();                                                                 // Close file
        printList(parkInfo,count);                                                      // Print list
        ofstream outFile(argv[2]);                                                      // opening file to output to using the 3rd command line argument
        
        for (int i = 0; i < count; i++)                                                 // Traverse through the numbers of parks stored
        {
            if (parkInfo[i].area > stoi(argv[3]))                                       // If the area of that park is greater than the 4th command line argument given
            {                                                                           // Output it into the csv file
                outFile << parkInfo[i].parkname << ", " << parkInfo[i].state << ", " << parkInfo[i].area << endl;
            }
        }
        outFile.close();
    }
return 0;
}