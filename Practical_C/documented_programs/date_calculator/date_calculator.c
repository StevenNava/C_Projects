/********************************************************
 *							*
 *	Name:	 Date Calculator			*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Performs various date calculations	*
 *		 such as determining the number of 	*
 *		 days/weeks/months/years between two	*
 *		 dates, determinging a date given an	*
 *		 input date and number of days, and	*
 *		 other things.				*
 *		 					*
 *	Usage:	 Run program and select action from 	*
 *		 the menu options. The date 		*
 *		 calculations will be performed and	*
 *		 the result printed out.		*
 *		 					*
 ********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	/* variable declaration */
	char line[100],
	date_input_1[15],
	date_input_2[15],
	month_string[3],
	date_string[3],
	year_string[5];
	int month_number_1,
	month_number_2,
	temp_month,
	date_number_1,
	date_number_2,
	temp_date,
	year_number_1,
	year_number_2,
	temp_year,
	months_with_thirty_days = 30,
	months_with_thirty_one_days = 31,
	february_non_leap_year_days = 28,
	february_leap_year_days = 29,
	total_number_of_days = 0;
	bool invalid_input = false;

	/*
	 * print program menu
	 */
	printf("/===============================================================\\\n");
	printf("|===============================================================|\n");
	printf("|								|\n");
	printf("|	Date Calculator	- Performs a variety of date		|\n");
	printf("|			  calculations.				|\n");
	printf("|								|\n");
	printf("|	Select an option below:					|\n");
	printf("|								|\n");
	printf("|	1 - Determine number of days between two dates		|\n");
	printf("|								|\n");
	printf("|	q - Quit program					|\n");
	printf("|								|\n");
	printf("|===============================================================|\n");
	printf("\\===============================================================/\n");

	/*
	 * feature 1: determine the number of days
	 * between two given dates
	 */

	/* prompt for date 1 and read in input */
	printf("Enter the first date in format (dd/mm/yyyy): \n");
	fgets(line, sizeof(line), stdin);
	/* strlen(line) -1 compares all but the '\n' character */
	for(int i = 0; i < strlen(line) - 1; i++) {
		if(i == 2 || i == 5) {
			if (line[i] != '/') {
				invalid_input = true;
				break;
			}
		} else if (i == 0) {
			if(line[i] != '0' && line[i] != '1') {
				invalid_input = true;
				break;
			}
		} else if(i == 1 && line[0] == '1' && (line[i] != '0' && line[i] != '1' && line[i] != '2')) {
			invalid_input = true;
			break;
		} else if(i == 1 && line[0] == '0' && line[i] == '0') {
			invalid_input = true;
			break;
		} else if(i == 3 && line[0] == '0' && line[1] == '2' && line[i] != '0' && line[i] != '1' && line[i] != '2') {
			invalid_input = true;
			break;
		} else if(i == 3 && line[i] != '0' && line[i] != '1' && line[i] != '2' && line[i] != '3') {
			invalid_input = true;
			break;
		} else if(i == 4 && ((line[1] == '4' || line[1] == '6' || line[1] == '9') || 
			  (line[0] == '1' && line[1] == '1')) && line[3] == '3' && line[i] != '0') {
			invalid_input = true;
			break;
		} else if(i == 4 && ((line[0] == '0' && (line[1] == '1' || line[1] == '3' || line[1] == '5' || line[1] == '7' ||
			  line[1] == '8')) || (line[0] == '1' && (line[1] == '0' || line[1] == '2'))) && line[3] == '3' && line[i] != '0' &&
			  line[i] != '1') {
			invalid_input = true;
			break;
		} else if(i == 4 && line[i] == '0' && line[3] == '0') {
			invalid_input = true;
			break;
		} else if(line[i] != '0' &&
			  line[i] != '1' &&
			  line[i] != '2' &&
			  line[i] != '3' &&
			  line[i] != '4' &&
			  line[i] != '5' &&
			  line[i] != '6' &&
			  line[i] != '7' &&
			  line[i] != '8' &&
			  line[i] != '9' ) {
			invalid_input = true;
			break;
		}
	}

	/* input validation */
	while(invalid_input) {
		invalid_input = false; /* reset invalid_input back to false */
		printf("\nA valid date was not entered in. Please try again.\n");
		printf("Enter the first date in format (dd/mm/yyyy): \n");
		fgets(line, sizeof(line), stdin);
		for(int i = 0; i < strlen(line) - 1; i++) {
			if(i == 2 || i == 5) {
				if (line[i] != '/') {
					invalid_input = true;
					break;
				}
			} else if (i == 0) {
				if(line[i] != '0' && line[i] != '1') {
					invalid_input = true;
					break;
				}
			} else if(i == 1 && line[0] == '1' && (line[i] != '0' && line[i] != '1' && line[i] != '2')) {
				invalid_input = true;
				break;
			} else if(i== 1 && line[0] == '0' && line[i] == '0') {
				invalid_input = true;
				break;
			} else if(i == 3 && line[0] == '0' && line[1] == '2' && line[i] != '0' && line[i] != '1' && line[i] != '2') {
				invalid_input = true;
				break;
			} else if(i == 3 && line[i] != '0' && line[i] != '1' && line[i] != '2' && line[i] != '3') {
				invalid_input = true;
				break;
			} else if(i == 4 && ((line[1] == '4' || line[1] == '6' || line[1] == '9') || 
			  (line[0] == '1' && line[1] == '1')) && line[3] == '3' && line[i] != '0') {
				invalid_input = true;
				break;
			} else if(i == 4 && ((line[0] == '0' && (line[1] == '1' || line[1] == '3' || line[1] == '5' || line[1] == '7' ||
				  line[1] == '8')) || (line[0] == '1' && (line[1] == '0' || line[1] == '2'))) && line[3] == '3' && line[i] != '0' &&
			 	  line[i] != '1') {
				invalid_input = true;
				break;
			} else if(i == 4 && line[i] == '0' && line[3] == '0') {
				invalid_input = true;
				break;
			} else if (line[i] != '0' &&
				   line[i] != '1' &&
				   line[i] != '2' &&
				   line[i] != '3' &&
				   line[i] != '4' &&
				   line[i] != '5' &&
				   line[i] != '6' &&
				   line[i] != '7' &&
				   line[i] != '8' &&
				   line[i] != '9' ) {
				invalid_input = true;
				continue;
			}
		}
	}

	/* set date / month / year strings and read into ints */
	date_string[0] = line[3];
	date_string[1] = line[4];
	date_string[2] = '\0';
	month_string[0] = line[0];
	month_string[1] = line[1];
	month_string[2] = '\0';
	year_string[0] = line[6];
	year_string[1] = line[7];
	year_string[2] = line[8];
	year_string[3] = line[9];
	year_string[4] = '\0';
	strcpy(date_input_1, line);
	date_input_1[strlen(date_input_1) -1] = '\0';

	sscanf(date_string, "%d", &date_number_1);
	sscanf(month_string, "%d", &month_number_1);
	sscanf(year_string, "%d", &year_number_1);

	/* prompt for date 2 and read in input */
	printf("Enter the second date in format (dd/mm/yyyy): \n");
	fgets(line, sizeof(line), stdin);
	/* strlen(line) -1 compares all but the '\0' character */
	for(int i = 0; i < strlen(line) - 1; i++) {
		if(i == 2 || i == 5) {
			if (line[i] != '/') {
				invalid_input = true;
				break;
			}
		} else if (i == 0) {
			if(line[i] != '0' && line[i] != '1') {
				invalid_input = true;
				break;
			}
		} else if(i == 1 && line[0] == '1' && (line[i] != '0' && line[i] != '1' && line[i] != '2')) {
			invalid_input = true;
			break;
		} else if(i== 1 && line[0] == '0' && line[i] == '0') {
			invalid_input = true;
			break;
		} else if(i == 3 && line[0] == '0' && line[1] == '2' && line[i] != '0' && line[i] != '1' && line[i] != '2') {
			invalid_input = true;
			break;
		} else if(i == 3 && line[i] != '0' && line[i] != '1' && line[i] != '2' && line[i] != '3') {
			invalid_input = true;
			break;
		} else if(i == 4 && ((line[1] == '4' || line[1] == '6' || line[1] == '9') || 
			  (line[0] == '1' && line[1] == '1')) && line[3] == '3' && line[i] != '0') {
			invalid_input = true;
			break;
		} else if(i == 4 && ((line[0] == '0' && (line[1] == '1' || line[1] == '3' || line[1] == '5' || line[1] == '7' ||
			  line[1] == '8')) || (line[0] == '1' && (line[1] == '0' || line[1] == '2'))) && line[3] == '3' && line[i] != '0' &&
			  line[i] != '1') {
			invalid_input = true;
			break;
		} else if(i == 4 && line[i] == '0' && line[3] == '0') {
			invalid_input = true;
			break;
		} else if (line[i] != '0' &&
			   line[i] != '1' &&
			   line[i] != '2' &&
			   line[i] != '3' &&
			   line[i] != '4' &&
			   line[i] != '5' &&
			   line[i] != '6' &&
			   line[i] != '7' &&
			   line[i] != '8' &&
			   line[i] != '9' ) {
			invalid_input = true;
			break;
		}
	}

	/* input validation */
	while(invalid_input) {
		invalid_input = false; /* reset invalid_input back to false */
		printf("\nA valid date was not entered in. Please try again.\n");
		printf("Enter the first date in format (dd/mm/yyyy): \n");
		fgets(line, sizeof(line), stdin);
		for(int i = 0; i < strlen(line) - 1; i++) {
			if(i == 2 || i == 5) {
				if (line[i] != '/') {
					invalid_input = true;
					break;
				}
			} else if (i == 0) {
				if(line[i] != '0' && line[i] != '1') {
					invalid_input = true;
					break;
				}
			} else if(i == 1 && line[0] == '1' && (line[i] != '0' && line[i] != '1' && line[i] != '2')) {
				invalid_input = true;
				break;
			} else if(i== 1 && line[0] == '0' && line[i] == '0') {
				invalid_input = true;
				break;
			} else if(i == 3 && line[0] == '0' && line[1] == '2' && line[i] != '0' && line[i] != '1' && line[i] != '2') {
				invalid_input = true;
				break;
			} else if(i == 3 && line[i] != '0' && line[i] != '1' && line[i] != '2' && line[i] != '3') {
				invalid_input = true;
				break;
			} else if(i == 4 && ((line[1] == '4' || line[1] == '6' || line[1] == '9') || 
				  (line[0] == '1' && line[1] == '1')) && line[3] == '3' && line[i] != '0') {
				invalid_input = true;
				break;
			} else if(i == 4 && ((line[0] == '0' && (line[1] == '1' || line[1] == '3' || line[1] == '5' || line[1] == '7' ||
				  line[1] == '8')) || (line[0] == '1' && (line[1] == '0' || line[1] == '2'))) && line[3] == '3' && line[i] != '0' &&
			 	  line[i] != '1') {
				invalid_input = true;
				break;
			} else if(i == 4 && line[i] == '0' && line[3] == '0') {
				invalid_input = true;
				break;
			} else if (line[i] != '0' &&
				   line[i] != '1' &&
				   line[i] != '2' &&
				   line[i] != '3' &&
				   line[i] != '4' &&
				   line[i] != '5' &&
				   line[i] != '6' &&
				   line[i] != '7' &&
				   line[i] != '8' &&
				   line[i] != '9' ) {
				invalid_input = true;
				continue;
			}
		}
	}

	/* set date / month / year strings and read into ints */
	date_string[0] = line[3];
	date_string[1] = line[4];
	date_string[2] = '\0';
	month_string[0] = line[0];
	month_string[1] = line[1];
	month_string[2] = '\0';
	year_string[0] = line[6];
	year_string[1] = line[7];
	year_string[2] = line[8];
	year_string[3] = line[9];
	year_string[4] = '\0';
	strcpy(date_input_2, line);
	date_input_2[strlen(date_input_2) -1] = '\0';

	sscanf(date_string, "%d", &date_number_2);
	sscanf(month_string, "%d", &month_number_2);
	sscanf(year_string, "%d", &year_number_2);

	/* perform date calculations for number of days between dates */
	if(year_number_1 == year_number_2) {
		if(month_number_1 == month_number_2) {
			if(date_number_1 - date_number_2 < 0) {
				total_number_of_days += (date_number_2 - date_number_1);
			} else {
				total_number_of_days += (date_number_1 - date_number_2);
			}
		} else {
			/* put smaller date in date 1 position */
			if(month_number_2 < month_number_1) {
				temp_month = month_number_1;
				month_number_1 = month_number_2;
				month_number_2 = temp_month;
				temp_date = date_number_1;
				date_number_1 = date_number_2;
				date_number_2 = temp_date;
			}

			if (month_number_1 == 2) {
				if(year_number_1 % 100 == 0 && year_number_1 % 400 != 0) {
					total_number_of_days += (28 - date_number_1);
				} else if (year_number_1 % 4 == 0) {
					total_number_of_days += (29 - date_number_1);
				} else {
					total_number_of_days += (28 - date_number_1);
				}
			}
			else if(month_number_1 == 1 ||
			   month_number_1 == 3 ||
			   month_number_1 == 5 ||
			   month_number_1 == 7 ||
			   month_number_1 == 8 ||
			   month_number_1 == 10 ||
			   month_number_1 == 12 ) {
				total_number_of_days += (months_with_thirty_one_days - date_number_1);
			} else {
				total_number_of_days += (months_with_thirty_days - date_number_1);
			}
			month_number_1++;
			
			while(month_number_1 < month_number_2) {
				if (month_number_1 == 2) {
					if(year_number_1 % 100 == 0 && year_number_1 % 400 != 0) {
						total_number_of_days += 28;
					} else if (year_number_1 % 4 == 0) {
						total_number_of_days += 29;
					} else {
						total_number_of_days += 28;
					}
				} else if(month_number_1 == 1 ||
					  month_number_1 == 3 ||
			 		  month_number_1 == 5 ||
			 		  month_number_1 == 7 ||
			 		  month_number_1 == 8 ||
			 		  month_number_1 == 10 ||
					  month_number_1 == 12 ) {
					total_number_of_days += months_with_thirty_one_days;
				} else {
					total_number_of_days += months_with_thirty_days;
				}
				month_number_1++;
			}

			total_number_of_days += date_number_2;
		}
	} else {
		/* put  smaller month in month 1 position */
		if(year_number_2 < year_number_1) {
			temp_year = year_number_1;
			year_number_1 = year_number_2;
			year_number_2 = temp_year;
			temp_month = month_number_1;
			month_number_1 = month_number_2;
			month_number_2 = temp_month;
			temp_date = date_number_1;
			date_number_1 = date_number_2;
			date_number_2 = temp_date;
		}

		if(month_number_1 == 1 ||
		   month_number_1 == 3 ||
		   month_number_1 == 5 ||
		   month_number_1 == 7 ||
		   month_number_1 == 8 ||
		   month_number_1 == 10 ||
		   month_number_1 == 12 ) {
			total_number_of_days += (months_with_thirty_one_days - date_number_1);
		} else if(month_number_1 != 2) {
			total_number_of_days += (months_with_thirty_days - date_number_1);
		} else if(year_number_1 % 100 == 0 && year_number_1 % 400 != 0) {
			total_number_of_days += 28;
		} else if(year_number_1 % 4 != 0) {
			total_number_of_days += 28;
		} else {
			total_number_of_days += 29;
		}
		
		if(month_number_1 == 12) {
			year_number_1++;
			month_number_1 = 1;
		} else {
			month_number_1++;
		}

		while(year_number_1 < year_number_2) {
			if(month_number_1 == 1 ||
			   month_number_1 == 3 ||
			   month_number_1 == 5 ||
			   month_number_1 == 7 ||
			   month_number_1 == 8 ||
			   month_number_1 == 10 ||
			   month_number_1 == 12 ) {
				total_number_of_days += months_with_thirty_one_days;
			} else if(month_number_1 != 2) {
				total_number_of_days += months_with_thirty_days;
			} else if(year_number_1 % 100 == 0 && year_number_1 % 400 != 0) {
				total_number_of_days += 28;
			} else if(year_number_1 % 4 != 0) {
				total_number_of_days += 28;
			} else {
				total_number_of_days += 29;
			}

			if(month_number_1 == 12) {
				year_number_1++;
				month_number_1 = 1;
			} else {
				month_number_1++;
			}
				
		}

		while(month_number_1 < month_number_2) {
			if (month_number_1 == 2) {
				if(year_number_1 % 100 == 0 && year_number_1 % 400 != 0) {
					total_number_of_days += 28;
				} else if (year_number_1 % 4 == 0) {
					total_number_of_days += 29;
				} else {
					total_number_of_days += 28;
				}
			} else if(month_number_1 == 1 ||
				  month_number_1 == 3 ||
			  	  month_number_1 == 5 ||
			 	  month_number_1 == 7 ||
			 	  month_number_1 == 8 ||
			 	  month_number_1 == 10 ||
				  month_number_1 == 12 ) {
				total_number_of_days += months_with_thirty_one_days;
			} else {
				total_number_of_days += months_with_thirty_days;
			}
			month_number_1++;
		}

		total_number_of_days += date_number_2;
			
	}
	printf("\nDate#1: %d\n", date_number_1);
	printf("\nDate#2: %d\n", date_number_2);
	printf("\nThe total number of days between %s and %s is: %d days\n", date_input_1, date_input_2, total_number_of_days);
	return(0);
}
