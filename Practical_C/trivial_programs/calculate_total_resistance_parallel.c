/********************************************************************************
 *										*
 *	Name:	 Calculate Parallel Resistance (Total)				*
 *										*
 *	Author:	 Steven Nava							*
 *										*
 *	Purpose: Calculate total resistance of parallel resistors.		*
 *										*
 *	Usage:	 Run program. Enter a number of parallel resistors. Program	*
 *		 will calculate the total resistance and output it.		*
 *		 								*
 ********************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration */
	char line[50];
	int number_of_resistors,
	numerator = 1,
	numerator_multiplier,
	denominator = 400,
	total_numerator = 1;
	double last_denominator = 400,
	total_resistance;

	/* prompt and read in number of resistors */
	while(1) {
		printf("Enter the number of parallel resistors: ");
		fgets(line, sizeof(line), stdin);
		if(sscanf(line, "%d", &number_of_resistors) == 1) {
			break;
		}
		printf("\nInvalid entry. Enter in a whole number for the number of parallel resistors. Please try again.\n");
	}

	/* calculate total resistance */
	for(int i = 1; i < number_of_resistors; i++) {
		last_denominator /= 2;
		numerator_multiplier = denominator / last_denominator;
		
		total_numerator += numerator_multiplier;
	}

	total_resistance = (double)denominator / (double)total_numerator;

	/* output total resistance */
	printf("\nThe total resistance for %d parallel resistors is %.2lf ohms.\n", number_of_resistors, total_resistance);
	return(0);
}
