// File:		vehicletrack.h
// Due Date:	March 24, 2016
// Author:		David Ludwig
// Description: Store information about a vehicle's distance between trips
// Course:		CSCI 2170 - 004

#ifndef VEHICLETRACK_H
#define VEHICLETRACK_H

// Includes
#include <iostream>
#include <cmath>

// Use the standard namespace
using namespace std;

class VehicleTrack
{
public:

    // Default constructor
    VehicleTrack();

    // Take the next trip, and return the distance
    int nextTrip(int newX, int newY);

    // Get the last trip's distance
    int getLastTripDistance();

    // Get the accumulated distance
    int getTotalDistance();

private:

    // Data variables
    int x, y;
    int distance;
    int totalDistance;
};

#endif // VEHICLETRACK_H
