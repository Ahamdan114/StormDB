#include "Imports.cpp"

#include "LogicHandler.cpp"
#include "Printer.cpp" // For next phases

// All commented commands are for next phases.

class CreateTable : LogicHandler
{
	static int CREATE_COUNTER;

public:

	bool testCreateTable(string const input) {
		bool createTable = regex_match(input.c_str(), regex("[[:blank:]]*create[[:blank:]]+table[[:blank:]]+(?!table)\\w+[[:blank:]]*(if[[:blank:]]+not[[:blank:]]+exists[[:blank:]]*)?(\\([[:blank:]]*(\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+.[0-9]+')|([0-9]+.[0-9]+)|(\")|([0-9]+))\\s*\\))(\\s*,\\s*\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+\\.[0-9]+')|([0-9]+\\.[0-9]+)|(\")|([0-9]+))\\s*\\))+\\))|[[:blank:]]*create[[:blank:]]+table[[:blank:]]+(?!table)\\w+[[:blank:]]*(if[[:blank:]]+not[[:blank:]]+exists[[:blank:]]*)?[[:blank:]]*(\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+\\.[0-9]+')|([0-9]+\\.[0-9]+)|(\")|([0-9]+))\\s*\\))[[:blank:]]*"));
		if (createTable) CREATE_COUNTER++;
		return createTable;
	}
	void creatingTableCheck() {
		string tableName = "";
	}

};

class DropTable : LogicHandler
{
	static int DROP_COUNTER;

public:

	bool testDropTable(string const input) {
		bool dropTable = regex_match(input.c_str(), regex("[[:blank:]]*drop[[:blank:]]+table[[:blank:]]+\\w+[[:blank:]]*"));
		if (dropTable) DROP_COUNTER++;
		return dropTable;
	}
};

class Select : LogicHandler
{
	static int SELECT_COUNTER;

public:
	bool testSelect(string const input)
	{
		bool selectColumns = regex_match(input.c_str(), regex("[[:blank:]]*select+[[:blank:]]+((all)|(\\((?!all)([^)]+)\\)))[[:blank:]]+from[[:blank:]]+(?!where)\\w+([[:blank:]]+(where(?!where)[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*(([0-9]+\\.[0-9]+)|([0-9]+)|(\"(\\w*)\"))))?[[:blank:]]*"));
		if (selectColumns) SELECT_COUNTER++;
		return selectColumns;
	}
};

class DisplayTable : LogicHandler
{
	static int DISPLAY_COUNTER;

public:
	bool testDisplayTable(string const input)
	{
		bool displayTable = regex_match(input.c_str(), regex("[[:blank:]]*display[[:blank:]]+table[[:blank:]]+\\w+[[:blank:]]*"));
		if (displayTable) DISPLAY_COUNTER++;
		return displayTable;
	}
};

class DeleteTable : LogicHandler
{
	static int DELETE_COUNTER;

public:
	bool testDeleteTable(string const input)
	{
		bool deleteTable = regex_match(input.c_str(), regex("[[:blank:]]*delete[[:blank:]]+from[[:blank:]]+\\w+[[:blank:]]+where[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|([0-9]+\\.[0-9]+)|[0-9]+))[[:blank:]]*"));
		if (deleteTable) DELETE_COUNTER++;
		return deleteTable;
	}

};

class UpdateTable : LogicHandler
{
	static int UPDATE_COUNTER;

public:
	bool testUpdateTable(string const input)
	{
		bool updateTable = regex_match(input.c_str(), regex("[[:blank:]]*update[[:blank:]]+\\w+[[:blank:]]+set[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|[0-9]+))[[:blank:]]+where[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|([0-9]+\\.[0-9]+)|[0-9]+))[[:blank:]]*"));
		if (updateTable) UPDATE_COUNTER++;
		return updateTable;
	}
};

class Insert : LogicHandler
{
	static int INSERT_COUNTER;

public:
	bool InsertIntoTable(string const input)
	{
		bool insertIntoTable = regex_match(input.c_str(), regex("[[:blank:]]*insert[[:blank:]]+into[[:blank:]]+\\w+[[:blank:]]+values[[:blank:]]*\\(\\s*((\"\\w+\"|([0-9]+\\.[0-9]+)|([0-9]+))\\s*,\\s*(\"\\w+\"|([0-9]+\\.[0-9]+)|([0-9]+))*)*\\s*,\\s*((\"\\w+\")|([0-9]+\\.[0-9]+)|[0-9]+)\\s*\\)[[:blank:]]*"));
		if (insertIntoTable) INSERT_COUNTER++;
		return insertIntoTable;
	}

};

int CreateTable::CREATE_COUNTER = 0;
int DropTable::DROP_COUNTER = 0;
int Select::SELECT_COUNTER = 0;
int DisplayTable::DISPLAY_COUNTER = 0;
int DeleteTable::DELETE_COUNTER = 0;
int UpdateTable::UPDATE_COUNTER = 0;
int Insert::INSERT_COUNTER = 0;

class Parser {
public:
	string cleanInput(string input) {
		return formatInput(input);
	}

	string formatInput(string input) {
		for (unsigned int i = 0; input[i] != '\0'; i++) if (input[i] >= 'A' && input[i] <= 'Z') input[i] = input[i] + 32;
		return input;
	}

	void parse(string cleanInput) {
		Printer printer = Printer();

		CreateTable createTable = CreateTable();
		Select selectTable = Select();
		DropTable dropTable = DropTable();
		DisplayTable displayTable = DisplayTable();
		DeleteTable deleteTable = DeleteTable();
		UpdateTable updateTable = UpdateTable();
		Insert insertTable = Insert();

		bool createCheck = createTable.testCreateTable(cleanInput);
		if (createCheck) printer.returnStatement(1);

		bool dropCheck = dropTable.testDropTable(cleanInput);
		if (dropCheck) printer.returnStatement(2);

		bool selectCheck = selectTable.testSelect(cleanInput);
		if (selectCheck) printer.returnStatement(3);

		bool displayCheck = displayTable.testDisplayTable(cleanInput);
		if (displayCheck) printer.returnStatement(4);

		bool deleteCheck = deleteTable.testDeleteTable(cleanInput);
		if (deleteCheck) printer.returnStatement(5);

		bool updateCheck = updateTable.testUpdateTable(cleanInput);
		if (updateCheck) printer.returnStatement(6);

		bool insertCheck = insertTable.InsertIntoTable(cleanInput);
		if (insertCheck) printer.returnStatement(7);
		
		if (!(createCheck || dropCheck || selectCheck || displayCheck || deleteCheck || updateCheck || insertCheck)) throw  "Syntax error.";
		else cout << "Syntax correct!" << endl;
	}

	~Parser() {}
};