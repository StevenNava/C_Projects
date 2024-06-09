/********************************************************
 *                                                      *
 *  Name:    Divisible by Ten Macro                     *
 *                                                      *
 *  Author:  Steven Nava                                *
 *                                                      *
 *  Purpose: Determines whether a number is evenly      *
 *           divisible by ten through the use of        *
 *           macros.                                    *
 *                                                      *
 *  Usage:   Run program. Enter a number to attempt     *
 *           to have number divided by ten. If number   *
 *           is divisible by 10 evenly, it will output  *
 *           that the number is evenly divisible by     *
 *           ten. Ohterwise, the program will output    *
 *           that the number is not divisible evenly    *
 *           by ten.                                    *
 *                                                      *
 ********************************************************/

#define  BOOLEAN int
#define  TRUE 1
#define  FALSE 0
#define divisible_by_ten(number) (number % 10 == 0)

#include <stdio.h>

int main(void) {
    /* variable declaration */
    char line[10];
    int divisor;

    /* prompt and read in divisor */
    while(TRUE) {
        printf("Enter in a number to be divided as a whole number: ");
        fgets(line, sizeof(line), stdin);
        if((sscanf(line, "%d", &divisor)) == 1) {
            break;
        }
        printf("\nInvalid divisor entered. Enter a whole number for a number to be divided by. Please try again.\n");
    }

    if(divisible_by_ten(divisor)) {
        printf("\nNumber %d is divisible evenly by ten!\n", divisor);
    } else {
        printf("\nNumber %d is not divisible evenly by ten.\n", divisor);
    }
    return 0;
}
