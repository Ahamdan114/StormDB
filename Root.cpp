#include <iostream>
#include <string>

#include "ErrorHandler.cpp";
#include "Print.cpp";
#include "ParsingChecker.cpp";
#include "LogicChecker.cpp";
#include "FileHandler.cpp";

using namespace std;

int main() {
	 string input = "";
	while (true) {
		cout << "Introdu o comanda: "; 
		getline(cin, input);
		if (input != "") {
			// Check-urile inputului.
			ErrorHandler errChecker = ErrorHandler(input);
			ParsingChecker parsingChecker = ParsingChecker(input);
			LoginChecker logicChecker = LoginChecker(input);
			FileHandler fileHandler = FileHandler(input);
			Print print = Print(input);
			// Ce e mai jos ignora
			cout << "Processing..." << endl;
			cout << "The input introduced is: " + errChecker.getInput() << endl;
		}
	}
}

// Structure:

// Printing  // FileHandler Adriana Vevo
// LogicChecker Maria
// Parsing Ahmed