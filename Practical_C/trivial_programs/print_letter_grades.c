/********************************************************
 *							*
 *	Name: 	 Print Letter Grades			*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Trivial program to determine letter	*
 *		 grade for a student given a numeric	*
 *		 value and print it out.		*
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
	char line[100], character_eater[100], letter_grade;
	int number_read_status, numerical_grade;

	/* prompt for numeric grade */
	printf("Please enter a numerical grade: ");

	/* read in input */
	fgets(line, sizeof(line), stdin);

	/* attempt to store numic input into variable */
	number_read_status = sscanf(line, "%d", &numerical_grade);

	/* store non-numerical characters entered in */
	sscanf(line, "%s", &character_eater);

	/* input validation for correct data */
	while(number_read_status != 1 || numerical_grade < 0) {
		printf("\nA valid numerical grade was not entered in. Numerical grade must be greater than 0. Please try again\n");
		printf("Please enter a numerical grade.\n");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%d", &numerical_grade);
		sscanf(line, "%s", &character_eater);
	}

	/* calculate letter grade */
	if(numerical_grade > 90) {
		letter_grade = 'A';
	} else if(numerical_grade > 80) {
		letter_grade = 'B';
	} else if(numerical_grade > 70) {
		letter_grade = 'C';
	} else if(numerical_grade > 60) {
		letter_grade = 'D';
	} else {
		letter_grade = 'F';
	}

	/* print letter grade */
	printf("\nThe appropriate letter grade for a numerical grade of %d is: %c\n", numerical_grade, letter_grade);
	return(0); /* exit program with exit code 0 */
}
