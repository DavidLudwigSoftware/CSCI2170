// File:		ola6.cc
// Due Date:	April 19, 2016
// Author:		David Ludwig
// Description: A class registration system that registers students based on a 'bid' that they have earned through their semesters
// Course:		CSCI 2170 - 004
// Input:		Data file of students: "registration.txt", and the class capacity (the capacity is assumed for all of the classes)
// Output:		All of the classes, and the students registered for those classes

// Include dependencies
#include <iostream>
#include <fstream>
#include <string.h>
#include "hibidderll.h"

// Use the standard namespace
using namespace std;

// Define constants
const char *REGISTRATION_FILE  = "registration.txt";
const string CLASSES[]         = {"cs1001", "cs1013", "cs1022", "cs1067"};
const int    NUM_CLASSES       = 4;

int main()
{
    // Declare variables
    int capacity;
    string classId;
    ifstream infile;
    RecordType *record;
    HiBidderLL classes[NUM_CLASSES];

    // Loop through the class list
    for (int i = 0; i < NUM_CLASSES; i++)

        // Create the class
        classes[i] = HiBidderLL(CLASSES[i]);

    // Open the registration file
    infile.open(REGISTRATION_FILE);

    // Create a new record
    record = new RecordType;

    // Prime read the file
    infile >> record->bidAmount;
    infile >> classId;
    infile >> record->firstName;
    infile >> record->lastName;

    // Read the registration
    while (!infile.eof())
    {
        // loop through the classes
        for (int i = 0; i < NUM_CLASSES; i++)

            // check if this is the correct class
            if (classes[i].classId() == classId)

                // Add the student to the class
                classes[i].insertInOrder(record);

        // Create a new record
        record = new RecordType;

        // Read the next line
        infile >> record->bidAmount;
        infile >> classId;
        infile >> record->firstName;
        infile >> record->lastName;
    }

    // Delete the current/blank record
    delete record;

    // Close the registration file
    infile.close();

    // Get the classes capacities
    cout << "Enter the number of seats available for each class: ";
    cin >> capacity;

    // Loop through each of the classes
    for (int i = 0; i < NUM_CLASSES; i++)
    {
        // Space the classes
        cout << endl;

        // Set the class capacity
        classes[i].setCapacity(capacity);

        // Print the registered students
        classes[i].print();
    }

    // Exit with no error
    return 0;
}
