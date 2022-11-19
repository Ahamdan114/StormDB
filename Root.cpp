#include <iostream>
#include <string>

#include "ErrorHandler.cpp";
#include "Print.cpp";
#include "ParsingChecker.cpp";
#include "LogicChecker.cpp";
#include "FileHandler.cpp";

using namespace std;

int main() {
	//string input;

	//while (true) {
	//	getline(cin, input);
	//}
	ErrorHandler handle = ErrorHandler(27);
	cout << handle.getAge() << endl;
}