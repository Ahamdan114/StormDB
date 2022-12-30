#pragma once
#include "Imports.cpp"

class Printer {
public:
	void print(string cleanInput) {
		cout << "Command details -> The command introduced is: " << cleanInput << endl;
	}

	void returnStatement(int number) {
		switch (number) {
		case 1:
			cout << "The table was created." << endl;
			break;
		case 2:
			cout << "The table was dropped." << endl;
			break;
		case 3:
			cout << "The table was displayed." << endl;
			break;
		case 4:
			cout << "The values were inserted." << endl;
			break;
		case 5:
			cout << "The table was selected." << endl;
			break;
		case 6:
			cout << "The values were deleted." << endl;
			break;
		case 7:
			cout << "The values were updated." << endl;
			break;
		default:
			cout << "ERROR: NO COMMAND ACCEPTED." << endl;
		}
	}

	~Printer() {
		 // cout << "Destructor Print" << endl;
	}
};


