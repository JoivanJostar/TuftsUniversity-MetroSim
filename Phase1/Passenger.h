/*
 * the Passenger class. This is defined by a cpp struct
 * which contains the basic infomation of a pasenger
 * and a basic print function which will print its 
 * member infomation.
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{

    int id, from, to;

    Passenger()
    {
        id = -1;
        from = -1;
        to = -1;
    }

    Passenger(int newId, int arrivalStation, int departureStation)
    {
        id = newId;
        from = arrivalStation;
        to = departureStation;
    }

    // TODO: implement the print function in Passenger.cpp
    void print(std::ostream& output);

};

#endif
