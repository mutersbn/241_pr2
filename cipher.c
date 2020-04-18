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
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "cipher.h"

/*
 * Function: Prepend()
 * Arguments: 2 pointers to arrays of characters
 * Return Type: void
 * Description: Prepends t into s
 */
void prepend(char * s, const char * t)
{
	size_t lengthT = strlen(t);
	memmove(s + lengthT, s, strlen(s) + 1);
	memcpy(s, t, lengthT);
}

/*
 * Function: StandardizeKEY()
 * Arguments: pointer to character array, int size of that array
 * Return Type: pointer to character array 'KEY'
 * Description: Takes our keyword and creates an array KEY
 */
char * StandardizeKEY(char * keyWord, int sizeOfKey)
{
	const int SUPER_ALPHA_LENGTH = 27; // 26 letter alphabet + null char

	// 'apk' = 'Alpha Plus (+) Key'
	int apkLength = (sizeOfKey + SUPER_ALPHA_LENGTH);

	char superAlpha[] = { 'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q',
		'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C',
		'B', 'A', '\0' };
	char * apkArray = NULL;
	apkArray = (char*)malloc(apkLength * sizeof(char*)); // TODO: FREE THIS ARRAY 'apkArray' (completed)
	char * KEY = NULL;
	KEY = (char*)malloc(SUPER_ALPHA_LENGTH * sizeof(char*)); // TODO: FREE THIS ARRAY 'KEY'

	prepend(apkArray, superAlpha);
	prepend(apkArray, keyWord);
	
	/*
	 * Lvl 1: Loop through each character in the array
	 * Lvl 2: Compare character 'i' with each successive character
	 * Lvl 3: Shift each character left one space
	 */
	for(int i=0; i<=apkLength; i++)
	{
		if(apkArray[i] >= 'a' && apkArray[i] <= 'z')
		{
			apkArray[i] = toupper(apkArray[i]);
		}
		
		for(int k=i+1; k<=apkLength; k++)
		{
			if(toupper(apkArray[i]) == toupper(apkArray[k]))
			{
				for(int n=k; n<=apkLength; n++)
				{
					apkArray[n] = apkArray[n+1];
				}
			}
		}
	}

	// Copy everything over to the KEY array
	for(int n=0; n<SUPER_ALPHA_LENGTH; n++)
	{
		KEY[n] = apkArray[n];
	}

	free(apkArray); // COMPLETED: FREE 'apkArray'

	printf("\nThe Key is: %s\n", KEY);

	return KEY;
}

/*
 * Function: GetFile()
 * Arguments: pointer to character array that holds our fileName
 * Return Type: void
 * Description: Open the file and read the contents of it into a character
 * array.
 */

char * GetFile(char * fileName)
{
	FILE * inFile;
	int sizeOfFile = SizeOfFile(fileName);
	char * fileContents;
	//printf("Attempting to open the file...\n");
	inFile = fopen(fileName, "r");

	if(access(fileName, F_OK ) != -1)
	{	
		//printf("Allocating %d bytes of space...\n", sizeOfFile);
		fileContents = (char*)malloc((sizeOfFile + 1) * sizeof(char)); // TODO: FREE 'fileContents'

		if(fileContents == NULL)
		{
			printf("Memory not allocated.");
			exit(0);
		}

		//printf("Reading file data into an array...\n");
		fread(fileContents, sizeOfFile, 1, inFile);
		fileContents[sizeOfFile] = '\0';
		fclose(inFile);
	}
	return fileContents;
}

/*
 * Function: SizeOfFile()
 * Arguments: pointer to character array that holds our fileName
 * Return Type: int
 * Description: Simply returns the size of the file
 */
int SizeOfFile(char * fileName)
{
	int size = 0;
	FILE * file;
	file = fopen(fileName, "r");
	if(file != NULL)
	{
		fseek(file, 0, SEEK_END);
		size = ftell(file);
		rewind(file);
		fclose(file);
	}
	return size;
}

/*
 * Function: Encrypt()
 * Arguments: pointer to KEY character array, pointer to a character array of 
 * 	the contents of the file, and the size of the file
 * Return Type: pointer to a character array
 * Description: Encrypts the file using the KEY
 */
char * Encrypt(char * KEY, char * fileContents, int size)
{
	char * output;
	int encryptingLetterIndex;

	output = (char*)malloc(size * sizeof(char)); // TODO: FREE 'output'

	for(int i=0; i<size; i++)
	{
		encryptingLetterIndex = fileContents[i] - 'A';

		// If our encrypted character is A - Z, use it.
		if(encryptingLetterIndex >= 0 && encryptingLetterIndex <= 26)
		{
			output[i] = KEY[encryptingLetterIndex];
		}
		// Otherwise, don't encrypt the character and place it directly into
		// the character array 'output[]'
		else
		{
			output[i] = fileContents[i];
		}
	}

	return output;
}

char * Decrypt(char * KEY, char * fileContents, int size)
{
	char * output;
	int decryptingLetterIndex;
	char * Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";

	output = (char*)malloc(size * sizeof(char)); // TODO: FREE 'output'

	for(int i=0; i<size; i++)
	{
		decryptingLetterIndex = KEY[i] - 'A';

		// If our encrypted character is A - Z, use it.
		if(decryptingLetterIndex >= 0 && decryptingLetterIndex <= 26)
		{
			output[i] = Alphabet[decryptingLetterIndex];
		}
		// Otherwise, don't encrypt the character and place it directly into
		// the character array 'output[]'
		else
		{
			output[i] = fileContents[i];
		}
	}

	return output;
}

void PublishToFile(char * fileContents, char * fileName, int size)
{
	FILE * outputFile;
	outputFile = fopen(fileName, "w");

	for(int i=0; i<size; i++)
	{
		fputc(fileContents[i], outputFile);
	}

	fclose(outputFile);
}
