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
 * Description: Reverses order of array
 */
void reverse(char * array, int sizeOfArray)
{
	for(int low = 0, high = sizeOfArray - 1; low < high; low++, high--)
	{
		char temp = array[low];
		array[low] = array[high];
		array[high] = temp;
	}
}

/*
 * Function: RemoveDuplicates()
 * Arguments: 
 * Return Type:
 * Description:
 */
char * RemoveDuplicates(char * key, int sizeOfKey)
{
	const int SUPER_ALPHA_LENGTH = 27;

	printf("sizeOfKey: %d\n", sizeOfKey);
	
	int superAlphaExtendedLength = (sizeOfKey + SUPER_ALPHA_LENGTH);
	int count = 0;

	char superAlpha[] = { 'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q',
		'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C',
		'B', 'A', '\0' };
	char * superAlphaExt = (char*)malloc(superAlphaExtendedLength * sizeof(char));

	prepend(superAlphaExt, superAlpha);
	prepend(superAlphaExt, key);

	//printf("This is what's inside the extended array: %s\n", superAlphaExt);
	
	/*
	 * Lvl 1: Loop through each character in the array
	 * Lvl 2: Compare character 'i' with each successive character
	 * Lvl 3: Make duplicates spaces
	 */
	for(int i=0; i<superAlphaExtendedLength; i++)
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

	printf("\nThe Key is: %s\n", superAlphaExt);

	return superAlphaExt;
}

/*
 * Function: GetFile()
 * Arguments: FILE * inFile
 * Return Type: void
 * Description: Open the file and read the contents of it into a character
 * array.
 */

char * GetFile(char * fileName)
{
	FILE * inFile;
	int sizeOfFile = SizeOfFile(fileName);
	char * fileArray;
	//printf("Attempting to open the file...\n");
	inFile = fopen(fileName, "r");
	
	//printf("Allocating %d bytes of space...\n", sizeOfFile);
	fileArray = (char*)malloc((sizeOfFile + 1) * sizeof(char));

	if(fileArray == NULL)
	{
		printf("Memory not allocated.");
		exit(0);
	}

	//printf("Reading file data into an array...\n");
	fread(fileArray, sizeOfFile, 1, inFile);
	fileArray[sizeOfFile] = '\0';

	/* printf("This is the content of the file:\n\n");
	printf("%s\n", decryptedArray); */

	return fileArray;
}

int SizeOfFile(char * nameInFile)
{
	int size;
	FILE * file;
	file = fopen(nameInFile, "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	printf("After opening the file, I've determined its length\nto be: %d\n",
			size);
	return size;
}

char * Encrypt(char * KEY, char * fileContents, int size)
{
	char * output;

	printf("Size: %d\n", size);

	output = (char*)malloc(size * sizeof(char));

	printf("%s\n", fileContents);

	for(int i=0; i<size; i++)
	{
		if(KEY[fileContents[i] - 'A'] >= 'A' && KEY[fileContents[i] - 'A'] <=
				'Z')
		{
			output[i] = KEY[fileContents[i] - 'A'];
		}
		else
		{
			output[i] = fileContents[i];
		}
	}

	printf("The output is: \n\n%s\n\n", output);

	return output;
}

char * Decrypt(char * KEY, char * fileContents, int size)
{

}
