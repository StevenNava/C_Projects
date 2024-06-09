#define  BOOLEAN int
#define  TRUE 1
#define  FALSE 0

#include <stdio.h>

int main(void) {
    /* variable declaration */
    BOOLEAN true = TRUE,
    false = FALSE,
    decision = 0;

    if(decision == true) {
        printf("Boolean true is printing!\n");
    } else if(decision == false) {
        printf("Boolean false is printing!\n");
    }
    return 0;
}
