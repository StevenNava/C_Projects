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

int Calculate_Days_Remaining(int is_leap_year, int month, int date) {
	int days_remaining = 0,
	    days_in_month_non_leap_year[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	/* handling leap years */
	if(is_leap_year && month <= 2) {
		days_remaining += 1;
	}

	days_remaining += (days_in_month_non_leap_year[month - 1] - date);

	/* month - 1 is to offset for 0/1 indexing */
	for(int i = month; i < 12; i++) {
		days_remaining += days_in_month_non_leap_year[i];
	}

	return days_remaining;
}

int Calculate_Days_Passed_In_Last_Year(int is_leap_year, int month, int date) {
	int days_remaining = 0,
	    days_in_month_non_leap_year[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	/* handling leap years */
	if(is_leap_year && month > 2) {
		days_remaining += 1;
	}

	/* month - 1 is to offset for 0/1 indexing */
	for(int i = 0; i < month - 1; i++) {
		days_remaining += days_in_month_non_leap_year[i];
	}

	days_remaining += date;

	return days_remaining;
}

int Calculate_Difference_In_Minutes(struct date_time dt1, struct date_time dt2) {
	int difference_in_minutes = 0,
	    dt1_year, 
	    dt2_year,
	    dt1_month,
	    dt2_month,
	    dt1_date,
	    dt2_date,
	    dt1_hours,
	    dt2_hours,
	    number_of_days = 0;
	char temp[5];

	/* get years out and into variables */
	/* dt1 year */
	for(int i = strlen(dt1.date) - 5, j = 0; dt1.date[i] != '\0'; i++) {
		temp[j] = dt1.date[i];
		j++;
	}
	temp[4] = '\0';
	sscanf(temp, "%d", &dt1_year);

	/* dt2 year */
	for(int i = strlen(dt2.date) - 5, j = 0; dt2.date[i] != '\0'; i++) {
		temp[j] = dt2.date[i];
		j++;
	}
	temp[4] = '\0';
	sscanf(temp, "%d", &dt2_year);

	/* determine largest year and put in dt1 */

	/* calculate # of days difference between dt1 year and dt2 year */
	while((dt1_year + 1) != dt2_year) {
		if(Is_Leap_Year(dt1_year)) {
			number_of_days += 366;
		} else {
			number_of_days += 365;
		}
		dt1_year++;
	}

	/* get month and date for dt1 */
	for(int i = 0; dt1.date[i] != '/'; i++) {
		temp[i] = dt1.date[i];
	}
	temp[2] = '\0';
	sscanf(temp, "%d", &dt1_month);

	/* 3 is the spot for date start */
	for(int i = 3, j = 0; dt1.date[i] != '/'; i++) {
		temp[j] = dt1.date[i];
		j++;
	}
	temp[3] = '\0';
	sscanf(temp, "%d", &dt1_date);

	/* get month and date for dt2 */
	for(int i = 0; dt2.date[i] != '/'; i++) {
		temp[i] = dt2.date[i];
	}
	temp[2] = '\0';
	sscanf(temp, "%d", &dt2_month);

	/* 3 is the spot for date start */
	for(int i = 3, j = 0; dt2.date[i] != '/'; i++) {
		temp[j] = dt2.date[i];
		j++;
	}
	temp[3] = '\0';
	sscanf(temp, "%d", &dt2_date);
	
	printf("%d\n", number_of_days);
	if(Is_Leap_Year(dt1_year - 1)) {
		number_of_days += Calculate_Days_Remaining(1, dt1_month, dt1_date);
	} else {
		number_of_days += Calculate_Days_Remaining(0, dt1_month, dt1_date);
	}
	printf("%d\n", number_of_days);
	if(Is_Leap_Year(dt2_year)) {
		number_of_days += Calculate_Days_Passed_In_Last_Year(1, dt2_month, dt2_date);
	} else {
		number_of_days += Calculate_Days_Passed_In_Last_Year(0, dt2_month, dt2_date);
	}

	printf("%d\n", number_of_days);
	/* number of days * 24 * 60 (hours & minutes in hour) */

	/* read in hour dt1 */
	for(int i = 0; dt1.time[i] != ':'; i++) {
		temp[i] = dt1.time[i];
	}
	temp[2] = '\0';
	sscanf(temp, "%d", &dt1_hours);
	
	/* read in hour dt2 */
	for(int i = 0; dt2.time[i] != ':'; i++) {
		temp[i] = dt2.time[i];
	}
	temp[2] = '\0';
	sscanf(temp, "%d", &dt2_hours);

	printf("dt1 hours: %d dt2 hours: %d\n", dt1_hours, dt2_hours);
	/* determine hour difference */

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
