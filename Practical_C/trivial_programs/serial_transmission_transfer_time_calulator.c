/********************************************************************************
*										*
*	Name:	 Serial Transmission Line Transfer Time Calculator		*
*										*
*	Author:	 Steven Nava							*
*										*
*	Purpose: A trivial program to calulate how long it would take to	*
*		 transfer a file of a given size using a serial trasmission	*
*		 line.								*
*		 								*
*	Usage:	 Run program and enter in a size and unit of measurement.	*
*		 Program will calulate how long it would take to transfer	*
*		 a file of given size at max speed through a serial 		*
*		 transmission line.						*
*										*
*	Notes:	 A serial tramsmission line can transfer 960 characters		*
*		 per minute. We will assume that 1 character equals 1 byte.	*
*										*
*********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	/* variable declaration */
	char line[100],
	invalid_characters[100],
	unit_of_measure[10];
	int number_read_successfully;
	long size_of_file,
	size_of_file_in_bytes;
	double length_of_time_to_transfer_file_minutes;

	/* prompt and read in file size */
	printf("Enter file size in whole numbers only: ");
	fgets(line, sizeof(line), stdin);
	number_read_successfully = sscanf(line, "%d", &size_of_file);
	sscanf(line, "%s", &invalid_characters);

	while(number_read_successfully != 1 && size_of_file > 0) {
		printf("\nA valid whole number for file size was not entered in. Please try again.\n");
		printf("Enter file size in whole numbers only: ");
		fgets(line, sizeof(line), stdin);
		number_read_successfully = sscanf(line, "%ld", &size_of_file);
		sscanf(line, "%s", &invalid_characters);
	}

	/* prompt user and read in unit of measurement */
	printf("Enter unit of measurement -- it must be either 'bytes', KB, MB, or GB: ");
	fgets(line, sizeof(line), stdin);
	
	/* check for valid units of measurement */
	if(strlen(line) <= 8) {
		/* converting string to uppercase for proper comparison */
		for(int i = 0; i < strlen(line); i++) {
			line[i] = toupper(line[i]);
		}

		/* removing the \n character */
		line[strlen(line) - 1] = '\0';
		strcpy(unit_of_measure, (line));
		if(strcmp(unit_of_measure, "bytes") == 0) {
			size_of_file_in_bytes = size_of_file;
		} else if(strcmp(unit_of_measure, "KB") == 0) {
			size_of_file_in_bytes = size_of_file * 1024;
		} else if(strcmp(unit_of_measure, "MB") == 0) {
			size_of_file_in_bytes = size_of_file * 1048576;
		} else if(strcmp(unit_of_measure, "GB") == 0) {
			size_of_file_in_bytes = size_of_file * 1073741824;
		} else {
			size_of_file_in_bytes = -1;
		}
	} else {
		size_of_file_in_bytes = -1;
	}
	/* input validation */
	while(size_of_file_in_bytes < 0) {
		printf("\nA valid unit of measure was not entered in. Please try again.\n");
		printf("Enter unit of measurement -- it must be either 'bytes', KB, MB, or GB: ");
		fgets(line, sizeof(line), stdin);
	
		if(strlen(line) <= 10) {
			line[strlen(line) - 1] = '\0';
			strcpy(unit_of_measure, line);
			if(strcmp(unit_of_measure, "bytes") == 0) {
				size_of_file_in_bytes = size_of_file;
			} else if(strcmp(unit_of_measure, "KB") == 0) {
				size_of_file_in_bytes = size_of_file * 1024;
			} else if(strcmp(unit_of_measure, "MB") == 0) {
				size_of_file_in_bytes = size_of_file * 1048576;
			} else if(strcmp(unit_of_measure, "GB") == 0) {
				size_of_file_in_bytes = size_of_file * 1073741824;
			} else {
				size_of_file_in_bytes = -1;
			}
		} else {
			size_of_file_in_bytes = -1;
		}
	}

	/* calculate how long it would take (in minutes) to transfer a file of the given size */
	length_of_time_to_transfer_file_minutes = size_of_file_in_bytes / 960;

	/* print results */
	printf("\nThe length of time in minutes that it would take to transfer a file of size %ld %s is %.2lf minutes.\n", size_of_file, unit_of_measure, length_of_time_to_transfer_file_minutes);

	return 0;
}
