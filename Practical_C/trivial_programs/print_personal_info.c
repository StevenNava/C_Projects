/********************************************************
*							*
*	Name:     Print Peronal Info			*
*							*
*	Author:   Steven Nava				*
*							*
*	Purpose:  Trivial program that prints out	*
*		  personal information.			*
*							*
*	Usage:	  Run program and it prints out		*
*		  hard-coded personal information.	*
*							*
********************************************************/

#include <stdio.h>
#include <string.h>

int main () {
	char first_name[7] = "Steven";
	char last_name[5] = "Nava";
	char date_of_birth[11] = "06/19/1988";
	char social_security_number[12] = "123-45-6789";

	/* prints personal information */
	printf("\nPersonal Info\n");
	printf("---------------------------------\n\n");
	printf("Name: %s ", first_name);
	printf("%s\n", last_name);
	printf("Date of Birth: %s\n", date_of_birth);
	printf("Social Security Number: %s\n", social_security_number);

	return(0); /* exit program with exit code 0 */
}
