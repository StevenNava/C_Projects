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
	negative_numbers[50],
	positive_number_incrementor = 0,
	negative_number_incrementor = 0,
	all_number_incrementor = 0,
	number_string_incrementor = 0;
	bool all_numbers_read_successfully = true;

	/* prompt for numbers and read in values */
	printf("Enter in a list of numbers with spaces between them: ");
	fgets(line, sizeof(line), stdin);
	
	int l = 0; // number string incrementor
	int k = 0;
	int j = 0;
	int m = 0;
	/* for every character aside from ending character */
	for(int i = 0; i < strlen(line); i++) {
		if(line[i] != ' ' && line[i] != '\n') {
			number_string[number_string_incrementor] = line[i];
			number_string_incrementor++;
			continue;
		}
		
		number_string[number_string_incrementor] = '\0';
		number_string_incrementor = 0;
		number_read_successfully = sscanf(number_string, "%d", &all_numbers[all_number_incrementor]);
		if(number_read_successfully != 1) {
			all_numbers_read_successfully = false;
			break;
		}

		if(all_numbers[all_number_incrementor] >= 0) {
			positive_numbers[positive_number_incrementor] = all_numbers[all_number_incrementor];
			positive_number_count++;
			positive_number_incrementor++;
		} else {
			negative_numbers[negative_number_incrementor] = all_numbers[all_number_incrementor];
			negative_number_count++;
			negative_number_incrementor++;
		}
		all_number_incrementor++;
	}

	/* input validation */

	/* output results */
	printf("\nThere are %d positive numbers and %d negative numbers.\n", positive_number_count, negative_number_count);
	printf("Positive numbers:\n");
	for(int i = 0; i < positive_number_incrementor; i++) {
		printf("%d\n", positive_numbers[i]);
	}

	printf("Negative numbers:\n");
	for(int i = 0; i < negative_number_incrementor; i++) {
		printf("%d\n", negative_numbers[i]);
	}
}
