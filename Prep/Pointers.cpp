#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    /*  A pointer is just a variable that holds/stores the memory address as it's value

        for example:

            int a = 5;
                -What we care about is that we can represent that location in memory through that variable name (a)
                -When we say or declare a variable that's name a, what we are actually saying is "go to this ram address"

            pointer b;
                & <--- get the address of that particular variable
                *b = &a <---- Assign pointer variable b to be equal the address of variable a

    */

    string food = "pizza";
    string* ptr = &food;

    cout << food << endl;
    cout << &food << endl;
    cout << ptr << endl;

return 0;
}