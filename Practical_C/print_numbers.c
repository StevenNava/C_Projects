/********************************************************\
 *							*
 *  Name:    Print Numbers				*
 *							*
 *  Author:  Steven Nava				*
 *  							*
 *  Purpose: Trivial program to show for loop and print	*
 *   	     in C.					*
 *							*
 *  Usage:   Run program and numbers 1 - 10 will print	*
 *   	     out with the sentence "The current number	*
 *   	     is: "					*
 *							*
\********************************************************/

#include <stdio.h>

int main() {
	/* Prints out "The current number is: [1 - 10]" */
	for (int i = 1; i <= 10; i++) {
		printf("The current number is: %d\n", i);
	}
	return 0;
}
