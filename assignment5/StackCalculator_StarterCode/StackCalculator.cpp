#include <iostream>
#include "StackCalculator.hpp"

using namespace std;
/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    // Given function
    if(s.size() == 1 && s == "-")
        return false;

    else if(s.size() > 1 && s[0] == '-')
        s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
        if(!isdigit(s[i]) && s[i] != '.')
            return false;
        if(s[i]=='.' and !point) point = true;
        else if(s[i]=='.' and point) return false;
    }
return true;
}
StackCalculator::StackCalculator()  //Constructor, set everything to zero or null
{
    float number = 0.0;
    Operand* next = nullptr;
    stackHead = nullptr;
}
StackCalculator::~StackCalculator() // Deconstructor
{
    Operand *crawler = stackHead;   // Declare a pointer to struct, set it equal to head
    while (crawler != nullptr)      // Traverse the linked list
    {
        crawler = stackHead->next;  // Set crawler to the next node after the current head
        delete stackHead;           // Delete current head
        stackHead = crawler;        // set the new head to what is stored in crawler
    }
}
bool StackCalculator::isEmpty()     // Check to see if linked list is empty
{   
    return (stackHead == nullptr);  // Return true is stackHead is pointing to null
}
void StackCalculator::push(float number)    // Push function for stack
{
    Operand * add = new Operand;            // Dynamically Allocate a pointer to struct
    add->number = number;                   // Assigning value being read in to the node
    add->next = stackHead;                  // next Node will be current head node
    stackHead = add;                        // Set the new head to be the node being added
}
void StackCalculator::pop()                 // Pop function for stack
{
    if (isEmpty())                          // Check to see if Linked List is empty
    {                                       // We return the function and print error statment
        cout << "Stack empty, cannot pop an item." << endl;
        return;
    }
    else                                    // If Linked List is not empty
    {
        Operand* tmp = stackHead;           // Declare a pointer to struct and set it to point to the current head
        stackHead = stackHead->next;        // the new head will be the next node over
        delete tmp;                         // Delete the current node temp is pointing to
    }
}
Operand* StackCalculator::peek()            // Peek will return the stackHead
{
	//TODO:
    if (isEmpty())                          // Check to see if Linked List is empty
    {                                       // Print error statement if so and return the function
        cout << "Stack empty, cannot peek." << endl;
        return nullptr;
    }
    return getStackHead();                  // Otherwise, we call getStackHead to return the stackHead
}
bool StackCalculator:: evaluate(string* s, int size)    // Evaluate and Calculate based on array being read in
{
    /*TODO: 
        1.scan the array from the end
        2.Use isNumber function to check if the input is an operand
        3.push all operands to the stack
        4.If operator take two element of from the stack,
            compute and put the result back in stack
        5.Handle the boundery cases as required.
        6.Read the writeup for more details
    */
    float compute = 0.0;                                // Declare a float variable to store calculation

    for (int i = size - 1; i >= 0; i--)                 // Traverse the array from end to beginning
    {
        if (s[i] == "+" || s[i] == "*")                 // Element being read in is a valid operator
        {
            if(isEmpty())                               // If we are trying to compute but list is empty
            {                                           // print err statement and exit function (return false)
                cout << "err: not enough operands" << endl;
                return false;
            }
            if(s[i] == "+")                             // Otherwise, operator is addition
            {                                           // Add the value at the head and the next one over
                compute = stackHead->number + stackHead->next->number;
                pop();                                  // After storing the calculation in compute, we pop the two nodes
                pop();
                push(compute);                          // Then, we push the value of compute to the linked list
            }
            else                                        // If the operator is multiplication
            {                                           // Store calculation in compute
                compute = stackHead->number * stackHead->next->number;
                pop();                                  // Pop the next two nodes
                pop();
                push(compute);                          // Push the calculated value into the list
            }
        }
        else if (isNumber(s[i]))                        // Evaluate if we are reading in an operand (numerical value)
        {
            push(stof(s[i]));                           // Push the value onto the linked list
        }
        else                                            // Evaluate if user entered any invalid operation
        {                                               // (such as a letter or any invalid operators)
            cout << "err: invalid operation" << endl;
            return false;                               // Break out the function and return false
        }
    }
    return true;                                        // If everything goes smoothly, return true
}