#pragma once
#include "Imports.cpp"

// ios::out -> write mode
// ios::app -> Appending mode
// ios::in -> read mode
// x.open(fileName, mode)
// x.is_open() => file is open?
// getline(fstream File, destinationString);
// x.close();

class FileHandler {
public:
	// the method opens a file and returns the text inside it.
	string inputFromCommandPrompt(string file) {

		fstream Input;
		Input.open(file, ios::in);
		if (Input.is_open())
		{
			string fileInput;

			while (getline(Input, fileInput)) {}
			Input.close();
			return fileInput;
		}
		return "";
	}
	
	string inputFromFile(string file) {

		fstream Input;
		Input.open(file, ios::in);
		if (Input.is_open())
		{
			string fileInput;
			string temp;

			while (getline(Input, temp)) {
				fileInput += (temp + " ");
			}
			cout << "inputFromFile is: " << fileInput << endl;
			Input.close();
			return fileInput;
		}
		return "";
	}

	void tableNameToFile(string tableName) {
		fstream Input;
		Input.open("TableNames.txt", ios::app);
		if (Input.is_open()) {
			Input << tableName << endl;
			Input.close();
		}
	}

	void suprascriptionTableNames(string* tableNames, int tableSize) {
		fstream Input;
		Input.open("TableNames.txt", ios::out);
		if (Input.is_open()) {
			for (int i = 0; i < tableSize - 1; i++) {
				Input << tableNames[i] << endl;
			}
			Input.close();
		}
	}

	void suprascriptionHistoryCounters(string* countersArr, int arrSize = 7) {
		fstream Input;
		Input.open("HistoryCounters.txt", ios::out);
		if (Input.is_open()) {
			for (int i = 0; i < arrSize - 1; i++) {
				Input << countersArr[i] << endl;
			}
			Input.close();
		}
	}

	void countersTableNamesSaver(string* countersArr, int countersSize) {
		fstream Input;
		Input.open("HistoryCounters.txt", ios::out);
		if (Input.is_open()) {
			for (int i = 0; i < countersSize - 1; i++) {
				Input << countersArr[i] << endl;
			}
			Input.close();
		}
	}

	// The method creates the history file with given command introduced 
	void createHistoryFile(string word, string input, int counter) {
		cout << endl << endl << endl;
		cout << "createHistoryFile: " << word + "_" + to_string(counter) + ".txt" << endl;
		cout << "FileHandlingTemp method CALLED: " << word << endl;

		fstream ObjectFile;
		ObjectFile.open(word + "_" + to_string(counter) + ".txt", ios::app);
		ObjectFile.write(input.c_str(), input.length());
		ObjectFile.close();
	}

	void createTableFile(string* currentArr, int size, string tableName) {
		fstream Input;
		Input.open(tableName + ".txt", ios::out);
		if (Input.is_open()) {
			int i = 3;
			if (currentArr[3] == "IF") i = 6;
			for (i; i < size; i++) {
				Input << currentArr[i] << endl;
			}
			Input.close();
		}
	}

	void displayTableFile(string tableName) {
		fstream Output;
		Output.open(tableName + ".txt", ios::in);
		if (Output.is_open()) {
			string fileOutput;
			cout << "The table " + tableName << " displayed." << endl << endl;
			while (getline(Output, fileOutput)) cout << fileOutput << endl;
			cout << endl << endl;
		}
		Output.close();
	}

	void deleteTableFile(string tableName) {
		remove((tableName + ".txt").c_str());
		cout << tableName << " " << "deleted successfully." << endl;
	}

	~FileHandler() {

	}
};