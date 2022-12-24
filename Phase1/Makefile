
CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow 
LDFLAGS  = -g3 
unit_test: unit_test_driver.o PassengerQueue.o Passenger.o
	$(CXX) $(CXXFLAGS) $^ 

PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp
Passenger.o: Passenger.cpp Passenger.h
	$(CXX) $(CXXFLAGS) -c Passenger.cpp


# This rule provides your final submission 
# NOTE: Don't forget to add any additional files you want to submit to this
#		rule! If you do not add them, they will not be submitted.
provide:
	provide comp15 proj1_MetroSim PassengerQueue.h \
				    PassengerQueue.cpp \
				    Passenger.h Passenger.cpp  \
				    unit_tests.h Makefile README

clean: 
	rm *.o *~ *.gch a.out 
