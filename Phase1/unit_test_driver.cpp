/*
* this is a simple unit_test driver
* main function will call all the 
* test functions in unit_tests.h
*/

#include<iostream>
#include "unit_tests.h"
using namespace std;


int main() {
	try {
		testPassengerNoArgsConstructor();
		testPassengerConstructorWithArgs();
		testPassengerPrint();

		testPassengerQueue_enque();
		testPassengerQueue_front();
		testPassengerQueue_front_Empty();
		testPassengerQueue_deque();
		testPassengerQueue_deque_Empty();
		testPassengerQueue_size();
		testPassengerQueue_print();
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

}

