// CSCI 2270 -- Data Structures
// Assignment 1 -- Problem 1
// Bach Nguyen

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct studentData                  // Declaring a struct of student data
{
    string studentName;             // Their name
    int homework;                   // Homework score
    int recitation;                 // Recitation score
    int quiz;                       // Quiz score
    int exam;                       // Exam score
    double average;                 // Average of sum of all assignment score
};

void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length)
{
    students[length].studentName = studentName;                                     // Adding the name of student into an array of struct
    students[length].homework = homework;                                           // Adding Homework score of student an array of struct
    students[length].recitation = recitation;                                       // Adding recitation score into an array of struct
    students[length].quiz = quiz;                                                   // Adding quiz score into an array of struct
    students[length].exam = exam;                                                   // Adding exam score into an array of struct
    students[length].average = (homework + recitation + quiz + exam)/(double)4;     // Adding average score into an array of struct 

return;
}
char calcLetter(double avg)                         // Function to return the letter grade based on student's average score
{
    if (avg >= (double)90)                          // Return letter/(char)acter A if the average is 90 or higher
    {
        return 'A';
    }
    else if (avg >= (double)80 && avg <= 89.9)      // Return letter/(char)acter B if the average is between 80 -> 89.9
    {
        return 'B';
    }
    else if (avg >= (double)70 && avg <= 79.9)      // Return letter/(char)acter C if the average is between 70 -> 79.9
    {
        return 'C';
    }
    else if (avg >= (double)60 && avg <= 69.9)      // Return letter/(char)acter A if the average is 60 -> 69.9
    {
        return 'D';
    }
return 'F';                                         // Return letter/(char)acter F if the average is below 60
}

void printList(const studentData students[], int length)        // Function to print the student data in a formatted way
{

    for (int i = 0; i < length; i++)
    {
        cout << students[i].studentName << " earned " << students[i].average << " which is a(n) ";
        cout << calcLetter(students[i].average) << endl;
    }
return;
}
int main(int argc, const char *argv[])                  // Passing in command line arguments
{
    studentData students_grades[100];                   // Declare an array of studentData struct
    ifstream inFile(argv[1]);                           // Open file using the second command line argument

    int count = 0;                                      // count variable will count the number of students we read in
    string line, name, hw, rec, quiz, exam;
    while(getline(inFile, line))                        // To grab each line of the file we are reading in
    {
        if (line.length() != 0)                         // Only evaluate if the line is not empty
        {
            stringstream s(line);                       // Declare a stringstream object to pass in the getline function
            getline(s, name, ',');                      // Get the name, which is from the start to the first delimiter
            getline(s, hw, ',');                        // get HW score from the first delimiter to the second delimiter
            getline(s, rec, ',');                       // get recitation score from second delimiter to third delimiter
            getline(s, quiz, ',');                      // get quiz score from third delimiter to fourth delimiter
            getline(s, exam);                           // get exam score from fourth delimiter to end of line
                                                        // Pass all the information into addStudentData function
                                                        // Convert any digit values into their respective type
            addStudentData(students_grades, name, stoi(hw), stoi(rec), stoi(quiz), stoi(exam), count);
            count++;                                    // Increment each time a line is read in
        }
    }
    inFile.close();                                     // Close file when done
    printList(students_grades, count);                  // Call print function to print the data we read in

    ofstream outFile(argv[2]);                          // Declaring output file using third command line arguments
    double upper_bound, lower_bound;                    // Declare a bound to print out the students with the respective grades

    string arg3 = argv[3], arg4 = argv[4];              // assign command line arguments to string value to compare

    for (int i = 0; i < count; i++)                     // Traverse through the number of data we read in
    {
        if (arg4 == "A")                                // If the 5th argument is the letter A
        {
            upper_bound = (double)100;                  // Declare the upper bound to be 100 max
            if(arg3 == "B")                             // fourth command line argument will be used for lower bound
            {
                lower_bound = (double)80;               // Lower bound set if argument is the letter B
            }
            else if (arg3 == "C")                       
            {
                lower_bound = (double)70;               // Lower bound set if argument is the letter C
            }
            else if(arg3 == "D")
            {
                lower_bound = (double)60;               // Lower bound set if argument is letter D
            }
            else
            {
                lower_bound = (double)0;                // Lower bound set if argument is F
            }
        }
        else if (arg4 == "B")                           // If the fifth argument is "B"
        {
            upper_bound = 89.9;                         // B will be the upper bound
            if (arg3 == "C")                            // Evaluate if fourth argument is letter C
            {
                lower_bound = (double)70;               // Set lower bound accordingly
            }
            else if(arg3 == "D")            
            {
                lower_bound = (double)60;               // Set lower bound if argument is letter D
            }
            else                                
            {
                lower_bound = (double)0;                // Lowest bound will be if argument is letter F
            }
        }
        else if (arg4 == "C")                           // Evaluate if the letter C is the upper bound (fifth command line argument)
        {
            upper_bound = 79.9;                         // Recall that if C is upper bound, then we can assume that
            if(arg3 == "D")                             // All the higher letters (A & B) will not be entered into the lower bound argument
            {
                lower_bound = (double)60;               // Set lower bound if argument is letter D
            }
            else                                        // Otherwise, the letter F will be set as the lowest bound
            {
                lower_bound = (double)0;
            }
        }
        else if (arg4 == "D")                           // Evaluate if the letter D is chosen as the upper bound
        {
            upper_bound = 69.9;                         // Recall that we can ignore the higher letters (A, B & C)
        }
        if(arg3 == "F")                                 // F will be the lower bound as it's the only letter below D
        {
            lower_bound = 0;
        }        
        if (students_grades[i].average <= upper_bound && students_grades[i].average >= lower_bound)     // Only write to file
        {                                                                                               // Of the student with the
            outFile << students_grades[i].studentName << "," << students_grades[i].average << ",";      // grades between the bounds that argument sets
            outFile << calcLetter(students_grades[i].average) << endl;
        }
    }
    outFile.close();            // Close the file when finish
return 0;
}