#include "ClassesImports.cpp"

int main() {
	system("color 0D"); // For purple color of the text.

	// First comment
	string input = "";
	Parser parser = Parser();
	LogicHandler logicHandler = LogicHandler();
	Printer printer = Printer(); 
	ErrorHandler errorHandler = ErrorHandler();
	FileHandler fileHandle = FileHandler();

	// Second Comment
	while (true) {
		//Third Comment
		if (input != "")
		{  
			if (input == "exit") break;
			if (input == "clear") {
				for (int i = 0; i < 50; i++) cout << endl << endl;
				input = "";
				continue;
			}
			try {
				string lowerCaseInput = parser.cleanInput(input);
				parser.parse(lowerCaseInput);
				logicHandler.LogicArrayModifier(input);
				printer.print(input);

				cout << "ROOT -> The name of the table is: " << logicHandler.getTableName(logicHandler.getCurrentArrSize()) << endl;
				fileHandle.FileHandlingCreateFile(logicHandler.getFirstElementCurrent(), input);
				
			}
			catch (exception const& e) {
				// For next phases
			}
		}

		cout << "Enter a command: ";
		getline(cin, input);
	}
	printer.goodByeModel();
}

// // // First comment

	// ifstream& infile1, ifstream& infile2, ifstream& infile3, ifstream& infile4, ifstream& infile5 -> Files that need to be added as parameters
	// 
	// Input and Objects initialization.
	/*for (int i = 1; i < numerOfFiles; ++i) {
		string fileName = filesArr[i];
		ifstream file(fileName);
		if (file.good()) {
			cout << "File " << fileName << " exists" << endl;
		}
		else {
			cout << "File " << fileName << " does not exist" << endl;
		}
	}*/

	// // // Second comment

	//// Console Entrance
	//int counter = 1;
	//int counter = 1;
	//string fileName1 = infile1;
	//string fileName2 = infile2;
	//string fileName3 = infile3;
	//string fileName4 = infile4;
	//string fileName5 = infile5;

		// // // Third comment
		
	//		//counter < 6 -> Counter condition
	//if (false) {
	//	/*string resultedStr = fileHandle.inputFromFile("fileName" + counter);
	//	if (resultedStr != "") input = resultedStr;
	//
	//	if (input == "") cout << "Input from file is inexistent!" << endl;
	//	else cout << "Input from file is: " << input << endl;
	//
	//	string cleanInput = parser.cleanInput(input);
	//	parser.parse(cleanInput);
	//	cout << "Command details -> The command introduced to lowercase is: " << cleanInput << endl;
	//
	//	counter++;
	//	continue;*/
	//}