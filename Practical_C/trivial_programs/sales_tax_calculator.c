/****************************************************************
 * 								*
 * 	Name:	 Sales Tax Calculator				*
 * 								*
 * 	Author:	 Steven Nava					*
 * 								*
 * 	Purpose: Calculates price + sales tax for a given	*
 * 		 price and prints out value rounded to		*
 * 		 nearest penny.					*
 * 		 						*
 * 	Usage:	 Enter valid amount in decimal format.		*
 * 		 Program calculates price + sales tax and	*
 * 		 outputs total price with sales tax rounded	*
 * 		 to the nearest penny.				*
 * 		 						*
 * 	Notes:	 Sales tax is assumed to be 8%.			*
 * 								*
 ****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	/* variable declaration */
	char line[50],
	invalid_characters[50];
	int number_of_decimals = 0,
	price_without_sales_tax_in_pennies;
	double price_without_sales_tax,
	price_with_sales_tax;
	bool input_invalid = false;

	/* prompt and read in price */
	printf("Enter the price of the item: ");
	fgets(line, sizeof(line), stdin);
	
	/* input validation */
	line[strlen(line) - 1] = '\0';
	for(int i = 0; i < strlen(line); i++) {
		if(line[i] != '1' &&
		   line[i] != '2' &&
		   line[i] != '3' && 
		   line[i] != '4' &&
		   line[i] != '5' &&
		   line[i] != '6' &&
		   line[i] != '7' &&
		   line[i] != '8' &&
		   line[i] != '9' &&
		   line[i] != '0') {
			if(line[i] == '.' && number_of_decimals < 1) {
				number_of_decimals++;
			} else {
				input_invalid = true;
			}
		}
	}

	while(input_invalid) {
		number_of_decimals = 0; /* resetting number of decimals found to 0 */
		input_invalid = false; /* resetting input invalid to false  for another try */
		printf("\nValid price was not entered in. Please try again.\n");
		printf("Enter the price of the item: ");
		fgets(line, sizeof(line), stdin);
	
		/* input validation */
		line[strlen(line) - 1] = '\0';
		for(int i = 0; i < strlen(line); i++) {
			if(line[i] != '1' &&
		   	line[i] != '2' &&
		   	line[i] != '3' && 
		   	line[i] != '4' &&
		   	line[i] != '5' &&
		   	line[i] != '6' &&
		   	line[i] != '7' &&
		   	line[i] != '8' &&
		   	line[i] != '9' &&
		   	line[i] != '0') {
				if(line[i] == '.' && number_of_decimals < 1) {
					number_of_decimals++;
				} else {
					input_invalid = true;
				}
			}
		}
	}

	sscanf(line, "%lf", &price_without_sales_tax);
	sscanf(line, "%s", &invalid_characters);

	/* calculate price with sales tax */
	price_without_sales_tax_in_pennies = price_without_sales_tax * 100;

	price_with_sales_tax = price_without_sales_tax_in_pennies * .0108;

	printf("\nThe price with sales tax for an item with price $%.2lf is $%.2lf.\n", price_without_sales_tax, price_with_sales_tax);

	return(0);
}
