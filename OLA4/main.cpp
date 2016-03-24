// File:		ola4.cc
// Due Date:	March 24, 2016
// Author:		David Ludwig
// Description: From a file called "next.txt", which contains trip coordinates, calculate the distance between each of the trips from the previous, and add up the total distance of all of the trips combined
// Course:		CSCI 2170 - 004
// Input:		Data file of trips to take: "next.txt"
// Output:		The trip's coordinates, the distance from the last trip's coordinates, and the accumulated trip distance


// File includes
#include <fstream>
#include <iostream>
#include <iomanip>
#include "vehicletrack.h"


// Use the standard namespace
using namespace std;

// Declare constants
const char *TRIPS_FILE = "next.txt";

int main()
{
    // Declare the variables
    int x, y;
    int distance;
    ifstream tripsFile;

    // Create the vehicle
    VehicleTrack v;

    // Open the trips file
    tripsFile.open(TRIPS_FILE);

    // Read the first two values from the file
    tripsFile >> x >> y;

    // Print the table heading
    cout << setw(0) << "Current location" << setw(20) << "This trip" << setw(20) << "Accumulated trip" << endl;

    // Read until the end of the file
    while (!tripsFile.eof())
    {
        // Take the trip and get the distance
        distance = v.nextTrip(x, y);

        // Print the x and y of the trip
        cout << setw(7) << x << setw(5) << y;

        // Print the distance of the trip
        cout << setw(20) << distance;

        // Print the accumulated distance;
        cout << setw(18) << v.getTotalDistance() << endl;

        // Read the next trip
        tripsFile >> x >> y;
    }

    // Exit with no error
    return 0;
}
