#include "ClassesImports.cpp"

int main(int argc, char* argv[]) {
	system("color 0D"); // For purple color of the text.
	
	int counter = 1;
	string input = "";
	string executableName = argv[0];

	Parser parser = Parser();
	LogicHandler logicHandler = LogicHandler();
	Printer printer = Printer(); 
	ErrorHandler errorHandler = ErrorHandler();
	FileHandler fileHandle = FileHandler();


	if (executableName == "sql-database.exe" && argc <= 6) 
	{
		printer.returnContinueStatement(1);
		printer.intro();

		while (true) {
			if (counter < argc) {
				string currentTextFile = argv[counter];
				input = fileHandle.inputFromCommandPrompt(currentTextFile);
				counter++;
			}
			if (input != "")
			{
				if (input == "exit") break;
				if (input == "clear") {
					system("CLS");
					input = "";
					continue;
				}
				try {

					string lowerCaseInput = parser.lowerCaseInput(input);
					parser.parse(lowerCaseInput);

					logicHandler.LogicCurrentArrayModifier(input);

					string firstElement = parser.getFirstInputElement(lowerCaseInput);
					string tableName = logicHandler.getTableName();
					logicHandler.tableLogicalChecks(firstElement, tableName);

					printer.print(input);
				}
				catch (exception const& e) {}
			}
			if (counter >= argc) {
				logicHandler.LogicTableNamesArrayModifier(fileHandle, true);
				cout << "Enter a command: ";
				getline(cin, input);
			}
		}
		printer.goodByeModel();
	}
	else cout << "The executable name introduced is incorrect! :(" << endl;
}