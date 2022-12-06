#pragma once
#include <iostream>
#include <string>
#include <regex>
#include "Printer.cpp" // For next phases
using namespace std;

// All commented commands are for next phases.

class CreateTable
{
public:
	bool testCreateTable(string const input)
	{
		bool createTable = regex_match(input.c_str(), regex("[[:blank:]]*create[[:blank:]]+table[[:blank:]]+(?!table)\\w+[[:blank:]]*(if[[:blank:]]+not[[:blank:]]+exists[[:blank:]]*)?(\\([[:blank:]]*(\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+.[0-9]+')|([0-9]+.[0-9]+)|(\")|([0-9]+))\\s*\\))(\\s*,\\s*\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+\\.[0-9]+')|([0-9]+\\.[0-9]+)|(\")|([0-9]+))\\s*\\))+\\))|[[:blank:]]*create[[:blank:]]+table[[:blank:]]+(?!table)\\w+[[:blank:]]*(if[[:blank:]]+not[[:blank:]]+exists[[:blank:]]*)?[[:blank:]]*(\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+\\.[0-9]+')|([0-9]+\\.[0-9]+)|(\")|([0-9]+))\\s*\\))[[:blank:]]*"));
		//if (createTable) cout << "Table " << " Here we'll have the table name " << "was created." << endl;	
		return createTable;
	}
};

class DropTable
{
public:
	bool testDropTable(string const input)
	{
		bool dropTable = regex_match(input.c_str(), regex("[[:blank:]]*drop[[:blank:]]+table[[:blank:]]+\\w+[[:blank:]]*"));
		//if (dropTable) cout << "Table " << " Here we'll have the table name " << "dropped." << endl;
		return dropTable;
	}
};
class Select
{
public:
	bool testSelect(string const input)
	{
		bool selectColumns = regex_match(input.c_str(), regex("[[:blank:]]*select+[[:blank:]]+((all)|(\\((?!all)([^)]+)\\)))[[:blank:]]+from[[:blank:]]+(?!where)\\w+([[:blank:]]+(where(?!where)[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*(([0-9]+\\.[0-9]+)|([0-9]+)|(\"(\\w*)\"))))?[[:blank:]]*"));
		return selectColumns;
	}
};
class DisplayTable
{public:
	bool testDisplayTable(string const input)
	{
		bool displayTable = regex_match(input.c_str(), regex("[[:blank:]]*display[[:blank:]]+table[[:blank:]]+\\w+[[:blank:]]*"));
		/*if (displayTable) cout << "Table " << " Here we'll have the table name " << "is:" << " Here we will have the data of table." << endl;*/
		return displayTable;
	}
};
class DeleteTable
{
public:
	bool testDeleteTable(string const input)
	{
		bool deleteTable = regex_match(input.c_str(), regex("[[:blank:]]*delete[[:blank:]]+from[[:blank:]]+\\w+[[:blank:]]+where[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|([0-9]+\\.[0-9]+)|[0-9]+))[[:blank:]]*"));
		/*if (deleteTable) cout << "Table " << " Here we'll have the table name " << "was deleted." << endl;*/
		return deleteTable;
	}

};
class UpdateTable
{
public:
	bool testUpdateTable(string const input)
	{
		bool updateTable = regex_match(input.c_str(), regex("[[:blank:]]*update[[:blank:]]+\\w+[[:blank:]]+set[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|[0-9]+))[[:blank:]]+where[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|([0-9]+\\.[0-9]+)|[0-9]+))[[:blank:]]*"));
		/*if (updateTable) cout << "Table " << " Here we'll have the table name " << "was updated." << endl;*/
		return updateTable;
	}
};
class Insert
{
	
	public:
	bool InsertIntoTable(string const input)
	{
		bool insertIntoTable = regex_match(input.c_str(), regex("[[:blank:]]*insert[[:blank:]]+into[[:blank:]]+\\w+[[:blank:]]+values[[:blank:]]*\\(\\s*((\"\\w+\"|([0-9]+\\.[0-9]+)|([0-9]+))\\s*,\\s*(\"\\w+\"|([0-9]+\\.[0-9]+)|([0-9]+))*)*\\s*,\\s*((\"\\w+\")|([0-9]+\\.[0-9]+)|[0-9]+)\\s*\\)[[:blank:]]*"));
		return insertIntoTable;
	}

};



class Parser {
public:
	string cleanInput(string input) {
		return formatInput(input);
	}

	string formatInput(string input) {
		for (unsigned int i = 0; input[i] != '\0'; i++) if (input[i] >= 'A' && input[i] <= 'Z') input[i] = input[i] + 32;
		return input;
	}

	// For logic phase: 
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
		CreateTable createTable = CreateTable();
		Select selectTable = Select();
		DropTable dropTable = DropTable();
		DisplayTable displayTable = DisplayTable();
		DeleteTable deleteTable = DeleteTable();
		UpdateTable updateTable = UpdateTable();
		Insert insertTable = Insert();

		bool createCheck = createTable.testCreateTable(cleanInput);
		bool dropCheck = dropTable.testDropTable(cleanInput);
		bool selectCheck = selectTable.testSelect(cleanInput);
		bool displayCheck = displayTable.testDisplayTable(cleanInput);
		bool deleteCheck = deleteTable.testDeleteTable(cleanInput);
		bool updateCheck = updateTable.testUpdateTable(cleanInput);
		bool insertCheck = insertTable.InsertIntoTable(cleanInput);
		
		if (!(createCheck || dropCheck || selectCheck || displayCheck || deleteCheck || updateCheck || insertCheck)) throw  "Syntax error.";
		else cout << "Syntax correct!" << endl;
	}


	~Parser() {
		// cout << "Destructor Parser" << endl;
	}
};