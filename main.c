#include <stdio.h>
#include <string.h>
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
		Encrypt(KEY, fileContents, sizeOfFile);
	}
	else
	{
		/* Decrypt. */
	}
	
	

	return 0;
}
