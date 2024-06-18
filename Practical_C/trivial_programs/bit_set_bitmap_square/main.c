#include <stdio.h>
#define X_SIZE 16
#define Y_SIZE 16

char graphics[X_SIZE/8][Y_SIZE]; // graphics array

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >> ((x)%8))

void print_graphics() {
    int x;
    int y;
    int bit;

    for(y = 0; y < Y_SIZE; y++) {
        for(x = 0; x < X_SIZE / 8; x++) {
            for(bit = 0x80; bit > 0; bit = (bit >> 1)) {
                if((graphics[x][y] & bit) != 0) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main(void) {

    for(int i = 0; i < X_SIZE; i++) {
        for(int j = 0; j < Y_SIZE; j++) {
            if(((i == 4 || i == 13) && (j <= 13 && j >= 4)) || ((i >= 4 && i <= 13) && (j == 13 || j == 4))) {
                SET_BIT(i, j);
            }
        }
    }
    print_graphics();
    return 0;
}
