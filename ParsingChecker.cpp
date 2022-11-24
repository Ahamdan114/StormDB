#pragma once
#include <iostream>
#include <string>

#include "ErrorHandler.cpp";
using namespace std;

enum MyStructureDBCommands {
	CREATE = 0, 
	TABLE = 1, 
	INDEX = 2, 
	DROP = 3,
	DISPLAY = 4
};

enum MyCRUDCommands {
	INSERT = 5,
	SELECT = 6,
	UPDATE = 7,
	DELETE = 8,
};

class ParsingChecker:public ErrorHandler {
	string input = "Default";
public:

	ParsingChecker(string input):ErrorHandler() {
		this->input = this->input;
	}

	string correctSpelling() {
		for (int i = 0; i < 4; i++) {
			/*if (this->command == towlower(MyStructureDBCommands)i || this->command == towupper(MyStructureDBCommands)i) {
				return "Command's syntax is correct";
			}*/
			cout << "Return Errorlist error: ";
			return ErrorsList(1);
		}
	}

	ParsingChecker(const ParsingChecker& err): ErrorHandler() {

	}

	~ParsingChecker() {
		cout << "Destructor ParsingChecker" << endl;
	}
};