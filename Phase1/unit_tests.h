/*
* unit tests file
* this file contains all the test functions 
* of this project.
*/

#include"Passenger.h"
#include <cassert>
#include <iostream>
#include "PassengerQueue.h"

//---------------test Passenger---------------------
/// <summary>
/// test the Passenger()
/// </summary>
void testPassengerNoArgsConstructor() {
	std::cout << "testPassenger()" << std::endl;
	Passenger p;
	assert(-1 == p.from && -1 == p.id && -1 == p.to);
	std::cout << "testPass" << std::endl;
}
/// <summary>
/// test the  Passenger(int newId, int arrivalStation, int departureStation)
/// </summary>
void testPassengerConstructorWithArgs() {
	std::cout << "test Passenger(int newId, int arrivalStation, int departureStation)" << std::endl;
	Passenger p(1,0,2);
	assert(1 == p.id && 0==p.from &&2 == p.to);
	std::cout << "testPass" << std::endl;
}
/// <summary>
/// test the Passenger Print() it will print the info using a output stream
/// </summary>
void testPassengerPrint() {
	
	std::cout << "test print(std::ostream & output); with id=1 from=0 to=2" << std::endl;
	Passenger p(1, 0, 2);
	std::cout << "print result: ";
	p.print(std::cout);
	std::cout << std::endl;
	std::cout << "testPass" << std::endl;
}


//--------------test PassengerQueue------------------

/// <summary>
/// test the  PassengerQueue::enque(Passenger)
/// </summary>
void testPassengerQueue_enque() {
	std::cout << "test PassengerQueue::enque(Passenger)" << std::endl;
	Passenger p1(1, 1, 2);
	Passenger p2(2, 2, 3);
	Passenger p3(3, 3, 2);
	PassengerQueue queue;
	queue.enqueue(p1);
	queue.enqueue(p2);
	queue.enqueue(p3);
	std::cout << "testPass" << std::endl;
}
/// <summary>
/// test PassengerQueue::front() 
/// </summary>
void testPassengerQueue_front() {
	std::cout << "test PassengerQueue::front()" << std::endl;
	Passenger p1(1, 1, 2);
	Passenger p2(2, 2, 3);
	Passenger p3(3, 3, 2);
	PassengerQueue queue;
	std::cout << "enque 3 passenger:";
	p1.print(std::cout); p2.print(std::cout); p3.print(std::cout);
	queue.enqueue(p1);
	queue.enqueue(p2);
	queue.enqueue(p3);
	std::cout << std::endl << "call front()" << std::endl;
	try {
		queue.front().print(std::cout);
	}
	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "testPass" << std::endl;
}
/// <summary>
/// an edge test trying calling front() 
/// from an empty queue
/// </summary>
void testPassengerQueue_front_Empty() {
	std::cout << "test PassengerQueue::front() in empty queue" << std::endl;
	PassengerQueue queue;
	try {
		queue.front().print(std::cout);
	}
	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "testPass" << std::endl;
}
/// <summary>
/// test PassengerQueue::deque()
/// </summary>
void testPassengerQueue_deque() {
	std::cout << "test PassengerQueue::deque() " << std::endl;
	Passenger p1(1, 1, 2);
	Passenger p2(2, 2, 3);
	Passenger p3(3, 3, 2);
	PassengerQueue queue;

	queue.enqueue(p1);
	queue.enqueue(p2);
	queue.enqueue(p3);
	try {
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		assert(queue.size() == 0);
	}
	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "testPass" << std::endl;
}
/// <summary>
/// an edge test . try calling PassengerQueue::deque() 
/// from an empty queue. This will catch an exception,
/// </summary>
void testPassengerQueue_deque_Empty() {
	std::cout << "test PassengerQueue::deque() in empty queue" << std::endl;
	PassengerQueue queue;
	try {
		queue.dequeue();
	}
	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "testPass" << std::endl;
}
/// <summary>
/// test PassengerQueue::size()
/// </summary>
void testPassengerQueue_size() {
	std::cout << "test PassengerQueue::size()" << std::endl;
	PassengerQueue queue;
	assert(queue.size() == 0);
	Passenger p1(1, 1, 2);
	queue.enqueue(p1);
	assert(queue.size() == 1);
	std::cout << "testPass" << std::endl;
}
/// <summary>
/// test PassengerQueue::print(ostream &)
/// </summary>
void testPassengerQueue_print() {
	std::cout << "test PassengerQueue::print(ostream &)" << std::endl;
	Passenger p1(1, 1, 2);
	Passenger p2(2, 2, 3);
	Passenger p3(3, 3, 2);
	PassengerQueue queue;
	std::cout << "enque 3 passenger:";
	p1.print(std::cout); p2.print(std::cout); p3.print(std::cout);
	queue.enqueue(p1);
	queue.enqueue(p2);
	queue.enqueue(p3);

	std::cout << std::endl << "the print result :";
	queue.print(std::cout);
	std::cout << std::endl;
	std::cout << "testPass" << std::endl;
}