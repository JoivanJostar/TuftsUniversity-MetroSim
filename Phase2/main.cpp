/*
 *Main module
 *this module will parse the command line arguments
 * and then creates Simulator, gets commands from user
 * and then pass them to the Simulator to execute.
 */


#include<iostream>
#include<cassert>
#include "MetroSim.h"
#include <fstream>
#include <memory>
using namespace std;

ifstream stationFileInStream;
ifstream commandInStream;
ofstream outputFileOutStream;
bool useFileCommand = false;
void ParseArgment(int argc,char * argv[]) {
	string stationFile, outputFile, commandsFile;
	if (argc != 3 && argc != 4) {
		cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]" << endl;
		exit(0);
	}
	stationFile = argv[1];
	stationFileInStream.open(stationFile);
	if (!stationFileInStream.is_open()) {
		cerr << "Error: could not open file " << stationFile << endl;
		exit(0);
	}
	outputFile = argv[2];
	outputFileOutStream.open(outputFile);
	if (!outputFileOutStream.is_open()) {
		cerr << "Error: could not open file " << outputFile << endl;
		exit(0);
	}

	if (argc == 4) {
		useFileCommand = true;
		commandsFile = argv[3];
		commandInStream.open(commandsFile);
		if (!commandInStream.is_open()) {
			cerr << "Error: could not open file " << commandsFile << endl;
			exit(0);
		}
	}
	else {
		useFileCommand = false;
	}
}

int main(int argc,char * argv[]) {
	//Usage : ./ MetroSim stationsFile outputFile [ commandsFile ]
	
	ParseArgment(argc, argv);
	shared_ptr<MetroSim> simulator = make_shared<MetroSim>(stationFileInStream, outputFileOutStream);
	string cmd;
	if (useFileCommand) {
		while (!commandInStream.eof()) {
			cout << "Command? ";
			getline(commandInStream, cmd);
			simulator->executeCommmand(cmd);
			simulator->printStateInfo();
		}
		cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
		commandInStream.close();
	}
	else {
		while (true) {
			cout << "Command? ";
			getline(cin, cmd); //get command from cin
			simulator->executeCommmand(cmd);
			simulator->printStateInfo();
		}

	}
}

