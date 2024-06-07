/************************************************************************
 *									*
 *	Name: 	 Count Number in Array Recursive			*
 *									*
 *	Author:	 Steven Nava						*
 *									*
 *	Purpose: Counts the number of occurrences in an array using	*
 *		 recursion.						*
 *		 							*
 *	Usage:	 Run program. Enter 10 integers for the array. Last,	*
 *		 enter the search number. The program will count	*
 *		 the number of occurrences of the search number in the	*
 *		 array.							*
 *		 							*
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int count(int number, int number_array[], int length) {
	int counter = 0;
	for(int i = 0; i < length; i++) {
		if(number_array[i] == number) {
			counter++;
		}
	}
	return counter;
}

int count_recursive(int number, int number_array[], int length) {
	int counter = 0;
	if(length > 0) {
		counter += count_recursive(number, number_array, length - 1);
	}
	if (number_array[length - 1] == number) {
		counter += 1;
	}
	return counter;
}

int main() {
	/* variable declaration */
	char line[50];
	int count_of_occurrences = 0,
	search_number,
	length_of_array;

	/* prompt for values and input validation */
	while(1) {
		printf("Enter the number of integers for the array: ");
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%d", &length_of_array)) == 1) {
			break;
		}
		printf("\nInvalid entry. Enter a valid positive integer. Please try again.\n");
	}

	int *number_array = malloc(sizeof(int) * length_of_array);

	for(int i = 0; i < length_of_array; i++) {
		while(1) {
			printf("Enter number %d for the array: ", i + 1);
			fgets(line, sizeof(line), stdin);
			if((sscanf(line, "%d", &number_array[i])) == 1) {
				break;
			}
			printf("\nInvalid input entered. Entry must be a valid integer. Please try again.\n");
		}
	}
	
	while(1) {
		printf("Enter a number to search the array for: ");
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%d", &search_number)) == 1) {
			break;
		}
		printf("\nInvalid number to search entered. Please try again.\n");
	}

	count_of_occurrences = count_recursive(search_number, number_array, length_of_array);
	printf("\nThe count of occurrences for number %d in the string of numbers is: %d times.\n", search_number, count_of_occurrences);
	free(number_array);
}
