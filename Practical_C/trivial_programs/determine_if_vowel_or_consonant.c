/************************************************************************
 *									*
 *	Name:	 Determine if Entered Character is Vowel or Consonant	*
 *									*
 *	Author:	 Steven Nava						*
 *									*
 *	Purpose: Determines if entered in character is a vowel or a	*
 *		 consonant.						*
 *		 							*
 *	Usage:	 Run program. Enter a character. Program determines	*
 *		 if character is a vowel or consonant and outputs the	*
 *		 results.						*
 *		 							*
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
int main() {
	/* variable declaration */
	char input_character,
	     line[50];

	/* read in input and input validation */
	while(1) {
		printf("Enter a character: ");
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%c", &input_character)) == 1 && ((int)tolower(input_character) >= 97 && (int)tolower(input_character) <= 122)) {
			break;
		}
		printf("\nInvalid input entered. Enter a single alphabetical character. Please try again.\n");
	}

	/* determine if character is a vowel or consonant */
	if(tolower(input_character) == 'a' ||
	   tolower(input_character) == 'e' ||
	   tolower(input_character) == 'i' ||
	   tolower(input_character) == 'o' ||
	   tolower(input_character) == 'u') {
		printf("\nInput character %c is a vowel.\n", input_character);
	} else {
		printf("\nInput character %c is a consonant.\n", input_character);
	}
	return 0;
}
