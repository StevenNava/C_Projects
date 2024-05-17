/********************************************************
 *							*
 *	Name:	 Perimeter of a Rectangle		*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Trivial program to calculate the	*
 *		 perimeter of a rectangle based on	*
 *		 a given width and height.		*
 *							*
 *	Usage:	 Enter prompted width and height.	*
 *		 Program will calculate the perimeter	*
 *		 of a rectangle with that width and	*
 *		 height and print it out.		*
 *		 					*
 ********************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declarations */
	char line[100], character_eater[100];
	int number_read_status;
	double height_of_rectangle, width_of_rectangle, perimeter_of_rectangle;

	/* prompt for height */
	printf("Enter a height for the rectangle: ");
	
	/* read input from user */
	fgets(line, sizeof(line), stdin);

	/* try to read numeric value for height */
	number_read_status = sscanf(line, "%lf", &height_of_rectangle);

	/* read in any non-numeric characters */
	sscanf(line, "%s", &character_eater);

	/* input validation for height */
	while(number_read_status != 1){
		printf("A valid numeric value for height was not entered. Please try again.\n");
		printf("Enter a height for the rectangle: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%lf", &height_of_rectangle);
		sscanf(line, "%s", &character_eater);
	}
	
	/* prompt for width */
	printf("Enter a width for the rectangle: ");

	/* read input from user */
	fgets(line, sizeof(line), stdin);

	/* try to read numeric value for width */
	number_read_status = sscanf(line, "%lf", &width_of_rectangle);

	/* read in any non-numeric characters */
	sscanf(line, "%s", &character_eater);

	/* input validation for width */
	while(number_read_status != 1){
		printf("A valid numeric value for width was not entered. Please try again.\n");
		printf("Enter a width for the rectangle: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%lf", &width_of_rectangle);
		sscanf(line, "%s", &character_eater);
	}

	/* calculate perimeter of rectangle */
	perimeter_of_rectangle = 2 * (width_of_rectangle + height_of_rectangle);

	/* print out perimeter of rectangle */
	printf("\nThe perimeter of a rectangle with a height of %lf and a width of %lf is %lf\n", height_of_rectangle, width_of_rectangle, perimeter_of_rectangle);
	return(0); /* exit program with exit code 0 */
}
