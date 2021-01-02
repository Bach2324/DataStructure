#include <iostream>
#include <array>
#include <string>
#include <cmath>

using namespace std;

/*
                        ==== Loops in C++ ====

- In general, loops are super helpful for us to use when we need to run a block of code certain amount of time.
- It is also useful to use if we need the block of code to run until a specific condition is met

- There are a couple types of loops that we can use:

    * for loop
    * while loop
    * do while loop

- for loops are pretty straight forward. They will run a block of code a certain amount of times you set.
- They are very useful to traverse through things like arrays and vectors from left to right (beginning to end) or right to left (end to beginning)
    
    To declare a for loop:
    
        for (int i = starting_position; i < final_position; i++)
        {
            // Code here
        }

- While loops are useful if you want the program to run a code until a specific conditions is met.
- They are useful for building out basic menu interface, or to streamline a specific task
- One good thing to keep in mind is while loop can caused what's called an infinite loop, 
    which basically means the code will never be met, therefore the loop has no exit option

    To declare a while loop:

        while (variable != condition)
        {
            // Run this
            // When variable == condition, the while loop will terminate/exit
        }
    
- do while loops are similar to the regular while loop, except for that it checks the test condition at the end of the body instead of the beginning
- This means that the do while loop will always guarantee that the block of code within the loop will run at least once

    To declare a do while loop:

        do
        {
            // Run this

        } while (this condition is not met)

*/

int main()
{
    string text = "Hello World!";

    // One of the biggest things to keep in mind that counters or index within C++ starts at zero. This means that the first position will = 0 and not 1
    // For this for loop, we declare i as our loop counter, it's starting position, which is zero.
    // In the peice after the semicolon, we are telling the loop how many times it should run or traverse before exiting
    // In the final peice before the closing parantheses, we are telling the counter i to increment by 1 each times it loops

    for (int i = 0; i < 5; i++)                 // Here we are telling the loop to run 5 times
    {                                           // In this for loops we are also telling it to increment or from left to right (small to large)
        cout << text << endl;                   // In the 5 times that it runs, it will print the variable text, which contains the string "Hello World!" each times
    }

    /* expected result:
        Hello World!
        Hello World!
        Hello World!
        Hello World!
        Hello World!
    */

    // We can also use a for loop to traverse from right to left (large to small; decrement)

    for (int i = text.length() - 1; i >= 0; i--) // Here, we are using the length() function to get the total length of the string variable text
    {                                            // We then tell the loop that the starting position will be at the end of the string instead of the beginning
                                                 // After that we then tell the loop that it should run until it reaches the starting position of the string
        cout << text[i];                         // And finally at the end, we tell our loop counter to decrement by one each iteration (move backward)
    }                                            // At the end, we will print out the result

    // Expected result:
    // !dlroW olleH

    /*
        To break down the loop above more visually:

        - At the beginning of our main, we declared our text variable of type string to contain the string "Hello World!"
        - When we use the length() function, we can see that "Hello World!" contains 11 characters/elements, including the space between the words
        - Now, recall the statement, that the first position in C++ always starts at zero:
                
                 H   e   l   l   o       W   o   r   l    d    ! 
                [0] [1] [2] [3] [4] [5] [6] [7] [8] [9]  [10] [11]
        
        - So if we tell the loop to traverse or iteration from 0 to 11, this means that it will run 12 times total (as zero is the 1st position/iteration)
        - This is why in our loop declaration, we always have to tell it to run up until "one less" than the actual times that we want to iterate through
        - For the reverse traversal for loop, we tell the loop counter to start at one position less than the actual length of the string
        - Then the counter i will decrement (-1) from that position until it reaches index zero of the string (first position)
        - Failure to do declare a for loop correctly will result in a segmation fault, which essentially means you are going out of bound
    */

    int x = 0;                                      // Declaring our condition variable
    while (x < 3)                                   // In this basic while loop we are telling the program to run while x is less than 3
    {                                               // Here we are telling x to increment by one every time the loop iterates
        x++;                                        // This means that the loop will run a total of 3 times;
    }                                               // because on the last iteration, x will be equal to 3, thus condition is met

    /* Now, what if we don't tell x to increment? Lets say we re-initialize x to be equal 5 within the loop instead:
    
    while (x != 3)
    {
        x = 5;
    }

    - This will result in an infinite loop, as you can see the condition will always be met and never have a terminating clause
    - x will always be equal to 5 no matter which loop iteration we are at, as we do not have a modifying statement within it
    - The "exit clause is when x equals to 3", which as stated above, will never be met */

    int y = 0;                                       // Declaring our condition variable
    do                                               // In this basic do while loop we are telling the program to run while y is less than 2
    {                                                // The main difference between a do while loop and a while loop is that it checks for the exit condition at the end of the loop
        cout << y << endl;                           // This means that the loop will guarantee to run at least once;
        y++;                                         // as it has to traverse through the loop and execute the block of code within before checking the conditional statement at the end
    } while (y < 2);                                    
    
return 0;
}