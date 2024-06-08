/****************************************************************
 *								*
 *	Name:	 Largest Number in Array			*
 *								*
 *	Author:	 Steven Nava					*
 *								*
 *	Purpose: Find the largest number in an array of numbers *
 *		 and output it.					*
 *		 						*
 *	Usage:	 Run program. Enter the number of numbers in 	*
 *		 the array. Enter the numbers. The largest	*
 *		 number will be calculated and printed out.	*
 *		 						*
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>

/************************************************
 *						*
 *	Calculate largest number in array	*
 *						*
 *	Parameters				*
 *	array					*
 *		- number array			*
 *						*
 *	length					*
 *		- length of the number array	*
 *						*
 *	Returns					*
 *	max_number				*
 *		- maximum nuber in array	*
 *						*
 ************************************************/
int Calculate_Largest_Number(int array[], int length, int max_number) {
	if (length > 0) {
		max_number = Calculate_Largest_Number(array, length - 1, max_number);
	}

	if (array[length - 1] > max_number) {
		max_number = array[length - 1];
	}

	return max_number;
}

int main() {
	/* variable declaration */
	char line[10];
	int number_of_numbers,
	maximum_number_in_array;

	/* read in number of numbers and input validation */
	while(1) {
		printf("Enter the number of numbers for the array: ");
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%d", &number_of_numbers)) == 1 && number_of_numbers > 0) {
			break;
		}
		printf("\nInvalid input entered. Enter a positive whole number. Please try again.\n");
	}

	int *number_array = malloc(sizeof(int) * number_of_numbers);
	
	/* read in all numbers into number array */
	for(int i = 0; i < number_of_numbers; i++) {
		while(1) {
			printf("\nEnter number %d: ", i + 1);
			fgets(line, sizeof(line), stdin);
			if((sscanf(line, "%d", &number_array[i])) == 1) {
				break;
			}
			printf("\nInvalid input. Enter a whole number. Please try again.\n");
		}
	}

	maximum_number_in_array = Calculate_Largest_Number(number_array, number_of_numbers, 0);
	printf("\nThe maximum number in the array is:  %d\n", maximum_number_in_array);
	free(number_array);
	return 0;
}
