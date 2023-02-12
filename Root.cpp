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
					string lowerCaseInput = parser.lowerCaseInput(input);
					parser.parse(lowerCaseInput);

					logicHandler.LogicCurrentArrayModifier(input);
					string firstElement = parser.getFirstInputElement(lowerCaseInput);
					string tableName = logicHandler.getTableName();
					if (firstElement == "create") {
						LogicalCheckingsCreate create = LogicalCheckingsCreate();
						create = logicHandler;
						create.tableLogicalChecks(tableName);
					}

					else if (firstElement == "drop")    {
						LogicalCheckingsDrop drop = LogicalCheckingsDrop();
						drop = logicHandler;
						drop.tableLogicalChecks(tableName);
					}

					else if (firstElement == "display") {
						LogicalCheckingsDisplay display = LogicalCheckingsDisplay();
						display = logicHandler;
						display.tableLogicalChecks(tableName);
					}

					else if (firstElement == "insert")  {
						LogicalCheckingsInsert insert = LogicalCheckingsInsert();
						insert = logicHandler;
						insert.tableLogicalChecks(tableName);
					}

					else if (firstElement == "select")  {
						LogicalCheckingsSelect select = LogicalCheckingsSelect();
						select = logicHandler;
						select.tableLogicalChecks(tableName);
					}

					else if (firstElement == "delete")  {
						LogicalCheckingsDelete deleteTable = LogicalCheckingsDelete();
						deleteTable = logicHandler;
						deleteTable.tableLogicalChecks(tableName);
					}

					else if (firstElement == "update")  {
						LogicalChekingsUpdate update = LogicalChekingsUpdate();
						update = logicHandler;
						update.tableLogicalChecks(tableName);
					}

					else if (firstElement == "import")  {
						LogicalCheckingsImport importCsv = LogicalCheckingsImport();
						importCsv = logicHandler;
						importCsv.tableLogicalChecks(tableName);
					}
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