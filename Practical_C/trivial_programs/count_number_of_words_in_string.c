/********************************************************************************
 *										*
 *	Name:	 Count the Number of Words in a String				*
 *										*
 *	Author:	 Steven Nava							*
 *										*
 *	Purpose: Counts the number of words in a string and outputs the result.	*
 *										*
 *	Usage:	 Run program. Enter in a string of words seperated by spaces.	*
 *		 Program will calculate the number of words in the string	*
 *		 and print it out on the screen.				*
 *		 								*
 ********************************************************************************/

#include <stdio.h>

int main() {
	/* variable declaration */
	char line[100],
	string_of_words;

	/* read input and input validation */
	while(1) {
		printf("Enter a string of words seperated by spaces: ");
		fgets(line, sizeof(line), stdin);
		if(sscanf(line, "%s", &string_of_words) == 1) {
			break;
		}
		printf("\nInvalid input. Please try again.\n");
	}

	/* output */
	printf("\nThe number of words in the string you entered is: %d", count_words_in_string(string_of_words));
	return 0;
}

/* function for counting words */
