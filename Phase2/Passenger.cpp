/*
 *the implement of Passenger.
 */

#include <iostream>
#include <string>
#include "Passenger.h"

/// <summary>
/// print the passenger info
///[PASSENGER_ID, ARRIVAL->DEPARTURE]
/// </summary>
/// <param name="output"></param> the outputStream object to output the info
void Passenger::print(std::ostream& output)
{
    // TODO: print passenger information to the output stream
    //       as described in the assignment specification
    output << "[" << id << ", " << from << "->" << to << "]";
}
