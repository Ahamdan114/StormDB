#pragma once
#include <iostream>
#include <string>

using namespace std;

class ErrorHandler {
	int age = 0;
public:
	ErrorHandler(int age) {
		this->age = age;
	}

	int getAge() {
		return age;
	}

	~ErrorHandler() {
		cout << "Destructor called" << endl;
	}
};

