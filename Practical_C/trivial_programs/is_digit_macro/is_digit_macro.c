/************************************************************
*                                                           *
 *  Name:    Is Digit Macro                                 *
 *                                                          *
 *  Author:  Steven Nava                                    *
 *                                                          *
 *  Purpose: Macro to check if digit is decimal digit and   *
 *           then output result.                            *
 *                                                          *
 *  Usage:   Run program. Enter a string. If string is a    *
 *           viable decimal digit then program will output  *
 *           that content is a decimal digit. Otherwise,    *
 *           program will output that content is not        *
 *           a decimal digit*                               *
 *                                                          *
 ************************************************************/

#include <stdio.h>
#include <string.h>

#define IS_DIGIT(input) \
    int is_digit = 1, \
    count_of_decimals = 0; \
    /* prepare input string for printing out. move back '\0' 1 character, deleting '\n' character */ \
    input[strlen(input) - 1] = '\0'; \
    for(int i = 0; i < strlen(input); i++) { \
        if(input[i] == '.') { \
            count_of_decimals++; \
            if(count_of_decimals > 1) { \
                is_digit = 0; \
                break; \
            }\
        } else if(input[i] != '0' && \
                  input[i] != '1' && \
                  input[i] != '2' && \
                  input[i] != '3' && \
                  input[i] != '4' && \
                  input[i] != '5' && \
                  input[i] != '6' && \
                  input[i] != '7' && \
                  input[i] != '8' && \
                  input[i] != '9' ) { \
            is_digit = 0; \
            break; \
        } \
    } \
    if(is_digit) { \
        printf("\n'%s' is a valid decimal digit.\n", input); \
    } else { \
        printf("\n'%s' is not a valid decimal digit.\n", input);\
    }

#define IS_HEX(hex_input) \
    int is_hex = 1, \
    hex_input[strlen(hex_input) - 1] = '\0'; \
    for(int i = 0; i < strlen(hex_input); i++) { \
        if(IS_DIGIT(hex_input)

int main(void) {
    /* variable declaration */
    char line[50];

    /* read in line value */
    printf("Enter a value for the program to determine if it is a valid decimal digit or not: ");
    fgets(line, sizeof(line), stdin);
    IS_DIGIT(line)
    return 0;
}
