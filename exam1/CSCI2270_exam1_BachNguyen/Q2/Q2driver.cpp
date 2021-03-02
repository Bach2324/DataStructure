#include <iostream>
#include <string>
using namespace std;

// any file that uses the SLL class must include this header file
#include "SLL.hpp"

int main(){
   
	/*
	Test cases are provided only to help you test your code. Each
	submission will be individually inspected by the teaching staff.

	*/

    /*
    Test 1
    */
    cout << "\n---------------------\n";
	int n = 5;
	char testStringA[] = {'m','a','d','a','m'};
	SLL sA;
	for(int i = 0; i<n; i++){
		sA.insert(nullptr,testStringA[i]);
	}
	cout << "Test A:" << endl; 
	sA.displayList();

	cout << "expected >> Palindrome " << endl;

	if(sA.palindrome())
		cout << "result   >> Palindrome" << endl;
	else
		cout << "result   >> Not a palindrome" << endl;
	    cout << "\n---------------------\n";
	/*
    Test 2
    */
    cout << "\n---------------------\n";
	char testStringB[] = {'m','a','d','m','a'};
	SLL sB;
	for(int i = 0; i<n; i++){
		sB.insert(nullptr,testStringB[i]);
	}
	cout << "Test B: \n";
	sB.displayList();
	cout << "expected >> Not a palindrome " << endl;
	if(sB.palindrome())
		cout << "result   >> Palindrome" << endl;
	else
		cout << "result   >> Not a palindrome" << endl;
    cout << "\n---------------------\n";

	// // Test 3
	// int size = 7;
    // cout << "\n---------------------\n";
	// char testStringC[] = {'r','a','c','e','c','a','r'};
	// SLL sC;
	// for(int i = 0; i<size; i++){
	// 	sC.insert(nullptr,testStringC[i]);
	// }
	// cout << "Test C: \n";
	// sC.displayList();
	// cout << "expected >> palindrome " << endl;
	// if(sC.palindrome())
	// 	cout << "result   >> Palindrome" << endl;
	// else
	// 	cout << "result   >> Not a palindrome" << endl;
    // cout << "\n---------------------\n";

	// sC.~SLL();

	// //Test case for if list size is 1
	// int sizeD = 1;
    // cout << "\n---------------------\n";
	// char testStringD[] = {'m'};
	// SLL sD;
	// for(int i = 0; i<sizeD; i++){
	// 	sD.insert(nullptr,testStringD[i]);
	// }
	// cout << "Test D: \n";
	// sD.displayList();
	// cout << "expected >> palindrome " << endl;
	// if(sD.palindrome())
	// 	cout << "result   >> Palindrome" << endl;
	// else
	// 	cout << "result   >> Not a palindrome" << endl;
    // cout << "\n---------------------\n";

	// sD.~SLL();

	// //Test case for empty list
	// int sizeE = 0;
    // cout << "\n---------------------\n";
	// char testStringE[] = {};
	// SLL sE;
	// // for(int i = 0; i<sizeE; i++){
	// // 	sE.insert(nullptr,testStringE[i]);
	// // }
	// cout << "Test E: \n";
	// sE.displayList();
	// cout << "expected >> palindrome " << endl;
	// if(sE.palindrome())
	// 	cout << "result   >> Palindrome" << endl;
	// else
	// 	cout << "result   >> Not a palindrome" << endl;
    // cout << "\n---------------------\n";

	// sE.~SLL();

	// //Test case for not Palindrome
	// int sizeF = 3;
    // cout << "\n---------------------\n";
	// char testStringF[] = {'c','o','d','e'};
	// SLL sF;
	// for(int i = 0; i<sizeF; i++){
	// 	sF.insert(nullptr,testStringF[i]);
	// }
	// cout << "Test F: \n";
	// sF.displayList();
	// cout << "expected >> palindrome " << endl;
	// if(sF.palindrome())
	// 	cout << "result   >> Palindrome" << endl;
	// else
	// 	cout << "result   >> Not a palindrome" << endl;
    // cout << "\n---------------------\n";

	// sE.~SLL();

	return 0;
}
