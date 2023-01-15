#pragma once
#pragma once
#include "Imports.cpp"

class ErrorHandler {
	int i = 0;
	string input = "Default";
public:
	ErrorHandler() {

	}

	ErrorHandler(string input) {
		this->input = input;
		this->i = i;
	}

	string handleError(string err) {
		return err;
	}
	// Getting the input of a variable.
	string getInput() {
		return this->input;
	}
	// Choosing which error to return.
	string ErrorsList(int i) {
		switch (i) {
			case 1:
				return "Error Number 1 -> The input " + this->getInput() + " is syntactically incorrect!";
				break;
			case 2:
				return "Error number 2 -> The input " + this->getInput() + " is missing a part of it!";
				break;
			 default:
				return "Error Number 2 -> The input " + this->getInput() + " has a problem in it!";
		}
	}

	ErrorHandler(const ErrorHandler& err) {}

	~ErrorHandler() {}
};

