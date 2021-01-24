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
    printList(students_grades, count);
return 0;
}