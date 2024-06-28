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

	/* last name length is the total length - current length + 1 ',' */
	name_length = name_length - (j + 1);

	for(i = 0; i < name_length; i++) {
		full_name_first_last[j] = name_reversed[i];
		j++;
	}
}

void Print_Mailing_Labels(struct mailing_label label) {
	printf("\n%s\n%s\n%s, %s %s\n", label.full_name, label.street_address, label.city, label.state_code, label.zipcode);
}

void Sort_Mailing_Labels(struct mailing_label mailing_labels[], int length, char sort_type) {
	struct mailing_label temp_element;

	if(sort_type == 'n') {
		for(int i = 0; i < length; i++) {
			for(int j = i + 1; j <= length; j++) {
				if(strcmp(mailing_labels[i].full_name, mailing_labels[j].full_name) > 0) {
					temp_element = mailing_labels[i];
					mailing_labels[i] = mailing_labels[j];
					mailing_labels[j] = temp_element;
				}
			}
		}
	} else if(sort_type == 'z') {
		for(int i = 0; i < length; i++) {
			for(int j = i + 1; j <= length; j++) {
				if(strcmp(mailing_labels[i].zipcode, mailing_labels[j].zipcode) > 0) {
					temp_element = mailing_labels[i];
					mailing_labels[i] = mailing_labels[j];
					mailing_labels[j] = temp_element;
				}
			}
		}
	} else {
		printf("Invalid sort type entered. Items left unsorted.\n");
	}
}

void Print_Menu() {
	printf("**********************************************************************************************\n");
	printf("*											     *\n");
	printf("*   Make a selection from the options below:						     *\n");
	printf("*   1 ) Add a label									     *\n");
	printf("*   2 ) Sort labels by last name and print out						     *\n");
	printf("*   3 ) Sort labels by zipcode and print out						     *\n");
	printf("*											     *\n");
	printf("*   0 ) Exit appplication								     *\n");
	printf("*											     *\n");
	printf("**********************************************************************************************\n");
}

int main() {
	char line[100],
	more_labels;
//	temp_input[100]; // do i need? can i do validation without it?
	struct mailing_label labels[30];
	int number_of_labels = -1,
	    menu_choice;
	
	/* read in and store mailing labels */
	/* read in name */
	while(1) {
		while(1) {
			Print_Menu();
			fgets(line, sizeof(line), stdin);
			if(((sscanf(line, "%d", &menu_choice)) == 1) && menu_choice >= 0 && menu_choice <= 3) {
				break;
			}
			printf("Invalid input entered. Please try again.\n");
		}
		if(menu_choice == 1) {
			/* increase number of labels by 1 */
			number_of_labels++;
			
			while(1) {
				printf("Enter the full name of the person in format last_name, first_name: ");
				fgets(line, sizeof(line), stdin);
				if((sscanf(line, "%[^\n]s", &labels[number_of_labels].full_name)) == 1) {
					break;
				}
			}

			/* sort name and store in full_name_first_last */
			Output_First_Name_Last_Name(labels[number_of_labels].full_name, labels[number_of_labels].full_name_first_last);

			/* read in street address */
			while(1) {
				printf("Enter the street address for %s: ", labels[number_of_labels].full_name_first_last);
				fgets(line, sizeof(line), stdin);
				if((sscanf(line, "%[^\n]s", &labels[number_of_labels].street_address)) == 1 && (int)labels[number_of_labels].street_address[0] > 48 && (int)labels[number_of_labels].street_address[0] < 58) {
					break;
				}
				printf("Invalid input entered. Please try again.\n");
			}		

			/* read in city */
			while(1) {
				printf("Enter the city for %s: ", labels[number_of_labels].full_name_first_last);
				fgets(line, sizeof(line), stdin);
				if((sscanf(line, "%[^\n]s", &labels[number_of_labels].city)) == 1) {
					break;
				}
				printf("Invalid input entered. Please try again.\n");
			}

			/* read in state code */
			while(1) {
				printf("Enter the two digit state code for %s: ", labels[number_of_labels].city);
				fgets(line, sizeof(line), stdin);
				if((sscanf(line, "%s", &labels[number_of_labels].state_code)) == 1 && State_Is_Valid(labels[number_of_labels].state_code)) {
					break;
				}
				printf("Invalid input entered. Please try again.\n");
			}	
	
			/* read in zipcode */
			while(1) {
				printf("Enter the zipcode for %s: ", labels[number_of_labels].city);
				fgets(line, sizeof(line), stdin);
				// zipcodes are five characters (+ terminating character) and all digits
				if(strlen(line) == 6 && (sscanf(line, "%s", &labels[number_of_labels].zipcode)) == 1 && Is_All_Numbers(labels[number_of_labels].zipcode)) {
					break;
				}
				printf("Invalid input entered. Please try again.\n");
			}

		} else if(menu_choice == 2) {
			/* sort mailing labels by input method */
			Sort_Mailing_Labels(labels, number_of_labels, 'n'); 

			/* output mailing labels */
			for(int i = 0; i <= number_of_labels; i++) { 
				Print_Mailing_Labels(labels[i]);
			}
		} else if(menu_choice == 3) {
			/* sort mailing labels by input method */
			Sort_Mailing_Labels(labels, number_of_labels, 'z'); 

			/* output mailing labels */
			for(int i = 0; i <= number_of_labels; i++) { 
				Print_Mailing_Labels(labels[i]);
			}
		} else {
			break;
		}
	}
	return 0;
}

