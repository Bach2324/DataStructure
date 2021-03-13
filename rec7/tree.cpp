#include <iostream>
#include "tree.hpp"
using namespace std;
#define COUNT 10


/*
Constructor for a Tree object
*/
Tree::Tree()
{
  this->root = NULL;
}

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void Tree::print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

void Tree::preOrderTraverse(Node *node)
{
  if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    preOrderTraverse(node->left);

    /* now recur on right subtree */
    preOrderTraverse(node->right);
}

void Tree::deleteTree(Node *node)
{
    if (node == NULL) return;

    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);

    /* then delete the node */
    cout<<"\n Deleting node:"<< node->data;
    delete node;
    node = NULL;
}

/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Gold problem
                    Implement this function
            This function prints all the leaf nodes of the tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
void Tree::printLeafNode(Node *node)
{
    // TODO print the leaf node of the tree
    // Base case, return function call if node is null pointer
    if (node == nullptr){return;}
    // Otherwise, when we node left and right are null (node has no child/ren, then it's a leaf node)
    else if (node->left == nullptr && node->right == nullptr)
    {
      // We print the data of the leaf node
      cout << "["<< node->data << "] ";
    }
    else
    {
      // Traverse the tree recursively, both left and right subtree to find leaf node
      if(node->left != nullptr){printLeafNode(node->left);}
      if(node->right != nullptr){printLeafNode(node->right);}
    }
}

/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Silver problem
                    Implement this function
          This function gives the sum of all the nodes in the tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
int Tree::sumNodes(Node *node)
{
  //TODO Base case
  // Base case when node is nullptr, we return zero
  if (node == nullptr){return 0;}
  //TODO Implement Sum of all nodes
  // Otherwise, compute the sum (recursively)
  else{return node->data + sumNodes(node->left) + sumNodes(node->right);}
}

/*
 Creates a tree of 7 elements
 */
void Tree::createTree()
{
  Node *root         = new Node(1);
  root->left         = new Node(2);
  root->right        = new Node(3);
  root->left->left   = new Node(4);
  root->left->right  = new Node(5);
  root->right->left  = new Node(6);
  root->right->right = new Node(7);
  this->root = root;
}
