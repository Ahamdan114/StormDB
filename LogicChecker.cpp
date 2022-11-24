#pragma once
#include <iostream>
#include <string>

#include "ErrorHandler.cpp";
using namespace std;

class LoginChecker:public ErrorHandler {
	string input = "Default";
public:

	LoginChecker(string input):ErrorHandler() {
		this->input = input;
	}

	LoginChecker(const LoginChecker& err):ErrorHandler() {

	}

	~LoginChecker() {
		cout << "Destructor LoginChecker" << endl;
	}
};