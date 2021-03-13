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
MovieTree::MovieTree()  // Class constructor, set root to null or prim data to zero
{
  root = nullptr;       // Set root to null
}
void MovieTreeDestructorHelper(MovieNode * crawler) // Function to help class destructor
{
  if (crawler == nullptr){return;}                  // Stop function call if crawler is null
  else
  {
    MovieTreeDestructorHelper(crawler->left);       // Traverse left
    MovieTreeDestructorHelper(crawler->right);      // Traverse right
    delete crawler;                                 // Deallocate the node crawler is currently at(pointing to)
  }
}
MovieTree::~MovieTree() // Class destructor
{
    MovieTreeDestructorHelper(root);
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
void queryMoviesHelper(MovieNode *ptr, float rating, int year)
{                                                       // Helper Function to queryMovies() 
    if (ptr == nullptr)                                 // If the pointer is pointing to null
    {
      return;                                           // We return the function
    }
    if (ptr->rating >= rating && ptr->year > year)      // When traversing, if we hit our case conditions to print the movie
    {                                                   // If we find a rating higher than the given parameter, and newer than given year
      cout << ptr->title << " (" << ptr->year << ") " << ptr->rating << endl;
    }
    queryMoviesHelper(ptr->left, rating, year);         // Pre-order traversal, function call to traverse left
    queryMoviesHelper(ptr->right, rating, year);        // Pre-order traversal, function call to traverse right
}
void MovieTree::queryMovies(float rating, int year)   // Main queryMovies() function
{
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  queryMoviesHelper(root, rating, year);              // Call the helper function (runs recursively)
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
int treeHeight(MovieNode *height)           // Helper function to find the max depth/heigh of tree
{
  if (height == nullptr)                    // Check to see if tree is empty
  {
    return 0;                               // Return zero if so
  }
  else                                      // Otherwise
  {
    int left = treeHeight(height->left);    // Assign the height of left subtree to int left
    int right = treeHeight(height->right);  // Do the same for right subtree
    if(left > right){return left + 1;}      // Return depth of left subtree if left subtree is higher than right
    else{return right + 1;}                 // Otherwise, if right is deeper/higher, we return it's height
  }
}
void printLevelNodeHelper(MovieNode *crawler, int i)  // Helper function to printLevelNode()
{
  if (crawler == nullptr)                             // Stop function call if pointer is null
  {
    return;
  }
  if (i == 0)                                         // When we are at height if 0
  {                                                   // We print the movie at that given level
    cout << "Movie: " << crawler->title << " (" << crawler->rating << ")" << endl;
  }
  else                                                // Ootherwise, we traverse til we hit that level
  {
    printLevelNodeHelper(crawler->left, i - 1);       // Traverse left
    printLevelNodeHelper(crawler->right, i - 1);      // Traverse right
  }
}
void MovieTree::printLevelNodes(int level)            // Print node at given level function
{
  if (level > treeHeight(root))                       // Exit function if the given level is heigher than the max tree height/depth
  {
    return;
  }
  printLevelNodeHelper(root, level);                  // Otherwise, we call our helper function to print the nodes at given level
}
