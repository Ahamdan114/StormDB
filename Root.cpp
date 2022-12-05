#include <iostream>
#include <string>
#include <regex>

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
	int counter = 0;

	// Console Entrance
	while (true) {
		if (counter == 0) {
			cout << "Enter a command: ";
			counter = 1;
		}
		else cout << "Enter a new command: ";
		getline(cin, input);
		if (input != "") {
			try {
				string cleanInput = parser.cleanInput(input);
				parser.parse(cleanInput);
				cout << "The command introduced is: " << cleanInput << endl;

				// Next phase: maintenance;
			
				//logicHandler.logicHandler(cleanInput); 
				// printer.print(cleanInput)
				//fileHandle.fileHandle(string cleanInput)
			}
			catch (std::exception const& e) {
				// For next phases
			}
		}

		
	}
}
