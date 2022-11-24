#pragma once
#include <iostream>
#include <string>

#include "ErrorHandler.cpp";
using namespace std;

class FileHandler:public ErrorHandler {
	string input = "Default";
public:

	FileHandler(string input):ErrorHandler() {
		this->input = input;
	}

	FileHandler(const FileHandler& err):ErrorHandler() {

	}

	~FileHandler() {
		cout << "Destructor FileHandler" << endl;
	}
};

