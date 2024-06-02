/********************************************************************************
 *										*
 *	Name: 	 Print Multiplication Tables Through 20				*
 *										*
 *	Author:	 Steven Nava							*
 *										*
 *	Purpose: Prints out the multiplaction tables through 20.		*
 *										*
 *	Usage:	 Run program. Program prints out, calculates the mutliplication	*
 *		 tables and then prints it out.					*
 *		 								*
 ********************************************************************************/

#include <stdio.h>

int main() {
	/* variable declaration */
	int ending_number = 20;

	/* print out multiplication tables */
	/* print header row */
	printf("==============================================================================================================================================================================================\n");
	printf("|   x    ");
	for(int i = 1; i <= ending_number; i++) {
		if(i < 10) {
			printf("|   %d    ", i);
		} else {
			printf("|   %d   ", i);
		}
	}
	printf("|\n");

	for(int i = 1; i <= ending_number; i++) {
		/* print row marker */
		printf("==============================================================================================================================================================================================\n");
		/* print number marker */
		if(i >= 10) {
			printf("|   %d   ", i);
		} else {
			printf("|   %d    ", i);
		}
		/* print multiplication table */
		for(int j = 1; j <= ending_number; j ++) {
			if(i * j >= 100) {
				printf("|   %d  ", i * j);
			} else if(i * j >= 10) {
				printf("|   %d   ", i * j);
			} else {
				printf("|   %d    ", i * j);
			}
		}
		printf("|\n");
	}
	/* print footer row */
	printf("==============================================================================================================================================================================================\n");
	return 0;
}
