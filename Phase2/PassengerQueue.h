/*
 *the PassengerQueue class. This Class is a queue whose
 * element type is Passenger, it has the basic funtions
 * of queue data structure.
 * It is implemented by C++ STL <list>.
 */
#ifndef __PASSENGERQUEUE_H__
#define __PASSENGERQUEUE_H__
#include "Passenger.h"
#include <iostream>
#include <list>
class PassengerQueue {
private:
	std::list<Passenger> queue;

public:
	Passenger front();
	void dequeue();
	void enqueue(const Passenger& passenger);
	int size();
	void print(std::ostream& output);
};

#endif // !__PASSENGERQUEUE_H__
