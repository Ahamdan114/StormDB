#include <iostream>
#include <string>

#include "ErrorHandler.cpp"
#include "Printer.cpp"
#include "Parser.cpp"
#include "LogicHandler.cpp"
#include "FileHandler.cpp"

using namespace std;

int main() {
	string input = "";
	Parser parser = Parser();
	LogicHandler logicHandler = LogicHandler();
	Printer printer = Printer();
	ErrorHandler errorHandler = ErrorHandler();

	while (true) {
		cout << "Introdu o comanda: "; 
		getline(cin, input);
		if (input != "") {
			// Input checking.
			try {
				string cleanInput = parser.cleanInput(input);
				parser.parse(cleanInput);
				/*string output = logicHandler.handleLogic(cleanInput);
				printer.print(output);*/
			}
			catch (string err) {
				errorHandler.handleError(err);
			}
		}
	}
}
