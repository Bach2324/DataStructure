// CSCI 2270 -- Data Structures
// Assignment 1 -- Problem 1
// Bach Nguyen

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct studentData
{
    string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};

void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length)
{
    students[length].studentName = studentName;
    students[length].homework = homework;
    students[length].recitation = recitation;
    students[length].quiz = quiz;
    students[length].exam = exam;
    students[length].average = (homework + recitation + quiz + exam)/(double)4; 

return;
}
char calcLetter(double avg)
{
    if (avg >= (double)90)
    {
        return 'A';
    }
    else if (avg >= (double)80 && avg <= 89.9)
    {
        return 'B';
    }
    else if (avg >= (double)70 && avg <= 79.9)
    {
        return 'C';
    }
    else if (avg >= (double)60 && avg <= 69.9)
    {
        return 'D';
    }
return 'F';
}

void printList(const studentData students[], int length)
{

    for (int i = 0; i < length; i++)
    {
        cout << students[i].studentName << " earned " << students[i].average << " which is a(n) ";
        cout << calcLetter(students[i].average) << endl;
    }
return;
}
int main(int argc, const char *argv[])
{
    studentData students_grades[100];
    ifstream inFile(argv[1]);

    int count = 0;
    string line, name, hw, rec, quiz, exam;
    while(getline(inFile, line))
    {
        if (line.length() != 0)
        {
            stringstream s(line);
            getline(s, name, ',');
            getline(s, hw, ',');
            getline(s, rec, ',');
            getline(s, quiz, ',');
            getline(s, exam);
            addStudentData(students_grades, name, stoi(hw), stoi(rec), stoi(quiz), stoi(exam), count);
            count++;
        }
    }
    inFile.close();
    printList(students_grades, count);

    ofstream outFile(argv[2]);
    double upper_bound, lower_bound;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(argv[4], "A") == 0)
        {
            upper_bound = (double)100;
            if (strcmp(argv[3], "B") == 0)
            {
                lower_bound = (double)80;
            }
            else if (strcmp(argv[3], "C") == 0)
            {
                lower_bound = (double)70;
            }
            else if(strcmp(argv[3], "D") == 0)
            {
                lower_bound = (double)60;
            }
            else
            {
                lower_bound = (double)0;
            }
        }
        else if (strcmp(argv[4], "B") == 0)
        {
            upper_bound = 89.9;
            if (strcmp(argv[3], "C") == 0)
            {
                lower_bound = (double)70;
            }
            else if(strcmp(argv[3], "D") == 0)
            {
                lower_bound = (double)60;
            }
            else
            {
                lower_bound = (double)0;
            }
        }
        else if(strcmp(argv[4], "C") == 0)
        {
            upper_bound = 79.9;
            if(strcmp(argv[3], "D") == 0)
            {
                lower_bound = (double)60;
            }
            else
            {
                lower_bound = (double)0;
            }
        }
        else if (strcmp(argv[4], "D") == 0)
        {
            upper_bound = 69.9;
        }
        if (strcmp(argv[3], "F") == 0)
        {
            lower_bound = 0;
        }
        
        if (students_grades[i].average <= upper_bound && students_grades[i].average >= lower_bound)
        {
            outFile << students_grades[i].studentName << "," << students_grades[i].average << ",";
            outFile << calcLetter(students_grades[i].average) << endl;
        }
    }
    outFile.close();
return 0;
}