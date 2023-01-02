#pragma once
#pragma warning ( disable : 4018 )

#include "Imports.cpp"
#include "FileHandler.cpp"

class LogicHandler {
protected:

	string* tableNames = nullptr;
	int tableSize = 0;

	string* currentArr = nullptr;
	int currentSize = 0;

public:

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
	// The method finds the table name
	string findTableName(int size) {
		string tableName = "";

		if (this->currentArr[0] == "SELECT") {
			for (int i = 0; i < size; i++) {
				if (this->currentArr[i] == "FROM") {
					tableName = this->currentArr[i + 1];
				}
			}
		}
		else if (this->currentArr[0] == "UPDATE") tableName = this->currentArr[1];
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
		cout << endl << "LOGIC PHASE ENTERED." << endl;

		// Input cleaning and size finding of currentArr

		string RemoveSpacesFromInput = removeSpaces(input);
		this->currentSize = sizeDiscovery(RemoveSpacesFromInput) + 1;
		
		// Setting the array

		currentArrCreate(this->currentSize);
		setCurrentArr(RemoveSpacesFromInput);

		// Printing part
		cout << "\tThe table name is: " << getTableName() << endl;
		cout << "\tCurrentArray Formed! It is:  ";
		for (int i = 0; i < this->currentSize; i++) cout << this->currentArr[i] << " ";
		cout << endl;
	}



	// The method returns the size of table names
	int getTableSize() {
		return this->tableSize;
	}
	
	 bool checkTabelExists(string tableName)
	 {
		
		for (int i = 0; i < getTableSize(); i++)
		{
			if (this->tableNames[i] == tableName)
				return true;
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
			cout << endl << "The table list from which to choose is this one now -> | ";
			if (!(getTableSize())) cout << "No list items |";
			else for (int z = 0; z < getTableSize(); z++) cout << this->tableNames[z] << " | ";
			cout << endl << "The table list size is this one now -> " << getTableSize() << endl << endl;
		}
	}



	void LogicalCheckingsCreate() {
		int i = 3;
		cout << this->currentArr[3] << endl;
		if (this->currentArr[3] == "IF" || this->currentArr[3] == "if" || this->currentArr[3] == "If" || this->currentArr[3] == "iF") i = 6;

		for (i; i < this->currentSize; i = i + 4) {

			int dimension = atoi(this->currentArr[i + 2].c_str());
			int nameLength = this->currentArr[i].length();
			
			// Checking if the name fits it's set dimension

			if (nameLength > dimension) {
				cout << "ERROR: " << this->currentArr[i].length() << this->currentArr[i + 2] << endl;
			}

			// Checking the type match if type is integer (or int).

			if (this->currentArr[i + 1] == "integer") {

				string firstLength = to_string(this->currentArr[i + 3].length());
				int number = atoi(this->currentArr[i + 3].c_str());
				string secondLength = to_string(to_string(number).length());

				if (firstLength != secondLength) {
					cout << firstLength << " " << secondLength << endl;
					cout << "ERROR: " << this->currentArr[i + 1] << " " <<  this->currentArr[i + 3] << endl;
				}
			}

			// Checking the type match if type is text (or string).

			else if (this->currentArr[i + 1] == "text") {

				const char quoteCheck = (this->currentArr[i + 3].c_str())[0];
				string quotesCheck = this->currentArr[i + 3];

				if (quoteCheck != '\'' && quotesCheck != "\"") {
					cout << "ERROR" << this->currentArr[i + 3] << endl;
				}
			}
		}
	}

	// The method requests the logic of command CREATE and continues the process based on the response
	void createTableElement(string tableName) {

		// Searching for element ( We don't want to find it )

		for (int i = 0; i < getTableSize(); i++) {
			if (tableName == this->tableNames[i]) throw "Elementul cautat exista deja!";
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
	void logicInsertInto(string tableName)
	{
		if (checkTabelExists(tableName) == true)
		{
			FileHandler check = FileHandler();
			int noOfColumnsCreate = check.noOfColumnsCreate(tableName);
			int counter = 4;
			int position = 0;
			string auxString;
			string columnValues = check.getCreateColumnValues(tableName);
			const char tempCompare = ' ';
			//put elements in this array of strings 
			string* columnValuesArray=new string[noOfColumnsCreate * 4];
			

			for (int i = 0; i < columnValues.length()-1; i++)
			{
				
				if (columnValues[i] == tempCompare)
				{
					columnValuesArray[position] = auxString;
					auxString = "";
					position++;

				}
				else
				{
	               auxString += columnValues[i];
				}

			}
		
			columnValuesArray[noOfColumnsCreate * 4 - 1] = auxString;
			
		
			if ((getCurrentArrSize() - 4) == noOfColumnsCreate)
			{
				for (int i = 3; i < (noOfColumnsCreate * 4); i = i + 4)
				{
					string expression1 = "[0-9]+"; // Number Check
					string expression2 = "'[a-zA-Z0-9_]+'"; // String Check
					string expression3 = "[0-9]+\\.[0-9]+"; // Float Check


					bool isIntegerCurrentArr = regex_match(this->currentArr[counter].c_str(), regex(expression1));
					bool isIntegerValues = regex_match(columnValuesArray[i].c_str(), regex(expression1));

					bool isStringCurrentArr = regex_match(this->currentArr[counter].c_str(), regex(expression2));
					bool isStringValues = regex_match(columnValuesArray[i].c_str(), regex(expression2));

					bool isFloatCurrentArr = regex_match(this->currentArr[counter].c_str(), regex(expression3));
					bool isFloatValues = regex_match(columnValuesArray[i].c_str(), regex(expression3));

					if ((isIntegerCurrentArr && isIntegerValues) || (isStringCurrentArr && isStringValues) || (isFloatCurrentArr && isFloatValues))
					{
						cout << "Succes!" << endl;
						columnValuesArray[i] = this->currentArr[counter];
					}
					else cout << "error.typeProblem" << endl;

					counter++;
				}
				check.suprascriptionTable(columnValuesArray, tableName, (noOfColumnsCreate * 4) + 1);

			}
			else cout << "The values sequence is not correlated with the  columns sequence from " << tableName << endl;
			delete[] columnValuesArray;
			columnValuesArray = nullptr;
		}

		else cout << "Table name doesn't exist!" << endl;
		
		
	}

	// The method, based on the command, checks it's respective logic																-> Main method
	void tableLogicalChecks(string firstElement, string tableName) {
		if (firstElement == "create") createTableElement(tableName);
		else if (firstElement == "drop") dropTableElement(tableName);
		else if (firstElement == "display") displayTableElement(tableName);
		else if (firstElement == "insert")logicInsertInto(tableName);

		cout << endl << "Logical & File phases Passed" << endl;
	} 
	

	// Avoids memory leaks
	~LogicHandler() {
		delete[] this->currentArr;
		this->currentArr = nullptr;

		delete[] this->tableNames;
		this->tableNames = nullptr;
	
	}
};