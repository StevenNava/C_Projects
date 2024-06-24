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
#include <string.h>
#include <stdlib.h>

/* variable declaration */
struct mailing_label {
	char full_name[60]; /* last name, first name */
	char full_name_first_last[60]; /* name in format first name last name */
	char street_address[80];
	char city[30];
	char zipcode[6];
	char state_code[3];
};

int Is_All_Numbers(char* input_string) {
	for(int i = 0; i < strlen(input_string); i++) {
		if((int)input_string[i] < 48 || (int)input_string[i] > 57) {
			printf("\n%d\n", (int)input_string[i]);
			return 0;
		}	
	}
	return 1;
}

int State_Is_Valid(char* state) {
	if(strcmp(state, "AL") == 0) {
		return 1;
	} else if(strcmp(state, "AK") == 0) {
		return 1;
	} else if(strcmp(state, "AZ") == 0) {
		return 1;
	} else if(strcmp(state, "CA") == 0) {
		return 1;
	} else if(strcmp(state, "CO") == 0) {
		return 1;
	} else if(strcmp(state, "CT") == 0) {
		return 1;
	} else if(strcmp(state, "DE") == 0) {
		return 1;
	} else if(strcmp(state, "FL") == 0) {
		return 1;
	} else if(strcmp(state, "GA") == 0) {
		return 1;
	} else if(strcmp(state, "HI") == 0) {
		return 1;
	} else if(strcmp(state, "ID") == 0) {
		return 1;
	} else if(strcmp(state, "IL") == 0) {
		return 1;
	} else if(strcmp(state, "IN") == 0) {
		return 1;
	} else if(strcmp(state, "IA") == 0) {
		return 1;
	} else if(strcmp(state, "KS") == 0) {
		return 1;
	} else if(strcmp(state, "KY") == 0) {
		return 1;
	} else if(strcmp(state, "LA") == 0) {
		return 1;
	} else if(strcmp(state, "ME") == 0) {
		return 1;
	} else if(strcmp(state, "MD") == 0) {
		return 1;
	} else if(strcmp(state, "MA") == 0) {
		return 1;
	} else if(strcmp(state, "MI") == 0) {
		return 1;
	} else if(strcmp(state, "MN") == 0) {
		return 1;
	} else if(strcmp(state, "MS") == 0) {
		return 1;
	} else if(strcmp(state, "MO") == 0) {
		return 1;
	} else if(strcmp(state, "MT") == 0) {
		return 1;
	} else if(strcmp(state, "NE") == 0) {
		return 1;
	} else if(strcmp(state, "NV") == 0) {
		return 1;
	} else if(strcmp(state, "NH") == 0) {
		return 1;
	} else if(strcmp(state, "NJ") == 0) {
		return 1;
	} else if(strcmp(state, "NM") == 0) {
		return 1;
	} else if(strcmp(state, "NY") == 0) {
		return 1;
	} else if(strcmp(state, "NC") == 0) {
		return 1;
	} else if(strcmp(state, "ND") == 0) {
		return 1;
	} else if(strcmp(state, "OH") == 0) {
		return 1;
	} else if(strcmp(state, "OK") == 0) {
		return 1;
	} else if(strcmp(state, "OR") == 0) {
		return 1;
	} else if(strcmp(state, "PA") == 0) {
		return 1;
	} else if(strcmp(state, "RI") == 0) {
		return 1;
	} else if(strcmp(state, "SC") == 0) {
		return 1;
	} else if(strcmp(state, "SD") == 0) {
		return 1;
	} else if(strcmp(state, "TN") == 0) {
		return 1;
	} else if(strcmp(state, "TX") == 0) {
		return 1;
	} else if(strcmp(state, "UT") == 0) {
		return 1;
	} else if(strcmp(state, "VT") == 0) {
		return 1;
	} else if(strcmp(state, "VA") == 0) {
		return 1;
	} else if(strcmp(state, "WA") == 0) {
		return 1;
	} else if(strcmp(state, "WV") == 0) {
		return 1;
	} else if(strcmp(state, "WI") == 0) {
		return 1;
	} else if(strcmp(state, "WY") == 0) {
		return 1;
	}
	return 0;
}

void Output_First_Name_Last_Name(char* name_reversed, char* full_name_first_last) {
	int name_length = strlen(name_reversed), i, j = 0;

	/* find ',' in name signifying end of last name */
	for(i = 0; name_reversed[i] != ','; i++) { } 

	/* start at 2 characters after finding comma to get to first name */
	for(i += 2; i < name_length; i++) {
		full_name_first_last[j] = name_reversed[i];
		j++;
	}

	full_name_first_last[j] = ' '; /* add a space between first and last name */
	j++;

	/* start back at beginning for last name and go to 2 characters less than first name start */
	name_length = j - 3;
	for(i = 0; i < name_length; i++) {
		full_name_first_last[j] = name_reversed[i];
		j++;
	}
}

void Print_Mailing_Labels(struct mailing_label label) {
	printf("\n%s\n%s\n%s, %s %s\n", label.full_name, label.street_address, label.city, label.state_code, label.zipcode);
}

void Sort_Mailing_Labels_Zipcode() {

}

void Sort_Mailing_Labels_Name() {

}


int main() {
	char line[100],
	temp_input[100]; // do i need? can i do validation without it?
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

	/* sort name and store in full_name_first_last */
	Output_First_Name_Last_Name(single_label.full_name, single_label.full_name_first_last);

	/* read in street address */
	while(1) {
		printf("Enter the street address for %s: ", single_label.full_name_first_last);
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%[^\n]s", &single_label.street_address)) == 1 && (int)single_label.street_address[0] > 48 && (int)single_label.street_address[0] < 58) {
			break;
		}
		printf("Invalid input entered. Please try again.\n");
	}

	/* read in city */
	while(1) {
		printf("Enter the city for %s: ", single_label.full_name_first_last);
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%[^\n]s", &single_label.city)) == 1) {
			break;
		}
		printf("Invalid input entered. Please try again.\n");
	}

	/* read in state code */
	while(1) {
		printf("Enter the two digit state code for %s: ", single_label.city);
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%s", &single_label.state_code)) == 1 && State_Is_Valid(single_label.state_code)) {
			break;
		}
		printf("Invalid input entered. Please try again.\n");
	}
	
	/* read in zipcode */
	while(1) {
		printf("Enter the zipcode for %s: ", single_label.city);
		fgets(line, sizeof(line), stdin);
		// zipcodes are five characters (+ terminating character) and all digits
		if(strlen(line) == 6 && (sscanf(line, "%s", &single_label.zipcode)) == 1 && Is_All_Numbers(single_label.zipcode)) {
			break;
		}
		printf("Invalid input entered. Please try again.\n");
	} 
	
	/* sort mailing labels by input method */

	/* output mailing labels */
	Print_Mailing_Labels(single_label);
	return 0;
}

