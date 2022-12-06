#pragma once
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class FileHandler {
public:
	string inputFromFile() {

		fstream Input;
		Input.open("input.txt", ios::in);
		if (Input.is_open())
		{
			string fileInput;
			while (getline(Input, fileInput));
			Input.close();
			return fileInput;
		}
		return "";
	}

	~FileHandler() {
		// cout << "Destructor FileHandler" << endl;
	}
};

