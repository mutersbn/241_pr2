/*
 * Author: Noah Mutersbaugh
 * Date: 02/14/2020
 * Name of File: cipher.h
 * Description: This is the header file that declares each function used in the
 * substitution cipher.
 */

void prepend(char * s, const char * t);
void reverse(char * array, int sizeOfArray);
char * StandardizeKEY(char * key, int sizeOfKey);
char * GetFile(char * fileName);
int SizeOfFile(char * fileName);
char * Encrypt(char * KEY, char * fileContents, int size);
char * Decrypt(char * KEY, char * fileContents, int size);
void PublishToFile(char * fileContents, char * fileName, int size);
