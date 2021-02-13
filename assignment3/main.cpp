// CSCI 2270 -- Data Structures
// Assignment 3 -- Given main driver file
// Bach Nguyen

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void displayMenu();
bool append(string* &str_arr, string s, int &numEntries, int &arraySize);
void doublingArray(string *& Arr, int &size);

int main(int argc, char* argv[])
{
    CUBuildingNetwork CUBuildingNet;
    int opt = 0; string s; string s1; string s2;

    while(opt != 5) {

        displayMenu();

        getline(cin, s);
        opt = stoi(s);

        switch(opt) {
            case 1: {
                CUBuildingNet.loadDefaultSetup();
                CUBuildingNet.printNetwork();
                break;
            }

            case 2: {
                CUBuildingNet.printNetwork();
                break;
            }

            case 3: {
                cout << "Enter name of the recipient to receive the message: "<< endl;
                getline(cin, s1);

                cout << "Enter the message to send: " << endl;
                getline(cin, s2);

                cout << endl;

                CUBuildingNet.transmitRoomInfo(s1);

                break;
            }
            case 4: {
                cout << "Enter a new building name: " << endl;
                getline(cin, s1);

                string roomNum;
                cout << "Enter total room number: " << endl;
                getline(cin, roomNum);

                cout << "Enter the previous building name (or First): " << endl;
                getline(cin, s2);
                
                while(!(s2 == "First" || CUBuildingNet.searchForBuilding(s2))) {
                    cout << "INVALID(previous building name)...Please enter a VALID building name!" << endl;
                    getline(cin, s2);
                }

                if(s2 == "First") {
                    CUBuildingNet.addBuildingInfo(NULL, s1,stoi(roomNum));
                }
                else {
                    CUBuildingNet.addBuildingInfo(CUBuildingNet.searchForBuilding(s2), s1, stoi(roomNum));
                }

                CUBuildingNet.printNetwork();
                break;
            }

            case 5: {
                cout << "Quitting..." << endl;
                break;
            }

        }
    }

    cout << "Goodbye!" << endl;

    return 0;
}
/************************************************
           Definitions for main.cpp
************************************************/
void doublingArray(string *& Arr, int &size)
{
    string *temp = new string[2*size];                                          // Temp array & Doubling the size by 2
    
    for (int i = 0; i < size ; i++)                                             // For loop to traverse through the original size of the array
    {
        temp[i] = Arr[i];                                                       // Copy everything over
    }
    delete[] Arr;                                                               // Delete the array to allocate memory
    Arr = temp;
    size = size * 2;                                                             
}
bool append(string* &str_arr, string s, int &numEntries, int &arraySize)        // Function to add string element to the end of the index
{
    bool is_doubled = false;                                                    // Create a bool variable to check if array has been doubled
    if(numEntries == arraySize)                                                 // Once the numEntries reaches array size
    {
        doublingArray(str_arr, arraySize);                                      // Use our doublingArray function to double the array size
        is_doubled = true;                                                      // Turn our is_doubled variable to true
    }
    str_arr[numEntries] = s;                                                    // Add element entries to the end of the index/array
    numEntries++;                                                               // increment numEntries
return is_doubled;
}
void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Broadcast Room Info " << endl;
    cout << " 4. Add Building " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
