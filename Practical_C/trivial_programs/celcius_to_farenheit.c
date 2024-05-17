/********************************************************
 *							*
 *	Name:	 Celcius to Farenheit			*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Trivial program to explore functions	*
 *		 by converting celcius to farenheit.	*
 *		 					*
 *	Usage:	 Enter prompted celcius temperature.	*
 *		 Program will convert celcius to 	*
 *		 farenheit and print it out.		*
 *		 					*
 *	Notes:	 F = 9/5 C + 32				*
 *							*
 * ******************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration */
	char line[100]; /* line to store input in */
	char character_eater[100];
	double temperature_in_celcius, temperature_in_farenheit;
	double nine_fifths = 9.0 / 5.0;
	int number_read_status;

	/* prompt user for celcius temperature */
	printf("Enter a temperature in celcius: ");

	/* read in input from user */
	fgets(line, sizeof(line), stdin); 

	/* store temperature as numbers */
	number_read_status = sscanf(line, "%lf", &temperature_in_celcius);
	/* eat newline character or any entered character */
	sscanf(line, "%s", &character_eater);

	while (number_read_status != 1) {
		//while (character_eater != '\n' && (character_eater = getchar()) != EOF);
		printf("You did not enter a numeric temperature. Please try again.\n");
		printf("Enter a temperature in celcius: ");
		fgets(line, sizeof(line), stdin); 
		number_read_status = sscanf(line, "%lf", &temperature_in_celcius);
		sscanf(line, "%s", &character_eater);
	}
	/* convert temperature to farenheit */
	temperature_in_farenheit = nine_fifths * temperature_in_celcius + 32;	

	/* print temperature back out to user */
	printf("\nThe temperature in farenheit for the entered celcius temperature is %lf\n", temperature_in_farenheit);
	return(0); /* exit program with exit code 0 */
}
