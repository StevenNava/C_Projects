/****************************************************************
 *								*
 *	Name:	 Determine if Leap Year or Not			*
 *								*
 *	Author:	 Steven Nava					*
 *								*
 *	Purpose: Trivial program to determine if given year is 	*
 *		 leap year or not.				*
 *		 						*
 *	Usage:	 Enter a year. Program will determine if the	*
 *		 given year is a leap year and print the 	*
 *		 results.					*
 *								*
 ****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main () {
	/* variable declaration */
	char line[100],
	character_eater[100];
	int entered_year,
	number_read_status;
	bool leap_year = false; /* initializing leap year to false */

	/* prompt for year */
	printf("Enter in a year: ");
	
	/* read in user input */
	fgets(line, sizeof(line), stdin);

	/* attempt to store year in variable */
	number_read_status = sscanf(line, "%d", &entered_year);

	/* store all non-numerical characters entered in */
	sscanf(line, "%s", &character_eater);

	/* input validation */
	while(number_read_status != 1) {
		printf("\nA valid year wasn't entered in. Please try again.\n");
		printf("Enter in a year: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%d", &entered_year);
		sscanf(line, "%s", &character_eater);
	}

	/* determine if the given year is a leap year */
	if(entered_year % 4 == 0) {
		leap_year = true;
		if(entered_year % 100 == 0 && entered_year % 400 != 0) {
			leap_year = false;
		}
	}

	/* print out results */
	if(leap_year) {
		printf("\nYear %d is a leap year.\n", entered_year);
	} else {
		printf("\nYear %d is not a leap year.\n", entered_year);
	}
	return(0); /* exit program with exit code 0 */
}
