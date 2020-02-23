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

	/* printf("This is what I read from the buffer:\n");
	printf("%s %s %s %s\n", cryptionDirection, wordKey,
			nameInFile, nameOutFile);
*/
	//printf("Trying to access file...\n");
	//GetFile("THE_VOICE.txt");
	
	RemoveDuplicates(wordKey, sizeOfKey);
	
	if(*cryptionDirection == 'e')
	{
		/* Encrypt. */
	}
	else
	{
		/* Decrypt. */
	}

	return 0;
}
