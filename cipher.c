/*
 * Author: Noah Mutersbaugh
 * Date: 02/22/2020
 * Name of File: cipher.c
 * Description: This file houses each of the functions that will be used in the
 * substitution cipher.
 */

/* Included header files. */
#include <stdio.h>
#include <stdlib.h>
#include "cipher.h"

/*
 * Function: RemoveDuplicates()
 * Arguments: 
 * Return Type:
 * Description:
 */
void RemoveDuplicates()
{
	
}

/*
 * Function: GetFile()
 * Arguments: FILE * inFile
 * Return Type: void
 * Description: Open the file and read the contents of it into a character
 * array.
 */

void GetFile(char * fileName)
{
	FILE * inFile;
	int sizeOfFile;
	char * decryptedArray;
	printf("Attempting to open the file...\n");
	inFile = fopen("THE_VOICE.txt", "r");

	fseek(inFile, 0, SEEK_END);
	sizeOfFile = ftell(inFile);
	rewind(inFile);
	printf("After opening the file, I've determined its length\nto be: %d\n",
			sizeOfFile);
	
	printf("Allocating %d bytes of space...\n", sizeOfFile);
	decryptedArray = (char*)malloc((sizeOfFile + 1) * sizeof(char));

	if(decryptedArray == NULL)
	{
		printf("Memory not allocated.");
		exit(0);
	}

	printf("Reading file data into an array...\n");
	fread(decryptedArray, sizeOfFile, 1, inFile);
	decryptedArray[sizeOfFile] = '\0';
	printf("This is the content of the file:\n\n");
	printf("%s\n", decryptedArray);
}

void InitializeEncryptArray()
{

}

void InitializeDecryptArray()
{

}

void ProcessInput(int direction)
{

}
