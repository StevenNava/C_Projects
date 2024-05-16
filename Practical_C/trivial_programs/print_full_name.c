/************************************************************************
 *									*
 *	Name:	 Print Full Name					*
 *									*
 *	Author:	 Steven Nava						*
 *									*
 *	Purpose: Trivial program that uses the string functions to	*
 *		 copy a first name, space, and last name into a 	*
 *		 full name and prints that full name.			*
 *									*
 *	Usage:	 Run program and it prints hard-coded full name		*
 *		 "Steven Nava"						*
 *									*
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* Declaring name variables */
	char first_name[50];
	char last_name[50];
	char full_name[100];

	/* Copying first and last name into variables */
	strcpy(first_name, "Steven");
	strcpy(last_name, "Nava");

	/* Copying names and formatting into full_name */
	strcpy(full_name, first_name);
	/* Cannot use ' ' in strcat or strcpy -- has to be " " */
	strcat(full_name, " "); 
	strcat(full_name, last_name);

	/* Printing full name */
	printf("Full name: %s\n", full_name);
	return(0); /* exit program with exit code 0 */
}
