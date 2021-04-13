#include <iostream>
#include "bst.hpp"

BST::BST() {
	root = NULL;
}

BST::~BST() {
	deleteTree(root);
	root = NULL;
}
void BST::deleteTree(Node* node) {
	if (node != NULL) {
		deleteTree(node->leftChild);
		deleteTree(node->rightChild);
		delete node;
	}
}

/*
** Implement the following function to return the count of comparisons, 
**   you may implement helper functions.
*/
int searchCounterHelper(Node *search, int target)			// Helper function to return counter
{
	int counter = 0;						// Declare a counter variable
	while (search != nullptr)					// iteratively traverse the BST
	{
		if (search->key > target)				// Go left if target is less than node's value
		{
			counter++;					// Count the comparison made
			search = search->leftChild;			// iterate/update the pointer
		}
		if (search->key < target)				// Go right if target is greater than node's value
		{
			counter++;					// Count the comparison
			search = search->rightChild;			// iterate/update the pointer
		}							// If we found the node, then update the comparison and break out of loop
		else if (search->key == target){counter++; break;}
	}
	return counter;							// return counter
}
int BST::searchCounter(int target)					// Main search Counter function
{	
	return searchCounterHelper(root, target);			// Call the helper function to solve code
	// your code here!
}
