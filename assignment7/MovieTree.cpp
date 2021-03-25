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
/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
	root = NULL;
}
/* ------------------------------------------------------ */
MovieTree::~MovieTree()
{

}
/* ------------------------------------------------------ */
void showMovieCollectionHelper(TreeNode *t)								// helper function Print movies according to given letter
{
	if(t == nullptr){return;}											// exit function call if t is null
	showMovieCollectionHelper(t->leftChild);							// Otherwise, in-order traversal (left side)
	cout << "Movies starting with letter: " << t->titleChar << endl;	// Print the header of print statement and letter of movies
	LLMovieNode *m = t->head;											// Create a new LL node that points to the head
	while (m != nullptr)												// Traverse the linked list for that specific letter
	{
		cout << " >> " << m->title << " " << m->rating << endl;			// Print all movies that started with given letter follow by rating
		m = m->next;													// Go to the next node
	}
	showMovieCollectionHelper(t->rightChild);							// In-order traversal (right side)
}
void MovieTree::showMovieCollection()									// Main print movie function
{
	showMovieCollectionHelper(root);									// Call helper function
}
/* ------------------------------------------------------ */
void inorderTraversalHelper(TreeNode * root) {
		if (root == NULL) {
			return;
		}

		inorderTraversalHelper(root->leftChild);
		cout << root->titleChar << " ";
		inorderTraversalHelper(root->rightChild);
}
void MovieTree::inorderTraversal() {
	inorderTraversalHelper(root);
	cout << endl;
}
/* ------------------------------------------------------ */
void MovieTree::insertMovie(int ranking,string title, int year, float rating)
{

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