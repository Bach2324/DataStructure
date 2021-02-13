// CSCI 2270 -- Data Structures
// Assignment 3 -- Implementation file
// Bach Nguyen

/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of CUBuilding structs to      */
/*     represet communication paths between buildings             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork(){
    /* finished. do not touch. */
    head = NULL;
}
/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUBuildingNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}
/*
 * Purpose: Add a new building to the network
 *   between the building *previous and the Building that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom){

    CUBuilding * newNode = new CUBuilding;                          // Dynamically allocate memory the pointer
    newNode->name = buildingName;                                   // Creating a node and assigning the data
    newNode->totalRoom = numOfroom;                                 // Assigning data the node

    if (head == nullptr || previous == nullptr)                     // Evaluate if the list is empty (head is pointing to NULL)
    {                                                               // Or if the previous pointer points to NULL (tail end)
        newNode->next = head;                                       // The pointer will point to the head
        head = newNode;                                             // Assign the head as the node we established above
        cout << "adding: " << buildingName << " (HEAD)" << endl;    // Print statement
    }
    else                                                            // Otherwise, we will add in from of the where previous is pointing
    {
        newNode->next = previous->next;                             // Assigning node pointer to where previous is pointing next
        previous->next = newNode;                                   // put the newNode to where previous is pointing 
        cout << "adding: " << buildingName << " (prev: " << previous->name << ")" << endl;
    }
}
/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{

    addBuildingInfo(head, "FLMG", 2);                       // Adding FLMG to head node
    addBuildingInfo(searchForBuilding("FLMG"), "DLC", 10);  // Returning pointer that points to FLMG, adding DLC to the next node
    addBuildingInfo(searchForBuilding("DLC"), "ECOT", 6);   // Returning pointer that points to DLC, adding ECOT to the next node 
    addBuildingInfo(searchForBuilding("ECOT"), "CASE", 5);  // Returning pointer that points to ECOT, adding CASE to the next node
    addBuildingInfo(searchForBuilding("CASE"), "AERO", 4);  // Returning pointer that points to CASE, adding AERO to the next node
    addBuildingInfo(searchForBuilding("AERO"), "RGNT", 9);  // Returning pointer that points to AERO, adding RGNT to the last node
}
/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName)
{
    CUBuilding *ptr = head;                 // Set pointer of struct to the head
    while (ptr != nullptr)                  // Traverse through the network to find if buildingName exist
    {                                       // Exit condition is when the ptr is NULL
        if (ptr->name == buildingName)      // If the buildingName is found in the network
        {
            return ptr;                     // We return the pointer to that node that contains buildingName
        }
        ptr = ptr->next;                    // Otherwise, we go to the next node
    }

return nullptr;                             // Return NULL if the buildingName is not found
}
/*
 * Purpose:
 * @param string receiver
 * @param string msg
 */
void CUBuildingNetwork::transmitRoomInfo(string receiver)
{
    CUBuilding *ptr = new CUBuilding;                       // Dynamically allocate our pointer to struct
    ptr = head;                                             // Set pointer to start at the head of the list

    if (head == nullptr)                                    // Evaluate if list is empty, print out a statement telling user so
    {
        cout << "Empty list" << endl;
        return;
    }
    else                                                    // Evaluate if list is not empty
    {
        if (searchForBuilding(receiver) != nullptr)         // Call searchForBuilding function to check whether receiver node is present
        {                                                   // This will evaluate if the function finds the building in in our list
            while(ptr != nullptr)                           // Traverse through the list
            {
                ptr->numberMessages++;                      // Increment number of message
                cout << ptr->name << " [# messages received: " << ptr->numberMessages << "] " << "received: ";
                cout << "available room at "<< ptr->name << " is " << ptr->totalRoom << endl;
                if (ptr->name == receiver)                  // When we reach the receiver node, we will break out of the loop
                {
                    break;
                }
                ptr = ptr->next;                            // Increment our pointer if receiver node has not been reached
            }
        }
        else                                                // Evaluate if searchForBuilding returns NULL (node not found)
        {
            cout << "Building not found" << endl;
        }
    }
}
/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork()
{
    CUBuilding *ptr = new CUBuilding;                       // Dynamically allocate our pointer to struct
    ptr = head;                                             // Set pointer to start at the head of the list d
    
    cout << "== CURRENT PATH ==" << endl;                   // Print header

    if (head == nullptr)                                    // Print if list is has not been created
    {
        cout << "nothing in path" << endl;
        cout << "===" << endl;
    }
    else
    {
        while(ptr != nullptr)                               // Traverse through the list
        {                                                   // Print the building and available room
            cout << ptr->name << "(" << (ptr->totalRoom) << ") -> ";
            ptr = ptr->next;                                // Go to the next node
        }
        cout << "NULL";                                     // Print ending
        cout << endl;
        cout << "===" << endl;
    }
}
