#include "Imports.cpp"
#include "FileHandler.cpp"
#include "Printer.cpp"

class CreateTable // : LogicHandler
{
	int CREATE_COUNTER = 0; 
public:

	bool testCreateTable(string const input) {
		bool createTable = regex_match(input.c_str(), regex("[[:blank:]]*create[[:blank:]]+table[[:blank:]]+(?!table)\\w+[[:blank:]]*(if[[:blank:]]+not[[:blank:]]+exists[[:blank:]]*)?(\\([[:blank:]]*(\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+.[0-9]+')|([0-9]+.[0-9]+)|(\")|([0-9]+))\\s*\\))(\\s*,\\s*\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+\\.[0-9]+')|([0-9]+\\.[0-9]+)|(\")|([0-9]+))\\s*\\))+\\))|[[:blank:]]*create[[:blank:]]+table[[:blank:]]+(?!table)\\w+[[:blank:]]*(if[[:blank:]]+not[[:blank:]]+exists[[:blank:]]*)?[[:blank:]]*(\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+\\.[0-9]+')|([0-9]+\\.[0-9]+)|(\")|([0-9]+))\\s*\\))[[:blank:]]*"));
		if (createTable) {
			this->CREATE_COUNTER++;
		}
		return createTable;
	}

	int returnCounterCreate() {
		return this->CREATE_COUNTER;
	}

	void SET_CREATE_COUNTER(int value) {
		this->CREATE_COUNTER = value;
	}
};

class DropTable // : LogicHandler
{
	int DROP_COUNTER = 0;

public:

	bool testDropTable(string const input) {
		bool dropTable = regex_match(input.c_str(), regex("[[:blank:]]*drop[[:blank:]]+table[[:blank:]]+\\w+[[:blank:]]*"));
		if (dropTable) {
			this->DROP_COUNTER++;
		}
		return dropTable;
	}

	int returnCounterDrop() {
		return this->DROP_COUNTER;
	}

	void SET_DROP_COUNTER(int value) {
		this->DROP_COUNTER = value;
	}
};

class Select // : LogicHandler
{
	int SELECT_COUNTER = 0;

public:
	bool testSelect(string const input)
	{
		bool selectColumns = regex_match(input.c_str(), regex("[[:blank:]]*select+[[:blank:]]+((all)|(\\((?!all)([^)]+)\\)))[[:blank:]]+from[[:blank:]]+(?!where)\\w+([[:blank:]]+(where(?!where)[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*(([0-9]+\\.[0-9]+)|([0-9]+)|(\"(\\w*)\"))))?[[:blank:]]*"));
		if (selectColumns) {
			this->SELECT_COUNTER++;
		}
		return selectColumns;
	}

	int returnCounterSelect() {
		return this->SELECT_COUNTER;
	}

	void SET_SELECT_COUNTER(int value) {
		this->SELECT_COUNTER = value;
	}
};

class DisplayTable  //: LogicHandler
{
	int DISPLAY_COUNTER = 0;

public:
	bool testDisplayTable(string const input)
	{
		bool displayTable = regex_match(input.c_str(), regex("[[:blank:]]*display[[:blank:]]+table[[:blank:]]+\\w+[[:blank:]]*"));
		if (displayTable) {
			this->DISPLAY_COUNTER++;
		}
		return displayTable;
	}

	int returnCounterDisplay() {
		return this->DISPLAY_COUNTER;
	}

	void SET_DISPLAY_COUNTER(int value) {
		this->DISPLAY_COUNTER = value;
	}
};

class DeleteTable // : LogicHandler
{
	int DELETE_COUNTER = 0;

public:
	bool testDeleteTable(string const input)
	{
		bool deleteTable = regex_match(input.c_str(), regex("[[:blank:]]*delete[[:blank:]]+from[[:blank:]]+\\w+[[:blank:]]+where[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|([0-9]+\\.[0-9]+)|[0-9]+))[[:blank:]]*"));
		if (deleteTable) {
			this->DELETE_COUNTER++;
		}
		return deleteTable;
	}

	int returnCounterDelete() {
		return this->DELETE_COUNTER;
	}

	void SET_DELETE_COUNTER(int value) {
		this->DELETE_COUNTER = value;
	}
};

class UpdateTable // : LogicHandler
{
	int UPDATE_COUNTER = 0;

public:
	bool testUpdateTable(string const input)
	{
		bool updateTable = regex_match(input.c_str(), regex("[[:blank:]]*update[[:blank:]]+\\w+[[:blank:]]+set[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|[0-9]+))[[:blank:]]+where[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*((\"\\w+\"|([0-9]+\\.[0-9]+)|[0-9]+))[[:blank:]]*"));
		if (updateTable) {
			this->UPDATE_COUNTER++;
		}
		return updateTable;
	}

	int returnCounterUpdate() {
		return this->UPDATE_COUNTER;
	}

	void SET_UPDATE_COUNTER(int value) {
		this->UPDATE_COUNTER = value;
	}
};

class Insert // : LogicHandler
{
	int INSERT_COUNTER = 0;

public:
	bool InsertIntoTable(string const input)
	{
		bool insertIntoTable = regex_match(input.c_str(), regex("[[:blank:]]*insert[[:blank:]]+into[[:blank:]]+\\w+[[:blank:]]+values[[:blank:]]*\\(\\s*((\"\\w+\"|([0-9]+\\.[0-9]+)|([0-9]+))\\s*,\\s*(\"\\w+\"|([0-9]+\\.[0-9]+)|([0-9]+))*)*\\s*,\\s*((\"\\w+\")|([0-9]+\\.[0-9]+)|[0-9]+)\\s*\\)[[:blank:]]*"));
		if (insertIntoTable) {
			this->INSERT_COUNTER++;
		}
		return insertIntoTable;
	}

	int returnCounterInsert() {
		return this->INSERT_COUNTER;
	}

	void SET_INSERT_COUNTER(int value) {
		this->INSERT_COUNTER = value;
	}

};

// int CreateTable::CREATE_COUNTER =  0;
// int DropTable::DROP_COUNTER = 0;
// int Select::SELECT_COUNTER = 0;

// int DisplayTable::DISPLAY_COUNTER = 0;
// int DeleteTable::DELETE_COUNTER = 0;
// int UpdateTable::UPDATE_COUNTER = 0;
 // int Insert::INSERT_COUNTER = 0;

class Parser {
public:
	// The method returns the first given input word
	string getFirstInputElement(string input) {
		unsigned int i = 0;
		string word = "";

		for (i; i < input.length(); i++) if (input[i] != ' ') break;
		for (unsigned int index = i; i < input.length(); i++) {
			if (input[i] == ' ') break;
			word += input[i];
		}
		return word;
	}

	// The method returns the input given to lowercase
	string lowerCaseInput(string input) {
		return formatInput(input);
	}

	// The method formats the input given to lowercase
	string formatInput(string input) {
		for (unsigned int i = 0; input[i] != '\0'; i++) if (input[i] >= 'A' && input[i] <= 'Z') input[i] = input[i] + 32;
		return input;
	}
	
	// The method checks for correctness of input syntax
	void parse(string cleanInput) {
		cout << "PARSER ENTERED." << endl;

		Printer printer = Printer();
		FileHandler fileHandle = FileHandler();

		CreateTable createTable = CreateTable();
		DropTable dropTable = DropTable();
		Select selectTable = Select();
		DisplayTable displayTable = DisplayTable();
		DeleteTable deleteTable = DeleteTable();
		UpdateTable updateTable = UpdateTable();
		Insert insertTable = Insert();
		cout << "First Stage" << endl;
		bool createCheck = createTable.testCreateTable(cleanInput);
		if (createCheck) {
			cout << "Second Stage" << endl;
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, createTable.returnCounterCreate());

			printer.returnStatement(1);
		}
		cout << "Third Stage" << endl;

		bool dropCheck = dropTable.testDropTable(cleanInput);
		if (dropCheck) {
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, dropTable.returnCounterDrop());
			printer.returnStatement(2);
		}

		bool selectCheck = selectTable.testSelect(cleanInput);
		if (selectCheck) {
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, selectTable.returnCounterSelect());
			printer.returnStatement(3);
		}

		bool displayCheck = displayTable.testDisplayTable(cleanInput);
		if (displayCheck) {
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, displayTable.returnCounterDisplay());
			printer.returnStatement(4);
		}

		bool deleteCheck = deleteTable.testDeleteTable(cleanInput);
		if (deleteCheck) {
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, deleteTable.returnCounterDelete());
			printer.returnStatement(5);
		}

		bool updateCheck = updateTable.testUpdateTable(cleanInput);
		if (updateCheck) {
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, updateTable.returnCounterUpdate());
			printer.returnStatement(6);
		}

		bool insertCheck = insertTable.InsertIntoTable(cleanInput);
		if (insertCheck) {
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, insertTable.returnCounterInsert());
			printer.returnStatement(7);
		}
		
		if (!(createCheck || dropCheck || selectCheck || displayCheck || deleteCheck || updateCheck || insertCheck)) throw  "Syntax error.";
		else cout << "Syntax correct!" << endl;
	}

	~Parser() {}
};