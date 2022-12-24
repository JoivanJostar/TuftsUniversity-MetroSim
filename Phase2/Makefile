
CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow 
LDFLAGS  = -g3 
MetroSim: main.o MetroSim.o PassengerQueue.o Passenger.o
	$(CXX) $(CXXFLAGS) -o MetroSim $^ 


PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp
Passenger.o: Passenger.cpp Passenger.h
	$(CXX) $(CXXFLAGS) -c Passenger.cpp
MetroSim.o: MetroSim.cpp MetroSim.h PassengerQueue.h Passenger.h
	$(CXX) $(CXXFLAGS) -c MetroSim.cpp
main.o: main.cpp MetroSim.h
	$(CXX) $(CXXFLAGS) -c main.cpp



unit_test: unit_test_driver.o PassengerQueue.o Passenger.o MetroSim.o
	$(CXX) $(CXXFLAGS) $^


# This rule provides your final submission 
# NOTE: Don't forget to add any additional files you want to submit to this
#		rule! If you do not add them, they will not be submitted.
provide:
	provide comp15 proj1_MetroSim PassengerQueue.h \
				    PassengerQueue.cpp \
				    Passenger.h Passenger.cpp  \
				    MetroSim.h MetroSim.cpp \
				    main.cpp unit_tests.h \
				    Makefile README

clean: 
	rm *.o *~ *.gch a.out 
