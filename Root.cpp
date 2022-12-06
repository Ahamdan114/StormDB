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
	int counter = 0;

	// Console Entrance
	while (true) {
		
	
		if (fileHandle.fileHandle() != "") { 
			input = fileHandle.fileHandle(); 
		}
		else 
		{
			getline(cin, input);

			if (counter == 0) {
				cout << "Enter a command: ";
				counter = 1;
			}
			else cout << "Enter a new command: ";
		}
		//getline(cin, input);
		if (input != "")
		{  
			try {
				if (input == "exit") break;
				string cleanInput = parser.cleanInput(input);
				parser.parse(cleanInput);
				cout << "The command introduced to lowercase is: " << cleanInput << endl;

				// Next phase: maintenance;

				//logicHandler.logicHandler(cleanInput); 
				// printer.print(cleanInput)
				

			}
			catch (std::exception const& e) {
				// For next phases
			}
		}

		
	}
}
