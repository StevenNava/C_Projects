/********************************************************************************
 *										*
 *	Name: 	 Calculate Total Resistance by Prompts				*
 *										*
 *	Author:	 Steven Nava							*
 *										*
 *	Purpose: Calculate total resistance by prompting for each resistor 	*
 *		 in parallel.							*
 *		 								*
 *	Usage:	 Run program. Enter in resistors for the number of resistors	*
 *		 prompted. Total resistance will be calculated and output.	*
 *		 								*
 ********************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration */
	char line[50],
	invalid_characters[50];
	int number_of_resistors,
	number_read_in_successfully,
	numerator,
	total_numerator,
	denominator,
	first_denominator,
	temporary_value;
	double resistor_decimal,
	total_resistor_value,
	total_resistance;

	/* prompt and read in number of resistors */
	printf("Enter the total number of resistors: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &number_of_resistors);

	/* prompt for all resistors */
	for(int i = 0; i < number_of_resistors; i++) {
		printf("\nEnter the resistor denominator: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &denominator);

		/* convert resistor to decimal value and add to totals */
		resistor_decimal = (double)1 / (double)denominator;
		total_resistor_value += resistor_decimal;
	}

	total_resistance = (double)1 / total_resistor_value;

	printf("\nThe total resistance for the %d resistors you entered in is %.2lf ohms.\n", number_of_resistors, total_resistance);

	return(0);
}
