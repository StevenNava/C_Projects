/********************************************************
 *							*
 *	Name: 	 Print Letter Grades			*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Trivial program to determine letter	*
 *		 grade for a student given a numeric	*
 *		 value and print it out. This version	*
 *		 prints out with a +/- grade as well.	*
 *		 This program takes in numeric values	*
 *		 between 0 and 100. Any others will be	*
 *		 considered invalid.			*
 *							*
 *	Usage:	 Input a numeric grade value. Program	*
 *		 will calculate letter grade and 	*
 *		 print it out.				*
 *		 					*
 ********************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration */
	char line[100], character_eater[100], letter_grade[3];
	int number_read_status, numerical_grade, remainder_of_division_by_ten;

	/* prompt for numeric grade */
	printf("Please enter a numerical grade: ");

	/* read in input */
	fgets(line, sizeof(line), stdin);

	/* attempt to store numic input into variable */
	number_read_status = sscanf(line, "%d", &numerical_grade);

	/* store non-numerical characters entered in */
	sscanf(line, "%s", &character_eater);

	/* input validation for correct data */
	while(number_read_status != 1 || numerical_grade < 0 || numerical_grade > 100) {
		printf("\nA valid numerical grade was not entered in. Numerical grade must be between 0 and 100. Please try again\n");
		printf("Please enter a numerical grade.\n");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%d", &numerical_grade);
		sscanf(line, "%s", &character_eater);
	}

	/* calculate letter grade */
	if(numerical_grade > 90) {
		strcpy(letter_grade, "A");
	} else if(numerical_grade > 80) {
		strcpy(letter_grade, "B");
	} else if(numerical_grade > 70) {
		strcpy(letter_grade, "C");
	} else if(numerical_grade > 60) {
		strcpy(letter_grade, "D");
	} else {
		strcpy(letter_grade, "F");
	}

	/* calculate +/- */
	if(numerical_grade > 60) {
		/* calculate remainder of division by 10 to determine if a +/- is needed */
		remainder_of_division_by_ten = numerical_grade % 10;

		if(remainder_of_division_by_ten >= 1 && remainder_of_division_by_ten <= 3) {
			strcat(letter_grade, "-");
		} else if(remainder_of_division_by_ten == 0 || (remainder_of_division_by_ten >= 8 && remainder_of_division_by_ten <= 9)) {
			strcat(letter_grade, "+");
		}
	}

	/* print letter grade */
	printf("\nThe appropriate letter grade for a numerical grade of %d is: %s\n", numerical_grade, letter_grade);
	return(0); /* exit program with exit code 0 */
}
