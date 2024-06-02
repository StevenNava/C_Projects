/************************************************************************
 *									*
 *	Name:	 Average Given Number of Numbers			*
 *									*
 *	Author:	 Steven Nava						*
 *									*
 *	Purpose: Averages a given number of numbers entered in by user.	*
 *									*
 *	Usage:	 Run program. Enter the number of numbers to be		*
 *		 averaged. Enter the numbers -- these will be totalled	*
 *		 and then averaged and output by the program.		*
 *		 							*
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main() {
	/* variable declaration */
	char line[50];
	int number_of_numbers_to_average, 
	whole_numbers,
	partial_numbers,
	whole_numbers_total = 0,
	partial_numbers_total = 0,
	i = 1;
	double average;

	/* read in and store values */
	while(true) {
		printf("Enter the number of numbers to be averaged: ");
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%d", &number_of_numbers_to_average)) != 1 || number_of_numbers_to_average < 2) {
			printf("\nA valid number of numbers to be averaged was not entered in. Please enter in a valid number greater than 2.\n");
			continue;
		}
		while(i <= 3) {
			/* read in variables and input validation */
			printf("\nEnter number %d: ", i);
			fgets(line, sizeof(line), stdin);
			if((sscanf(line, "%d.%d", &whole_numbers, &partial_numbers)) != 2) {
				printf("\nValid input was not entered. Please enter the number of numbers to be averaged and the numbers in ##.## format.\n");
				continue;
			}
			whole_numbers_total += whole_numbers;
			partial_numbers_total += partial_numbers;
			i++;
		}
		break;
	}
	printf("\nWhole Numbers: %d   Partial Numbers: %d \n", whole_numbers_total, partial_numbers_total);
	/* calculate average and output */
	average = (double)((whole_numbers_total * 100) + partial_numbers_total) / (double)(number_of_numbers_to_average * 100);
	
	printf("\nThe average of the %d numbers you entered in is %.2lf.\n", number_of_numbers_to_average, average);
	return 0;
}
