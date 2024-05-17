/********************************************************
 *							*
 *	Name:	 Convert Miles per Hour to Kilometers	*
 *		 per Hour				*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Trivial program to convert an entered	*
 *		 rate of miles per hour to the		*
 *		 equivalent number of kilometers per	*
 *		 hour.					*
 *		 					*
 *	Usage:	 Enter a rate of miles per hour. 	*
 *		 Program will calculate the equivalent	*
 *		 speed in kilometers per hour and	*
 *		 print it out.				*
 *		 					*
 *	Notes:	 Miles = Kilometers * .6213712		*
 *							*
 ********************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration */
	char line[100], character_eater[100];
	int number_read_status;
	double miles_per_hour, kilometers_per_hour;

	/* prompt for a number of miles per hour */
	printf("Enter the number of miles per hour: ");

	/* read in user input */
	fgets(line, sizeof(line), stdin);

	/* try to store numeric value */
	number_read_status = sscanf(line, "%lf", &miles_per_hour);

	/* store any entered non-numeric characters */
	sscanf(line, "%s", &character_eater);

	/* input validation */
	while(number_read_status != 1) {
		printf("A valid numeric miles per hour was not entered. Please try again.\n");
		printf("Enter the number of miles per hour: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%lf", &miles_per_hour);
		sscanf(line, "%s", &character_eater);
	}

	/* calculate kilometers per hour */
        kilometers_per_hour = miles_per_hour / .6213712;

	/* print kilometers per hour */
	printf("\nThe kilometers per hour equivalent to %lf miles per hour is: %lf kilometers per hour\n", miles_per_hour, kilometers_per_hour);
	return(0); /* exit program with exit code 0 */
}
