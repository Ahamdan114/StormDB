#pragma once
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class FileHandler : public LogicHandler {
public:

	FileHandler() {}
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


	// string input, bool resultInput, ofstream ObjectFile

	void FileHandlingCreateFile(string str, string input) {
		// SELECT_1.txt
		// CREATE_1.txt
		// CREATE_2.txt
		// counter
		cout << endl << endl << endl;
		cout << "FileHandlingTemp method CALLED: " << str << endl;
		fstream ObjectFile;
		ObjectFile.open(str + "_" + ".txt", ofstream::out);
		ObjectFile.write(input.c_str(), input.length());
		ObjectFile.close();
	}

	~FileHandler() {

	}
};

