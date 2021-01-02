#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*
                        ==== bigO notation in C++ ====

- Big O notation is used in computer science to describe the performance/complexity of an algorithm
- Usually used to determine the worst case scenerio of executed time required or space used

- Some good analogy/example of big O:

    * O(s), where s is the size of the file:
        - In this case, the time of transfering a file will be dependent to the size of the file.
        - The larger the file, the longer time it takes to complete the transfer
        - This is usually the case if we are transfering data via cloud/internet
    
    * O(1), where 1 is a constant time no matter the size of the file
        - In this case, the time it takes to transfer a file is constant no matter the size
        - If the size is 2 mb big, it would take the same amount of time it takes if it was 1tb big
        - This is usually the case if we are transfering data physically (plane, car, etc)

- In function terms, below are some of the most common big O examples

    * O(1), where 1 is a constant (straight line parrallel to the x axis)
    * O(n), where the time grows linearly
    * O(n²), where the time grows quadractically
    * O(2^n), where the time grows exponentially

- For big O notation, because we are looking for the worst case scenerio possible, we drop the constant and the keep the "worst" term

    - What this essentially means is if we calculate the time to be O(1/2(n^2)), it would simply be O(n^2) as 1/2 is a constant
    - Keeping the worst term means we drop all the lower terms. If we have O(n^2 + n), we would drop n at the end
*/

int fibonacci(int num);

int main()
{
    string greeting = "Hello World";

    // Examples of O(1):
    cout << greeting << endl;                           // This is because the program only executes this line once
    cout << greeting[2] << endl;                        // Much like the line above, even though this line is grabbing access to an index of the string
                                                        // It does not loop through the array of string to grab the element

    // Example of O(n):
    for (int i = greeting.length() - 1; i >= 0; i--)    // An example of O(n) (time grows linearly) is a single loop
    {                                                   // Where n is the number of items or times we traverse through the loop
        cout << greeting[i] << endl;                    // If we have 10 items, the loop will traverse and execute program 10 times
    }                                                   // If we have 100 items, the loop will traverse and execute the program 100 times

    // Example of O(n²):
    for (int i = 0; i < greeting.length(); i++)         // An example of O(n²) (time grows quadratically) are nested loops
    {                                                   // Where n is the number of items or times we traverse through the loop
        for (int j = 0; j < greeting.length(); j++)     // If we have 10 items, the loop will traverse and execute the program 100 times (10²)
        {
            cout << greeting[i] << endl;                // If we have 100 itesm, the loop will traverse and execute the program 10000 times (100²)
        }
    }                                                   // More nested loops will mean the exponent will increase    

return 0;
}
// Example of O(2^n):
int fibonacci(int num)                                  // An example of O(2^n) (time gorws exponentially) is a recursive function
{                                                       // Growth doubles with each addition to the input data set
    if (num <= 1)                                       // The curve (growth) will start off very shallow, then rises extremely fast                                       
    {
        return num;
    }
    return fibonacci(num - 2) + fibonacci(num -1);
}

// Drop the constant(s):
void print_text(string text)
{
    cout << text[text.length()] << endl;                // This line executes once, so it's O(1)

    for (int i = 0; i < (text.length()/2); i++)         // This loop will execute half of n, so it's O(n/2)
    {
        cout << "First half of the text: " << text[i];
    }
    cout << endl;                                       // This line will execute once, so it's O(1)

    for (int j = 0; j < 2; j++)                         // This loop will execute 2 times, so it's O(2)
    {
        cout << text[j];
    }
    cout << endl;                                       // This line will execute once, so it's O(1)
}                                                       // Recall that big O is specifically looking for worst case senerio
                                                        // Computing all of this, we get O(1 + n/2 + 1 + 2 + 1) = > O(5 + n/2)
                                                        // The constants in this equation are 5 and 1/2, so we drop them and we end up with just O(n)

