/*
CSCI 2270 - Spring 2021
Midterm 1
Question 1 starter code.

*/
#include <iostream>

using namespace std;

void trim (int *& arr, int &lenth, int target);

void testPrint(int *p0, int length);

int main(){
   
    // Provided test case #1
    int a_test[] = {3, 2, 5 ,1, 0, 8, 4};
    int test_length = 7;

    // Edge case if value is not found
    // int a_test[] = {3, 2, 5 ,1, 0, 8, 0, 4};
    // int test_length = 8;
   
    /*
    Test 1
    */
    cout << "\n---------------------\n";
    
    int * a0 = new int[test_length];
    for(int i = 0; i<test_length; i++){
        a0[i] = a_test[i];
    }

    int target = 0;
    // target value that does not exist within the function
    // int target = 33; 
    /*
        * TODO your function call goes here. It should look like:    
    */ 
    // cout << test_length << endl;
    trim(a0, test_length, target);

    cout << "Test 1: \n"  << "expected >> 3 2 5 1 " << endl;
    // Test case if value is not found in the index
    // cout << "Test 1: \n"  << "expected >> 3 2 5 1 0 8 0 4" << endl;
    testPrint(a0, test_length);
    delete [] a0;

    return 0;
}
/*
    * TODO your function definition goes here
*/
void trim (int *& arr, int &length, int target)
{
    int index = 0;                      // Declare a variable to store the found value's index
    bool found = false;                 // found will check to see if the value was found or not

    if (length == 0)                    // If original array is empty
    {
        return;                         // break out array
    }
    for (int i = 0; i < length;i++)     // Traverse through the original length of the array
    {
        if (arr[i] == target)           // When value is found
        {
            index = i;                  // Store the index of that value
            found = true;               // found will be true
        }
        if (i == length - 1 && found == false)  // If we are at the end of our array and found is still false
        {
            return;                             // Break out of the function
        }
    }
    int *temp = new int[index];                 // Dynamically allocate an array
    for (int i = 0; i < index;i++)              // Traverse up to the index of the found value
    {
        temp[i] = arr[i];                       // Copy everything over
    }
    delete[] arr;                               // Deallocate the original array
    arr = temp;                                 // Copy everything that was stored in temp (everything up to the found value's index)
    length = index;                             // Update length to be the length of the trimmed array (size of the trim array is up to the found index)
}

void testPrint(int *p0, int length){
    
    cout << "result   >> ";

    for(int i = 0; i<length; i++){
        cout << p0[i] << " ";
    }
    cout << "\n---------------------\n\n" << endl;
}