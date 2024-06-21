/********************************************************
 *							*
 *	Name:	 Split Long Int Into Four		*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Splits a 32 binary digit long int into	*
 *		 four binary pieces and then prints	*
 *		 out the ASCII values.			*
 *		 					*
 *	Usage:	 Run program. Program will split long	*
 *		 int value into four and then print	*
 *		 out as ASCII text.			*
 *		 					*
 ********************************************************/

#include <stdio.h>

#define SET_BIT_LEFT(x, bit_move) (x) |= (0x01 << (bit_move))
#define SPLIT_BIT(a, b, c, d, l_int) 	long j = l_int; \
					for(int i = 0; i < 32; i++) { \
						/* shift right and take right most bit and \ 
						 * use & bitwise operator to see if bit is \
						 * set */ \
						if(((j >> i) & 0x01) != 0) { \
							/* since we are splitting a long int \
							 * we will use i up to 32 */ \
							if(i <= 7) { \
								SET_BIT_LEFT(a, i); \
							} else if(i <= 15) { \
								SET_BIT_LEFT(b, i - 8); \
							} else if (i <= 23) {  \
								SET_BIT_LEFT(c, i - 16); \
							} else { \
								SET_BIT_LEFT(d, i - 24); \
							} \
						} \
					} 

int main() {\
	char line[50];
	long number;
	int a, b, c, d;

	/* read in long int and parse */
	while(1) {
		printf("Enter a number up to a max of 2147483647: ");
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%ld", &number)) == 1) {
			break;
		}
		printf("\nInvalid number entered. Please try again.\n");
	}

	/* splits into four ints */
	SPLIT_BIT(a, b, c, d, number);

	/* print out bits from d to a to get correct comparison */
	printf("\n%d\n%d\n%d\n%d\n", d, c, b, a);
	return 0;
}

