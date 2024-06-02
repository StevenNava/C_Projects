#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[256];
    int dollars, cents, total_cents, quarters, dimes, nickels, pennies;

    // Loop until valid numerical input is entered
    while (1) {
        printf("Enter a currency amount in the format 'dollars.cents': ");
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d.%2d", &dollars, &cents) == 2 && dollars >= 0 && cents >= 0 && cents < 100) {
            break;
        }
        printf("Invalid input. Please enter a non-negative decimal value in the format 'dollars.cents'.\n");
    }

    // Convert dollars and cents to total cents
    total_cents = dollars * 100 + cents;

    // Calculate the number of quarters, dimes, nickels, and pennies
    quarters = total_cents / 25;
    total_cents %= 25;
    dimes = total_cents / 10;
    total_cents %= 10;
    nickels = total_cents / 5;
    pennies = total_cents % 5;

    // Output the results
    printf("Quarters: %d\n", quarters);
    printf("Dimes: %d\n", dimes);
    printf("Nickels: %d\n", nickels);
    printf("Pennies: %d\n", pennies);

    return 0;
}
