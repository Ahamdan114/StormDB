#pragma once
#include <iostream>
#include <string>
#include "ErrorHandler.cpp";
using namespace std;

class Printer {
public:
	void print(string output) {
	
	}

	~Printer() {
		cout << "Destructor Print" << endl;
	}
};


