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

#define SET_BIT_LEFT(x, bit_move) (x) |= (0x80 >> (bit_move))
#define SPLIT_BIT(a, b, c, d, l_int) 	long j = l_int; \
					for(int i = 0, bit = 0x80000000; i < 32; i++) { \
						bit = (bit >> 1); \
						if(((j << i) & bit) != 0) { \
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

int main() {
	long number = 2132080115;
	int a, b, c, d;
	SPLIT_BIT(a, b, c, d, number);

	printf("\n%d\n%d\n%d\n%d\n", a, b, c, d);
	return 0;
}

