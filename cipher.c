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
#include "cipher.h"

/*
 * Description: Prepends t into s
 */
void prepend(char * s, char * t)
{
	size_t lengthT = strlen(t);
	memmove(s + lengthT, s, strlen(s) + 1);
	memcpy(s, t, lengthT);
}

/*
 * Function: RemoveDuplicates()
 * Arguments: 
 * Return Type:
 * Description:
 */
void RemoveDuplicates(char * key, int sizeOfKey)
{
	const int SUPER_ALPHA_LENGTH = 27;
	
	int superAlphaExtendedLength = (sizeOfKey + SUPER_ALPHA_LENGTH);
	int count = 0;

	char superAlpha[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
		'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
		'Z', '\0' };
	char * superAlphaExt = (char*)malloc(superAlphaExtendedLength * sizeof(char));

	prepend(superAlphaExt, superAlpha);
	prepend(superAlphaExt, key);

	printf("This is what's inside the extended array: %s\n", superAlphaExt);

	//printf("Capitalizing all characters and removing duplicate chars...\n");
	
	/*
	 * Lvl 1: Loop through each character in the array
	 * Lvl 2: Compare character 'i' with each successive character
	 * Lvl 3: Make duplicates spaces
	 */
	for(int i=0; i<superAlphaExtendedLength-1; i++)
	{
		if(superAlphaExt[i] >= 'a' && superAlphaExt[i] <= 'z')
		{
			superAlphaExt[i] = toupper(superAlphaExt[i]);
		}
		
		for(int k=i+1; k<superAlphaExtendedLength; k++)
		{
			if(toupper(superAlphaExt[i]) == toupper(superAlphaExt[k]))
			{
				count++;
				for(int n=k; n<superAlphaExtendedLength; n++)
				{
					superAlphaExt[n] = superAlphaExt[n+1];
				}
			}
		}
	}

	// Reallocate memory so we aren't taking up more space than we should be.
	superAlphaExt = (char*)realloc(superAlphaExt,
			(superAlphaExtendedLength - count)*sizeof(char*));

	printf("\nAfter capitalizing all characters and removing duplicates, the string is now %s\n",
			superAlphaExt);
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
