#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Helper function: Create new node using provided args
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() {
  //write your code
}
MovieTree::~MovieTree()
{
}
void printMovieInventoryHelper(MovieNode * ptr) // Function to help print movie (recursively)
{
  if(ptr->left != nullptr)                      // Check if left pointer is not null
  {
    printMovieInventoryHelper(ptr->left);       // Traverse the left side
  }                                             // Print the movie info as we recursively traver
  cout << "Movie: " << ptr->title << " (" << ptr->rating << ")" << endl;
  if(ptr->right != nullptr)                     // Check if right isde is not null
  {
    printMovieInventoryHelper(ptr->right);      // Traverse the right side
  }
}
void MovieTree::printMovieInventory()
{
  if (root != nullptr)                          // Check to see if we have a root node or not
  {
    printMovieInventoryHelper(root);            // Call the helper function
  }
  else                                          // Error statement prints if the tree is empty
  {
    cout << "Tree is Empty. Cannot print." << endl;
  }
}
void addMovieNodeHelper(MovieNode *&ptr,int ranking, string title, int year, float rating)
{                                               // Function to help add movie info (recursively)
  if (ptr == nullptr)                           // If the pointer is null
  {
    ptr = new MovieNode;                        // Create a node (dynamically allocation)
    ptr->ranking = ranking;                     // Assign each data being read in to the according node data
    ptr->title = title;                         // For title of movie
    ptr->year = year;                           // For year of movie
    ptr->rating = rating;                       // For rating of movie
    ptr->left = nullptr;                        // Set both left and right pointer to null
    ptr->right = nullptr;
  }
  else if (title < ptr->title)                  // If title being read in is alphabetically "less than" the title at that node
  {                                             // We add it to the left (left child)
    addMovieNodeHelper(ptr->left,ranking, title, year, rating);
  }
  else                                          // Otherwise, we add it to the right side of the node (right child)
  {
    addMovieNodeHelper(ptr->right,ranking, title, year, rating);    
  }
}
void MovieTree::addMovieNode(int ranking, string title, int year, float rating)
{
  addMovieNodeHelper(root,ranking, title, year, rating);
}
void findMovieHelper(MovieNode*finder, string title)  // Helper function to help find movie function (recursively)
{                                                     
  if(finder == nullptr)                               // Check if finder is null
  {
    cout << "Movie not found." << endl;               // if so, movie was not found
    return;                                           // Exit function
  }
  else                                                // Otherwise recursively traverse the tree
  {
    if(title < finder->title)                         // Traverse the left side if title is alphabetically "less than" the current node
    {
      findMovieHelper(finder->left, title);           // Recursively traversing
    }
    else if (title > finder->title)                   // Otherwise, traverse the right side if greater
    {
      findMovieHelper(finder->right, title);          // Recursively traversing
    }
    else                                              // If we found the title
    {
      if (title == finder->title)                     // Print all the information of that movie
      {
        cout << "Movie Info:" << endl;
        cout << "=================="<< endl;
        cout << "Ranking:" << finder->ranking << endl;
        cout << "Title  :" << finder->title << endl;
        cout << "Year   :" << finder->year << endl;
        cout << "Rating :" << finder->rating << endl;
      }
    }
  }
}
void MovieTree::findMovie(string title)               // function to find moviie
{
    findMovieHelper(root, title);                     // Call it's recursive helper function
}
void MovieTree::queryMovies(float rating, int year)
{
  //write your code
}
float sum(MovieNode *compute)                         // Helper function for averageRating()
{
  if (compute == nullptr)                             // If tree is empty
  {
    return 0;                                         // return zero
  }                                                   // Otherwise, we recursively add up the total sum of the left and right side of the tree
  return compute->rating + sum(compute->left) + sum(compute->right);
}
int countNode(MovieNode*count)                        // Function to help averageRating()
{
  if (count == nullptr)                               // Check to see if tree is empty
  {
    return 0;                                         // Return zero if so
  }                                                   // Otherwise return value of countNode will increment every time a node is not null/found
  return 1 + countNode(count->left) + countNode(count->right);
}
void MovieTree::averageRating()                       // Function to calculate the Average Rating of all the movies
{
  if (root == nullptr)                                // If the tree is empty
  {
    cout << "Average rating:0.0" << endl;             // We print 0.0 as the average rating
  }
  else                                                // Othewrwise, we call our two helper function to compute the average
  {
    cout << "Average rating:" << sum(root) / float(countNode(root)) << endl;
  }
}
void MovieTree::printLevelNodes(int level) {
  //write your code
}
