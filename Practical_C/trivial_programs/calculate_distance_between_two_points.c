/********************************************************
 *							*
 *	Name: 	 Calculate Distance Between Two Points	*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Trivial program to calculate the 	*
 *		 distance betwween two points.		*
 *							*
 *	Usage:	 Enter two points represented by	*
 *		 decimal numbers or whole numbers.	*
 *		 Program will calculate the distance	*
 *		 between the two points and print	*
 *		 it out.				*
 *		 					*
 ********************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration */
	char line[100], character_eater[100];
	int number_read_status;
	double point_a, point_b, distance_between_points;

	/* prompt user for point a */
	printf("Please enter a numerical value for point a: ");

	/* read in input for point a*/
	fgets(line, sizeof(line), stdin);

	/* attempt to store point a in variable */
	number_read_status = sscanf(line, "%lf", &point_a);

	/* read in any non-numerical characters entered in */
	sscanf(line, "%s", &character_eater);

	/* input validation */
	while(number_read_status != 1) {
		printf("\nA valid numerical value was not entered in for point a. Please try again.\n");
		printf("Please enter a numerical value for point a: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%lf", &point_a);
		sscanf(line, "%s", &character_eater);
	}

	/* prompt user for point b */
	printf("Please enter a numerical value for point b: ");

	/* read in input for point b*/
	fgets(line, sizeof(line), stdin);

	/* attempt to store point b in variable */
	number_read_status = sscanf(line, "%lf", &point_b);
	
	/* read in any non-numerical characters entered in */
	sscanf(line, "%s", &character_eater);

	/* input validation */
	while(number_read_status != 1) {
		printf("\nA valid numerical value was not entered in for point b. Please try again.\n");
		printf("Please enter a numerical value for point b: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%lf", &point_b);
		sscanf(line, "%s", &character_eater);
	}

	/* calculate distance between point a and point b */
	if (point_a > point_b) {
		distance_between_points = point_a - point_b;
	} else {
		distance_between_points = point_b - point_a;
	}

	/* print out distance between point a and point b */
	printf("\nThe distance between point a (%lf) and point b (%lf) is: (%lf)\n", point_a, point_b, distance_between_points);
	return(0); /* exit program with exit code 0 */
}
