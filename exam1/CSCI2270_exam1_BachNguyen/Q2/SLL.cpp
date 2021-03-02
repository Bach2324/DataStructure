#include <iostream> // predefined header file (defined for you)
using namespace std;

#include "SLL.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
	head = nullptr;
}

SLL::~SLL(){
	Node* crawler;

	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}
void SLL::displayList(){
	Node* crawler = head;
	while( crawler != nullptr ){
		cout << crawler->key << "->";
		crawler = crawler->next;
	}

	cout << "END" << endl;
}
void SLL::insert(Node* afterMe, char newValue){

	if(head == nullptr){
		// first case: empty list
		// add new node and make head point to it
		head = new Node;
		head->key = newValue;
		head->next = nullptr; // what if we forget this line?
	}
	else if(afterMe == nullptr){
		// This condition implies that the list is not empty, but
		// the caller wants to add node before the head node
		Node* newNode = new Node;
		newNode->key = newValue;
		newNode->next = head;
		head = newNode;
		// at this point, we can test our code for this use case

	}
	else{
		Node* newNode = new Node;
		newNode->key = newValue;
		newNode->next = afterMe->next;
		afterMe->next = newNode;
	}
}

bool SLL::palindrome(){
/*
    * TODO your function definition goes here
*/
	Node *curr = head;				// Pointer to traverse comparison code
	Node *count = head;				// Pointer to traverse the count code
	int count_nodes = 0;
	if (head == nullptr)			// If the list is empty
	{
		return true;				// Return true as we are assuming that it will be a palindrome
	}
	while(count->next != nullptr)	// Counting the size of our Linked List
	{
		count = count->next;		// Updating current pointer
		count_nodes++;				// incrementing count
	}
	while (count_nodes >= 0)		// Traverse from the end of the list to the beginning
	{								// curr pointer will traverse from beginning to end
		if(curr->key != atIndex(count_nodes))	// We call atIndex to return the pointer of the node at count_nodes(current index)
		{										// If we find a key value that does not match each other
			return false;						// the function will return false
		}
		curr = curr->next;						// Otherwise, curr pointer we go to the next node (right of it)
		count_nodes--;							// Respectively count_nodes will decrement 
	}											// which means pointer returned by atIndex will go to the node previous (left of it)
	return true;								// Function will return true if it's palindrome
}
char SLL::atIndex(int i){

	Node *count_nodes = head;				// Declare pointer to traverse through list
	int count = 0;							// int to count the nodes
	while(count_nodes->next != nullptr)		// Traverse through the list
	{
		count_nodes = count_nodes->next;	// Update pointer
		count++;							// Increment count
	}
	if (i < 0)								// If the index is less than zero, we will exit and print error statement
	{
		cout << "Invalid index value. Must be greater than or equal to 0." << endl;
		return '\0';
	}
	else if (i > count)						// If index is greater than or equal to the size of the list
	{										// then we will exit and print error statement
		cout << "Invalid -- Index is greater than the size of Linked List." << endl;
		return '\0';
	}
	Node *crawler = head;					// Declare a pointer to traverse the list
	for (int j = 0; j < i; j++)				// For loop to traverse up to the wanted index
	{
		crawler = crawler->next;			// Update pointer
	}
	return crawler->key;					// Return the character of that pointer at the wanted index
}


