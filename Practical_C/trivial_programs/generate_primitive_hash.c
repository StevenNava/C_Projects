/****************************************************************
 *								*
 *	Name:	 Generate Primitive Hash			*
 *								*
 *	Author:	 Steven Nava					*
 *								*
 *	Purpose: Generates a primitive hash by adding up ASCII	*
 *		 number for each character.			*
 *		 						*
 *	Usage:	 Run program. Enter string. Program will	*
 *		 generate hash recursively and output it.	*
 *								*
 ****************************************************************/

#include <stdio.h>
#include <string.h>

/************************************************
 *						*
 *	Generate hash				*
 *						*
 *	Parameters				*
 *		input_string - string of 	*
 *		characters			*
 *						*
 *		length - length of string	*
 *						*
 *	Return					*
 *		hash_value - integer value hash *
 *		made up of all ASCII values	*
 *		of string characters added	*
 *		together			*
 *						*
 ************************************************/
int Generate_Hash(char *input_string, int length) {
	int count = 0;
	if(length > 0) {
		count += Generate_Hash(input_string, length - 1);
	}
	count += (int)input_string[length - 1];
	return count;
}

int main() {
	/* variable declaration */
	char line[100],
	input_string[100];
	int hash;
	
	/* prompt and reading in character string */
	while(1) {
		printf("Enter a string of characters: ");
		fgets(line, sizeof(line), stdin);
		/* set delimiter for sscanf to \n character */
		if((sscanf(line, "%[^\n]s", &input_string)) == 1) {
			break;
		}
		printf("\nInvalid value entered. Please try again.\n");
	}

	hash = Generate_Hash(input_string, strlen(input_string));
	printf("\nThe hash for the entered input string is: %d\n", hash);
	return 0;
}
