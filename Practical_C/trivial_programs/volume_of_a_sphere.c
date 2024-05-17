/****************************************************************
 *								*
 *	Name:	 Volume of a Sphere				*
 *								*
 *	Author:	 Steven Nava					*
 *								*
 *	Purpose: Trivial program to calculate the volume	*
 *		 of a sphere.					*
 *		 						*
 *	Usage:	 When prompted, enter in the radius of a 	*
 *		 sphere and the program will calculate		*
 *		 and print out the volume of that size		*
 *		 sphere.					*
 *		 						*
 *	Notes:	 Volume of sphere: 4/3 * pi * radius ^ 3	*
 *								*
 ****************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration */
	char line[100], character_eater[100];
	int number_read_status;
	double four_thirds = 4.0/3.0;
	double radius, volume_of_sphere;

	/* prompt for radius of a sphere */
	printf("Enter the radius of the sphere: ");

	/* read in input into character array */
	fgets(line, sizeof(line), stdin);

	/* try to read number */
	number_read_status = sscanf(line, "%lf", &radius);

	/* get rid of any entered characters (non-numbers) */
	sscanf(line, "%s", &character_eater);

	/* input validation to verify input is a number */
	while(number_read_status != 1) {
		printf("A valid numeric radius was not entered. Please try again.\n");
		printf("Enter the radius of the sphere: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%lf", &radius);
		sscanf(line, "%s", &character_eater);
	}

	/* calculate the volume of sphere */
	volume_of_sphere = four_thirds * 3.14 * (radius * radius * radius);

	/* print volume of sphere */
	printf("\nThe volume of a sphere with radius %lf is: %lf\n",radius, volume_of_sphere);

	return(0); /* exit program with exit code 0 */
}
