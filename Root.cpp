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
	Select select = Select();
	DisplayTable display = DisplayTable();
	DeleteTable deleteTab = DeleteTable();
	UpdateTable updateTab = UpdateTable();
	Insert insertus = Insert();

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
				bool b = select.testSelect(cleanInput);
				cout << b << endl;
				/*string output = logicHandler.handleLogic(cleanInput);
				printer.print(output);*/
				bool c = display.testDisplayTable(cleanInput);
				cout << c << endl;
				bool d = deleteTab.testDeleteTable(cleanInput);
				cout << d << endl;
				bool e = updateTab.testUpdateTable(cleanInput);
				cout << e << endl;
				bool f = insertus.InsertIntoTable(cleanInput);
				cout << f << endl;
			}
			catch (string err) {
				errorHandler.handleError(err);
			}
		}

	}
}
