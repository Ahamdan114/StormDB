#include <iostream>
#include <string>

using namespace std;

class ErrorHandler {
	~ErrorHandler() {
		cout << "Destructor called" << endl;
	}
};

