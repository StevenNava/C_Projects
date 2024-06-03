/********************************************************
 *							*
 *	Name:	 Print Numbers as Text			*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Prints a given number as its text	*
 *		 form.					*
 *							*
 *	Usage:	 Run program. Enter a whole number.	*
 *		 Program will determine the text form	*
 *		 for that number and print out that	*
 *		 number in text.			*
 *							*
 ********************************************************/

#include <stdio.h>

int main() {
	/* variable declaration */
	char line[50];
	int number_as_number;

	/* read input and input validation */
	while(1) {
		printf("Enter a whole number: ");
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%d", &number_as_number)) == 1) {
			break;
		}
		printf("\nInvalid input entered. Please try again.\n");
	}

	/* calculate text for number */

	/* print out number as text */
	printf("\nThe number you entered, %d, printed as text is %d.\n", number_as_number, number_as_number);
	return 0;
}
