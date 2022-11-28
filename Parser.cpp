#pragma once
#include <iostream>
#include <string>
#include<regex>

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

class Parser {
	public:
		string cleanInput(string input) {
			return formatInput(removeSpaces(input));
		}

		string formatInput(string input) {
			for (int i = 0; input[i] != '\0'; i++) {
				if (input[i] >= 'A' && input[i] <= 'Z') input[i] = input[i] + 32;
			}
			return input;
		}

		string removeSpaces(string input) {
			char comparison = ' ';
			string removeSpacesArr = "";
			for (unsigned int i = 0; i < input.length(); i++) {
				if (input[i] != comparison) {
					removeSpacesArr += input[i];
				}
			}
			input = comparison = NULL;
			return removeSpacesArr;
		}

		void parse(string cleanInput) {
			/*int tokens_index = 0;
			string token = "";
			string[cleanInput.length()] tokens = {};
			for (int i = 0; i < cleanInput.length(); i++) {
				char currentChar = cleanInput[i];
				bool isLastChar = i == cleanInput.length() - 1;
				bool isWhiteSpace = currentChar == ' ';

				if (isWhiteSpace) {
					tokens[tokens_index++] = token;
					token = "";
				} else if (isLastChar) {
					token += currentChar;
					tokens[tokens_index++] = token;
					token = "";
				} else {
					token += currentChar;
				}
			}*/
		}
		class create_table
		{
			void testCreateTable(input) {
				if (regex_match(input, regex("^create table[a-zA-z0-9]+[\_]${1,}",regex::icase))) {
					cout << "your input is valid! ";
				else throw "your input is not valid. try again!";
				}
			}
		};

		~Parser() {
			cout << "Destructor Parser" << endl;
		}
};