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

struct date_time {
	char date[12];
	char time[10];
	int number_of_minutes;
};

int Calculate_Difference_In_Minutes(struct date_time dt1, struct date_time dt2) {
	int difference_in_minutes = 0;
	return difference_in_minutes;
}

int main() {
	struct date_time dates[2];

	/* calculate difference in minutes and output */
	printf("\nThe difference in the two date times in minutes is %d minutes.\n", Calculate_Difference_In_Minutes(dates[0], dates[1])); 
	return 0;
}
