/********************************************************
 *							*
 *	Name: 	 Calculate Change in Coins		*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: This program calculates the 		*
 *		 equivalent change in quarters, dimes,	*
 *		 nickels, and pennies given an amount	*
 *		 less than $1.00.			*
 *		 					*
 *	Usage:	 Enter an amount less than $1.00 in	*
 *		 the format .## where ## represents	*
 *		 numbers. The program will calculate	*
 *		 the equivalent amount in change and 	*
 *		 print out the numbers of quarters,	*
 *		 dimes, nickels, and pennies.		*
 *		 					*
 ********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	/* variable declarations */
	char line[100], clean_input_string[100];
	int number_of_quarters, 
	number_of_dimes,number_of_nickels, 
	number_of_pennies, 
	cents_amount_entered_in, amount_left,
	found_numbers = 0, improper_characters = 0, 
	length_of_input, proper_decimal_position;
	bool has_cents = false;

	/* prompt for amount of change less than $1.00 */
	printf("Enter in a currency amount to be converted to quarters, dimes, nickels, and pennies: ");

	/* read in input */
	fgets(line, sizeof(line), stdin);

	/* remove any non-numeric characters */
	int j = 0;
	for(int i = 0; i < strlen(line); i++) {
		if(line[i] == '0' ||
		   line[i] == '1' ||
		   line[i] == '2' ||
		   line[i] == '3' ||
		   line[i] == '4' ||
		   line[i] == '5' ||
		   line[i] == '6' ||
		   line[i] == '7' ||
		   line[i] == '8' ||
		   line[i] == '9') {
			clean_input_string[j] = line[i];
			j++;
			found_numbers++;
		} else if (line[i] == '.') {
			proper_decimal_position = strlen(line) - 4;
			if (i == proper_decimal_position) {
				has_cents = true;
			} else {
				improper_characters++;
			} 
		/* if character is part of a normal keyboard charset */
		} else if ((int)line[i] >= 32 && (int)line[i] <= 126) {
			improper_characters++;
		}
	}
	clean_input_string[j] = '\0';

	while(found_numbers < 1 || improper_characters > 0) {
		printf("\nA valid amount was not entered in. The amount must be less than $1.00 in format '.##'. Please try again.\n");
		printf("Enter in a currency amount to be converted to quarters, dimes, nickels, and pennies: ");
		fgets(line, sizeof(line), stdin);
		found_numbers = 0;
		improper_characters = 0;
		j = 0;
		for(int i = 0; i < strlen(line); i++) {
			if(line[i] == '0' ||
		   	line[i] == '1' ||
		   	line[i] == '2' ||
		   	line[i] == '3' ||
		   	line[i] == '4' ||
		   	line[i] == '5' ||
		   	line[i] == '6' ||
		   	line[i] == '7' ||
		   	line[i] == '8' ||
		   	line[i] == '9') {
				clean_input_string[j] = line[i];
				j++;
				found_numbers++;
			} else if (line[i] == '.') {
				proper_decimal_position = strlen(line) - 4;
				if (i == proper_decimal_position) {
					has_cents = true;
				} else {
					improper_characters++;
				} 
			/* if character is part of a normal keyboard charset */
			} else if ((int)line[i] >= 32 && (int)line[i] <= 126) {
				improper_characters++;
			}
		}
		clean_input_string[j] = '\0';
	}

	sscanf(clean_input_string, "%d", &cents_amount_entered_in); 
	
	/* check for decimal to see if we are dealing with whole numbers or input has cents */
	if (has_cents == false) {
		printf("has cents");
		cents_amount_entered_in *= 100;
	}

	/* try to store input into variable */
	//number_read_status = sscanf(line, "%d", &cents_amount_entered_in);

	/* store all non-numeric characters entered in */
	//sscanf(line, "%s", &character_eater);

	/* input validation */
	/*while(number_read_status != 1 || cents_amount_entered_in > 99) {
		printf("\nA valid amount was not entered in. The amount must be less than $1.00 in format '.##'. Please try again.\n");
		printf("Enter in an amount less than $1.00 to be converted to quarters, dimes, nickels, and pennies: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%d", &cents_amount_entered_in);
		sscanf(line, "%s", &character_eater);
	}*/

	/* calculate change in quarters, dimes, nickels, and pennies */
	number_of_quarters = (cents_amount_entered_in / 25);
	amount_left = cents_amount_entered_in - number_of_quarters * 25;
	number_of_dimes = (amount_left / 10);
	amount_left -= number_of_dimes * 10;
	number_of_nickels = (amount_left / 5);
	amount_left = (amount_left - number_of_nickels * 5);
	amount_left = (amount_left / 1);
	number_of_pennies = amount_left;

	/* print out change in quarters, dimes, nickels, and pennies */
	printf("\nThe number of quarters, dimes, nickels, and pennies equivalent to %d are as follows:\n", cents_amount_entered_in);
	printf("\tQuarters: %d\n", number_of_quarters);
	printf("\tDimes: %d\n", number_of_dimes);
	printf("\tNickels: %d\n", number_of_nickels);
	printf("\tPennies: %d\n", number_of_pennies);
	return(0); /* exit program with exit code 0 */
}
