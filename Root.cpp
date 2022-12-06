#include <iostream>
#include <string>
#include <regex>
#include<fstream>

#include "ErrorHandler.cpp"
#include "Printer.cpp"
#include "Parser.cpp"
#include "LogicHandler.cpp"
#include "FileHandler.cpp"
using namespace std;

int main() {

	// Input and Objects initialization.
	string input = "";
	Parser parser = Parser();
	LogicHandler logicHandler = LogicHandler();
	Printer printer = Printer();
	ErrorHandler errorHandler = ErrorHandler();
	FileHandler fileHandle = FileHandler();
	int counter = 1;
	
	if (fileHandle.inputFromFile() != "") input = fileHandle.inputFromFile();
	if (input == "") cout << "Input from file is: inexistent " << endl;
	else cout << "Input from file is: " << input << endl;
	// Console Entrance
	while (true) {
		if (input != "")
		{  
			if (input == "exit") break;
			try {
				string cleanInput = parser.cleanInput(input);
				parser.parse(cleanInput);
				cout << "Command details -> The command introduced to lowercase is: " << cleanInput << endl;

				// Next phase: maintenance;

				//logicHandler.logicHandler(cleanInput); 
				// printer.print(cleanInput)
				

			}
			catch (std::exception const& e) {
				// For next phases
			}
		}

		if (counter > 0) {
			cout << "Enter a new command: ";
			counter = 0;
		}
		else cout << "Enter a command: ";
		getline(cin, input);
		
	}

	cout << "##############" << endl;
	cout << "## Goodbye! ##" << endl;
	cout << "##############" << endl;
}
