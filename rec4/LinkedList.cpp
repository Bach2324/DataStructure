// CSCI 2270 -- Data Structures
// Recitation 4 -- Implementation file
// Bach Nguyen

#include "LinkedList.h"

using namespace std;

// Add a new node to the list
void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;

    }
  }

// TODO: SILVER PROBLEM
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;
  Node *temp = head;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

  // Special case to delete the head
    if (n == 0) {
      temp = head->next;    // Assign temp to be the next head node
      head = temp;          // reassign head to what temp is

      delete temp;          // Deallocate temp
      return true;          // exist function
    }
    else
    {
      Node *pres = head;
      Node *prev = NULL;

      for (int i = 0; i < n; i++)   // Traverse to nth position
      {
        if (i == n - 1)             // Once we are at that position
        {
          prev = pres->next;        // Assign prev to the node pres is pointing to
          pres->next = prev->next;  // Reassign pres->next
          delete prev;              // Deallocate prev
          return true;              // exit function
        }
        pres = pres->next;          // Increment pointer if condition not met
      }
    }
	return isDeleted;
}

// TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values)
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;
    Node *temp = head;
    Node *temp2 = nullptr;

    if(head == NULL) {
        cout << "List is empty. Cannot swap" << endl;
        return false;
    }
    // TODO (take care of the edge case when your linkedlist has just 2 nodes)
    else
    {
      temp2 = head;
      temp = head->next;
      return true;
    }
    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}
