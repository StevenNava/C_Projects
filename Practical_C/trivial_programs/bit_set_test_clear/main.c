#include <stdio.h>

#define SET_BIT(x) (x) |= (0x80 >>((x)%8))

int main(void) {
    int byte;

    for(int i = 0; i < 8; i++) {
        if(i == 0 || i % 2 == 0) {
            SET_BIT(byte);
        }
        printf("\n%d\n", byte);
    }

    return 0;
}
