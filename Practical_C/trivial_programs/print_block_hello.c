/************************************************************************
 *									*
 *	Name:	  Print Hello in Block Text				*
 *									*
 *	Author:	  Steven Nava						*
 *									*
 *	Purpose:  Trivial program prints out 'HELLO' in block text 7 	*
 *		  characters high and 5 characters wide.		*
 *									*
 *	Usage:	  Run program and it prints 'HELLO' in large		*
 *		  block lettering.					*
 *									*
 ************************************************************************/

#include <stdio.h>

int main() {
	printf("*    *  *****  *      *      *****\n");
	printf("*    *  *      *      *      *   *\n");
	printf("*    *  *      *      *      *   *\n");
	printf("******  *****  *      *      *   *\n");
	printf("*    *  *      *      *      *   *\n");
	printf("*    *  *      *      *      *   *\n");
	printf("*    *  *****  *****  *****  *****\n");

	return(0); /* exit with exit code 0 */
}
