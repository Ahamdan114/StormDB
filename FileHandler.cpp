#pragma once
#include "Imports.cpp"
#include "LogicHandler.cpp"

// string input, bool resultInput, ofstream ObjectFile
	// 
	// SELECT_1.txt
		// CREATE_1.txt
		// CREATE_2.txt
		// counter

class FileHandler {
public:
	string inputFromFile(string file) {

		fstream Input;
		Input.open(file, ios::in);
		if (Input.is_open())
		{
			string fileInput;
			while (getline(Input, fileInput));
			Input.close();
			return fileInput;
		}
		return "";
	}

	void createHistoryFile(string word, string input, int counter) {
		cout << endl << endl << endl;
		cout << "createHistoryFile: " << word + "_" + to_string(counter) + ".txt" << endl;
		cout << "FileHandlingTemp method CALLED: " << word << endl;

		fstream ObjectFile;
		ObjectFile.open(word + "_" + to_string(counter) + ".txt", ofstream::out);
		ObjectFile.write(input.c_str(), input.length());
		ObjectFile.close();
	}

	~FileHandler() {

	}
};

