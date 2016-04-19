// File:		hibidderll.h
// Author:		David Ludwig
// Description: A class registration system that registers students based on a 'bid' that they have earned through their semesters

#ifndef HIBIDDERLL_H
#define HIBIDDERLL_H

// Include dependencies
#include <iostream>
#include <string>

// Use the standard namespace
using namespace std;

struct RecordType
{
    int bidAmount;
    string firstName;
    string lastName;
    RecordType *next;
};


class HiBidderLL
{
public:
    HiBidderLL(string classId = "");

    string classId() const;

    void insertInOrder(RecordType *record);
    void setCapacity(int capacity);
    void print() const;

private:
    // Head node of the list
    RecordType *_head;

    // Store the class capacity
    int _capacity;

    // Store the class id/name
    string _classId;

};

#endif // HIBIDDERLL_H
