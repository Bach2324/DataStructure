#include <iostream>
#include <array>
#include <string>

using namespace std;

/*
                        ==== Array in C++ ====

- An array is a collection of items stored at contiguous memory locations
- Elements can be accessed randomly using indices of an array (USUALLY denoted with i)
- Can be used to store collections of data such as

    * strings
    * char
    * int
    * double
    * float

- Declaring and initializing: 

    1D array:
    datatype array_name[size] = {items};
    
    Multi-dimensional array:
                                        [column1][column2] (goes up and down - Vertically)

    datatype array_name[row][column] =  {items1, items2   [row1] 
                                         item3, items4};   [row2]   

- Note that when you declare the an array a specific datatype, such as string, the items in it must be the same datatype
    
    Example: 
        1) string student_names[5] = {"Mary", "Will", "Chris", "Ashley", "Adam"} - > an array of strings containing the names of students
        
        2) int student_grades[5] = {90, 75, 80, 100, 84} - > an array of integers containing student's grades
        
        3) int student_id[5] = {"12323", "324353", "12343", "23235", "656454"}; - > This will return an error as the array was declared as an int
                                                                                    but we tried to store string values in it

- Arrays are not dynamic, which means that it's only able to allow a set amount of items entered/stored, which is decided at the time of declaration

*/

int main()
{
    // Array's index starts at 0 and counts up, meaning that the first index (position) will be 0

    const int size = 5; // Declare the size of the array

    string student_names[size] = {"Mary", "Will", "Chris", "Ashley", "Adam"};
    // Indices:                     [0]     [1]      [2]      [3]       [4]   

    int student_grades[size] = {90, 75, 80, 100, 84};
    // Indices:                [0]  [1] [2] [3]  [4]   

    // To access a specific item, we can use array_name[index_of_choice];
    // For example: 

    cout << student_names[0] << endl; // This will output/print the item at index zero in the student_names array, which is "Mary"
    cout << student_grades[2] << endl; // This will output/print the item at index 2 in the student_grade array, which is 80

    // We can use a for loop to traverse through the array as well
    // Lets say we want to print out all the student's name without having to cout each individually line
    
    cout << "Print out student names accordingly" << endl;

    for (int i = 0; i < size; i++)          // Traverse from the first index 0, up to the the index 4
    {                                       // i, which is the index variable we declared in the loop, will increment by 1 every loop
        cout << student_names[i] << endl;   // Print the name of the student at that specific index
    }

    // One good tip to realize is that the index is always one less than the position, so 1st position is index zero, 2nd position is index 1, etc
    // This is why we tell the loop to only traverse to 1 less the array size, as 5th(last) position of the array is index 4
    // If we try to access index 5 (i = 5), then we would get a seg fault, which is accessing a memory that does not exist

    cout << "Print out student names from last to first" << endl;

    for (int j = size - 1; j >= 0; j--)       // This loop will traverse backward, from the end of the array to the beginning
    {                                         // Here, we say i is equal to (start at) the size of the array - 1 (5th position, index 4), and decrement by 1
        cout << student_names[j] << endl;     // Print the name of the student at that specific index
    }
    
    // We can also initialize the values in our arrays if it isn't done so beforehand. To do so, we can use a for loop
    
    for (int k = 0; k < size; k++)            // Here we are traversing through the student_grades array accordingly from left to right
    {
        student_grades[k] = 0;                // We are initializing all the values (items) to zero
    }                                         // This is good practice to do with all types of arrays (except strings should be equal = "").
                                              // Like variables, C++ will assign uninitialized arrays garbage values

    // We can use the same method to replace or fill in a specific index with a non-empty/zero value

    student_grades[2] = 76; // This will replace or fill in the value at index 2 in student_grades array with 76

return 0;
}