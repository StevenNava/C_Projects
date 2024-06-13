#include <stdio.h>

#define SWAP_NUMBERS(a, b) \
    int temp;                      \
    temp = a;                      \
    a = b;                         \
    b = temp;

int main(void) {
    /* variable declaration */
    char line[10];
    int input1,
    input2;

    /* read in input1 and input2 and input validation */
    while(1) {
        printf("Enter in number 1: ");
        fgets(line, sizeof(line), stdin);
        if((sscanf(line, "%d", &input1)) == 1) {
            break;
        }
        printf("\nInvalid numeric value entered. Enter a valid number. Please try again.\n");
    }

    while(1) {
        printf("Enter in number 2: ");
        fgets(line, sizeof(line), stdin);
        if((sscanf(line, "%d", &input2)) == 1) {
            break;
        }
        printf("\nInvalid numeric value entered. Enter a valid number. Please try again.\n");
    }

    SWAP_NUMBERS(input1, input2)
    printf("\nThe first number swapped is %d. The second number swapped is %d.\n", input1, input2);
    return 0;
}
