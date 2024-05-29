/****************************************************************
 *								*
 *	Name:	 Prime Number Calculator			*
 *								*
 *	Author:	 Steven Nava					*
 *								*
 *	Purpose: Determines whether or not a number is prime.	*
 *								*
 *	Usage:	 Run program and enter in a number. Program	*
 *		 will determine if it is prime and output	*
 *		 the result.					*
 *		 						*
 ****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	/* variable declarations */
	char line[100],
	invalid_characters[100];
	int valid_input_entered,
	entered_number;
	bool is_prime = true;

	/* prompt for and read in number */
	printf("Enter in a number: ");
	fgets(line, sizeof(line), stdin);
	valid_input_entered = sscanf(line, "%d", &entered_number);
	sscanf(line, "%s", &invalid_characters);
	for(int i = 0; i < strlen(line); i++) {
		if(line[i] == '.') {
			/* value is a float */
			valid_input_entered = 0;
		}
	}

	/* input validation */
	while(valid_input_entered != 1) {
		printf("\nA valid whole number was not entered in. Please try again.\n");	
		printf("Enter in a number: ");
		fgets(line, sizeof(line), stdin);
		valid_input_entered = sscanf(line, "%d", &entered_number);
		sscanf(line, "%s", &invalid_characters);
		for(int i = 0; i < strlen(line); i++) {
			if(line[i] == '.') {
				/* value is a float */
				valid_input_entered = 0;
			}
		}
	}

	/* calculate if number is prime */
	for(int i = 2; i <= (entered_number / 2); i++) {
		if(entered_number % i == 0) {
			is_prime = false;
			break;
		}
	}

	/* output results */
	if(is_prime) {
		printf("\n%d is a prime number.\n", entered_number);
	} else {
		printf("\n%d is not a prime number.\n", entered_number);
	}

	return(0);
}
