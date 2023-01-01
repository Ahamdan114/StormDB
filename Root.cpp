#include "ClassesImports.cpp"

int main(int argc, char* argv[]) {
	// For purple color of the text.
	system("color 0D"); 

	string input = "";
	string executableName = argv[0];
	int counter = 1;

	Parser parser = Parser();
	LogicHandler logicHandler = LogicHandler();
	Printer printer = Printer(); 
	ErrorHandler errorHandler = ErrorHandler();
	FileHandler fileHandle = FileHandler();
	
	
	/*for (int i = 0; i < argc; i++) {
		cout << "ELEMENT: " << argv[i] << endl;
	}
	cout << executableName << " sql-database.exe" << endl 
		 << "argc: " << argc << endl;

	if (executableName == "sql-database.exe" && argc <= 6) */
	{
		while (true) {
			// logicHandler.dataReloader();
			logicHandler.LogicTableNamesArrayModifier(fileHandle);
			cout << "END" << endl;
			if (counter < argc) {
				string currentTextFile = argv[counter];
				input = fileHandle.inputFromCommandPrompt(currentTextFile);
				counter++;
			}
			if (input != "")
			{  
				if (input == "exit") break;
				if (input == "clear") {
					for (int i = 0; i < 50; i++) cout << endl << endl;
					input = "";
					continue;
				}
				try {

					string lowerCaseInput = parser.lowerCaseInput(input);
					parser.parse(lowerCaseInput);

					logicHandler.LogicCurrentArrayModifier(input);
					printer.print(input);

					string firstElement = parser.getFirstInputElement(lowerCaseInput);
					string tableName = logicHandler.getTableName(logicHandler.getCurrentArrSize());
					logicHandler.tableNameCheck(firstElement, tableName);

					cout << "ROOT -> The name of the table is: " << tableName << endl;
					cout << "ROOT -> The first element of the table is: " << firstElement << endl;
				}
				catch (exception const& e) {
					// For next phases
				}
			}
			if (counter >= argc) {
				cout << "Enter a command: ";
				getline(cin, input);
			}
		}
		// logicHandler.dataSaver();
		printer.goodByeModel();
	}
}