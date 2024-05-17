/****************************************************************
 *								*
 *	Name:	 strcpy and strcat				*
 *								*
 *	Author:	 Steven Nava					*
 *								*
 *	Purpose: Trivial program to test and show the 		*
 *		 uses of the strcpy and strcat string		*
 *		 functions.					*
 *		 						*
 *	Usage:	 Run the program and view the output.		*
 *		 strcpy and strcat will be used to		*
 *		 store and manipulate string data and the	*
 *		 comments will elaborate on proper usage	*
 *		 and errors that can occur.			*
 *		 						*
 ****************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* string declaration */
	char strcpytest[10]; /* variable for strcpy() test */
	char strcattest[10]; /* variable for strcat() test */
	char fgetstest[20];

	/*
	 * below statement will not work as it is 10 
	 * chars + '\0' so 11 chars and going into a
	 * 10 char array. gcc throws errors and even if
	 * it didn't it wouldn't print properly
	 * strcpy(strcpytest, "abcdefghij");
	 * printf("%s", strcpytest);
	 */

	/* proper usage of strcpy -- maximum allowed chars */
	strcpy(strcpytest, "abcdefghi");
	printf("%s\n\n", strcpytest);

	/* 
	 * moving '\0' end of string character forward 4
	 * putting it at strcpytest[5] which should print
	 * "abcde"
	 */
	strcpytest[5] = '\0';
	printf("Same string 4 chars shorter: %s\n\n\n\n", strcpytest);

	/* 
	 * testing if strcat can be used for initializing 
	 * turns out it can be used for initializing
	 */
	strcat(strcattest, "abcdefghi");
	printf("%s\n\n", strcattest);

	/*
	 * if you strcat() into a full character array it
	 * can behave unexpectedly. in my test it still
	 * worked but could/can cause unexpected problems.
	 * it is best to make sure the character array can
	 * handle the concatenation.
	 *
	 * strncat(strcattest, "jk");
	 * printf("%s\n", strcattest);
	 *
	 * the above printed "abcdefghijk" with a character
	 * array defined to hold ten characters including
	 * the end of string character
	 */

	/* 
	 * finding length of strcattest after testing 
	 * strlen() does not include the end-of-string character
	 */
	printf("strcattest has a length of %d\n\n", strlen(strcattest));

	printf("Enter your first and last name: ");
	printf("Your name is %s\n\n", fgets(fgetstest, sizeof(fgetstest), stdin));
	return(0); /* exit program with exit code 0 */
}
