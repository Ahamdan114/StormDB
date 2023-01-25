#pragma once

#include "Imports.cpp"
#include "ErrorHandler.cpp"

class FileHandler {
public:
	// The method opens a file and returns the text inside it
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

	// The method opens a file and returns the text in layers inside it
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
			Input.close();
			return fileInput;
		}
		return "";
	}

	// The method stores the table name inside TableNames.txt file
	void tableNameToFile(string tableName) {
		fstream Input;

		Input.open("TableNames.txt", ios::app);
		if (Input.is_open()) {
			Input << tableName << endl;
			Input.close();
		}
	}

	// The method suprascripts on the screen the arrays ( the arrays given for now are: HistoryCounters, TableNames)
	void suprascriptionTable(string* tableArray, string tableName, int tableSize) {
		fstream Input;
		string tableFile = tableName + ".txt";

		Input.open(tableFile, ios::out);
		if (Input.is_open()) {
			for (int i = 0; i < tableSize - 1; i++) {
				Input << tableArray[i] << endl;
			}
			Input.close();
		}
	}

	void appendTable(string* tableArray, string tableName, int tableSize) {
		fstream Input;
		string tableFile = tableName + ".txt";

		Input.open(tableFile, ios::app);
		if (Input.is_open()) {
			for (int i = 0; i < tableSize - 1; i++) {
				Input << tableArray[i] << endl;
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

	// The method creates the history for each command introduced in the console.
	void createHistoryFile(string word, string input, int counter) {
		cout << "\tcreateHistoryFile: " << word + "_" + to_string(counter) + ".txt" << endl;

		string name = word + "_" + to_string(counter) + ".txt";
		fstream ObjectFile;
		rename(name.c_str(), "C:/Users/User/source/repos/sql-database-repo/Debug/HistoryTextFiles");
		ObjectFile.open(name, ios::app);
		ObjectFile.write(input.c_str(), input.length());
		ObjectFile.close();

	}

	// The method creates the table file.
	void createTableFile(string* currentArr, int size, string tableName) {
		fstream Input;
		string tableFile = tableName + ".txt";

		Input.open(tableFile, ios::out);
		if (Input.is_open()) {
			int i = 3;
			if (stringToUpper(currentArr[3]) == "IF") i = 6;
			for (i; i < size; i++) {
				Input << currentArr[i] << endl;
			}
			Input.close();
		}
		cout << "\tFile " << tableFile << " created successfully." << endl;
	}

	// The method returns the number of columns that the table contains
	int noOfColumnsCreate(string tabelName)
	{
		fstream input;
		int counter = 1;
		input.open(tabelName + ".txt", ios::in);
			if (input.is_open()) {
				string fileInput;
				
				getline(input, fileInput);
				string startingPoint = fileInput;
				
				while (getline(input, fileInput) && startingPoint != fileInput) {
					counter++;
				}
			}
			return counter / 4;
	}

	// The method returns a string containing all contents of a table accessed
	string getCreateColumnValues(string tabelName)
	{
		fstream input;
		string fileInput;
		string columnValues;
		input.open(tabelName + ".txt", ios::in);
		if (input.is_open())
		{
			getline(input, fileInput);

			string startingPoint = fileInput;
			columnValues += (fileInput + " ");

			while (getline(input, fileInput) && startingPoint != fileInput) {
				columnValues += (fileInput + " ");
		    }

		}
		return columnValues;
	}
	//-------------------------------------
	



	// The method returns the number of columns that the table contains
	int noOfBigColumnsCreate(string tabelName) {
		fstream input;
		int counter = 0;
		input.open(tabelName + ".txt", ios::in);
		if (input.is_open()) {
			string fileInput;

			while (getline(input, fileInput)) {
				counter++;
			}
		}
		return counter / 4;
	}

	// The method returns a string containing all contents of a table accessed
	string getBigCreateColumnValues(string tabelName) {
		fstream input;
		string fileInput;
		string columnValues;
		input.open(tabelName + ".txt", ios::in);
		if (input.is_open())
		{
			while (getline(input, fileInput)) {
				columnValues += (fileInput + " ");
			}

		}
		return columnValues;
	}







	//-------------------------------------




	// The method drops the table file.
	void dropTableFile(string tableName) {
		string tableFile = tableName + ".txt";

		remove(tableFile.c_str());
		cout << "\tFile " << tableFile << " dropped successfully." << endl;
	}

	// The method displays the table file.
	void displayTableFile(string tableName) {
		fstream Output;
		string tableFile = tableName + ".txt";

		Output.open(tableFile, ios::in);
		if (Output.is_open()) {
			string fileOutput;
			int i = 0;
			int columnCount = 1;
			int recordCount = 1;
			cout << "\tThe table " << tableFile << " is displayed..." << endl;

			/*int noFileColumns = noOfBigColumnsCreate(tableName);
			int noTableColumns = noOfColumnsCreate(tableName);

			int numberOfTables = noFileColumns / noTableColumns;*/

			while (getline(Output, fileOutput)) {
				if (i % 16 == 0) {
					cout << endl;
					cout << "Record: " << recordCount << endl;
					cout << endl;
					recordCount++;
				}
				if (i % 4 == 0) {
					cout << endl;
					cout << "\tColumn: " << columnCount << endl;
					cout << endl;
					columnCount++;
				}

				cout << "\t\t" + fileOutput << endl;
				i++;
			}
			
			cout << "\tThe table " << tableFile << " displayed successfully." << endl;
			cout << endl << endl;
		}
		Output.close();
	}

	// The method returns a boolean value representing the existence of a CSV file given by user.
	bool csvFileExists(string csvFileName) {
		fstream File;
		bool csvFileExists = false;
		File.open(csvFileName, ios::in);
		if (File.is_open()) {
			csvFileExists = true;
			File.close();
		}
		return csvFileExists;
	}

	// The method returns a string containing all contents of the CSV file accessed
	string csvFileContent(string csvFileName) {
		fstream File;
		File.open(csvFileName, ios::in);
		if (File.is_open()) {
			string infoContainer;
			string interationStr;
			while (getline(File, interationStr)) {
				infoContainer += interationStr;
			}
			File.close();
			return infoContainer;
		}
		return "";
	}

	// The method converts the string input to uppercase letters
	string stringToUpper(string input)
	{
		string response = "";
		for (unsigned int i = 0; i < input.length(); i++)
		{
			if (input[i] >= 'a' && input[i] <= 'z') response += (input[i] - 32);
			else response += input[i];
		}
		return response;
	}
};