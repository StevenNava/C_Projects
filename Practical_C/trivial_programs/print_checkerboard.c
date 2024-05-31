/****************************************************************
 *								*
 *	Name:	 Print Checkerboard				*
 *								*
 *	Author:	 Steven Nava					*
 *								*
 *	Purpose: Prints out an 8 x 8 checkerboard pattern 	*
 *		 using ASCII characters.			*
 *		 						*
 *	Usage:	 Run program. Program prints out 8 x 8 ASCII	*
 *		 checkerboard.					*
 *		 						*
 ****************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declarations */
	int rows = 8,
	columns = 8,
	row_height = 3, /* number of characters high for rows */
	column_width = 3; /* number of characters wide for columns */

	for(int i = 0; i < rows; i++) {
		/* print row dividers */
		for(int j = 0; j < columns; j++){
			printf("+");
			for(int k = 0; k < column_width; k++) {
				printf("-");
			}
		}
		printf("+\n");
		
		/* print column dividers */
		for(int l = 0; l < row_height; l++) {
			for(int m = 0; m < columns; m++) {
				printf("|");
				for(int n = 0; n < column_width; n++) {
					printf(" ");
				}
			}
			printf("|\n");
		}
	}

	/* print bottom row border */
	for(int j = 0; j < columns; j++){
		printf("+");
		for(int k = 0; k < column_width; k++) {
			printf("-");
		}
	}
	printf("+\n");
	return(0);
}
