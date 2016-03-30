// File:		vehicletrack.cc
// Due Date:	April 5, 2016
// Author:		David Ludwig
// Description: Store information about a vehicle's distance between trips
// Course:		CSCI 2170 - 004

// Include the header file
#include "vehicletrack.h"

VehicleTrack::VehicleTrack()
{
    // Initialize the x and y coordinates
    x = y = 0;

    // Initialize the total distance
    totalDistance = 0;
}

int VehicleTrack::nextTrip(int newX, int newY)
{
    // Calculate the trip's distance
    distance = abs(newX - x) + abs(newY - y);

    // Add this distance to the total distance
    totalDistance += distance;

    // Set the new coordinates
    x = newX;
    y = newY;

    // Return the distance of this trip
    return distance;
}

int VehicleTrack::getLastTripDistance()
{
    // Return the distance of the last trip
    return distance;
}

int VehicleTrack::getTotalDistance()
{
    // Return the total distance
    return totalDistance;
}
