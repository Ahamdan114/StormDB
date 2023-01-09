#pragma once
#include "Imports.cpp"

class Printer {
public:
	// The method returns the command details
	void print(string cleanInput) {
		cout << "Command details -> The command introduced is: " << cleanInput << endl;
	}

	void intro() {
		cout << "The compiler supports the following commands: Create, Drop, Display, Insert, Select, Delete, Update, Import" << endl;
		cout << "Use help and the name of the command to get a quick guide." << endl;
		cout << endl << endl;
	}

	void returnManual(string word) {
		// (create|drop|display|insert|select|delete|update|import)
		cout << "The word is: " << word << endl;

		if (word == "create") {
			cout << endl << endl;
			cout << "The CREATE statement is used to create database objects such as tables, views, stored procedures, and other objects in an SQL database." << endl;
			cout << "General syntax :" << endl;
			cout << "create table table_name(var_name, integer / float / text, size, default_value)																		-> For a table with one column" << endl;
			cout << "create table table_name((var_name1, integer / float / text, size1, default_value1), (var_name2, integer / float / text, size2, default_value2))	-> For a table with two columns" << endl;
			cout << endl << endl;
		}

		else if (word == "drop") {
			cout << endl << endl;
			cout << "The DROP statement is used to delete database objects such as tables, views, stored procedures, and other objects in an SQL database." << endl;
			cout << "General syntax :" << endl;
			cout << "drop table table_name" << endl;
			cout << endl << endl;
		}

		else if (word == "display") {
			cout << endl << endl;
			cout << "The DISPLAY statement is used to display a database object brougth to life by the CREATE statement." << endl;
			cout << "General syntax :" << endl;
			cout << "display table table_name" << endl;
			cout << endl << endl;
		}

		else if (word == "insert") {
			cout << endl << endl;
			cout << "The INSERT statement is used to add new records to a database table." << endl;
			cout << "General syntax :" << endl;
			cout << "insert into table_name values(value1, value2, ..., valueN)" << endl;
			cout << "Rules :" << endl;
			cout << "The values need to be the exact numberand have the exact order like they are in the original table.(You can use Display to check your original table values)" << endl;
			cout << endl << endl;
		}

		else if (word == "select") {
			cout << endl << endl;
			cout << "The SELECT statement is used to retrieve data from a database table." << endl;
			cout << "General syntax :" << endl;
			cout << "select(column1, column2, ..., columnN) from table_name							-> specific columns" << endl;
			cout << "select(column1, column2, ..., columnN) from table_name where var_name = filter -> select with a filter" << endl;
			cout << "select all from table_name														-> select all columns" << endl;
			cout << endl << endl;
		}

		else if (word == "delete") {
			cout << endl << endl;
			cout << "The DELETE statement is used to delete records from a database table." << endl;
			cout << "General syntax :" << endl;
			cout << "delete from table_name where var_name = value" << endl;
			cout << endl << endl;
		}

		else if (word == "update") {
			cout << endl << endl;
			cout << "The UPDATE statement is used to modify existing records in a database table." << endl;
			cout << "General syntax :" << endl;
			cout << "update table_name set var_name1 = value1 where var_name2 = value2" << endl;
			cout << endl << endl;
		}

		else if (word == "import") {
			cout << endl << endl;
			cout << "The IMPORT statement is used to import data from a file into a database table." << endl;
			cout << "General syntax :" << endl;
			cout << "import table_name file_name.csv" << endl;
			cout << endl << endl;
		}
	}

	// The method if the command is valid displays the succes message
	void returnStatement(int number) {
		/*switch (number) {*/
		/*case 1:
			cout << "The table was created." << endl;
			break;
		case 2:
			cout << "The table was dropped." << endl;
			break;
		case 3:
			cout << "The table was displayed." << endl;
			break;
		case 4:
			cout << "The values were inserted." << endl;
			break;
		case 5:
			cout << "The table was selected." << endl;
			break;
		case 6:
			cout << "The values were deleted." << endl;
			break;
		case 7:
			cout << "The values were updated." << endl;
			break;
		default:
			cout << "ERROR: NO COMMAND ACCEPTED." << endl;
			*/
			/*}*/
	}

	// The method returns a goodbye message at the end of the program
	void goodByeModel() {
		cout << endl << endl;
		cout << "							   								" << endl;
		cout << "						## # #  # # ## 						" << endl;
		cout << "						##############						" << endl;
		cout << "						## Goodbye! ##						" << endl;
		cout << "						##############						" << endl;
		cout << "						## # #  # # ## 						" << endl;
		cout << endl << endl;
	}

	~Printer() {}
};
class TableCharacteristic:public LogicHandler {
protected:
	int size = 0;
	string content = "";
public:

	TableCharacteristic(): LogicHandler() {
		LogicHandler logicHandler = LogicHandler();
		FileHandler fileHandler = FileHandler();
		size = fileHandler.noOfColumnsCreate(name);
		content = fileHandler.getCreateColumnValues(name);
    }
};

//class TableHandler : public TableCharacteristic {
//public:
//	TableCharacteristic* tableCharacteristics = nullptr;
//
//	string getTableNames(FileHandler& handlingFile) {
//		return handlingFile.inputFromFile("TableNames.txt");
//	}
//	void logicTableCharacteristicsSet() {
//		FileHandler fileHandler = FileHandler();
//		string tableNames = getTableNames(fileHandler);
//		int size = 0;
//		for (int i = 0; i < tableNames.length(); i++) {
//			if (tableNames[i] == ' ') size++;
//		}
//		string* table
//		// size tablenName;
//		//array 
//		//calluim metodele din logic Handler
//	}
//
//	~TableHandler() {
//		delete[] this->tableCharacteristics;
//	}
};
