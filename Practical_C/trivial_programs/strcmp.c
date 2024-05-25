 /***********************************************************************
 *									*
 *	Name:	 Strcmp Summary						*
 *									*
 *	Author:	 Steven Nava						*
 *									*
 *	Purpose: Cover summary and working of strcmp function.		*
 *									*
 *	Usage:	 Run program to see running of strcmp function.		*
 *									*
 ***********************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration */
	char strcmp1[10],
	strcmp2[10];

	/* prompt and read in values */
	printf("Enter string value 1 for comparison: ");
	fgets(strcmp1, sizeof(strcmp1), stdin);
	printf("\nEnter string value 2 for comparison (it should be the same as string value 1): ");
	fgets(strcmp2, sizeof(strcmp2), stdin);

	/* compare functionality */
	printf("\n%d\n", strcmp(strcmp1, strcmp2));
	return(0);
}
