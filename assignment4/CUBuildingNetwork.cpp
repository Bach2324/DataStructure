/*******************************************************************/
/*                CUBuildingNetwork Implementation                 */
/*******************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*       This class uses a linked-list of CUBuilding nodes to      */
/*       represent communication paths between buildings           */
/*******************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork() 
{
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
 *   between the CUBuilding *previous and the CUBuilding that follows it in the network.
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
 * Purpose: populates the network with the predetermined CUBuildings
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
 * Purpose: Relay a message through the linked list until the specified CUBuilding
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
/****************************************************/
/*  ASSIGNMENT 4: Functions to be completed below.  */
/****************************************************/

/*
 * Purpose: Delete the CUBuilding in the network with the specified name.
 * @param buildingName name of the CUBuilding to delete in the network
 * @return none
 */
void CUBuildingNetwork::deleteCUBuilding(string buildingName) 
{
    CUBuilding *curr = head;
    CUBuilding *prev = nullptr;

    if (searchForBuilding(buildingName) == nullptr)         // Using searchForBuilding function to check if there's a node with the given data
    {
        cout << "Building does not exist." << endl;         // Print notification if searchForBuilding returns null (building not in the list)
        return;                                             // Exit function
    }
    else
    {
        while (curr != nullptr)                             // Traverse the list
        {
            if (curr->name == buildingName)                 // Evaluate if the data is found within an existing node
            {
                if (prev == nullptr)                        // If that particular node is the first node in the list
                {
                    head = curr->next;                      // We move head to be the next node over
                    delete curr;                            // We delete that current node
                }
                else                                        // Otherwise, if the node found exist after the first node
                {
                    prev->next = curr->next;                // We assign prev pointer to be what curr pointer is
                    delete curr;                            // Delete that node
                }
            }
            prev = curr;                                    // We assign curr to prev if node is not found (yet)
            curr = curr->next;                              // Increment pointer
        }
    }
}
/*
 * Purpose: deletes all CUBuildings in the network starting at the head CUBuilding.
 * @param: none
 * @return: none
 */
void CUBuildingNetwork::deleteEntireNetwork()
{
    CUBuilding *curr = head;                            // Declare a struct pointer pointing to head

    if (head == nullptr)                                // Return function if list is empty
    {
        return;
    }
    while(curr != nullptr)                              // Traverse through the linked list
    {
        cout << "deleting: " << curr->name << endl;     // Print statement on the node that's being deleted
        head = curr->next;                              // Reassign head
        delete curr;                                    // Deallocate the current node
        curr = head;                                    // Reassign curr to the new head
    }
    delete head;                                        // Once we are done, we deallocate the head
    head = nullptr;                                     // Set the pointer to point to NULL
    cout << "Deleted network" << endl;                  // The network has been deleted
}

/*
* Purpose: Creates a loop from last node to the CUBuilding specified.
* @param buildingName name of the CUBuilding to loop back
* returns the last node before loop creation (to break the loop)
*/
CUBuilding* CUBuildingNetwork::createLoop(string buildingName) 
{
    CUBuilding * curr = head;                               // Declare a pointer for our node, set it to head
    while (curr->name != buildingName && curr != nullptr)   // Traverse the linked list until we found the data we want
    {
        curr = curr->next;                                  // Increment pointer
    }
    CUBuilding * loop = curr;                               // Declare a pointer of where we want our loop
    while (curr->next != nullptr)                           // Traverse the remaining of the list
    {
        curr = curr->next;                                  // Increment pointer
    }
    curr->next = loop;                                      // Set the last node of the list to join the node that we are looping

return curr;                                                // Return pointer to the last node
}
/*
 * Purpose: to detect loop in the linked list
 * @return: true if loop is detected, else false
 */
bool CUBuildingNetwork::detectLoop()                        // Function to detect a loop (not a code loop, but a linked loop)
{
    CUBuilding * fast = head->next;                         // Fast pointer will point to the 2nd node in the linked list
    CUBuilding * slow = head;                               // Slow pointer will point to the head

    while (fast != nullptr && fast->next != nullptr && slow != nullptr)     // Traverse through the list (taking care of edgecases)
    {
        if (fast == slow)                                   // When we are traversing, if fast overlaps slow (pointing to the same node)
        {                                                   // Then we know that there is a loop in our linked list
            return true;                                    // Return true
        }       
        fast = fast->next->next;                            // Fast will increment twice (jump two nodes per loop)
        slow = slow->next;                                  // Slow will increment normally (go from node to node)
    }
return false;                                               // Return false if no loop is detected
}

/*
 * Purpose: Take the chunk of nodes from start index to end index
 *          Move that chunk to the end of the List
 * @param: start_index, end_index
 * @return: none
 */
void CUBuildingNetwork::readjustNetwork(int start_index, int end_index)
{
    CUBuilding *count_node = head, *firstSubNode = head, *lastSubNode = head;
    CUBuilding *prevCount = nullptr, *bForeFirst = nullptr, *bForeLast = nullptr, *temp = nullptr;
    int count = 0, pos1 = 0, pos2 = 0;

    if (head == nullptr)                                    // Evaluate if list is empty
    {
        cout << "Linked List is Empty" << endl;
        return;                                             // Exit function
    }
    else if (start_index > end_index)                       // Evaluate if start index is greater than end index
    {
        cout << "Invalid indices" << endl;
        return;                                             // exit function
    }
    while (count_node != nullptr)                           // Get the length of our linked list and extract the tail node
    {
        prevCount = count_node;                             // get the last node of our list before null
        count_node = count_node->next;                      // Increment count
        count++;                                            // Increment index checker
    }    
    while (firstSubNode != nullptr && pos1 < start_index)   // Extract the first node of our sublist
    {
        bForeFirst = firstSubNode;                          // Extract the node before our first node of our sublist
        firstSubNode = firstSubNode->next;                  // Increment node
        pos1++;                                             // Increment index counter
    }
    while (lastSubNode != nullptr && pos2 < end_index)      // Extract the last node of our sublist
    {
        lastSubNode = lastSubNode->next;                    // Increment node
        pos2++;                                             // Increment index counter
    }
    if (end_index >= count - 1 || end_index < 0)                // Evaluate if count is less than or equal end index, or if end index is negative
    {
        cout << "Invalid end index" << endl;
        return;                                             // Exit function
    }
    else if (start_index >= count - 1|| start_index < 0)    // Same thing logic for but for start index
    {
        cout << "Invalid start index" << endl;
        return;                                             // Exit function
    }
    else
    {
        if (start_index == end_index)                           // Special case if we are swapping one element (domain index are the same)
        {
            temp = count_node;                                  // Use a temp pointer to temporarily store count_node (tail node)
            count_node = firstSubNode->next;                    // Point count_node to where firstSubNode is pointing to next
            firstSubNode->next = temp;                          // First sub node will now point to temp (where count_node use to point)
            if (bForeFirst != nullptr)                          // Evaluate if we are not swapping that's the first node of the list
            {
                bForeFirst->next = count_node;                  // point bForeFirst next to where count_node is now currently at
                prevCount->next = firstSubNode;                 // The node before the tail will now point to the new tail, which is the node we swapped
            }
        }
        else if (start_index == 0)                              // Special case if the first Sub Node is our head (first node)
        {
            prevCount->next = firstSubNode;                     // Put the firstSubNode to the end of the list (prevCount is the last node before null)
            head = lastSubNode->next;                           // The new head is going to be where the node after lastSubNode is (since it's the last node to be moved)
            lastSubNode->next = nullptr;                        // LastSubNode will point to null since it's now the last node in the list
        }
        else                                                    // When we are swapping nodes within the last (index > 0)
        {
            prevCount->next = firstSubNode;                     // Put the firstSubNode to the end of the list (prevCount is the last node before null)
            bForeFirst->next = lastSubNode->next;               // Assign the pointer of the node before the first sub node to point to the node after the sublist
            lastSubNode->next = nullptr;                        // Assign our new end node to point to null
        }
    }                       
}
/*
 * Purpose: Destructor to delete the entire list on program termination
 * @param none
 * @return none
 */
CUBuildingNetwork::~CUBuildingNetwork()
{
    deleteEntireNetwork();
}
