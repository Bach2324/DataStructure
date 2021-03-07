#include <iostream>
#include "JobQueue.hpp"

using namespace std;

JobQueue::JobQueue()
{   
    int queueFront = 0; //the index in queue[] that will be dequeued next
    int queueEnd = 0; //the index in queue[] that keeps track of the next available empty space
    int counter = 0; // number of elements in the queue currently
    string queue[SIZE];
    
}
bool JobQueue::isEmpty()            // Check if the Array is empty
{                                   // If queueFront and end are at the same index and no value is assigned to it
    return (queueFront == queueEnd && queue[queueEnd] == "");
}                                   // We return true, false otherwise
bool JobQueue::isFull()             // Function to check if array is full
{                                   // Same thing as isEmpty(), but this time return true if there's a value assigned to the index
    return (queueFront == queueEnd && queue[queueEnd] != "");
}
void JobQueue::enqueue(string job)      // Function to enqueue (add) value into the array
{
    if (isFull())                       // Array is full, we return the function and print err statemnet
    {   
        cout << "Queue full, cannot add new job" << endl;
        return;
    }
    queue[queueEnd] = job;                  // Otherwise, add element being read in into the array
    queueEnd = (queueEnd + 1) % SIZE;       // Increment using circular array method
    counter++;                              // Increment the number of elements in the array
}
void JobQueue::dequeue()                    // Function to dequeue (remove) element from array
{
    if (isEmpty())                          // Can't dequeue if the array is empty
    {
        cout << "Queue empty, cannot dequeue a job" << endl;
        return;
    }
    queue[queueFront] = "";                 // Remove the element at the current index
    queueFront = (queueFront + 1) % SIZE;   // Increment the Front index to the next index
    counter--;                              // Decrement the number of elements in the array
}
string JobQueue::peek()                     // Function to get the front element (next to be dequeued)
{
    if (isEmpty())                          // Nothing to return
    {
        cout << "Queue empty, cannot peek" << endl;
        return "";
    }
    return queue[queueFront];               // Return element
}
int JobQueue::queueSize()                   // Function to get current size
{
    return counter;                         // return counter which is the variable that keeps track of num elements being stored
}