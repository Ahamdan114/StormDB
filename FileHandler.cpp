#pragma once
#include <iostream>
#include <string>
using namespace std;

class FileHandler {
public:
	~FileHandler() {
		cout << "Destructor FileHandler" << endl;
	}
};

