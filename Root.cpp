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
	DropTable dropTable = DropTable();
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
				cout << "Test for create table " << a << endl;
				bool b = select.testSelect(cleanInput);
				cout << "Test for select command " << b << endl;
				/*cout << a << endl;*/
				/*string output = logicHandler.handleLogic(cleanInput);
				printer.print(output);*/
				bool c = display.testDisplayTable(cleanInput);
				cout << "Test for display tab command "<<c << endl;
				bool d = deleteTab.testDeleteTable(cleanInput);
				cout << "Test for delete tab command "<<d << endl;
				bool e = updateTab.testUpdateTable(cleanInput);
				cout << "Test for update tab command "<< e << endl;
				bool f = insertus.InsertIntoTable(cleanInput);
				cout <<"Test for insert command "<< f << endl;
				bool g = dropTable.testDropTable(cleanInput);
				cout << "Test for dropt table command " << g << endl;
			}
			catch (std::exception const& e) {
				//errorHandler.handleError(err);
				std::cerr << e.what() << std::endl;
			}
		}

	}
}
