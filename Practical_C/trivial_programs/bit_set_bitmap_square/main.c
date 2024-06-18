/************************************************
 *                                              *
 *  Name:    Print 10 x 10 Bitmap Square        *
 *                                              *
 *  Author:  Steven Nava                        *
 *                                              *
 *  Purpose: Prints a 10 x 10 bitmapped square. *
 *                                              *
 *  Usage:   Run program. 10 x 10 square will   *
 *           print out of '*' characters. To    *
 *           change the size, change X_SIZE,    *
 *           Y_SIZE, and the if statement for   *
 *           i and j.                           *
 *                                              *
 ************************************************/

#include <stdio.h>
#define X_SIZE 16
#define Y_SIZE 16

/* define a graphics array in bytes (X_SIZE / 8) by bits */
char graphics[X_SIZE/8][Y_SIZE]; // graphics array

/* set bit */
#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >> ((x)%8))

void print_graphics() {
    int x;
    int y;
    int bit;

    for(y = 0; y < Y_SIZE; y++) {
        for(x = 0; x < X_SIZE / 8; x++) {
            for(bit = 0x80; bit > 0; bit = (bit >> 1)) {
                /* if bit is set */
                if((graphics[x][y] & bit) != 0) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        /* print character to move to next 'y' line */
        printf("\n");
    }
}

int main(void) {

    for(int i = 0; i < X_SIZE; i++) {
        for(int j = 0; j < Y_SIZE; j++) {
            /* check for nodes on centered 10 x 10 square */
            if(((i == 4 || i == 13) && (j <= 13 && j >= 4)) || ((i >= 4 && i <= 13) && (j == 13 || j == 4))) {
                SET_BIT(i, j);
            }
        }
    }
    print_graphics();
    return 0;
}
