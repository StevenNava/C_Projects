#include <stdio.h>
#include <string.h>
#include <errno.h>
#define SCALE_FACTOR 1000000 // Scale factor (e.g., 10^6)

int main() {
    int num_count;
    long long sum = 0, avg;
    char input[256];

    printf("Enter the number of inputs: ");
    scanf("%d", &num_count);

    for (int i = 1; i <= num_count; ++i) {
        long value, fractional_part = 0, multiplier = SCALE_FACTOR;
        char *endptr;
        printf("Enter number %d: ", i);
        scanf("%s", input);

        char *decimal_point = strchr(input, '.'); // Find decimal point if present
        if (decimal_point != NULL) {
            *decimal_point = '\0'; // Split string into integer and fractional parts
        }

        errno = 0; // Clear error indicator before calling strtol()
        value = strtol(input, &endptr, 10); // Convert integer part to a long integer with error checking
        if (errno != 0 || endptr == input || *endptr != '\0') {
            printf("Invalid input. Please enter a non-negative number.\n");
            --i; // Repeat the current iteration if input is invalid
            continue;
        }

        if (decimal_point != NULL) {
            for (char *ptr = decimal_point + 1; *ptr != '\0'; ++ptr) {
                if (*ptr >= '0' && *ptr <= '9') {
                    fractional_part = fractional_part * 10 + (*ptr - '0'); // Convert fractional part to a long integer
                } else {
                    printf("Invalid input. Please enter a non-negative number.\n");
                    --i; // Repeat the current iteration if input is invalid
                    break;
                }
                multiplier /= 10; // Adjust multiplier for fractional part
            }
        }

        sum += value * SCALE_FACTOR + fractional_part * multiplier; // Accumulate sum as fixed-point number with scale factor
    }

    avg = sum / num_count; // Calculate average as fixed-point number with scale factor
    printf("The average of the entered numbers is: %.6lf\n", (double)avg / SCALE_FACTOR); // Divide by scale factor and print as decimal number

    return 0;
}