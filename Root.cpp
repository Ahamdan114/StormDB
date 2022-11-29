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
	string input = "";
	Parser parser = Parser();
	LogicHandler logicHandler = LogicHandler();
	Printer printer = Printer();
	ErrorHandler errorHandler = ErrorHandler();
	CreateTable testCreateTable = CreateTable();

	while (true) {
		cout << "Introdu o comanda: "; 
		getline(cin, input);
		if (input != "") {
			
			try {
				string cleanInput = parser.cleanInput(input);
				cout << cleanInput << endl;
				//parser.parse(cleanInput);
				/*testCreateTable.testCreateTable(input);*/
				bool a= testCreateTable.testCreateTable(cleanInput);

				/*string output = logicHandler.handleLogic(cleanInput);
				printer.print(output);*/
			}
			catch (string err) {
				errorHandler.handleError(err);
			}
		}

	}
}
