/*Name: Robert Stovall
 *TA: Stephen Slayden
 *Date: 4/22/2014
 *Project: Lab10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#define MAX_LINE 250




int main(int argc, char **argv){

	FILE *fPointer = fopen(argv[1],"r");

	if(fPointer == NULL){
		printf("Unable to open file");
		return 0;
	};

	char line[MAX_LINE];
	char* token;
	int date,num,name,email,counter=0;
	
	printf("\n");

	while(fgets(line,MAX_LINE,fPointer)!=NULL){
		if(line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		token = strtok(line," ");
		while(token != NULL){
			//run all the functions using the token
			num = is_phone_number(token);
			date = is_date(token);
			name = looks_like_name(token);
			email = is_email(token);
			token = strtok(NULL," ");
			counter++;
		};
	};
	
	printf("\nThere are %d words in this file.\n\n",counter);
	
	fclose(fPointer);

	return 0;
};



