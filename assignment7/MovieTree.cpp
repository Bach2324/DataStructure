#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}
TreeNode *getTreeNode(string title)			// Function to dynamically allocate a Tree Node
{
	TreeNode *in = new TreeNode();			// Dynamically allocate a new node
	in->titleChar = title[0];			// Assign it's data value
	return in;					// return the pointer
}
/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
    root = NULL;
}
/* ------------------------------------------------------ */
void DeleteAllDS(TreeNode *del,	LLMovieNode *delLL)	// Helper function for destructor
{
	if (del == nullptr){return;}			// Return if pointer is null
	DeleteAllDS(del->leftChild, del->head);		// Otherwise we will post-order traverse
	DeleteAllDS(del->rightChild, del->head);	// Traverse right
	while (del->head != nullptr)			// Entering the linked list portion
	{						// Traverse the linked list
		delLL = del->head->next;		// Assign the next head node to delLL
		delete del->head;			// Delete current head node
		del->head = delLL;			// Assign the new head node to what we stored in DelLL
	}
	delete del;					// delete/deallocate the tree node we are currently at
}
MovieTree::~MovieTree()					// Desctructor function
{
	DeleteAllDS(root, root->head);			// Call helper function to deallocate all Data Structure
}
/* ------------------------------------------------------ */
void showMovieCollectionHelper(TreeNode *t)		// helper function Print movies according to given letter
{
	if(t == nullptr){return;}			// exit function call if t is null
	showMovieCollectionHelper(t->leftChild);	// Otherwise, in-order traversal (left side)
	LLMovieNode *m = t->head;			// Create a new LL node that points to the head
	if (m != nullptr)				// Make sure we are not printing anything if 
	{						// Print the header of print statement and letter of movies
		cout << "Movies starting with letter: " << t->titleChar << endl;
		while (m != nullptr)			// Traverse the linked list for that specific letter
		{					// Print all movies that started with given letter follow by rating
			cout << " >> " << m->title << " " << m->rating << endl;
			m = m->next;			// Go to the next node
		}
	}
	showMovieCollectionHelper(t->rightChild);	// In-order traversal (right side)
}
void MovieTree::showMovieCollection()			// Main print movie function
{
	showMovieCollectionHelper(root);		// Call helper function
}
/* ------------------------------------------------------ */
void inorderTraversalHelper(TreeNode * root)
{
    if (root == NULL) {
        return;
    }

    inorderTraversalHelper(root->leftChild);
    cout << root->titleChar << " ";
    inorderTraversalHelper(root->rightChild);
}
void MovieTree::inorderTraversal()
{	
    inorderTraversalHelper(root);
	cout << endl;
}
/* ------------------------------------------------------ */
void insertLLNode(TreeNode *t, LLMovieNode *m)		// Helper function to insert node in the Linked List part
{
	if (t->head == nullptr){t->head = m;}		// add the node to the head if linked list is empty
	else if (m->title < t->head->title)		// If the node is alphabetically before the head node
	{						// we will insert at the head
		m->next = t->head;			// Assign the next slot node as the current head
		t->head = m;				// Assign the current head position to be the node being inserted
	}
	else						// Otherwise, we will evaluate if node needs to be inserted 
	{						// Somewhere inbetween or at the end
		LLMovieNode *crawler = t->head;		// Declare a crawler pointer to traverse the linked list
		LLMovieNode *previous = crawler;	// Declare a previous pointer to traverse behind crawler
		bool added = false;			// Bool checker to see if the node has been added
		while(crawler != nullptr)		// Traversing the linked list from head
		{					// If we find that the data is somewhere in between alphabetically
			if (m->title > previous->title && m->title < crawler->title)
			{				// We will insert it inbetween the two nodes that it sits at
				m->next = crawler;	// Assign the next slot node to be what crawler is pointing to
				previous->next = m;	// assign the node to be inserted to where previous next is (where crawler is at)
				added = true;		// Convert added bool to be true since we just inserted the node
			}			
			previous = crawler;		// Iterate previous pointer
			crawler = crawler->next;	// Iterate crawler pointer
		}
		if (!added)				// If we are at the end of our traversal and the node has not been added
		{					// This means that the data is alphabetically greater than all the other data
			previous->next = m;		// previous next pointer will now point to node that m contains
			m->next = nullptr;		// Since it's the tail node, we need to assign it's pointer to null
			added = true;			// Turn added to true since we added the node
		}
	}
}
void insertTreeNode(TreeNode *&t, TreeNode *&parent)	// Helper function to add node as a tree node
{
	if (parent == nullptr){parent = t;}		// If tree is empty, we insert node t to be the root node
	if (t->titleChar < parent->titleChar)		// If the current node's title is alphabetically less than the parent node
	{
		if (parent->leftChild == nullptr)	// If we hit a left child that points to null
		{
			parent->leftChild = t;		// We insert the node at that position
			t->parent = parent;		// Set the parent pointer
		}					// will will evaluate the left side
		else{insertTreeNode(t, parent->leftChild);}// otherwise, we recursively traverse until we hit a nullptr
	}
	if (t->titleChar > parent->titleChar)		// This is for if the title is greater than the parent data 
	{								
		if (parent->rightChild == nullptr)	// If we hit a right child that points to null
		{															
			parent->rightChild = t;		// Insert the node at that position
			t->parent = parent;		// Set the parent pointer
		}
		else{insertTreeNode(t, parent->rightChild);}// Otherwise, traverse until we find a nullptr
	}
}
void MovieTree::insertMovie(int ranking, string title, int year, float rating)
{	
	if (searchCharNode(title[0]) == NULL)		// Call searchChar node check if node containing the char exist
	{						// If not we, need to allocate memory and insert a new tree NOde
		TreeNode *t = getTreeNode(title);	// Call getTreeNode to create new node
		insertTreeNode(t, root);		// Call insertTree helper function to insert tree node
	}						// Otherwise, we call our insertTreeNode function to insert the tree node											// Main function to insert movie
	TreeNode* search = searchCharNode(title[0]);	// Call searchCharNode to get the pointer pointing to the node that contains key char
	LLMovieNode * LLnode = getLLMovieNode(ranking, title, year, rating);// get the information from the getLLMovieNode function and assign it to LLnode
	if(search->titleChar == title[0]){insertLLNode(search,LLnode);} // If we found the node containing key char, call insertLLnode to insert node
	else{insertLLNode(root,LLnode);}				// otherwise, we insert it at the root tree node
}
/* ------------------------------------------------------ */
void MovieTree::removeMovieRecord(string title)
{							// Evaluate if we are deleting from an empty tree
	if (root == nullptr){cout << "Movie not found." << endl;return;}

	TreeNode *search = searchCharNode(title[0]);	// Call search function to return the pointer to node containing key char and assign it to search
	LLMovieNode *crawler = search->head;		// Declare a crawler pointer to traverse linked list, assign it as the head
	LLMovieNode *previous = crawler;		// Declare a previous pointer to traverse behind crawler

	if (search->head->title == title)		// If the node we are deleting is the head node of the linked list
	{
		if (crawler->next == nullptr)		// Then we evaluate to see if it's the only node or if there are several nodes
		{
			delete crawler;			// If it's the only node, we delete it 
			search->head = nullptr;		// and set the associated tree node to nullptr, indicating empty LL
		}
		else					// otherwise, if there are several nodes
		{											
			search->head = crawler->next;	// Assign the head to be the next node in the linked list
			delete crawler;			// Delete the current node
		}
	}
	else						// Evaluate if we are not deleting at the head/front of the linked list
	{
		while (crawler != nullptr)		// Traverse the Linked List
		{
			if (crawler->title == title)	// If we found the node that contains the title we are looking for
			{
				previous->next = crawler->next;	// Assign the current node pointer will be the next node
				delete crawler;		// Delete the current node
			}
			previous = crawler;		// Iterate previous
			crawler = crawler->next;	// Iterate crawler
		}
	}
}
/* ------------------------------------------------------ */
TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}
/* ------------------------------------------------------ */
void MovieTree::leftRotation(TreeNode* curr)		// Function to rotate tree
{											
	TreeNode* y = curr->rightChild;			// Declare a new pointer and point it to right child of curr
	curr->rightChild = y->leftChild;		// assign curr right child to be y's left child
	
	if (y->leftChild != NULL)			// Check to see if y is null
	{
		y->leftChild->parent = curr;		// If not, then we assign y's leftchild's parent as curr
	}
	y->parent = curr->parent;			// Assign y parent as curr's parent
	if (curr->parent == NULL){root = y;}		// if curr's parent is null, assign root as y
	else						// Otherwise, we check for other conditions
	{
		if (curr == curr->parent->leftChild)	// if the current node is the left child's parent
		{
			curr->parent->leftChild = y;	// Then we assign it as y
		}
		else{curr->parent->rightChild = y;}	// Otherwise, we assign rightchild's as y
	}
	y->leftChild = curr;				// At the end, y's left child is curr
	curr->parent = y;				// curr's parent is y
}
