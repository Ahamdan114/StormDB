#pragma once
#pragma warning ( disable : 4018 )
#include "Imports.cpp"
#include "FileHandler.cpp"
 // #include "Parser.cpp"


	// Array de files accesate by name (pentru insert, select)

class LogicHandler {
protected:

	string* tableNames = nullptr;
	int tableSize = 0;

	string* currentArr = nullptr;
	int currentSize = 0;

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
			if (input[i] != comparison) {
				removeSpacesArr += input[i];
			}
			else {
				if (i == input.length() + 1) break;
				if (input[i - 1] != ',' && input[i - 1] != '(' && input[i + 1] != ',' && input[i + 1] != ')') {
					if (input[i] == comparison && input[i + 1] != comparison) {
						removeSpacesArr += input[i];
					}
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
			if (input[i] == ' ' || input[i] == ',') {
				size++;
			}
		}
		return size;
	}

	// The method creates a dynamic size current array
	void currentArrCreate(string input, int size) {
		if (this->currentArr != nullptr) {
			delete[] this->currentArr;
			this->currentArr = nullptr;
		}
		this->currentArr = new string[size];
	}

	// The method sets the current array values
	void setCurrentArr(string input, int size) {
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
		/*for (int i = 0; i <= j; i++) {
			cout << this->currentArr[i] << " " << this->currentArr[i].length() << endl;
		}*/

		// cout << "this->currentArr[j] => " << this->currentArr[j] << endl;
		// cout << "Size: " << size << endl << "j: " << j << endl;
	}

	// The method finds the array name
	string getTableName(int size) {
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

	// The method gets the current array size
	int getCurrentArrSize() {
		return this->currentSize;
	}

	// The method creates a dynamic current array with the given input values words on each index position
	void LogicCurrentArrayModifier(string input) {
		string RemoveSpacesFromInput = removeSpaces(input);
		cout << "1" << endl;
		this->currentSize = sizeDiscovery(RemoveSpacesFromInput) + 1;
		cout << "2" << endl;
		currentArrCreate(RemoveSpacesFromInput, this->currentSize);
		cout << "3" << endl;
		setCurrentArr(RemoveSpacesFromInput, this->currentSize);
		cout << "4" << endl;
		cout << "The array formed is: ";
		for (int i = 0; i < this->currentSize; i++) cout << this->currentArr[i] << " ";
		string currentTableName = getTableName(getCurrentArrSize());
		cout << endl << "The array name is: " << currentTableName << endl;
	}

	void LogicalCheckingsCreate() {
		int i = 3;
		if (this->currentArr[3] == "IF") i = 6;
		for (i; i < this->currentSize; i = i + 4) {
			cout << "Iteration: " << i << endl;

			if (this->currentArr[i].length() > atoi(this->currentArr[i + 2].c_str())) {
				cout << "ERROR: " << this->currentArr[i].length() << this->currentArr[i + 2] << endl;
			}
			cout << "FIRST IF ACCEPTED SIZE" << endl;

			if (this->currentArr[i + 1] == "integer") {

				string firstLength = to_string(this->currentArr[i + 3].length());
				int number = atoi(this->currentArr[i + 3].c_str());
				string secondLength = to_string(to_string(number).length());

				if (firstLength != secondLength) {
					cout << firstLength << " " << secondLength << endl;
					cout << "ERROR: " << this->currentArr[i + 1] << " " <<  this->currentArr[i + 3] << endl;
				}
				cout << "SECOND IF ACCEPTED LENGTH" << endl;
			}
			else if (this->currentArr[i + 1] == "text") {
				if ((this->currentArr[i + 3].c_str())[0] != '\'' && this->currentArr[i + 3] != "\"") {
					cout << "ERROR" << this->currentArr[i + 3] << endl;
				}
				cout << "THIRD IF ACCEPTED SIZE" << endl;
			}
		}
	}

	// The method find the size of the table names
	void setTableNamesSize(FileHandler& handlingFile) {
		this->tableSize = 0;
		string tableNames = getTableNames(handlingFile);
		const char comparisonSpace = ' ';
		for (unsigned int i = 0; i < tableNames.length(); i++) {
			if (tableNames[i] == comparisonSpace) {
				this->tableSize++;
			}
		}
		cout << "setTableNamesSize -> TABLE SIZE: " << this->tableSize << endl;
	}

	// The method creates a dynamic size current array
	void tableNameArrCreate() {
		delete[] this->tableNames;
		this->tableNames = new string[this->tableSize];
	}

	// The method gets all the table names in the project
	string getTableNames(FileHandler& handlingFile) {
		return handlingFile.inputFromFile("TableNames.txt");
	}

	// The method sets the tableNames array values
	void setTableNames(string tableNames) {
		int j = 0;
		const char comparisonSpace = ' ';
		string tempStr = "";

		for (unsigned int i = 0; i < tableNames.length(); i++) {
			if (tableNames[i] == comparisonSpace) {
				this->tableNames[j] = tempStr;
				tempStr = "";
				j++;
			}
			else tempStr += tableNames[i];
		}
		cout << endl << endl << endl;

		cout << "TableName: " << tableNames << endl;
		cout << "TableSize: " << this->tableSize << endl;

		cout << "The table names are: ";
		for (int z = 0; z < j; z++) cout << this->tableNames[z] << " ";
		cout << endl;
	}

	// The method creates a dynamic current array with the table names as values on each index position
	void LogicTableNamesArrayModifier(FileHandler& handlingFile) {
		setTableNamesSize(handlingFile);
		tableNameArrCreate();
		string tableNames = getTableNames(handlingFile);
		setTableNames(tableNames);
	} 

	void displayTableElement(string firstElement, string tableName) {
		
		if (firstElement == "display") {
			cout << "displayTableElement ENTERED" << endl;
			for (int i = 0; i < this->tableSize; i++) {
				if (tableName == this->tableNames[i]) {
					cout << "FOUND element " + tableName + " UP!" << endl;
					FileHandler fileHandle = FileHandler();
					fileHandle.displayTableFile(tableName);
				}
			}
		}
		//else {
		//	// throw "Elementul cautat nu exista";
		//	cout << "Elementul nu exista" << endl;
		//}
	}


	void deleteTableElement(string firstElement, string tableName) {
		if (firstElement == "drop") {
			// cout << "DELETE-TABLE-ELEMENT ENTERED: "  << tableName << " " << tableName.length() << endl;
			for (int i = 0; i < this->tableSize; i++) {
				/*cout << tableName.length() << " " << this->tableNames[i].length() << endl;
				cout << tableName << " " << this->tableNames[i] << endl;*/
				if (tableName == this->tableNames[i]) {
					/*cout << "FOUND UP!" << endl;*/
					for (int j = i; j < this->tableSize - 1; j++) {
						this->tableNames[j] = this->tableNames[j + 1];
					}
					this->tableNames[this->tableSize - 1] = "";
					cout << "The new array after drop is: ";
					for (int i = 0; i < this->tableSize; i++) {
						cout << this->tableNames[i] << " & ";
					}
					cout << endl;
					FileHandler fileHandle = FileHandler();
					fileHandle.suprascriptionTableNames(this->tableNames, this->tableSize);
					fileHandle.deleteTableFile(tableName);
					break;
				}
			}
		}
		//else {
		//	// throw "Elementul cautat nu exista";
		//	cout << "Elementul nu exista" << endl;
		//}
	}

	void addTableElement(string firstElement, string tableName) {
		FileHandler fileHandle = FileHandler();
		if (firstElement == "create") {
			for (int i = 0; i < this->tableSize; i++) {
				if (tableName == this->tableNames[i]) throw "Elementul cautat exista deja";
			}
			// Daca ajungem aici inseamna ca nu l-a gasit.
			LogicalCheckingsCreate();
			fileHandle.tableNameToFile(tableName);
			fileHandle.createTableFile(this->currentArr, this->currentSize, tableName);
		}
	}

	void tableNameCheck(string firstElement, string tableName) {
		addTableElement(firstElement, tableName);
		deleteTableElement(firstElement, tableName);
		displayTableElement(firstElement, tableName);
	}

	~LogicHandler() {
		delete[] this->currentArr;
		this->currentArr = nullptr;

		delete[] this->tableNames;
		this->tableNames = nullptr;
	}
};