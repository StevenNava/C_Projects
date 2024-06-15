/************************************************************
 *                                                          *
 *  Name:    Perform Bitwise Operations                     *
 *                                                          *
 *  Author:  Steven Nava                                    *
 *                                                          *
 *  Purpose: Performs bitwise operations, by turning on/off *
 *           specific bits.                                 *
 *                                                          *
 *  Usage:   Run program and it will toggle on bits by an   *
 *           even number of bits every run and output       *
 *           the result.                                    *
 *                                                          *
 ************************************************************/
#include <stdio.h>

/* Sets bit left # from position as on */
#define SET_BIT_LEFT(x, bit_move) (x) |= (0x80 >>(bit_move))

/* Sets bit right # from position as on */
#define SET_BIT_RIGHT(x, bit_move) (x) |= (0x80 <<(bit_move))

int main(void) {
    /* int has # positions */
    int byte;
    for(int i = 0; i < 8; i++) {
        /* odd is if(i == 1 || i % 2 != 0) { */
        if(i == 1 || i % 2 != 0) {
            SET_BIT_RIGHT(byte, i);
            printf("\n%d\n", byte);
        }
    }

    return 0;
}
