/********************************************************
 *							*
 *	Name:	 Gallons to Liters			*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Converts gallons to equivalent number 	*
 *		 of liters and prints out the result.	*
 *		 					*
 *	Usage:	 Run the program and enter in an amount	*
 *		 of gallons in whole number or decimal	*
 *		 form. The equivalent number of liters	*
 *		 will be displayed.			*
 *		 					*
 ********************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration */
	char line[100],
	invalid_input[100];
	int number_read_status,
	number_of_decimal_points = 0; /* starting with 0 decimal points */
	double number_of_liters,
	number_of_gallons;

	/* prompt for number of liters and read in input */
	printf("Enter in the number of gallons you would like converted into liters: ");
	fgets(line, sizeof(line), stdin);
	for(int i = 0; i < strlen(line); i++) {
		if(line[i] == '.') {
			number_of_decimal_points += 1;
		}
	}
	number_read_status = sscanf(line, "%lf", &number_of_gallons);
	sscanf(line, "%s", &invalid_input); /* read in all invalid characters to consume them */

	/* input validation */
	while(number_read_status != 1 || number_of_decimal_points > 1) {
		number_of_decimal_points = 0; /* re-setting number of decimal points to 0 for each loop */
		printf("\nA valid number of gallons was not entered in. Please try again.\n");
		printf("Enter in the number of gallons you would like converted into liters: ");
		fgets(line, sizeof(line), stdin);
		for(int i = 0; i < strlen(line); i++) {
			if(line[i] == '.') {
				number_of_decimal_points += 1;
			}
		}
		number_read_status = sscanf(line, "%lf", &number_of_gallons);
		sscanf(line, "%s", &invalid_input); /* read in all invalid characters to consume them */
	}

	/* convert gallons to liters */
	number_of_liters = number_of_gallons * 3.78541178; /* 1 gallon = 3.78541178 liters */

	/* display results */
	printf("\nThe number of liters equivalent to %.2lf gallons is approximately %.2lf liters.\n", number_of_gallons, number_of_liters);
	return(0); /* exit program with exit code 0 */
}
