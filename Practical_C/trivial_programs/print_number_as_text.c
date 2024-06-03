/********************************************************
 *							*
 *	Name:	 Print Numbers as Text			*
 *							*
 *	Author:	 Steven Nava				*
 *							*
 *	Purpose: Prints a given number as its text	*
 *		 form.					*
 *							*
 *	Usage:	 Run program. Enter a whole number.	*
 *		 Program will determine the text form	*
 *		 for that number and print out that	*
 *		 number in text.			*
 *							*
 ********************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	/* variable declaration */
	char line[50],
	number_as_text[50];
	int number_as_number,
	temp_number;

	/* read input and input validation */
	while(1) {
		printf("Enter a whole number less than 1000: ");
		fgets(line, sizeof(line), stdin);
		if((sscanf(line, "%d", &number_as_number)) == 1 && number_as_number < 1000) {
			break;
		}
		printf("\nInvalid input entered. Please try again.\n");
	}

	/* calculate text for number */
	temp_number = number_as_number;
	if(temp_number >= 900) {
		temp_number -= 900;
		strcpy(number_as_text, "nine hundred");
	} else if(temp_number >= 800) {
		temp_number -= 800;
		strcpy(number_as_text, "eight hundred");
	} else if(temp_number >= 700) {
		temp_number -= 700;
		strcpy(number_as_text, "seven hundred");
	} else if(temp_number >= 600) {
		temp_number -= 600;
		strcpy(number_as_text, "six hundred");
	} else if(temp_number >= 500) {
		temp_number -= 500;
		strcpy(number_as_text, "five hundred");
	} else if(temp_number >= 400) {
		temp_number -= 400;
		strcpy(number_as_text, "four hundred");
	} else if(temp_number >= 300) {
		temp_number -= 300;
		strcpy(number_as_text, "three hundred");
	} else if(temp_number >= 200) {
		temp_number -= 200;
		strcpy(number_as_text, "two hundred");
	} else if(temp_number >= 100) {
		temp_number -= 100;
		strcpy(number_as_text, "one hundred ");
	}
	
	if(temp_number >= 90) {
		temp_number -= 90;
		strcat(number_as_text, "ninety");
	} else if(temp_number >= 80) {
		temp_number -= 80;
		strcat(number_as_text, " eighty");
	} else if(temp_number >= 70) {
		temp_number -= 70;
		strcat(number_as_text, " seventy");
	} else if(temp_number >= 60) {
		temp_number -= 60;
		strcat(number_as_text, " sixty");
	} else if(temp_number >= 50) {
		temp_number -= 50;
		strcat(number_as_text, " fifty");
	} else if(temp_number >= 40) {
		temp_number -= 40;
		strcat(number_as_text, " fourty");
	} else if(temp_number >= 30) {
		temp_number -= 30;
		strcat(number_as_text, " thirty");
	} else if(temp_number >= 20) {
		temp_number -= 20;
		strcat(number_as_text, " twenty");
	} else if(temp_number >= 10) {
		if(temp_number == 19) {
			temp_number -= 19;
			strcat(number_as_text, " nineteen");
		} else if(temp_number == 18) {
			temp_number -= 18;
			strcat(number_as_text, "eighteen");
		} else if(temp_number == 17) {
			temp_number -= 17;
			strcat(number_as_text, " seventeen");
		} else if(temp_number == 16) {
			temp_number -= 16;
			strcat(number_as_text, " sixteen");
		} else if(temp_number == 15) {
			temp_number -= 15;
			strcat(number_as_text, " fifteen");
		} else if(temp_number == 14) {
			temp_number -= 14;
			strcat(number_as_text, " fourteen");
		} else if(temp_number == 13) {
			temp_number -= 13;
			strcat(number_as_text, " thirteen");
		} else if(temp_number == 12) {
			temp_number -= 12;
			strcat(number_as_text, " twelve");
		} else if(temp_number == 11) {
			temp_number -= 11;
			strcat(number_as_text, " eleven");
		} else if(temp_number == 10) {
			temp_number -= 10;
			strcat(number_as_text, " ten");
		}
	}
	
	if(temp_number > 0) {
		if(temp_number == 9) {
			temp_number -= 9;
			strcat(number_as_text, " nine");
		} else if(temp_number == 8) {
			temp_number -= 8;
			strcat(number_as_text, " eight");
		} else if(temp_number == 7) {
			temp_number -= 7;
			strcat(number_as_text, " seven");
		} else if(temp_number == 6) {
			temp_number -= 6;
			strcat(number_as_text, " six");
		} else if(temp_number == 5) {
			temp_number -= 5;
			strcat(number_as_text, " five");
		} else if(temp_number == 4) {
			temp_number -= 4;
			strcat(number_as_text, " four");
		} else if(temp_number == 3) {
			temp_number -= 3;
			strcat(number_as_text, " three");
		} else if(temp_number == 2) {
			temp_number -= 2;
			strcat(number_as_text, " two");
		} else if(temp_number == 1) {
			temp_number -= 1;
			strcat(number_as_text, " one");
		}
	}

	/* print out number as text */
	printf("\nThe number you entered, %d, printed as text is %s.\n", number_as_number, number_as_text);
	return 0;
}
