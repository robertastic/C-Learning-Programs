#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"


int is_phone_number(char* word){
	
	if(strlen(word) == 14){
		if(word[0] == '(' && word[4] == ')'){
			if(word[5] == '-' && word[9] == '-'){
				printf("\nPhone Number: %s",word);
				return 1;
			}
		}
	}

	return 0;
};


int is_date(char* word){

	int validDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int day,month;
	if(strlen(word) == 10){
		if(word[2] == '/' && word[5] == '/')
			//change / to null for atoi
			word[2] = '\0';
			word[5] = '\0';
			month = atoi(word	);
			day = atoi(&word[3]);

			if(day<=validDays[month + 1] && month < 13 && month > 0){
				//change back
				word[2] = '/';
				word[5] = '/';
				printf("\nDate: %s",word);
				return 1;
		}
	}


	return 0;
};

//This doesn't work
int looks_like_name(const char* word){

	int i=1,ret=1;

	if(isupper(word[0]) == 1){
		do{
			i++;
			if(islower(word[i]) == 0)
				ret = 0;	
		   }while(word[i] != '\0');
		printf("\nName: %s",word);
	};
	return ret;
};

//This works but it doesn't check for as many arguments as it should
int is_email(char* word){

	int i=0;
	while(word[i] != '@'){
		if(word[i] == '\0'){
			return 0;
		}
		i++;
	};
	printf("\nEmail: %s",word);
	return 0;
};

