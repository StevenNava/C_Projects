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

/****************************************************************
 *								*
 *	Computes the number of words in a string 		*
 *								*
 *	Parameters						*
 *		input - the string to have words counted for	*
 *								*
 *	Returns							*
 *		count - the number of words in the string	*
 *								*
 ****************************************************************/
int Count_Words(char* input) 
{
	int count = 0;
	for(int i = 0; input[i] != '\0'; i++) {
		if(input[i] == ' ' || input[i] == '\n') {
			count++;
		} 
	}
	count++;
	return count;
}

int main() {
	/* variable declaration */
	char line[100],
	string_of_words[100];

	/* read input and input validation */
	while(1) {
		printf("Enter a string of words seperated by spaces: ");
		fgets(line, sizeof(line), stdin);
		/* "%[^\n]s" sets the delimeter for reading in the string to a newline character */
		if(sscanf(line, "%[^\n]s", &string_of_words) == 1) {
			break;
		}
		printf("\nInvalid input. Please try again.\n");
	}
	
	/* output */
	printf("\nThe number of words in the string you entered is: %d", Count_Words(string_of_words));
	return 0;
}
