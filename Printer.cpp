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
	void returnContinueStatement(int number) {
		switch (number) {
		case 0:
			cout << "\tThe command introduced has correct syntax" << endl;
			break;
		case 1:
			cout << endl << "The executable name is correct! Continue..." << endl;
			break;
		case 2:
			cout << "\tThe table name is: ";
			break;
		case 3:
			cout << "\tThe current array formed based on input is:  ";
			break;
		case 4:
			cout << endl << "The table list from which to choose is this one now -> | No list items |" << endl;
			break;
		case 5:
			cout << endl << "The table list from which to choose is this one now -> | ";
			break;
		case 6:
			cout << endl << "The table list dimension is this one now -> ";
			break;
		case 7:
			cout << "The new table is displayed... " << endl;
			break;
		case 8:
			cout << "\tThe command introduced has correct logic" << endl;
			break;
		}
	}

	string returnTerminatingStatement(int number) {
		string message;
		switch (number) {
		case 1:
			message = "ERROR: The command introduced is not correct from a syntactic point of view. ( Parser Error )";
			return message;
		case 2:
			message = "ERROR: The value introduced is bigger than it's set dimension. ( Logic Error )";
			return message;
		case 3:
			message = "ERROR: The value you have introduced is not of integer type. ( Logic Error )";
			return message;
		case 4:
			message = "ERROR! The value you have introduced is not of float type. ( Logic Error )";
			return message;
		case 5:
			message = "ERROR: The value you have introduced is not of text type. ( Logic Error )";
			return message;
		case 6:
			message = "ERROR: The table name exists already. ( Logic Error )";
			return message;
		case 7:
			message = "ERROR: The name of column(s) doesn't exists in the table. ( Logic Error )";
			return message;
		case 8:
			message = "ERROR: The value of identifier is inexistent in the table. ( Logic Error )";
			return message;
		case 9:
			message = "ERROR: The where identifier is inexistent in the table. ( Logic Error )";
			return message;
		case 10:
			message = "ERROR: The column name in where condition doesn't contain something similar with the table. ( Logic Error ) ";
			return message;
		case 11:
			message = "ERROR: The column name in where condition is inexistent in table. ( Logic Error ) ";
			return message;
		case 12:
			message = "ERROR: Table name doesn't exist!. ( Logic Error )";
			return message;
		case 13:
			message = "ERROR: The column name or value is wrong. ( Logic Error )";
			return message;
		case 14:
			message = "ERROR: The data type you tried to set is not correct or the column doesn't exist. ( Logic Error )";
			return message;
		case 15:
			message = "ERROR: Type of given values is not similar. ( Logic Error )";
			return message;
		case 16:
			message = "ERROR: The values sequence is not correlated with the columns sequence from. ( Logic Error ) ";
			return message;
		case 17:
			message = "Csv file name doesnt't exist or table name is wrong. ( Logic Error ) ";
			return message;
		default:
			message = "ERROR: NEW ERROR APPEARED";
			return message;
		}
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