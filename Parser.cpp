#include "Imports.cpp"

#include "FileHandler.cpp"
#include "ErrorHandler.cpp"

class CreateTable
{
	static int CREATE_COUNTER;

public:
	bool testCreateTable(string const input) {
		bool createTable = regex_match(input.c_str(), regex("[[:blank:]]*create[[:blank:]]+table[[:blank:]]+(?!table)\\w+[[:blank:]]*(if[[:blank:]]+not[[:blank:]]+exists[[:blank:]]*)?(\\([[:blank:]]*(\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+.[0-9]+')|([0-9]+.[0-9]+)|(\")|([0-9]+))\\s*\\))(\\s*,\\s*\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+\\.[0-9]+')|([0-9]+\\.[0-9]+)|(\")|([0-9]+))\\s*\\))+\\))|[[:blank:]]*create[[:blank:]]+table[[:blank:]]+(?!table)\\w+[[:blank:]]*(if[[:blank:]]+not[[:blank:]]+exists[[:blank:]]*)?[[:blank:]]*(\\(\\s*\\w+\\s*,\\s*((integer)|(text)|(float))\\s*,\\s*[0-9]+\\s*,\\s*(('[0-9_a-z]+')|('[0-9]+\\.[0-9]+')|([0-9]+\\.[0-9]+)|(\")|([0-9]+))\\s*\\))[[:blank:]]*"));
		return createTable;
	}

	int returnCounterCreate() {
		return this->CREATE_COUNTER;
	}

	void SET_CREATE_COUNTER(int value) {
		this->CREATE_COUNTER = value;
	}
};

class DropTable
{
	static int DROP_COUNTER;

public:

	bool testDropTable(string const input) {
		bool dropTable = regex_match(input.c_str(), regex("[[:blank:]]*drop[[:blank:]]+table[[:blank:]]+\\w+[[:blank:]]*"));
		return dropTable;
	}

	int returnCounterDrop() {
		return this->DROP_COUNTER;
	}

	void SET_DROP_COUNTER(int value) {
		this->DROP_COUNTER = value;
	}
};

class Select
{
	static int SELECT_COUNTER;

public:
	bool testSelect(string const input)
	{
		//bool selectColumns = regex_match(input.c_str(), regex("[[:blank:]]*select+[[:blank:]]+((all)|(\\((?!all)([^)]+)\\)))[[:blank:]]+from[[:blank:]]+(?!where)\\w+([[:blank:]]+(where(?!where)[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*(([0-9]+\\.[0-9]+)|([0-9]+)|('(\\w*)'))))?[[:blank:]]*"));
		bool selectColumns = regex_match(input.c_str(), regex("[[:blank:]]*select+[[:blank:]]+((all)|(\\((?!all)([^)]+)\\)))[[:blank:]]+from[[:blank:]]+(?!where)\\w+([[:blank:]]+(where(?!where)[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*(([0-9]+\\.[0-9]+)|([0-9]+)|('(\\w*)')|'([[:blank:]]*\\w.+[[:blank:]]*)')))?[[:blank:]]*"));
		return selectColumns;
	}

	int returnCounterSelect() {
		return this->SELECT_COUNTER;
	}

	void SET_SELECT_COUNTER(int value) {
		this->SELECT_COUNTER = value;
	}
};

class DisplayTable
{
	static int DISPLAY_COUNTER;

public:
	bool testDisplayTable(string const input)
	{
		bool displayTable = regex_match(input.c_str(), regex("[[:blank:]]*display[[:blank:]]+table[[:blank:]]+\\w+[[:blank:]]*"));
		return displayTable;
	}

	int returnCounterDisplay() {
		return this->DISPLAY_COUNTER;
	}

	void SET_DISPLAY_COUNTER(int value) {
		this->DISPLAY_COUNTER = value;
	}
};

class DeleteTable
{
	static int DELETE_COUNTER;

public:
	bool testDeleteTable(string const input)
	{
		
		bool deleteTable = regex_match(input.c_str(), regex("[[:blank:]]*delete[[:blank:]]+from[[:blank:]]+\\w+[[:blank:]]+where[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*(('\\w+'|('[a-zA-Z0-9_.]+')|([0-9]+\\.[0-9]+)|[0-9]+))[[:blank:]]*"));
		// bool deleteTable = regex_match(input.c_str(), regex("[[:blank:]]*delete[[:blank:]]+from[[:blank:]]+\\w+[[:blank:]]+where[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*(('\\w+'|([0-9]+\\.[0-9]+)|[0-9]+))[[:blank:]]*"));
		return deleteTable;
	}

	int returnCounterDelete() {
		return this->DELETE_COUNTER;
	}

	void SET_DELETE_COUNTER(int value) {
		this->DELETE_COUNTER = value;
	}
};

class UpdateTable
{
	static int UPDATE_COUNTER;

public:
	bool testUpdateTable(string const input)
	{
		bool updateTable = regex_match(input.c_str(), regex("[[:blank:]]*update[[:blank:]]+\\w+[[:blank:]]+set[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*(('[[:blank:]]*\\w.+[[:blank:]]*'|([0-9]+\\.[0-9]+)|[0-9]+))[[:blank:]]+where[[:blank:]]+\\w+[[:blank:]]*=[[:blank:]]*(('[[:blank:]]*\\w.+[[:blank:]]*'|([0-9]+\\.[0-9]+)|[0-9]+))[[:blank:]]*"));
		return updateTable;
	}

	int returnCounterUpdate() {
		return this->UPDATE_COUNTER;
	}

	void SET_UPDATE_COUNTER(int value) {
		this->UPDATE_COUNTER = value;
	}
};

class Insert
{
	static int INSERT_COUNTER;

public:
	bool InsertIntoTable(string const input)
	{
		bool insertIntoTable = regex_match(input.c_str(), regex("[[:blank:]]*insert[[:blank:]]+into[[:blank:]]+\\w+[[:blank:]]+values[[:blank:]]*\\(\\s*(('\\w.+'|([0-9]+\\.[0-9]+)|([0-9]+))\\s*(\\s*(,\\s*'\\w.+')|(\\s*,\\s*[0-9]+\\.[0-9]+)|(\\s*,\\s*[0-9]+))*)\\s*\\)[[:blank:]]*"));
		return insertIntoTable;
	}

	int returnCounterInsert() {
		return this->INSERT_COUNTER;
	}

	void SET_INSERT_COUNTER(int value) {
		this->INSERT_COUNTER = value;
	}

};

class Import
{
	static int IMPORT_COUNTER;
public:
	bool ImportCheck(string const input)
	{
		bool importIntoTable = regex_match(input.c_str(), regex("[[:blank:]]*import[[:blank:]]+\\w+[[:blank:]]+\\w+.csv[[:blank:]]*"));
		return importIntoTable;

	}
	int returnCounterImport()
	{
		return IMPORT_COUNTER;
	}
	void SET_IMPORT_COUNTER(int value)
	{
		IMPORT_COUNTER = value;
	}
};

class HelpManual {
public:
	bool HelpManualVerify(string const input) {
		bool helpManualVerify= regex_match(input.c_str(), regex("[[:blank:]]*help[[:blank:]]+(create|drop|display|insert|select|delete|update|import){0,1}[[:blank:]]*"));
		return helpManualVerify;
	}
};

 int CreateTable::CREATE_COUNTER = 0;
 int DropTable::DROP_COUNTER = 0;
 int Select::SELECT_COUNTER = 0;

 int DisplayTable::DISPLAY_COUNTER = 0;
 int DeleteTable::DELETE_COUNTER = 0;
 int UpdateTable::UPDATE_COUNTER = 0;
 int Insert::INSERT_COUNTER = 0;
 int Import::IMPORT_COUNTER = 0;
 


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

	string getLastInputElement(string input) {
		unsigned int i = input.length() - 1;
		string word = "";
		for (i; i > 0; i--) if (input[i] != ' ') break; 
		for (unsigned int index = i; index >= 0; index--) {
			if (input[index] == ' ')break;
			word += input[index];
		}
		// reversed for loop problem fixed
		reverse(word.begin(), word.end());
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
		Printer printer = Printer();
		ErrorHandler errorHandler = ErrorHandler();


		FileHandler fileHandle = FileHandler();
		HelpManual helpManual = HelpManual();

		CreateTable createTable = CreateTable();
		DropTable dropTable = DropTable();
		Select selectTable = Select();
		DisplayTable displayTable = DisplayTable();
		DeleteTable deleteTable = DeleteTable();
		UpdateTable updateTable = UpdateTable();
		Insert insertTable = Insert();
		Import importTable = Import();

		
		bool createCheck = createTable.testCreateTable(cleanInput);

		if (createCheck) {
			int counter = createTable.returnCounterCreate() + 1;
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, counter);
			
			createTable.SET_CREATE_COUNTER(counter);
			printer.returnContinueStatement(1);
		}

		bool dropCheck = dropTable.testDropTable(cleanInput);

		if (dropCheck) {
			int counter = dropTable.returnCounterDrop() + 1;
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, counter);
			
			dropTable.SET_DROP_COUNTER(counter);
			printer.returnContinueStatement(2);
		}

		bool selectCheck = selectTable.testSelect(cleanInput);

		if (selectCheck) {
			int counter = selectTable.returnCounterSelect() + 1;
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, counter);
			
			selectTable.SET_SELECT_COUNTER(counter);
			printer.returnContinueStatement(3);
		}

		bool displayCheck = displayTable.testDisplayTable(cleanInput);

		if (displayCheck) {
			int counter = displayTable.returnCounterDisplay() + 1;
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, counter);
			
			displayTable.SET_DISPLAY_COUNTER(counter);
			printer.returnContinueStatement(4);
		}

		bool deleteCheck = deleteTable.testDeleteTable(cleanInput);

		if (deleteCheck) {
			int counter = deleteTable.returnCounterDelete() + 1;
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, counter);
			
			deleteTable.SET_DELETE_COUNTER(counter);
			printer.returnContinueStatement(5);
		}

		bool updateCheck = updateTable.testUpdateTable(cleanInput);

		if (updateCheck) {
			int counter = updateTable.returnCounterUpdate() + 1;
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, counter);
			
			updateTable.SET_UPDATE_COUNTER(counter);
			printer.returnContinueStatement(6);
		}

		bool insertCheck = insertTable.InsertIntoTable(cleanInput);

		if (insertCheck) {
			int counter = insertTable.returnCounterInsert() + 1;
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, counter);

			insertTable.SET_INSERT_COUNTER(counter);
			printer.returnContinueStatement(7);
		}

		bool importCheck = importTable.ImportCheck(cleanInput);
		if (importCheck) {
			int counter = importTable.returnCounterImport() + 1;
			fileHandle.createHistoryFile(getFirstInputElement(cleanInput), cleanInput, counter);
			importTable.SET_IMPORT_COUNTER(counter);
			printer.returnContinueStatement(8);
		}
		bool helpCheck = helpManual.HelpManualVerify(cleanInput);
		if (helpCheck){
			printer.returnManual(getLastInputElement(cleanInput));
		}

		if (!(createCheck || dropCheck || selectCheck || displayCheck || deleteCheck || updateCheck || insertCheck || helpCheck || importCheck)) errorHandler.ErrorsList(1);
		else printer.returnContinueStatement(0);
	}

	~Parser() {}
};