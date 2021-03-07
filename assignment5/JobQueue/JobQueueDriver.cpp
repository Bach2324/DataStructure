/****************************************************************/
/*                Job Queue Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/
#include "JobQueue.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Add jobs into the queue" << endl;
	cout << "2. Dispatch jobs from the queue" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
	/* TODO */
	JobQueue work;						// Declare an option to class JobQueue
	string option;						// String for input option
	int i = 0;							// Index counter

	while(option != "3")				// Loop will run til user enters option 3 (exit condition)
	{
		menu();							// Print menu interface
		getline(cin,option);			// ask for user input
		if(option == "1")				// User chooses 1 (enqueueing jobs)
		{
			i = 0;						// set/reset index counter to start at 0
			string num_job, job;		// Declare strings to store user inputs
			cout << "Enter the number of jobs to be created:"<< endl; 
			getline(cin, num_job);		// Get the number of jobs users are entering in

			while(i+1 <= stoi(num_job)) // Traverse until we hit the job number
			{
				cout << "job" << i+1 << ":" << endl;
				getline(cin,job);		// Ask user for name of jobs
				work.enqueue(job);		// add job to queue
				i++;					// Increment index counter
			}
		}	
		else if (option == "2")			// User chose option 2 (dequeuing jobs)
		{
			i = 0;						// set/reset index counter to start at 0
			string dispatched;			// String to store the number of jobs user wants to remove
			cout << "Enter the number of jobs to be dispatched:" << endl;
			getline(cin, dispatched);	// get the number

			while(i < stoi(dispatched))	// Convert number to int, and have loop traverse until we hit the num jobs
			{
				cout << "Dispatched: " << work.peek() << endl;
				work.dequeue();			// Dequeue the amount of jobs users wanted
				i++;					// Increment index counter
				if (work.isEmpty())		// If the array is empty
				{
					cout << "No more jobs to be dispatched from queue" << endl;
					break;				// print err statement and exit loop
				}
			}
		}
		else if (option == "3")			// User chose option 3 (exit program)
		{								// Print out the number of jobs after enqueue and dequeue
			cout << "Number of jobs in the queue:" << work.queueSize() << endl;
		}								
		else							// Invalid input edge case
		{
			cout << "Invalid input." << endl;
		}
	}
return 0;
}