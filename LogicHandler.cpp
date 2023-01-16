#pragma once
#pragma warning ( disable : 4018 )

#include "Imports.cpp"
#include "FileHandler.cpp"
#include "ErrorHandler.cpp"

class LogicHandler {
protected:

	string* tableNames = nullptr;
	int tableSize = 0;

	string* currentArr = nullptr;
	int currentSize = 0;

	Printer printer = Printer();
	ErrorHandler errorHandler = ErrorHandler();

public:

	LogicHandler() {}

	// The method removes spaces from the given input
	string removeSpaces(string input) {
		char comparison = ' ';
		string removeSpacesArr = "";
		int startingIndex = 0;

		for (unsigned int i = 0; i < input.length() + 1; i++) {
			if (input[i] != comparison) {
				startingIndex = i;
				break;
			}
		}
		for (unsigned int i = startingIndex; i < input.length() + 1; i++) {
			if (input[i] != comparison) removeSpacesArr += input[i];
			else {
				if (i == input.length() + 1) break;
				if (input[i - 1] != ',' && input[i - 1] != '(' && input[i + 1] != ',' && input[i + 1] != ')') {
					if (input[i] == comparison && input[i + 1] != comparison) removeSpacesArr += input[i];
				}
			}
		}

		input = comparison = startingIndex = NULL;
		return removeSpacesArr;
	}

	// The method find the size of a given input
	int sizeDiscovery(string input) {
		int size = 0;

		for (unsigned int i = 0; i < input.length() + 1; i++) {
			if (input[i] == ' ' || input[i] == ',') size++;
		}

		return size;
	}

	// The method creates a dynamic size current array
	void currentArrCreate(int size) {
		if (this->currentArr != nullptr) {
			delete[] this->currentArr;
			this->currentArr = nullptr;
		}
		this->currentArr = new string[size];
	}

	// The method sets the current array values
	void setCurrentArr(string input) {
		int j = 0;
		string tempStr = "";

		for (unsigned int i = 0; i < input.length() - 1; i++) {
			if (input[i] != '(' && input[i] != ')') {
				if (input[i] == ' ' || input[i] == ',') {
					this->currentArr[j] = tempStr;
					tempStr = "";
					j++;
				}
				else tempStr += input[i];
			}
		}
		this->currentArr[j] = tempStr;
	}

	// The method converts the string input to uppercase letters
	string stringToUpper(string input)
	{
		string response = "";
		for (unsigned int i = 0; i < input.length(); i++)
		{
			if (input[i] >= 'a' && input[i] <= 'z')response += (input[i] - 32);
			else response += input[i];
		}
		return response;
	}

	// The method converts the string input to lowercasw letters
	string lowerCaseInput(string input) {
		for (unsigned int i = 0; input[i] != '\0'; i++) if (input[i] >= 'A' && input[i] <= 'Z') input[i] = input[i] + 32;
		return input;
	}

	// The method finds the table name
	string findTableName(int size) {
		string tableName = "";
		string firstCheck = stringToUpper(currentArr[0]);

		if ((firstCheck) == "SELECT") 
		{
		for (int i = 0; i < size; i++) {
			string secondCheck = stringToUpper(this->currentArr[i]);
			if (secondCheck == "FROM") {
				tableName = this->currentArr[i + 1];
			      }
		    }
	    }
		
		else if (firstCheck == "UPDATE" || firstCheck =="IMPORT") tableName = this->currentArr[1];
		else tableName = this->currentArr[2];
		return tableName;
	}

	// The method gets the table name
	string getTableName() {
		return findTableName(getCurrentArrSize());
	}

	// The method gets the current array size
	int getCurrentArrSize() {
		return this->currentSize;
	}

	// The method creates a dynamic current array with the given input values words on each index position							-> Main method
	void LogicCurrentArrayModifier(string input) {

		// Input cleaning and size finding of currentArr

		string RemoveSpacesFromInput = removeSpaces(input);
		this->currentSize = sizeDiscovery(RemoveSpacesFromInput) + 1;
		
		// Setting the array

		currentArrCreate(this->currentSize);
		setCurrentArr(RemoveSpacesFromInput);

		// Printing part
		this->printer.returnContinueStatement(2);
		cout << getTableName() << endl;
		this->printer.returnContinueStatement(3);

		for (int i = 0; i < this->currentSize; i++) cout << this->currentArr[i] << " ";
		cout << endl;
	}


	// The method returns the size of table names
	int getTableSize() {
		return this->tableSize;
	}
	
	// The method checks if the table given exists or not
	 bool checkTabelExists(string tableName)
	 {
		for (int i = 0; i < getTableSize(); i++) {
			if (this->tableNames[i] == tableName) return true;
		}
		return false;
	}

	// The method gets all the table names in the project
	string getTableNames(FileHandler& handlingFile) {
		return handlingFile.inputFromFile("TableNames.txt");
	}

	// The method find the size of the table names
	void setTableNamesSize(FileHandler& handlingFile, string tableNames) {

		this->tableSize = 0;
		const char comparisonSpace = ' ';

		for (unsigned int i = 0; i < tableNames.length(); i++) {
			if (tableNames[i] == comparisonSpace) this->tableSize++;
		}
	}

	// The method creates a dynamic size current array
	void tableNameArrCreate() {
		delete[] this->tableNames;
		this->tableNames = new string[getTableSize()];
	}

	// The method sets the tableNames array values
	void setTableNames(string tableNames) {
		int j = 0;
		const char comparisonSpace = ' ';
		string tempStr = "";

		for (int i = 0; i < tableNames.length(); i++) {
			if (tableNames[i] == comparisonSpace) {
				this->tableNames[j] = tempStr;
				tempStr = "";
				j++;
			}
			else tempStr += tableNames[i];
		}
	}

	// The method creates a dynamic array containing a table name on each index position											-> Main method
	void LogicTableNamesArrayModifier(FileHandler& handlingFile, bool writeStatus = false) {
		string tableNames = getTableNames(handlingFile);
		setTableNamesSize(handlingFile, tableNames);
		tableNameArrCreate();
		setTableNames(tableNames);

		// Printing tableNames array 
		if (writeStatus == true) {
			if (!(getTableSize())) this->printer.returnContinueStatement(4);
			else {
				this->printer.returnContinueStatement(5);
				for (int z = 0; z < getTableSize(); z++) cout << this->tableNames[z] << " | ";
			}
			this->printer.returnContinueStatement(6);
			cout << getTableSize() << endl << endl;
		}
	}

	// The method handles the logic create command checks
	void LogicalCheckingsCreate() {
		int i = 3;
		if (stringToUpper(this->currentArr[3]) == "IF") i = 6;

		for (i; i < this->currentSize; i = i + 4) {

			int dimension = atoi(this->currentArr[i + 2].c_str()); // The dimension identifiable value
			int introducedValue = this->currentArr[i+3].length(); // The value given for determining the dimension
			string expression3 = "[0-9]+\\.[0-9]+"; // Float Check
			
			// Checking if the name fits it's set dimension

			if (introducedValue > dimension) this->errorHandler.ErrorsList(2);

			// Checking the type match if type is integer (or int).

			if (this->currentArr[i + 1] == "integer") {

				string firstLength = to_string(this->currentArr[i + 3].length());
				int number = atoi(this->currentArr[i + 3].c_str());
				string secondLength = to_string(to_string(number).length());

				if (firstLength != secondLength) this->errorHandler.ErrorsList(3);
			}
			else if (this->currentArr[i + 1] == "float")
			{
				bool isFloatCurrentArr = regex_match(this->currentArr[i + 3].c_str(), regex(expression3));
				if (!isFloatCurrentArr) this->errorHandler.ErrorsList(4);
			}

			// Checking the type match if type is text (or string).

			else if (this->currentArr[i + 1] == "text") {

				const char quoteCheck = (this->currentArr[i + 3].c_str())[0];
				string quotesCheck = this->currentArr[i + 3];
				if (quoteCheck != '\'' && quotesCheck != "\"") this->errorHandler.ErrorsList(5);
			}
		}
	}

	// The method requests the logic of command CREATE and continues the process based on the response
	void createTableElement(string tableName) {

		// Searching for element ( We don't want to find it )

		for (int i = 0; i < getTableSize(); i++) {
			if (tableName == this->tableNames[i]) this->errorHandler.ErrorsList(6);
		}

		// Element not found, so continue

		FileHandler fileHandle = FileHandler();
		
		LogicalCheckingsCreate();
		fileHandle.tableNameToFile(tableName);
		fileHandle.createTableFile(this->currentArr, getCurrentArrSize(), tableName);
	}

	// The method requests the logic of command DROP and continues the process based on the response
	void dropTableElement(string tableName) {

		bool finderState = false;

		// Searching for element ( We want to find it. )

		for (int i = 0; i < getTableSize(); i++) {
				
			if (tableName == this->tableNames[i]) {
				// Element found, so continue 

				finderState = true;

				for (int j = i; j < getTableSize() - 1; j++) {
					this->tableNames[j] = this->tableNames[j + 1];
				}

				this->tableNames[getTableSize() - 1] = "";

				FileHandler fileHandle = FileHandler();
				
				// Calling for TableNames array

				fileHandle.suprascriptionTable(this->tableNames, "TableNames", getTableSize());
				fileHandle.dropTableFile(tableName);
			}
		}

		if (!finderState) throw "Elementul cautat nu exista!";
	}

	// The method requests the logic of command DISPLAY and continues the process based on the response
	void displayTableElement(string tableName) {

		bool finderState = false;

		// Searching for element ( We want to find it. )

		for (int i = 0; i < getTableSize(); i++) {
			if (tableName == this->tableNames[i]) {
				// Element found, so continue 

				finderState = true;

				FileHandler fileHandle = FileHandler();
				fileHandle.displayTableFile(tableName);
			}
		}

		if (!finderState) throw "Elementul cautat nu exista!";
	}
	
	// The method handles the logic insert command checks
	void logicInsertInto(string tableName)
	{
		if (checkTabelExists(tableName) == true)
		{
			FileHandler check = FileHandler();

			int noOfColumnsCreate = check.noOfColumnsCreate(tableName);
			string auxString;
			string columnValues = check.getCreateColumnValues(tableName);
			string* columnValuesArray=new string[noOfColumnsCreate * 4];
			
			int counter = 4;
			int position = 0;
			const char tempCompare = ' ';			

			for (int i = 0; i < columnValues.length()-1; i++) {
				if (columnValues[i] == tempCompare) {
					columnValuesArray[position] = auxString;
					auxString = "";
					position++;

				}
				else auxString += columnValues[i];
			}
		
			columnValuesArray[noOfColumnsCreate * 4 - 1] = auxString;
			
		
			if ((getCurrentArrSize() - 4) == noOfColumnsCreate)
			{
				for (int i = 3; i < (noOfColumnsCreate * 4); i = i + 4)
				{
					string expression1 = "[0-9]+"; // Number Check
					string expression2 = "'[a-zA-Z0-9_.]+'"; // String Check
					string expression3 = "[0-9]+\\.[0-9]+"; // Float Check

					bool isIntegerCurrentArr = regex_match(this->currentArr[counter].c_str(), regex(expression1));
					bool isIntegerValues = regex_match(columnValuesArray[i].c_str(), regex(expression1));

					bool isStringCurrentArr = regex_match(this->currentArr[counter].c_str(), regex(expression2));
					bool isStringValues = regex_match(columnValuesArray[i].c_str(), regex(expression2));

					bool isFloatCurrentArr = regex_match(this->currentArr[counter].c_str(), regex(expression3));
					bool isFloatValues = regex_match(columnValuesArray[i].c_str(), regex(expression3));

					if ((isIntegerCurrentArr && isIntegerValues) || (isStringCurrentArr && isStringValues) || (isFloatCurrentArr && isFloatValues)) {
						columnValuesArray[i] = this->currentArr[counter];
					}
					else this->errorHandler.ErrorsList(15);
					counter++;
				}
				check.suprascriptionTable(columnValuesArray, tableName, (noOfColumnsCreate * 4) + 1);

			}
			else this->errorHandler.ErrorsList(16);
			delete[] columnValuesArray;
			columnValuesArray = nullptr;
		}
		else this->errorHandler.ErrorsList(12);
	}

	// The method handles the logic select command checks
	void logicSelect(string tableName)
	{
		if (checkTabelExists(tableName) == true) {
			FileHandler check = FileHandler();

			int noOfColumnsCreate = check.noOfColumnsCreate(tableName);
			int noOfElementsCreate = noOfColumnsCreate * 4;
			string* columnValuesArray = new string[noOfElementsCreate];
			int columnCount = 1;

			int position = 0;
			int j = 1;
			int k = 0;

			string auxString;
			string createValues = check.getCreateColumnValues(tableName);

			string comparisonStrAll = "ALL";
			string comparisonStrFrom = "FROM";
			string comparisonStrWhere = "WHERE";

			const char tempCompare = ' ';

			for (int i = 0; i < createValues.length() - 1; i++) {
				if (createValues[i] == tempCompare) {
					columnValuesArray[position] = auxString;
					auxString = "";
					position++;
				}
				else auxString += createValues[i];
			}
			columnValuesArray[noOfElementsCreate - 1] = auxString;
			if (stringToUpper(this->currentArr[1]) != comparisonStrAll) {
				if (stringToUpper(this->currentArr[getCurrentArrSize() - 4]) == comparisonStrWhere) {
					for (int i = 0; i < noOfElementsCreate; i = i + 4) {
						
						if (columnValuesArray[i] == this->currentArr[getCurrentArrSize() - 3]) {
							
							if (columnValuesArray[i + 3] == this->currentArr[getCurrentArrSize() - 1]) {
								
								int checkerEveryColumn = 0;
								while (stringToUpper(this->currentArr[j]) != comparisonStrFrom) {
									for (int i = 0; i < noOfElementsCreate; i = i + 4) if (this->currentArr[j] == columnValuesArray[i]) checkerEveryColumn++;									
									j++;
								}
								j = 1; // Resetting the j
								cout << "CheckerEveryColumn: " << checkerEveryColumn << " " << "noOfColumnsCreate: " << noOfColumnsCreate << endl;
								if (checkerEveryColumn > noOfColumnsCreate) this->errorHandler.ErrorsList(7);
								while (stringToUpper(this->currentArr[j]) != comparisonStrFrom) {
									for (int i = 0; i < noOfElementsCreate && stringToUpper(this->currentArr[j]) != comparisonStrFrom; i = i + 4) {
										cout << this->currentArr[j] << " " << columnValuesArray[i] << endl;
										if (this->currentArr[j] == columnValuesArray[i]) {

											cout << "Column: " << columnCount << " displayed." << endl << endl;
											for (int adder = i; adder < i + 4; adder++) cout << columnValuesArray[adder] << endl;
											cout << endl << endl;
											columnCount++;
											j++;
											i = -4;
											continue;
										}
									}
								}
								return;
							}
							this->errorHandler.ErrorsList(8);
						}
					}
				}
				else {
					int checkerEveryColumn = 0;
					while (stringToUpper(this->currentArr[j]) != comparisonStrFrom) {
						for (int i = 0; i < noOfElementsCreate; i = i + 4) {
							
							if (this->currentArr[j] == columnValuesArray[i]) {
								checkerEveryColumn++;
							}
						}
						j++;
					}
					j = 1; // Resetting the j
					cout << "CheckerEveryColumn: " << checkerEveryColumn << " " << "noOfColumnsCreate: " << noOfColumnsCreate << endl;
					if (checkerEveryColumn > noOfColumnsCreate) this->errorHandler.ErrorsList(7);
					while (stringToUpper(this->currentArr[j]) != comparisonStrFrom) {
						for (int i = 0; i < noOfElementsCreate && stringToUpper(this->currentArr[j]) != comparisonStrFrom; i = i + 4) {
							cout << this->currentArr[j] << " " << columnValuesArray[i] << endl;
							if (this->currentArr[j] == columnValuesArray[i]) {

								cout << "Column: " << columnCount << " displayed." << endl << endl;
								for (int adder = i; adder < i + 4; adder++) cout << columnValuesArray[adder] << endl;
								cout << endl << endl;
								columnCount++;
								j++;
								i = -4;
								continue;
							}
						}
					}
					return;
				}
			}
			else {
				if (stringToUpper(this->currentArr[getCurrentArrSize() - 4]) == comparisonStrWhere) {
					for (int i = 0; i < noOfElementsCreate; i = i + 4) {
						if (columnValuesArray[i] == this->currentArr[getCurrentArrSize() - 3]) {
							if (columnValuesArray[i + 3] == this->currentArr[getCurrentArrSize() - 1]) check.displayTableFile(tableName);
							else this->errorHandler.ErrorsList(10);
							return;
						}
					}
					this->errorHandler.ErrorsList(11);
					return;
				}
				else check.displayTableFile(tableName);
			}

			delete[] columnValuesArray;
			columnValuesArray = nullptr;
		}
		else this->errorHandler.ErrorsList(12);
	}

	// The method handles the logic delete command checks
	void logicDelete(string tableName)
	{ 
		if (checkTabelExists(tableName) == true)
		{
			FileHandler check = FileHandler();
			FileHandler fileHandle = FileHandler();

			int noOfColumnsCreate = check.noOfColumnsCreate(tableName);
			int noElementsCreate = noOfColumnsCreate * 4;
			string createValues = check.getCreateColumnValues(tableName);
			string* columnValuesArray = new string[noOfColumnsCreate * 4];

			int position = 0;
			int breaker = 0;

			string auxString;
			const char tempCompare = ' ';

			int retainIndex = 0;
			int number = 0;

			for (int i = 0; i < createValues.length() - 1; i++) {
				if (createValues[i] == tempCompare)
				{
					columnValuesArray[position] = auxString;
					auxString = "";
					position++;
				}
				else auxString += createValues[i];
			}
			columnValuesArray[noElementsCreate - 1] = auxString;

			for (int i = 0; i < noElementsCreate; i = i + 4) {
				if ((columnValuesArray[i] == this->currentArr[4]) && (breaker == 0)) {
					breaker = 1;
					retainIndex = i;
				}
				if ((currentArr[6] == columnValuesArray[retainIndex + 3]) && (breaker == 1))
				{
					number = 1;
					for (int j = retainIndex; j < noElementsCreate - 4; j++) {

						columnValuesArray[j] = columnValuesArray[j + 4];
					}
					this->printer.returnContinueStatement(7);
					fileHandle.suprascriptionTable(columnValuesArray, tableName, noElementsCreate - 3);
				}
			}
			if ((breaker != 1) || (number != 1)) this->errorHandler.ErrorsList(13);

			delete[] columnValuesArray;
			columnValuesArray = nullptr;
		}
		else this->errorHandler.ErrorsList(12);
	}

	// The method checks the data type from the table given.
	int checkSetDataType(string tableName)
	{
		string expression1 = "[0-9]+$"; // integer Check
		string expression2 = "'[^']+'"; // text Check
		string expression3 = "([0-9]*[.])+[0-9]+"; // Float Check

		int typeIdSet = 0;

		bool isIntegerCurrentArr = regex_match(this->currentArr[5].c_str(), regex(expression1));
		bool isStringCurrentArr = regex_match(this->currentArr[5].c_str(), regex(expression2));
		bool isFloatCurrentArr = regex_match(this->currentArr[5].c_str(), regex(expression3));

		if (isIntegerCurrentArr==true) typeIdSet = 1;
		else if (isStringCurrentArr==true) typeIdSet = 2;
	    else if (isFloatCurrentArr==true) typeIdSet = 3;
		return typeIdSet;
	}

	int checkColumnArrayDataType(string tableName)
	{
		int position = 0;
		int breaker = 0;

		FileHandler fileHandle = FileHandler();
		int noOfColumnsCreate = fileHandle.noOfColumnsCreate(tableName);
		int noElementsCreate = noOfColumnsCreate * 4;
		string createValues = fileHandle.getCreateColumnValues(tableName);
		string* columnValuesArray = new string[noOfColumnsCreate * 4];

		string auxString;
		const char tempCompare = ' ';

		int retainIndex = 0;
		int typeIdColumn = 0;

		for (int i = 0; i < createValues.length() - 1; i++) {
			if (createValues[i] == tempCompare)
			{
				columnValuesArray[position] = auxString;
				auxString = "";
				position++;
			}
			else auxString += createValues[i];

		}
		for (int i = 0; i < noElementsCreate; i = i + 4) {
			if ((columnValuesArray[i] == currentArr[3]) && (breaker == 0)) {
				breaker = 1;
				retainIndex = i;
			}
		}
		if (breaker == 1) {
			string expression1 = "integer"; // Number Check
			string expression2 = "text"; // String Check
			string expression3 = "float"; // Float Check

			bool isIntegerCurrentArr = regex_match(columnValuesArray[retainIndex + 1].c_str(), regex(expression1));
			bool isStringCurrentArr = regex_match(columnValuesArray[retainIndex + 1].c_str(), regex(expression2));
			bool isFloatCurrentArr = regex_match(columnValuesArray[retainIndex + 1].c_str(), regex(expression3));

			if (isIntegerCurrentArr == true) typeIdColumn = 1;
			else if (isStringCurrentArr == true) typeIdColumn = 2;
			else if (isFloatCurrentArr == true) typeIdColumn = 3;
			
			delete[] columnValuesArray;
			columnValuesArray = nullptr;

			return typeIdColumn;
		}
		else {
			delete[] columnValuesArray;
			columnValuesArray = nullptr;

			return 100;
		}
	}

	// The method handles the logic update command checks
	void LogicUpdate(string tableName)
	{   
		if (checkTabelExists(tableName) == true)
		{
			FileHandler fileHandle = FileHandler();

			int noOfColumnsCreate = fileHandle.noOfColumnsCreate(tableName);
			int noElementsCreate = noOfColumnsCreate * 4;
			string createValues = fileHandle.getCreateColumnValues(tableName);
			string* columnValuesArray = new string[noOfColumnsCreate * 4];

			int position = 0;
			int breaker = 0;

			string auxString;
			const char tempCompare = ' ';

			int retainIndex1 = 0;
			int retainIndex2 = 0;

			int valueAfterWhere = 0;

			int dataTypeColumn = checkColumnArrayDataType(tableName);
			int dataTypeSet = checkSetDataType(tableName);

			for (int i = 0; i < createValues.length() - 1; i++) {
				if (createValues[i] == tempCompare)
				{
					columnValuesArray[position] = auxString;
					auxString = "";
					position++;
				}
				else auxString += createValues[i];
			}
			columnValuesArray[noElementsCreate - 1] = auxString;

			for (int i = 0; i < noElementsCreate; i = i + 4) {
				// Modified if ((columnValuesArray[i] == this->currentArr[5]) && (breaker == 0)) {, this->currentArr[5] was this->currentArr[7]
				if ((columnValuesArray[i] == this->currentArr[7]) && (breaker == 0)) {
					breaker = 1;
					retainIndex1 = i;
				}
				if ((this->currentArr[9] == columnValuesArray[retainIndex1 + 3]) && (breaker == 1) && (valueAfterWhere == 0)) {
					valueAfterWhere = 1;
				}
				cout << columnValuesArray[i] << " " << this->currentArr[3] << " " << i << endl;
				cout << "The breaker is: " << breaker << " and the valueAfterWhere is: " << valueAfterWhere << endl;
				if ((columnValuesArray[i] == this->currentArr[3]) && (breaker == 1) && (valueAfterWhere == 1)) {
					cout << "SUCCES!" << endl;
					retainIndex2 = i;
				}

			}
			if ((breaker == 1) && (valueAfterWhere == 1) && (dataTypeColumn == dataTypeSet))
			{
				cout << columnValuesArray[retainIndex2 + 3] << " " << this->currentArr[5] << endl;
				cout << "columnValuesArray[retainIndex2] Index is: " << retainIndex2 << endl;

				columnValuesArray[retainIndex2 + 3] = this->currentArr[5];

				cout << "HERE IS THE ARRAY: ";
				for (int i = 0; i < noElementsCreate; i++) {
					cout << columnValuesArray[i] << " ";
				}
				cout << endl;

				fileHandle.suprascriptionTable(columnValuesArray, tableName, (noElementsCreate)+1);
			}
			else if ((breaker != 1) || (valueAfterWhere != 1)) this->errorHandler.ErrorsList(13);
			else if ((dataTypeColumn != dataTypeSet)) this->errorHandler.ErrorsList(14);

			delete[] columnValuesArray;
			columnValuesArray = nullptr;
		}
		else this->errorHandler.ErrorsList(12);
	}

	// The method determines the CSV file content length
	int csvFileLength(string csvFileName) {
		char separator = '|';
		FileHandler fileHandler = FileHandler();
		string csvFileContent = fileHandler.csvFileContent(csvFileName);
		int csvFileLength = 1;
		for (int i = 0; i < csvFileContent.length(); i++) {
			if (csvFileContent[i] == separator)csvFileLength++;
		}
		return csvFileLength;
	}

	// The method gets the values from CSV file into a dynamic array
	string* getCsvFileContentArray(string csvFileName) {
		FileHandler fileHandler = FileHandler();
		int csvLength = csvFileLength(csvFileName);
		string csvFileContent = fileHandler.csvFileContent(csvFileName);
		string* csvFileContentArray = new string[csvLength];
		string tempStr;
		char separator = '|';
		for (int i = 0, j = 0; i < csvFileContent.length(); i++) {
			if (csvFileContent[i] != separator) tempStr += csvFileContent[i];
			else {
				csvFileContentArray[j] = tempStr;
				tempStr = "";
				j++;
			}
		}
		csvFileContentArray[csvLength - 1] = tempStr;
		return csvFileContentArray;
	}

	// The method handles the logic import command checks
	void logicImport(string tableName, string csvFileName) {
		FileHandler fileHandler = FileHandler();
		bool csvFileExists = fileHandler.csvFileExists(csvFileName);
		char separator = '|';

		if (checkTabelExists(tableName) && csvFileExists) {

			int csvLength = csvFileLength(csvFileName);
			string* csvFileContentArray = getCsvFileContentArray(csvFileName);

			int noOfColumnsCreate = fileHandler.noOfColumnsCreate(tableName);
			int noOfCreateElements = noOfColumnsCreate * 4;
			string columnValues = fileHandler.getCreateColumnValues(tableName);
			string* columnValuesArray = new string[noOfCreateElements];

			int counter = 0;
			int position = 0;
			string auxString;
			const char tempCompare = ' ';

			for (int i = 0; i < columnValues.length() - 1; i++) {
				if (columnValues[i] == tempCompare) {
					columnValuesArray[position] = auxString;
					auxString = "";
					position++;
				}
				else auxString += columnValues[i];
			}
			columnValuesArray[noOfCreateElements - 1] = auxString;
			if (csvLength == noOfColumnsCreate) {
				for (int i = 3; i < (noOfColumnsCreate * 4); i = i + 4)
				{
					string expression1 = "[0-9]+$"; // Number Check
					string expression2 = "'[^']+'"; // String Check
					string expression3 = "([0-9]*[.])+[0-9]+"; // Float Check
					
					bool isIntegerCurrentArr = regex_match(csvFileContentArray[counter].c_str(), regex(expression1));
					bool isIntegerValues = regex_match(columnValuesArray[i].c_str(), regex(expression1));

					bool isStringCurrentArr = regex_match(csvFileContentArray[counter].c_str(), regex(expression2));
					bool isStringValues = regex_match(columnValuesArray[i].c_str(), regex(expression2));

					bool isFloatCurrentArr = regex_match(csvFileContentArray[counter].c_str(), regex(expression3));
					bool isFloatValues = regex_match(columnValuesArray[i].c_str(), regex(expression3));

					if ((isIntegerCurrentArr && isIntegerValues) || (isStringCurrentArr && isStringValues) || (isFloatCurrentArr && isFloatValues)) {
						columnValuesArray[i] = csvFileContentArray[counter];
					}
					else this->errorHandler.ErrorsList(15);
					counter++;
				}

				fileHandler.suprascriptionTable(columnValuesArray, tableName, noOfCreateElements + 1);
			}
			else this->errorHandler.ErrorsList(16);

			delete[] columnValuesArray;
			columnValuesArray = nullptr;

			delete[] csvFileContentArray;
			csvFileContentArray = nullptr;
		}
		else this->errorHandler.ErrorsList(17);
	}

	// The method, based on the command, checks it's respective logic																-> Main method
	void tableLogicalChecks(string firstElement, string tableName) {

		if (firstElement == "create") createTableElement(tableName);
		else if (firstElement == "drop") dropTableElement(tableName);
		else if (firstElement == "display") displayTableElement(tableName);

		else if (firstElement == "insert") logicInsertInto(tableName);
		else if (firstElement == "select") logicSelect(tableName);
		else if (firstElement == "delete") logicDelete(tableName);

		else if (firstElement == "update") LogicUpdate(tableName);
		else if (firstElement == "import") logicImport(tableName, this->currentArr[getCurrentArrSize()-1]);

		this->printer.returnContinueStatement(8);
	} 
	

	// Avoids memory leaks
	~LogicHandler() {
		delete[] this->currentArr;
		this->currentArr = nullptr;

		delete[] this->tableNames;
		this->tableNames = nullptr;
	
	}
};

class TableHandler {
public:
	// The method gets the table names
	string getTableNames(FileHandler& handlingFile) {
		return handlingFile.inputFromFile("TableNames.txt");
	}

	// The method gets the number of tables in system
	int getNoOfTables() {
		FileHandler fileHandler = FileHandler();
		string tableNames = getTableNames(fileHandler);
		const char tempCompare = ' ';
		int noOfTables = 0;
		for (unsigned int i = 0; i < tableNames.length(); i++) {
			if (tableNames[i] == tempCompare) noOfTables++;
		}
		return noOfTables;
	}

	// The method transforms the given tables in an dynamic array of tables.
	string* getTableNamesArr() {
		FileHandler fileHandler = FileHandler();
		string tableNames = getTableNames(fileHandler);
		string* tableNamesArr = new string[getNoOfTables()];
		string auxString;
		int position = 0;
		const char tempCompare = ' ';
		for (int i = 0; i < getNoOfTables() - 1; i++) {
			if (tableNames[i] == tempCompare) {
				tableNamesArr[position] = auxString;
				auxString = "";
				position++;
			}
			else {
				auxString += tableNames[i];
			}
		}
		tableNamesArr[getNoOfTables() - 1] = auxString;
		return tableNamesArr;
	}

	// The method checks the existance of the name given by user
	bool checkNameExists(string input) {
		string* tableNamesArr = new string[getNoOfTables()];
		tableNamesArr = getTableNamesArr();
		bool exists = false;
		for (int i = 0; i < getNoOfTables(); i++) {
			if (input == tableNamesArr[i])
			{
				exists = true;
			}
		}
		return exists;
	}

	// The method gets the size of table as a whole
	int getSize(string input) {
		if (checkNameExists(input)) {
			FileHandler fileHandle = FileHandler();
			int sizeOfColumns = fileHandle.noOfColumnsCreate(input) / 4;
			return sizeOfColumns;
		}
		else {
			cout << "THE TABLE NAME DOESN'T EXIST" << endl;
			return -1;
		}
	}

	// The method gets the content of table as a whole.
	string* getContent(string input) {
		if (checkNameExists(input) && (getSize(input) > 0)) {
			FileHandler check = FileHandler();

			int noOfColumnsCreate = check.noOfColumnsCreate(input);
			int noElementsCreate = noOfColumnsCreate * 4;

			string createValues = check.getCreateColumnValues(input);
			string* columnValuesArray = new string[noOfColumnsCreate * 4];

			int position = 0;
			string auxString;
			const char tempCompare = ' ';

			for (unsigned int i = 0; i < createValues.length() - 1; i++) {
				if (createValues[i] == tempCompare) {
					columnValuesArray[position] = auxString;
					auxString = "";
					position++;
				}
				else auxString += createValues[i];
			}
			columnValuesArray[noElementsCreate - 1] = auxString;
			return columnValuesArray;
		}
		else {
			cout << "TABLE NAME IS WRONG";
			return nullptr;
		}
	}

};

class Table {
public:
	int size = 0;
	string* content = nullptr;
	string input;

	Table() {
		TableHandler tableHandler = TableHandler();
		this->size = tableHandler.getSize(this->input);
		this->content = tableHandler.getContent(this->input);
	}

	void setInput(string input) {
		this->input = input;
	}

	~Table() {
		delete[] this->content;
		this->content = nullptr;
	}
};

class printCharacteristics : public TableHandler {
public:

	Table* tables = nullptr;
	TableHandler* tableArr = nullptr;

	printCharacteristics(Table* tables) {
		this->tables = tables;
	}

	void printTableDescription(string input) {
		{
			cout << "The name of the table introduced is: " << input << endl;
			cout << "The size of the table: " << tables->size << endl;
			cout << "The content of the table: " << endl;
		}
	}

};