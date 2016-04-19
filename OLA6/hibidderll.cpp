// File:		hibidderll.cc
// Author:		David Ludwig
// Description: A class registration system that registers students based on a 'bid' that they have earned through their semesters

// Include the header file
#include "hibidderll.h"

// Use the standard namespace
using namespace std;

HiBidderLL::HiBidderLL(string classId)
{
    // Store the class ID
    _classId = classId;

    // Initialize the list to empty
    _head = NULL;
}

string HiBidderLL::classId() const
{
    // Return the class id/name
    return _classId;
}

void HiBidderLL::print() const
{
    // Start with the head node
    RecordType *current = _head;

    // Print the header
    cout << "Students registered for " << _classId << endl;

    // Loop through the list until empty or the capacity is met
    for (int i = 0; i < _capacity && current != NULL; i++)
    {
        // Print the student
        cout << '\t'
             << current->bidAmount << "\t"
             << current->firstName << "\t"
             << current->lastName  << endl;

        // Get the next node
        current = current->next;
    }
}

void HiBidderLL::insertInOrder(RecordType *record)
{
    // Declare and initialize the current node
    RecordType *current = _head;

    // Check if the list is empty
    if (_head == NULL)

        // Set the head as the new record
        _head = record;

    // Check if the new record should be at the beginning of the list
    else if (record->bidAmount > _head->bidAmount)
    {
        // Set the record's next node as the current head
        record->next = _head;

        // Set the new record as the head
        _head = record;
    }
    else
    {
        // Loop until the we're at the location to insert the new record
        while (current->next != NULL && record->bidAmount < current->next->bidAmount)
        {
            // Get the next node
            current = current->next;
        }

        // Check if this is not the last node
        if (current->next != NULL)

            // Set the new record's next node
            record->next = current->next;

        // Set the next record to the new record
        current->next = record;
    }
}

void HiBidderLL::setCapacity(int capacity)
{
    // Set the class capacity
    _capacity = capacity;
}
