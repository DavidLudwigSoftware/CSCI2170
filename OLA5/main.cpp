// File:		ola5.cc
// Due Date:	April 5, 2016
// Author:		David Ludwig
// Description: A taxi system that dispatches a set number of vehicles to customers and keeps track of each of the vehicle's trip distances
// Course:		CSCI 2170 - 004
// Input:		Data file of trips to take: "nextMulti.txt"
// Output:		The trip's coordinates, the distance from the last trip's coordinates, the accumulated trip distance of each car in the order that it is dispatched


// File includes
#include <fstream>
#include <iostream>
#include <iomanip>
#include "vehicletrack.h"


// Use the standard namespace
using namespace std;

// Declare constants
const char *TRIPS_FILE = "nextMulti.txt";
const int NUM_VEHICLES = 5;

int main()
{
    // Declare the variables
    int v = 0;
    int x, y;
    int distance;
    ifstream tripsFile;

    // Create the vehicles
    VehicleTrack vehicles[NUM_VEHICLES];

    // Open the trips file
    tripsFile.open(TRIPS_FILE);

    // Read the first two values from the file
    tripsFile >> x >> y;

    // Print the table heading
    cout << setw(0) << "Current location"
         << setw(20) << "This trip"
         << setw(20) << "Accumulated trip"
         << setw(12) << "Vehicle"
         << endl;

    // Read until the end of the file
    while (!tripsFile.eof())
    {
        // Take the trip and get the distance
        distance = vehicles[v % NUM_VEHICLES].nextTrip(x, y);

        // Print the x and y of the trip
        cout << setw(7) << x << setw(5) << y;

        // Print the distance of the trip
        cout << setw(20) << distance;

        // Print the accumulated distance;
        cout << setw(18) << vehicles[v % NUM_VEHICLES].getTotalDistance();

        // Print the vehicle letter ID
        cout << setw(15) << char(65 + (v++ % NUM_VEHICLES)) << endl;

        // Read the next trip
        tripsFile >> x >> y;
    }

    // Exit with no error
    return 0;
}
