/********************************************************
 *							*
 *	Name:	 Hours and Minutes to Total Minutes	*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Trivial program that converts a 	*
 *		 given number of hours and minutes	*
 *		 to total minutes and prints the 	*
 *		 result.				*
 *		 					*
 *	Usage:	 Enter a number of hours and minutes.	*
 *		 Program will calculate the total	*
 *		 number of minutes and print the	*
 *		 result.				*
 *		 					*
 ********************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration */
	char line[100], character_eater[100];
	int number_read_status, hours, minutes, total_minutes;

	/* prompt for total number of hours */
	printf("Enter the total number of hours: ");

	/* read in user input */
	fgets(line, sizeof(line), stdin);

	/* try to store numeric value for hours */
	number_read_status = sscanf(line, "%d", &hours);

	/* store any non-numeric characters entered */
	sscanf(line, "%s", &character_eater);

	/* input validation for number of hours */
	while(number_read_status != 1) {
		printf("A valid number of hours was not entered. Please try again.\n");
		printf("Enter the total number of hours: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%d", &hours);
		sscanf(line, "%s", &character_eater);
	}

	/* prompt for total number of minutes */
	printf("Enter the total number of minutes: ");

	/* read in user input */
	fgets(line, sizeof(line), stdin);

	/* try to store numeric value for minutes */
	number_read_status = sscanf(line, "%d", &minutes);

	/* store any non-numeric characters entered */
	sscanf(line, "%s", &character_eater);

	/* input validation for number of minutes */
	while(number_read_status != 1) {
		printf("A valid number of minutes was not entered. Please try again.\n");
		printf("Enter the total number of minutes: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%d", &minutes);
		sscanf(line, "%s", &character_eater);
	}

	/* calculate total number of minutes */
	total_minutes = hours * 60 + minutes;

	/* print out total number of minutes */
	printf("\nThe total number of minutes for %d hours and %d minutes is: %d minutes\n", hours, minutes, total_minutes);
	return(0); /* exit with exit code 0 */
}
