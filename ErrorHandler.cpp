#pragma once
#pragma once
#include "Imports.cpp"
#include "Printer.cpp"

class ErrorHandler : public Printer {
	int i = 0;
	string input = "Default";
public:
	ErrorHandler() {}

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
	void ErrorsList(int i) {
		return actualStatement(i);
	}

	void actualStatement(int i) {
		cout << returnTerminatingStatement(i) << endl;
		throw returnTerminatingStatement(i);
	}

	ErrorHandler(const ErrorHandler& err) {}

	~ErrorHandler() {}
};

