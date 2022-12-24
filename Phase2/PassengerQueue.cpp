/*
 *the PassengerQueue class implemation.
 * All of the interfaces are implemented base on
 * C++ STL list interface.
 */
#include"PassengerQueue.h"
#include "iostream"
#include <exception>
using namespace std;
/// <summary>
/// Returns, but does not remove, the element at the front of the queue
/// </summary>
/// <returns> the Passenger Object at the front of the queue</returns>
Passenger PassengerQueue::front() {
	if (!this->queue.empty()) {
		return this->queue.front();
	}
	else
	{
		throw runtime_error("get element from an empty list");
	}
}
/// <summary>
/// Removes the element at the front of the queue
/// </summary>
void PassengerQueue::dequeue() {
	if (!this->queue.empty()) {
		return this->queue.pop_front();
	}
	else
	{
		throw runtime_error("pop element from an empty list");
	}
}
/// <summary>
/// Inserts a new passenger at the end of the queue
/// </summary>
/// <param name="passenger"> a const ref to a Passenger Object.
/// it will insert a copy Object of this Passenger into the queue </param> 
void PassengerQueue::enqueue(const Passenger& passenger) {
	this->queue.push_back(passenger);
}

/// <summary>
/// Prints each Passenger in the PassengerQueue to the given output
/// stream from front to back, with no spaces in betweenand no trailing
/// newline.For example :[1, 1->2][2, 1->3][3, 2->3]
/// </summary>
void PassengerQueue::print(ostream& output) {
	for (auto it = this->queue.begin(); it != this->queue.end(); ++it) {
		it->print(output);
	}
}
/// <summary>
/// Returns the number of elements in the queue
/// </summary>
/// <returns></returns>
int PassengerQueue::size() {
	return (int)this->queue.size();
}



