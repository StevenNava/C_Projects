/********************************************************
 *							*
 *	Name:	 Convert Minutes to Hours and 		*
 *	     	 Remaining Minutes 			*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Trivial program to take a given 	*
 *		 number of minutes and convert it 	*
 *		 to a number of hours and remaining	*
 *		 minutes.				*
 *		 					*
 *	Usage:	 Enter a number of minutes. Program	*
 *		 will convert it to a number of hours	*
 *		 and remaining minutes and print	*
 *		 out the results.			*
 *		 					*
 ********************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration*/
	char line[100], character_eater[100];
	int number_read_status, total_minutes, hours, minutes_remaining;

	/* prompt for number of minutes */
	printf("Enter the total number of minutes: ");

	/* read in user input */
	fgets(line, sizeof(line), stdin);

	/* try to store numeric value for total minutes */
	number_read_status = sscanf(line, "%d", &total_minutes);

	/* store all non-numeric characters */
	sscanf(line, "%s", &character_eater);

	/* input validation */
	while(number_read_status != 1) {
		printf("A valid number of minutes was not entered in. Please try again.\n");
		printf("Enter the total number of minutes: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%d", &total_minutes);
		sscanf(line, "%s", &character_eater);
	}

	/* calculate the number of hours and minutes */
	hours = total_minutes / 60;
	minutes_remaining = total_minutes % 60;

	/* print out the number of hours and minutes */
	printf("\nThe total number of hours and minutes equal to %d minutes is: %d hours and %d minutes\n", total_minutes, hours, minutes_remaining);
	return(0); /* exit with exit code 0 */
}
