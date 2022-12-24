/*
 *the class definition of MetroSim
 *it is a Simulator that could execute the commands
 * from main module, and print its state infomation.
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"

 // Put any other necessary includes here
#include "PassengerQueue.h"
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <map>
 // Put any other structs you need here

class MetroSim
{
public:

	MetroSim(std::ifstream& stationsFileStream, std::ofstream& outputFileStream);
	~MetroSim();
	///parse the command and then execute.
	void executeCommmand(std::string command);
	//print the state of Simulator after executing a command.
	void printStateInfo();

	// add a passenger to a station Queue. this will be called by executeCommand when the command is "p from to"
	void addPassenger(int id, int from, int to);
	//this will be called by executeCommand when the command is "m m"
	void move();

private:


	unsigned int passenger_ID;// id generator, each time invoke addPassenger() will get this auto increament id 
	std::ofstream &output; //output stream (bind the output Log files)
	unsigned int presentStation; //the station where the train stops at.
	std::map<int ,std::string> stationMap; //a map <station_ID, station_Name> to get the station name by its ID number.
	std::vector<PassengerQueue> stations; //each element of the vector is a PassengerQueue of station i, where i is the station ID.
	std::vector<PassengerQueue> train; //each element of the vector is a PassengerQueue dividing by the destnation station id
	//eg. train[i] means the Passengers whose destination are station i.
};

#endif
