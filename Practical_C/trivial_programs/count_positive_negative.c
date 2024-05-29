/****************************************************************
 *								*
 *	Name:	 Calculate Positive and Negative Numbers	*
 *								*
 *	Author:	 Steven Nava					*
 *								*
 *	Purpose: Counts the number of positive numbers and 	*
 *		 negative numbers and prints out the counts	*
 *		 and numbers.					*
 *								*
 *	Usage:	 Run program and enter in number values 	*
 *		 separated by a space. Negative and positive	*
 *		 number counts will be calculated and the 	*
 *		 number of positive and negative values will	*
 *		 be printed out along with their respective	*
 *		 numbers.					*
 *		 						*
 ****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	/* variable declaration */
	char line[100],
	invalid_characters[100],
	number_string[10];
	int number_read_successfully,
	positive_number_count = 0,
	negative_number_count = 0,
	all_numbers[100],
	positive_numbers[50],
	negative_numbers[50];
	bool all_numbers_read_successfully = true;

	/* prompt for numbers and read in values */
	printf("Enter in a list of numbers with spaces between them: ");
	fgets(line, sizeof(line), stdin);
	
	int l = 0;
	int k = 0;
	/* for every character aside from ending character */
	for(int i = 0; i < strlen(line); i++) {
		if(line[i] != ' ' && line[i] != '\n') {
			number_string[l] = line[i];
			l++;
			continue;
		}

		l = 0;
		number_read_successfully = sscanf(number_string, "%d", &all_numbers[k]);
		if(number_read_successfully != 1) {
			all_numbers_read_successfully = false;
			break;
		}

		if(all_numbers[k] >= 0) {
			positive_numbers[k] = all_numbers[k];
			positive_number_count++;
		} else {
			negative_numbers[k] = all_numbers[k];
			negative_number_count++;
		}
		k++;
	}

	/* input validation */

	/* calculate positive and negative number totals */
	int size_of_array = sizeof(positive_numbers)/sizeof(int);
	/* output results */
	printf("\nThere are %d positive numbers and %d negative numbers.\n", positive_number_count, negative_number_count);
	printf("Positive numbers:\n");
	for(int i = 0; i < k; i++) {
		if(positive_numbers[i]) {
			printf("%d\n", positive_numbers[i]);
		}
	}
}
