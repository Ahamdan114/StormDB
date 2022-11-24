#pragma once
#include <iostream>
#include <string>
#include "ErrorHandler.cpp";
using namespace std;

class Print:public ErrorHandler {
	string input = "Default";
public:

	Print(string input):ErrorHandler() {
		this->input = input;
	}

	Print(const Print& err):ErrorHandler() {

	}

	~Print() {
		cout << "Destructor Print" << endl;
	}

};


