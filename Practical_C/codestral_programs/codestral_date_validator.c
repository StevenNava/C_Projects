#include <stdio.h>
#include <stdbool.h>

// Function to check if a given year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a given month and year
int getDaysInMonth(int month, int year) {
    if (month == 2) { // February
        return isLeapYear(year) ? 29 : 28;
    } else if (month < 8) { // January to July
        return month % 2 == 0 ? 30 : 31;
    } else { // August to December
        return month % 2 == 0 ? 31 : 30;
    }
}

int main() {
    char buffer[256];
    int month, day, year;

    // Loop until valid date input is entered
    while (1) {
        printf("Enter a date in the format 'mm/dd/yyyy': ");
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d/%d/%d", &month, &day, &year) == 3 && month >= 1 && month <= 12 && day >= 1 && day
<= getDaysInMonth(month, year)) {
            break;
        }
        printf("Invalid input. Please enter a valid date in the format 'mm/dd/yyyy'.\n");
    }

    // Output the validated date
    printf("Valid date: %d/%d/%d\n", month, day, year);

    return 0;
}