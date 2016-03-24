// File:		ola3.cc
// Due Date:	March 15, 2016
// Author:		David Ludwig
// Description: From a file called 'scores.txt', find the students with the lowest and highest scores, and calculate the average of all of the students
// Course:		CSCI 2170 - 004
// Input:		Data file of students and scores: "scores.txt"
// Output:		The students with the lowest and highest score, and the average of all of the students

// Includes
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

// Use the standard namespace
using namespace std;

// Constants
const int    MAX_STUDENTS = 100;
const char*  SCORES_FILE  = "scores.txt";

// Define a student
struct Student
{
    int id;
    string firstName;
    string lastName;
    float score;
};


// Find the student with the lowest score
Student lowestScoreStudent(Student students[], int numStudents)
{
    // Set the first student as the lowest score
    Student student = students[0];

    // Loop through the students
    for (int i = 1; i < numStudents; i++)

        // Check if the student has a lower score
        if (student.score > students[i].score)

            // Set the new lowest student
            student = students[i];

    // Return the student
    return student;
}


// Find the student with the highest score
Student highestScoreStudent(Student students[], int numStudents)
{
    // Set the first student as the highest score
    Student student = students[0];

    // Loop through the students
    for (int i = 1; i < numStudents; i++)

        // Check if the student has a higher score
        if (student.score < students[i].score)

            // Set the new highest student
            student = students[i];

    // Return the student
    return student;
}


// Calculate the average of all of the students
float averageStudentScore(Student students[], int numStudents)
{
    // Declare and initialize the total
    float total = 0.0;

    // Loop through the students
    for (int i = 0; i < numStudents; i++)

        // Add the student's score to the total
        total += students[i].score;

    // Return the average
    return total / numStudents;
}


// Parse a student from the file
Student parseStudent(ifstream &scoreFile)
{
    // Declare a student
    Student student;

    // Read the student information from the file
    scoreFile >> student.id;
    scoreFile >> student.firstName;
    scoreFile >> student.lastName;
    scoreFile >> student.score;

    // Return the student
    return student;
}


// Main function
int main()
{
    // Declare variables
    Student students[MAX_STUDENTS];
    Student student;
    Student lowestStudent;
    Student highestStudent;
    ifstream scoreFile;
    int count = 0;

    // Open the scores file
    scoreFile.open(SCORES_FILE);

    // Parse and retrieve the student
    student = parseStudent(scoreFile);

    // Loop while there is data and while there is space available
    while (!scoreFile.eof() && count < MAX_STUDENTS)
    {
        // Add the student to the list
        students[count++] = student;

        // Parse the retrieve the student
        student = parseStudent(scoreFile);
    }

    // Close the scores file
    scoreFile.close();

    // Get the lowest student
    lowestStudent = lowestScoreStudent(students, count);

    // Get the highest student
    highestStudent = highestScoreStudent(students, count);

    // Print the student with the lowest score
    cout << "Lowest: \t" << lowestStudent.firstName << ' '
                       << lowestStudent.lastName  << ' '
                       << lowestStudent.score << endl;

    // Print the student with the highest score
    cout << "Highest:\t" << highestStudent.firstName << ' '
                        << highestStudent.lastName  << ' '
                        << highestStudent.score << endl;

    // Print the average of all of the students scores
    cout << setprecision(2) << fixed << "Average:\t" << averageStudentScore(students, count) << endl;

    // Exit with no error
    return 0;
}
