#pragma once
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class FileHandler {
public:
	string fileHandle() {

		fstream Input;
		Input.open("input.txt", ios::in);
		if (Input.is_open())
		{
			string fileInput;
			while (getline(Input, fileInput)) 
			{
				cout << fileInput << endl;
			};
			Input.close();
			return fileInput;

		}
		else return "";
		
		
	}

	~FileHandler() {
		cout << "Destructor FileHandler" << endl;
	}
};

