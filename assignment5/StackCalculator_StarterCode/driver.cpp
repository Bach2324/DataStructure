#include<iostream>
#include<cmath>
#include<iomanip>
#include "StackCalculator.hpp"

using namespace std;

int main()
{
    // stack to hold the operandsß
    StackCalculator stack;

    int numElement = 0;
    string* inparr = new string[50];

    // enter a number
    string number;
    cout << "Enter the operators and operands ('+', '*') in a prefix format" << endl;

    while(true)
    {
        /* TODO
        1. Read input (operators and operands) until you encounter a "="
        2. store them in inparr
        */
        cout << "#> ";
        getline(cin, number);
        if (number == "=")
        {
            break;
        }
        inparr[numElement] = number;
        numElement++;
    }
    /* TODO - If the inparr is empty then print "No operands: Nothing to evaluate"
            else call the evaluate function
    */
    bool eval = true;                   // bool variable to store the return value of evaluate function
    if (numElement == 0)                // Evaluate if inparr is empty
    {
        cout << "No operands: Nothing to evaluate" << endl;
        return 0;                       // We stopped the program
    }
    else                                // Otherwise, call the evaluate function
    {                                   // And assign eval to it
        eval = stack.evaluate(inparr, numElement);
        if (!eval)                      // If evaluate returns false, we stop the program
            return 0;                   // The error print statements exists within the function already
    }
    /* TODO - Validate the expression
        1. If valid then print the result cout << "Result= "<<result << endl;
        2. Else, print "Invalid expression"*/
    if(eval)                            // Otherwise, if eval ran smoothly                       
    {   
        Operand* result = stack.peek(); // We print the result
        cout << "Result= " << result->number << endl;
    }
    else                                // print if invalid expression
    {
        cout << "Invalid expression" << endl;
    }
    delete[]inparr;
    stack.~StackCalculator();
return 0;
}