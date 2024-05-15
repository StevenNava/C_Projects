/****************************************************************
 *								*
 *	Name: 	  Errors in Printing				*
 *		 						*
 *	Author:	  Steven Nava					*
 *								*
 *	Purpose:  Trivial program that shows errors in 		*
 *		  printing different types.			*
 *								*
 *	Usage:	  Run program and it prints types that are	*
 *		  passed into the printf function as 		*
 *		  different types.				*
 *								*
 ****************************************************************/

#include <stdio.h>

int main() {
	float float_example = 1.82; /* example of a float */
	int integer_example = 3; /* example of an integer */
	char character_example = 'c'; /* example of a character */
	
	printf("\nErrors in Printing Types\n");
	printf("-----------------------------\n");
	printf("Printing a float '1.82' as an integer: %d\n", float_example);
	printf("Printing an integer '3' as a float: %f\n", integer_example);
	printf("Printing a charcter 'c' as an integer: %d\n", character_example);

	
	printf("\nProper Printing\n");
	printf("-----------------------------\n");
	printf("Printing a float '1.82': %f\n", float_example);
	printf("Printing an integer '3': %d\n", integer_example);
	printf("Printing a charcter 'c': %c\n", character_example);
	

	return(0); /* exit program with exit code 0 */
}
