#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


/*
                        ==== Vectors in C++ ====

- Vectors are sequence containers representing arrays that can change in size (dynamic not static)
- Recall that in standard C++ arrays, the size of the array is fixed and cannot be dynamically changed once declared
- Similar to arrays, elements in a vector can be access through uses of loop and index
- Because of this, vectors consume more memory in exchange for ability to:
    
    * manage storage
        * Grow dynamically

- To declare and initialize a vector ---- > vector <datatype> variableName;

    Ex:
    
        * vector <string> student_names;    - > vector of type string containing string element(s)
        * vector <int> student_ID;          - > vector of type (int)eger containing int element(s)
        * vector <double> student_grades;   - > vector of type double containing double element(s) 

- Vectors come with modifier built in-functions that we can use to do certain tasks:

    vector <string> student_names; 

    student_names.push_back();                                  - > This will add the string "John Smith" to last position of the vector
    student_names.insert(student_names.begin(), element);       - > This will add an element to the first element of the vector
    student_names.pop_back();                                   - > this will remove the last element of the vector
    student_names.erase(student_names.begin() + position);      - > This will remove an element at the specfic position you specified in the argument
    student_names.clear();                                      - > This will erase all the elements within the vector
    student_names.size();                                       - > This will return the current size of the vector
    student_names.capacity();                                   - > This will return the maximum size of the vector

- There are more built in functions that we can use for vectors, but for now, these will typically be the most used
- When getting ready to compile, we use g++ -std=c++11 fileName.cpp for vectors

*/

int main()
{
 
    // Declaring a vector of type string and intializing them with string values
    vector <string> student_names {"John Smith", "Jane Doe", "Jack Den"};

    // Here, we will print out the size of the vector before we add any addtional elements onto it
    cout << "Vector size before adding elements: " << student_names.size()<< endl; 
    
    // We can use the pop_back() function if we want to add additional names to our vector
    student_names.push_back("Cheems Doge");
    student_names.push_back("Noobmaster69");
    student_names.push_back("Gryffin");

    // This will add all the new names into the last position of the vector, starting from top to bottom
    // If the vector is already at capacity, then the vector will dynamically increase it's size to accomodate the new name

    // Here, we will print out the size of the vector after adding elements. We should get different size value
    cout << "Vector size before after elements: " << student_names.size()<< endl; 

    // Now we will create a loop to traverse through the vector and print out all the elements within it
    // For vectors, we have to declare our index variable as 'unsigned int'
    
    cout << "class list before drop: ";
    for (unsigned int i = 0; i < student_names.size(); i++)
    {
        if (i < (student_names.size() - 1))                     // If our index variable has not reached the last element of our student_names vector
        {
            cout << student_names[i] << ", ";                   // We will print all the student names with a comma to seperate them
        }
        else                                                    // Otherwise, if the index is on the last element
        {
            cout << student_names[i] << ".";                    // We will print the last name/element with a period to end the output
        }
    }
    cout << endl;                                               // end line after everything gets printed

    // If we want to remove a name from the vector
    // We can either do a explicity erase if we know where "John Smith" is located within our vector/attendance sheet
    student_names.erase(student_names.begin() + 0);

    // Let's however say we have a vector that contains hundreds of names and want to streamline our search
    // We can create a loop to traverse through all the elements of the vector

    cout << "Class list after drop: ";
    for (unsigned int i = 0; i < student_names.size(); i++)    
    {
        if (student_names[i] == "Jane Doe")                     // If the code finds that one of the element matches the name that we are searching for 
        {
            student_names.erase(student_names.begin() + i);     // Then we will use the erase function to delete/remove the element at that specific index/position
        }
        if (i < (student_names.size() - 1))                     // If our index variable has not reached the last element of our student_names vector
        {
            cout << student_names[i] << ", ";                   // We will print all the student names with a comma to seperate them
        }
        else                                                    // Otherwise, if the index is on the last element
        {
            cout << student_names[i] << ".";                    // We will print the last name/element with a period to end the output
        }
    }
    cout << endl;                                               // end line after everything gets printed
return 0;
}