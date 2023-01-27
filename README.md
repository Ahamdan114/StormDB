#Team Working On Project: 
	1. Adriana-Maria Jianu.
	2. Enculescu Andrei.
	3. Maria Copaci.
	4. Ahmed-Iulian Hamdan.

# Structure:

#	Brainstorming Ideas:
		A cascade structure type. Input goes through many phases, meaning
		that the output of a phase is the input of another one. 
		If the input is wrong in any possible sense, an error is returned. 
		Else, the asked operation is processed.

#	Input Flow:
		Input goes through Parser, where it is formatted to lowercase, then returned for actual checking of correctness.
		After that, it is printed on the console the feedback.
		Next, the output of the parsing is pointed towards the logical part, more exactly in class LogicHandler, where 
		a current array containing the command introduced is created, with every word on a position in array, in order.
		
		Then the current array is transfered to one of it's derived class, where it is checked based on the command type.
		The first word of command is taken in order to find the command type. It is checked from every logical angle and, 
		if an error isn't returned the process of writting in files starts.

		The process of writting files is made in the class FileHandler. Also, we have the classes Printer and ErrorHandler
		for printing errors and statements in our program, for an more organizational structure and, for the same purpose 
		two abstract classes, DataAlterer and Type.

		Also, the project has a "help" manual with explicatons about the commands.


#	Implementation:
		The description of the table is in the same file as the records. The files used in this project are of text type
		and the size of every record is determined as the distance between the first attribute of the first record and the 
		first attribute of the second record.

#	Youtube Link:
	