#pragma once
#include <iostream>
#include <string>
#include <regex>

using namespace std;


class Parser {
	public:
		string cleanInput(string input) {
			return formatInput(input);
		}

		string formatInput(string input) {
			for (unsigned int i = 0; input[i] != '\0'; i++) {
				if (input[i] >= 'A' && input[i] <= 'Z') input[i] = input[i] + 32;
			}
			return input;
		}

	/*	string removeSpaces(string input) {
			char comparison = ' ';
			string removeSpacesArr = "";
			for (unsigned int i = 0; i < input.length(); i++) {
				if (input[i] != comparison) {
					removeSpacesArr += input[i];
				}
			}
			input = comparison = NULL;
			return removeSpacesArr;
		}*/

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
		

		~Parser() {
			cout << "Destructor Parser" << endl;
		}
};
class CreateTable
{public:
	bool testCreateTable(string const input)
	{
		bool reg = regex_match(input.c_str(), regex("^create+table+[a-zA-Z_]*_*[a-zA-Z0-9_]{0,63}$"));
		cout << reg<<endl;
		return reg;
		
	}
};

class DropTable
{
public:
	bool testCreateTable(string const input)
	{
		bool reg = regex_match(input.c_str(), regex("^create+table+[a-zA-Z_]*_*[a-zA-Z0-9_]{0,63}$"));
		cout << reg << endl;
		return reg;

	}
};
class Select
{
public:
	bool testSelect(string const input)
	{
		bool selectColumns = regex_match(input.c_str(), regex("^select+[[:blank:]]+((all)|(\\((?!all)([^)]+)\\)))[[:blank:]]+from[[:blank:]]+(?!where)\\w+([[:blank:]]+(where(?!where)[[:blank:]]+\\w+[[:blank:]]{0,}=[[:blank:]]{0,}([0-9]+|\"(\\w*?)\")))?$"));
		return selectColumns;
	}
};
class DisplayTable
{public:
	bool testDisplayTable(string const input)
	{
		bool displayTable = regex_match(input.c_str(), regex("[[:blank:]]{0,}display[[:blank:]]+table[[:blank:]]+[a-z0-9_]+[[:blank:]]+"));
		return displayTable;
	}
};
