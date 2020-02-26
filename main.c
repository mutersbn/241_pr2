#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cipher.h"

int main(int argc, char * argv[])
{
	char * cryptionDirection = argv[1];
	char * wordKey = argv[2];
	char * nameInFile = argv[3];
	char * nameOutFile = argv[4];

	int sizeOfKey = strlen(wordKey);
	int sizeOfFile = SizeOfFile(nameInFile);

	char * KEY = RemoveDuplicates(wordKey, sizeOfKey);
	char * fileContents = GetFile(nameInFile);
	
	if(*cryptionDirection == 'e')
	{
		/* Encrypt. */
		char * encryptedFileContents = Encrypt(KEY, fileContents, sizeOfFile);
		PublishToFile(encryptedFileContents, nameOutFile, sizeOfFile);
		free(fileContents);
		free(KEY);
		free(encryptedFileContents);
	}
	else if(*cryptionDirection == 'd')
	{
		/* Decrypt. */
	}
	
	

	return 0;
}
