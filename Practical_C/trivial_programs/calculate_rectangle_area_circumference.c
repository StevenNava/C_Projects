/************************************************************************
 *									*
 *	Name:	 Calculate Rectangle Dimensions				*
 *									*
 *	Author:	 Steven Nava						*
 *									*
 *	Purpose: Trivial program to calculate and print area		*
 *		 and circumference of a 3 x 5 rectangle.		*
 *									*
 *	Usage:	 Run program and it calculates and prints out		*
 *		 dimensions, area, and circumference of a 3 x 5		*
 *		 rectangle.						*
 *									*
 ************************************************************************/

#include<stdio.h>

int main() {
	int length_in_inches = 3;
	int width_in_inches = 5;
	int area_in_inches = length_in_inches * width_in_inches;

	printf("\tLength of rectangle: %d\n", length_in_inches);
	printf("\tWidth of rectangle: %d\n", width_in_inches);
	printf("\t-----------------------------------\n\n");
	printf("\tArea of rectangle is: %d inches\n", area_in_inches);
	return(0);
}
