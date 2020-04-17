# 241_pr2
Author: Noah Mutersbaugh
Date: 02/14/2020
Name of File: README.md
Description: This is for Project 2 of CIS241-03 with Professor Xinli Wang. The
purpose of this assignment is to practice manipulation of arrays as well as
working with file import/exporting from a C program.

For this project, there are several objectives:
	1. Encrypt data located in a file of plain text defined by the user using a
	keyword, both defined by the user
	2. Save the encrypted data in a new file defined by the user
	3. Decrypt data located in a file of plain text defined by the user using a
	keyword, both defined by the user
	4. Save the decrypted data in a new file defined by the user
	
Some optional objectives, imposed by myself:
	i. Automatically check the keyword for capitalization and transpose
	lowercase letters to capitalized letters
	ii. Automatically determine if the save file exists in the file system
	already. If it does not, create one using the name defined by the user
	iii. Check for improper entries in the INPUT_FILE and inform the user that
	they exist. 
		a. Keep these entries in the INPUT_FILE and make sure they are placed
		in the correct location in the OUTPUT_FILE. This will increase
		legibility and result in more useful bit of code. 
		b. These improper entries include punctuation, new line characters,
		spaces, numbers, and any other foreign character.


Other Information:
	I will be using the poem "THE VOICE" by Shel Silverstein as my input text
	file. It is very short, but has a great, wholesome message about his belief
	of the good inside every person.

	To run this program using the "cipher" executable file, type the following
	command:
		
		cipher [e/d] [KEYWORD] [INPUT_FILE] [OUTPUT_FILE]
