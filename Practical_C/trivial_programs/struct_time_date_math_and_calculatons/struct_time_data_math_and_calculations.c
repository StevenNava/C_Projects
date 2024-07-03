/****************************************************************
 *								*
 *	Name: 	 Time and Date Math				*
 *								*
 *	Author:	 Steven Nava					*
 *								*
 *	Purpose: Performs time and date math between two given	*
 *		 dates and times.				*
 *		 						*
 *	Usage:	 Run program. Enter a valid date. Enter a valid	*
 *		 time. Enter a second date. Enter a second 	*
 *		 time. Program will perform math and output	*
 *		 difference in minutes between the two dates.	*
 *		 						*
 ****************************************************************/

#include <stdio.h>
#include <string.h>
#define NUM_OF_DATES 2

struct date_time {
	char date[12];
	char time[12];
	int number_of_minutes;
};

int Is_Leap_Year(int year) {
	if(year % 100 == 0 && year % 400 == 0) {
		return 1;
	}
	return 0;
}

int Calculate_Difference_In_Minutes(struct date_time dt1, struct date_time dt2) {
	int difference_in_minutes = 0;
	int dt1_minutes = 0;
	char temp[5];

	/* calculate # of days difference between dt1 and dt2 */
	// TODO
	
	/* number of days * 24 * 60 (hours & minutes in hour) */

	return difference_in_minutes;
}

int main() {
	struct date_time dates[NUM_OF_DATES];
	char line[12];
	int valid = 1;

	/* read in date and time for both entries */
	for(int i = 0; i < NUM_OF_DATES; i++) {
		while(1) {
			valid = 1;
			printf("Enter a valid date in mm/dd/yyyy format: ");
			fgets(line, sizeof(line), stdin);
			
			if(strlen(line) < 10) {
				valid = 0;
			}

			for(int j = 0; j < strlen(line) - 1; j++) {
				if((int)line[j] < 47 || (int)line[j] > 57) {
					valid = 0;
					break;
				}
			}
			if(valid) {
				strcpy(dates[i].date, line);
				break;
			}
			printf("Invlaid date entered. Please try again.\n");
		}

		while(1) {
			valid = 1;
			printf("Enter a valid time in a 24 hour hh:mm format: ");
			fgets(line, sizeof(line), stdin);
			
			if(strlen(line) < 5) {
				valid = 0;
			}

			for(int j = 0; j < strlen(line) - 1; j++) {
				if((int)line[j] < 48 || (int)line[j] > 58) {
					valid = 0;
					break;
				}
			}
			if(valid) {
				strcpy(dates[i].time, line);
				break;
			}	
			printf("Invalid time entered. Please try again.\n");
		}
	}

	for(int i = 0; i < NUM_OF_DATES; i++) {
		printf("Date: %s\n", dates[i].date);
		printf("Time: %s\n", dates[i].time);
	}

	/* calculate difference in minutes and output */
	printf("\nThe difference in the two date times in minutes is %d minutes.\n", Calculate_Difference_In_Minutes(dates[0], dates[1])); 
	return 0;
}
