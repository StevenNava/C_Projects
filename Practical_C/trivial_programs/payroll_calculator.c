/****************************************************************
 *								*
 *	Name:	 Payroll Calculator				*
 *								*
 *	Author:	 Steven Nava					*
 *								*
 *	Purpose: Calculates weekly wages given pay rate and	*
 *		 number of hours worked.			*
 *		 						*
 *	Usage:	 Enter pay rate and hours worked. Program will	*
 *		 calculate weekly wages and print them out.	*
 *		 						*
 ****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main() {
	/* variable declaration */
	char line[100],
	clean_input_string[100],
	character_eater[100];
	int hourly_wage_in_cents,
	number_read_status,
	weekly_wages_in_cents;
	double hours_worked,
	hours_up_to_forty = 0,
	hours_over_forty = 0, /* assume no hours over 40 */
	weekly_wages,
	hourly_wage;
	bool hourly_rate_has_cents = false, /* assume whole dollar input unless proven otherwise */
	input_is_invalid = false; /* initializing input to valid */

	/* prompt for hourly wage */
	printf("Enter an hourly wage for the employee: ");

	/* read in user input */
	fgets(line, sizeof(line), stdin);

	/* determine if input was a whole dollar amount or has cents */
	int j = 0;
	for(int i = 0; i < strlen(line); i++) {
		/* if character is numeric, store it in clean input string to be converted */
		/* cannot start value with leading 0 */
		if(line[i] == '0' & i != 0 ||
		   line[i] == '1' ||
		   line[i] == '2' ||
		   line[i] == '3' ||
		   line[i] == '4' ||
		   line[i] == '5' ||
		   line[i] == '6' ||
		   line[i] == '7' ||
		   line[i] == '8' ||
		   line[i] == '9') {
			/* put number into clean_input_string for conversion later */
			clean_input_string[j] = line[i];
			j++;
		/* checking for cents while already iterating through characters */
		} else if (line[i] == '.' && i == strlen(line) - 4 && line[i + 1] != '.') {
			hourly_rate_has_cents = true;
		} else if (line[i] == '.' && i == strlen(line) - 3 && line[i - 1] != '.') {
			hourly_rate_has_cents = true;
			/*
			 * user entered a value like 11.5 so we are adding a 0 to the end to
			 * make format it to ##.## like 11.50 so that the calculations below
			 * work properly
			 */
			strcat(line, "0");
		/* if character is an ascii character that is not 1-9 input is invalid */
		} else if ((int)line[i] > 32 && (int)line[i] < 127) {
			input_is_invalid = true;
		}
	}
	/* add string terminating character */
	clean_input_string[j] = '\0';

	/* input validation */
	while(input_is_invalid) {
		printf("\nA valid hourly wage was not entered. Please try again.\n");
		printf("Enter an hourly wage for the employee: ");
		fgets(line, sizeof(line), stdin);
		/* re-initializing variables to defaults for each loop */
		j = 0;
		hourly_rate_has_cents = false;
		input_is_invalid = false;
		for(int i = 0; i < strlen(line); i++) {
			/* if character is numeric, store it in clean input string to be converted */
			/* cannot start value with leading 0 */
			if(line[i] == '0' && i != 0 ||
		   	   line[i] == '1' ||
		   	   line[i] == '2' ||
		   	   line[i] == '3' ||
		   	   line[i] == '4' ||
		   	   line[i] == '5' ||
		   	   line[i] == '6' ||
		   	   line[i] == '7' ||
		   	   line[i] == '8' ||
		   	   line[i] == '9') {
				/* put number into clean_input_string for conversion later */
				clean_input_string[j] = line[i];
				j++;
			/* checking for cents while already iterating through characters */
			} else if (line[i] == '.' && i == strlen(line) - 4 && line[i + 1] != '.') {
				hourly_rate_has_cents = true;
			} else if (line[i] == '.' && i == strlen(line) - 3 && line[i - 1] != '.') {
				hourly_rate_has_cents = true;
				/*
				 * user entered a value like 11.5 so we are adding a 0 to the end to
				 * make format it to ##.## like 11.50 so that the calculations below
				 * work properly
				 */
				strcat(line, "0");
			/* if character is an ascii character that is not 1-9 input is invalid */
			} else if ((int)line[i] > 32 && (int)line[i] < 127) {
				input_is_invalid = true;
			}
		}
		/* add string terminating character */
		clean_input_string[j] = '\0';
	}

	/* convert character array to currency value in cents */
	sscanf(clean_input_string, "%d", &hourly_wage_in_cents);

	/* if whole dollar amount convert to cents */
	if(hourly_rate_has_cents == false) {
		hourly_wage_in_cents *= 100;
	}

	/* prompt for hours worked */
	printf("Enter hours worked by employee: ");

	/* read in user input */
	fgets(line, sizeof(line), stdin);

	/* attempt to store hours worked into variable */
	number_read_status = sscanf(line, "%lf", &hours_worked);

	/* store invalid characters entered in */
	sscanf(line, "%s", &character_eater);

	/* input validation */
	while(number_read_status != 1) {
		printf("\nA valid number of hours worked was not entered in. Please try again.\n");
		printf("Enter hours worked by employee: ");
		fgets(line, sizeof(line), stdin);
		number_read_status = sscanf(line, "%lf", &hours_worked);
		sscanf(line, "%s", &character_eater);
	}

	/* deterime if hours are over 40 and if so by how many */
	if(hours_worked > 40) {
		hours_over_forty = hours_worked - 40;
		hours_up_to_forty = 40;
	} else { 
		hours_up_to_forty = hours_worked;
	}

	/* calculate weekly wage */
	weekly_wages = hours_up_to_forty * hourly_wage_in_cents + hours_over_forty * (hourly_wage_in_cents * 1.5);

	/* get rid of anything past cents by converting to int and then back into double by division by 100 */
	weekly_wages_in_cents = round(weekly_wages); /* truncate anything past cents */
	weekly_wages = weekly_wages_in_cents / 100.0;

	/* convert hourly rate to from cents to decimal to print out */
	hourly_wage = hourly_wage_in_cents / 100.0; /* divide by 100 to move decimal two places to left for printing */

	/* print weekly wages */
	printf("Weekly wages for employee who worked %.2lf hours with an hourly rate of $%.2lf is: $%.2lf\n", hours_worked, hourly_wage, weekly_wages);
	return(0); /* exit program with exit code 0 */
}
