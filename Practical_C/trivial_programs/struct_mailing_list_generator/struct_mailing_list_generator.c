/********************************************************************************
 *										*
 *	Name:	 Mailing List Generator						*
 *										*
 *	Author:	 Steven Nava							*
 *										*
 *	Purpose: Stores, sorts, and outputs a list of mailing labels.		*
 *										*
 *	Usage:	 Run program. Enter name then address for up to 30 users	*
 *										*
 ********************************************************************************/

/* #### TODO: UPDATE PROGRAM TO MANUALLY ALLOCATE NEEDED MEMORY #### */

#include <stdio.h>

/* variable declaration */
struct mailing_label {
	char full_name[60]; /* last name, first name */
	char street_address[80];
	char city[30];
	int zipcode;
	char state_code[3];
};

void Print_Mailing_Labels(struct mailing_label label) {
	printf("\n%s\n%s\n%s, %s %d\n", label.full_name, label.street_address, label.city, label.state_code, label.zipcode);
}

void Sort_Mailing_Labels_Zipcode() {

}

void Sort_Mailing_Labels_Name() {

}


int main() {
	char line[100],
	temp_input[100];
	struct mailing_label single_label;
	
	/* read in and store mailing labels */
	/* read in name */
	while(1) {
		printf("Enter the full name of the person in format last_name, first_name: ");
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%[^\n]s", &single_label.full_name)) == 1) {
			break;
		}
	}

	/* read in street address */
	while(1) {
		printf("Enter the street address for %s: ", single_label.full_name);
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%[^\n]s", &single_label.street_address)) == 1) {
			break;
		}
	}

	/* read in city */
	while(1) {
		printf("Enter the city for %s: ", single_label.full_name);
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%[^\n]s", &single_label.city)) == 1) {
			break;
		}
	}

	/* read in state code */
	while(1) {
		printf("Enter the two digit state code for %s: ", single_label.city);
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%s", &single_label.state_code)) == 1) {
			break;
		}
	}
	
	/* read in zipcode */
	while(1) {
		printf("Enter the zipcode for %s: ", single_label.city);
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%d", &single_label.zipcode)) == 1) {
			break;
		}
	} 
	
	/* sort mailing labels by input method */

	/* output mailing labels */
	Print_Mailing_Labels(single_label);
	return 0;
}

