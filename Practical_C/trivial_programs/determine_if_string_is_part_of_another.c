/************************************************************************
 *									*
 *	Name:	 Determine If One String Is Part of Another		*
 *									*
 *	Author:	 Steven Nava						*
 *									*
 *	Purpose: Determines if one string is part of another string.	*
 *									*
 *	Usage:	 Run program. Enter two strings of text. Program will	*
 *		 determine if the first string is the beginning of the	*
 *		 second string.						*
 *		 							*
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/********************************************************
 *							*
 *	Determine if first string begins the second	*
 *	string.						*
 *							*
 *	Parameters:					*
 *		string1 - first string			*
 *		string2	- second string			*
 *							*
 *	Retruns:					*
 *		true/false - if string2 contains 	*
 *			string1 as the beginning then	*
 *			returns true, else returns	*
 *			false				*
 *							*
 ********************************************************/
bool begins(char* string1, char* string2) {
	/* take last character - 1 (last actual character) and compare to same position in string 2 */
	for(int i = strlen(string1) - 1 ; i >= 0; i--) {
		/* if not the same, return false */
		if(string2[i] != string1[i]) {
			return false;
		}
	}
	/* if all characters are the same return true */
	return true;
}

int main() {
	/* variable declaration */
	char line[100],
	string1[100],
	string2[100];

	/* read in strings and input validation */
	while(true) {
		printf("Enter string 1: ");
		fgets(line, sizeof(line), stdin);
		if(sscanf(line, "%[^\n]s", &string1) == 1) {
			break;
		}
		printf("\nString invalid. Please try again.\n");
	}

	while(true) {
		printf("Enter string 2: ");
		fgets(line, sizeof(line), stdin);
		if(sscanf(line, "%[^\n]s", &string2) == 1) {
			break;
		}
		printf("\nString invalid. Please try again.\n");
	}

	if(begins(string1, string2)) {
		printf("\nString 1 is the beginning of string 2.\n");
	} else {
		printf("\nString 1 is not the beginning of string 2.\n");
	}


	return 0;
}
