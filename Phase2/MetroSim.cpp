/*
 *the implementions of MetroSim (Simulator)
 */


#include "MetroSim.h"
#include "iostream"
#include <string>
#include <cstdio>
using namespace std;
MetroSim::MetroSim(std::ifstream& stationsFileStream, std::ofstream& outputFileStream) :
	output(outputFileStream)
{
	this->presentStation = 0;
	this->passenger_ID = 1;
	//init stations vector by read the stations file
	string line;
	int n = 0;
	while (!stationsFileStream.eof()) {
		getline(stationsFileStream, line);
		if (line != "") {
			this->stationMap[n++] = line;
			PassengerQueue empty_queue;
			stations.push_back(empty_queue);
			train.push_back(empty_queue);
		}
			
	}
	stationsFileStream.close();
	printStateInfo();

}
MetroSim::~MetroSim() {
	output.close();
}

void MetroSim::executeCommmand(string cmd) {
	//p ARRIVAL DEPARTURE
	if (cmd[0] == 'p') {
		int from, to;
		sscanf(cmd.c_str(), "p %d %d", &from, &to);
		if (from < 0 || to < 0) {
			cout << "Wrong station number with from " << from << " to " << to << endl;
			return;
		}
		addPassenger(this->passenger_ID, from, to);
		this->passenger_ID++; // dont forget!
	}
	else if (cmd == "m m") {
		move();
	}
	else if (cmd == "m f") {
		cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
		exit(0);
	}
	else {
		cerr << "unknown command :" << cmd << endl;
		return;
	}
}

void MetroSim::addPassenger(int id, int from, int to) {
	if (from < 0 || to < 0) return;
	Passenger p(id, from, to);
	this->stations[from].enqueue(p); //let this person enque the station queue.
}
void MetroSim::move() {
	//circulate
	unsigned int nextStation = (this->presentStation + 1) % stations.size();
	//leave the station
	PassengerQueue& passengerWaitingQueue = stations[presentStation];
	while (passengerWaitingQueue.size() != 0) {
		Passenger p=passengerWaitingQueue.front();
		passengerWaitingQueue.dequeue();
		train[p.to].enqueue(p);// board
	}
	//arrive at the next station
	presentStation=nextStation;
	PassengerQueue& passengerExitQueue = train[presentStation];
	while (passengerExitQueue.size() != 0) {
		Passenger p = passengerExitQueue.front();
		passengerExitQueue.dequeue();
		//Passenger ID left train at station STATION_NAME
		output << "Passenger " << p.id << " left train at station " << stationMap[presentStation] << endl;
	}

}
void MetroSim::printStateInfo(){
	//print the Passengers on the train  in ascending order based on the destination Station.
	cout << "Passengers on the train: {";

	for (size_t i = 0; i < train.size(); ++i) {
		train[i].print(cout);
	}
	cout << "}" << endl;

	//print the Staion info
	for (size_t i = 0; i < stations.size(); ++i) {
		string prefix;
		if (presentStation != i) {
			prefix = "       ";
		}
		else {
			prefix = "TRAIN: ";
		}
		cout << prefix << "[" << i << "] " << stationMap[(int)i] << " " << "{";
		stations[i].print(cout);
		cout << "}" << endl;
	}
}