/************************************************************************
 *									*
 *	Name:	 Replace Character in String				*
 *									*
 *	Author:	 Steven Nava						*
 *									*
 *	Purpose: Replaces a character in a given string with a given	*
 *		 character.						*
 *		 							*
 *	Usage:	 Run program. Enter a string of characters. Enter a 	*
 *		 character to search for. Enter a character to replace	*
 *		 this character with.					*
 *		 							*
 ************************************************************************/

#include <stdio.h>
#include <string.h>

/************************************************
 *						*
 *	Replace a Character in a String		*
 *						*
 *	Parameters				*
 *	char_array				*
 *		- an array of characters	*
 *						*
 *	search_char				*
 *		- character to search for	*
 *						*
 *	replace_char				*
 *		- character to be replaced	*
 *						*
 *	length					*
 *		- length of the string		*
 *						*
 ************************************************/
char *Replace_in_String(char *char_array, char search_char, char replace_char, int length) {
	if(length == 0) {
		return char_array;
	} else {
		length -= 1;
		if(char_array[length] == search_char) {
			char_array[length] = replace_char;
		}
		return Replace_in_String(char_array, search_char, replace_char, length);
	}
}

int main() {
	/* variable declaration */
	char search_char,
	replace_char,
	char_array[50],
	line[3];
	
	/* read in character array */
	printf("Enter a string of characters: ");
	fgets(char_array, sizeof(char_array), stdin);

	/* read in search char */
	while(1) {
		printf("\nEnter a character to search the array for: ");
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%c", &search_char)) == 1) {
			break;
		}
		printf("\nInvalid input entered. Enter a single character to search for. Please try again.\n");
	}

	/* read in replace char */
	while(1) {
		printf("\nEnter a character to replace with if the search character is found: ");
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%c", &replace_char)) == 1) {
			break;
		}
		printf("\nInvalid input entered. Enter a single character to use as a replacement character. Please try again.\n");
	}

	strcpy(char_array, Replace_in_String(char_array, search_char, replace_char, strlen(char_array)));

	printf("\nThe new string with the characters replaced is: %s\n", char_array);
	return 0;	
}
