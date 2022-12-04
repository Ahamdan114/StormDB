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

		bool reg = regex_match(input.c_str(), regex("[[:blank:]]*create[[:blank:]]+table[[:blank:]]+(?!table)\\w+[[:blank:]]*(if[[:blank:]]+not[[:blank:]]+exists[[:blank:]]*)?(\\([[:blank:]]*(\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+.[0-9]+')|([0-9]+.[0-9]+)|(\")|([0-9]+))\\s*\\))(\\s*,\\s*\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+.[0-9]+')|([0-9]+.[0-9]+)|(\")|([0-9]+))\\s*\\))+\\))|[[:blank:]]*create[[:blank:]]+table[[:blank:]]+(?!table)\\w+[[:blank:]]*(if[[:blank:]]+not[[:blank:]]+exists[[:blank:]]*)?[[:blank:]]*(\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+.[0-9]+')|([0-9]+.[0-9]+)|(\")|([0-9]+))\\s*\\))[[:blank:]]*"));
		
		return reg;
		
	}
};

class DropTable
{
public:
	bool testDropTable(string const input)
	{
		bool dropTab = regex_match(input.c_str(), regex("[[:blank:]]*drop[[:blank:]]+table[[:blank:]]+\\w+[[:blank:]]*"));
		
		return dropTab;

	}
};
class Select
{
public:
	bool testSelect(string const input)
	{
		bool selectColumns = regex_match(input.c_str(), regex("[[:blank:]]*select+[[:blank:]]+((all)|(\\((?!all)([^)]+)\\)))[[:blank:]]+from[[:blank:]]+(?!where)\\w+([[:blank:]]+(where(?!where)[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*([0-9]+|\"(\\w*?)\")))?[[:blank:]]*"));
		return selectColumns;
	}
};
class DisplayTable
{public:
	bool testDisplayTable(string const input)
	{
		bool displayTable = regex_match(input.c_str(), regex("[[:blank:]]*display[[:blank:]]+table[[:blank:]]+\\w+[[:blank:]]*"));
		return displayTable;
	}
};
class DeleteTable
{
public:
	bool testDeleteTable(string const input) 
	{
		bool deleteTable = regex_match(input.c_str(), regex("[[:blank:]]*delete[[:blank:]]+from[[:blank:]]+\\w+[[:blank:]]+where[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|[0-9]+))[[:blank:]]*"));
		return deleteTable;
	}

};
class UpdateTable
{
public:
	bool testUpdateTable(string const input) 
	{
		
		bool updateTable = regex_match(input.c_str(), regex("[[:blank:]]*update[[:blank:]]+\\w+[[:blank:]]+set[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|[0-9]+))[[:blank:]]+where[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|[0-9]+))[[:blank:]]*"));
		return updateTable;
	}


};
class Insert
{
	
	public:
	bool InsertIntoTable(string const input)
	{
		bool testInsertInto = regex_match(input.c_str(), regex("[[:blank:]]*insert[[:blank:]]+into[[:blank:]]+(\\w+)[[:blank:]]+values[[:blank:]]+(\\((\"?((\\w+)|([0-9]+\\.[0-9]+))\"?,)*\"?((\\w+)|([0-9]+\\.[0-9]+))\"?\\))[[:blank:]]*"));
		return testInsertInto;
	}
	//s-ar putea sa fie de la float uri, check tomorrow
};
