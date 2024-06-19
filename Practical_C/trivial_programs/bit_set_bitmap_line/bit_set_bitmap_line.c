/********************************************************
 *							*
 *	Name:	 Bit Set Bitmap Line			*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Creates a bitmapped stripe that can be	*
 *		 modified but always stays in the 	*
 *		 center of the printed output.		*
 *		 					*
 *	Usage:	 Run program. Bitmapped line will be	*
 *		 printed out. Size can be changed by	*
 *		 changing the X_SIZE and Y_SIZE macros.	*
 *							*
 ********************************************************/

#include <stdio.h>

#define X_SIZE 40
#define Y_SIZE 40

char graphics[(X_SIZE)/8][Y_SIZE];

#define SET_BIT(x, y) graphics[(x)/8][y] |= 0x80 >> ((x) % 8)

/* prints out bitmapped graphics */
void Print_Graphics() {
	for(int y = 0; y < Y_SIZE; y++) {
		for(int x = 0; x < X_SIZE / 8; x++) {
			for(int bit = 0x80; bit > 0; bit = bit >> 1) {
				if((graphics[x/8][y] & bit) != 0) {
					printf("=");
				} else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}

int main() {
	for(int i = 0; i < Y_SIZE; i++) {
		for(int j = 0; j < X_SIZE; j++) {
			/* sets all even bits, creating stripes */
			if(i % 2 == 0) {
				SET_BIT(j, i);
			}
		}
	}

	Print_Graphics();
	return 0;
}
