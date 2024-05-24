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

#include<stdio.h>
#include<string.h>

int main() {
	/* variable declaration */
	char line[100],
	invalid_characters[100],
	unit_of_measure[5];
	int number_read_successfully,
	size_of_file,
	size_of_file_in_bytes;
	double length_of_time_to_transfer_file;

	/* prompt and read in file size */
	printf("Enter file size in whole numbers only: ");
	fgets(line, sizeof(line), stdin);
	number_read_successfully = sscanf(line, "%d", &size_of_file);
	sscanf(line, "%s", &invalid_characters);

	while(number_read_successfully != 1) {
		printf("\nA valid whole number for file size was not entered in. Please try again.\n");
		printf("Enter file size in whole numbers only: ");
		fgets(line, sizeof(line), stdin);
		number_read_successfully = sscanf(line, "%d", &size_of_file);
		sscanf(line, "%s", &invalid_characters);
	}

	/* prompt user and read in unit of measurement */
	printf("Enter unit of measurement -- it must be either 'byetes', KB, MB, or GB: ");
	fgets(line, sizeof(line), stdin);
	
	/* check for valid units of measurement */
	if(strcmp(line, "bytes") == 0) {
		printf("\nUnit of measurement entered in is bytes.\n");
	} else if(strcmp(line, "KB") == 0) {
		printf("\nUnit of measurement entered in is kilobytes.\n");
	} else if(strcmp(line, "MB") == 0) {
		printf("\nUnit of measurement entered in is megabytes.\n");
	} else if(strcmp(line, "GB") == 0) {
		printf("\nUnit of measurement entered in is gigabytes.\n");
	}

	return 0;
}
