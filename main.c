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

	char * KEY = StandardizeKEY(wordKey, sizeOfKey);
	char * fileContents = GetFile(nameInFile);

	printf("cryptionDirection: %s\n", cryptionDirection);
	
	if(strcmp(argv[1], "e\0") == 0)
	{
		/* Encrypt. */
		char * encryptedFileContents = Encrypt(KEY, fileContents, sizeOfFile);
		PublishToFile(encryptedFileContents, nameOutFile, sizeOfFile);
		free(fileContents); // COMPLETED: FREE 'fileContents'
		//free(KEY); // COMPLETED: FREE 'KEY'
		free(encryptedFileContents); // COMPLETED: FREE 'output'
	}
	else if(strcmp(argv[1], "d\0") == 0)
	{
		/* Decrypt. */
		char * decryptedFileContents = Decrypt(KEY, fileContents, sizeOfFile);
		PublishToFile(decryptedFileContents, nameOutFile, sizeOfFile);
		free(fileContents);
		//free(KEY);
		free(decryptedFileContents);
	}
	
	return 0;
}
