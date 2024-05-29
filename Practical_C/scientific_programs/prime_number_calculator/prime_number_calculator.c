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
	int entered_number;
	bool is_prime = true;

	/* prompt for and read in number */
	printf("Enter in a number: \n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &entered_number);

	/* input validation */

	/* calculate if number is prime */
	for(int i = 1; i < (entered_number / 2); i++) {
		if(entered_number % i == 0) {
			is_prime = false;
			break;
		}
	}

	/* output results */
	if(is_prime) {
		printf("%d is a prime number.", entered_number);
	} else {
		printf("%d is not a prime number.", entered_number);
	}

	return(0);
}
