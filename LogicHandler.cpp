#pragma once
#include "Imports.cpp"

class LogicHandler {
protected:
	// Array de table name
	// string* tableNames = nullptr;
	// Array de valori

	string* currentArr = nullptr;
	int size = 0;
	// Array de files accesate by name (pentru insert, select)


public:

	LogicHandler() {
		// this->tableNames = new string[size];
	}

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

	int sizeDiscovery(string input) {
		int size = 0;
		for (unsigned int i = 0; i < input.length() + 1; i++) {
			if (input[i] == ' ' || input[i] == ',') {
				size++;
			}
		}
		return size;
	}

	void logicHandler(string input, int size) {
		if (this->currentArr != nullptr) {
			delete[] this->currentArr;
			this->currentArr = nullptr;
		}
		this->currentArr = new string[size];
	}

	void setCurrentArr(string input, int size) {
		int j = 0;
		string tempStr = "";
		for (unsigned int i = 0; i < input.length() + 1; i++) {
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
		// cout << "this->currentArr[j] => " << this->currentArr[j] << endl;
		// cout << "Size: " << size << endl << "j: " << j << endl;
	}

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

	int getCurrentArrSize() {
		return this->size;
	}

	string* getCurrentArr() {
		string* copy = new string[this->size];
		for (int i = 0; i < this->size; i++) {
			copy[i] = this->currentArr[i];
		}
		return copy;
	}

	string getFirstElementCurrent() {
		return this->currentArr[0];
	}

	void LogicArrayModifier(string input) {
		string RemoveSpacesFromInput = removeSpaces(input);
		cout << "1" << endl;
		this->size = sizeDiscovery(RemoveSpacesFromInput) + 1;
		cout << "2" << endl;
		logicHandler(RemoveSpacesFromInput, this->size);
		cout << "3" << endl;
		setCurrentArr(RemoveSpacesFromInput, this->size);
		cout << "4" << endl;
		cout << "The array formed is: ";
		for (int i = 0; i < this->size; i++) cout << this->currentArr[i] << " ";
		string currentTableName = getTableName(getCurrentArrSize());
		cout << endl << "The array name is: " << currentTableName << endl;
	}

	void deleteTableElement(string tableName) {
		/*	int size = sizeof(tablesList) / sizeof(tablesList[0]);
			int i = 0;
			for (i; i < size; i++) {
				if (tableName == tablesList[i]) {
					for (int j = i; j < size; j++) tablesList[j] = tablesList[j + 1];
					break;
				}
			}
			if (i == size) throw "Elementul cautat nu exista";*/
	}


	~LogicHandler() {
		delete[] this->currentArr;
		this->currentArr = nullptr;
		/*delete[] this->tableNames;
		this->tableNames = nullptr;*/
		
	}
};