/* Reading Files
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STR_LENGTH 100
#define DB_SIZE 25
#define DB_LEN 5


void readInput(char *);
int cleanString(char *, char *);
int dnaSequence(char*,char [][5],int);
void printDNAseq(char [][5], int);
int checkDNAseq(char *s);


int main(void){

	//Declare Variables
	int dna=0,type=0,i,len=0;
	char a[STR_LENGTH]={0},b[STR_LENGTH]={0},c[][DB_LEN]={{0}};
	
	//Read the input from the user
	readInput(a);
	//store cleanstring size in len
	len=cleanString(a,b);
	//store # of DNA rows in DNA
	dna=dnaSequence(b,c,len);
	//Print the DNA rows
	printDNAseq(c,dna);

	//Run a for loop to equate the DNA's to their assignments
	for(i=0;i<dna;++i){
		type=checkDNAseq(*(c+i));
		switch(	type ){
			case 1:
				printf("Sequence ACTG is human DNA");
				break;

			case 2:
				printf("Sequence ACTC is cow DNA");
				break;

			case 3:
				printf("Sequence ACTH is horse DNA");
				break;

			default:
				printf("Sequence %s is not a DNA sequence.",*(c+i));
				break;
		}
		printf("\n");
	}
	return 0;

};

//FUNCTIONS
void readInput(char *a){
	int i=0;
	char c;
	while ((c=getchar()) != '\n'){
		*(a+i)=c;
		i++;
	};
	*(a+i) = '\0';
};

//prints out beautiful letters
int cleanString(char *a,char *b){
	
	int i,k,counter=0;
	for (i=0;i<STR_LENGTH;++i){
		if (isalpha(*(a+i))){
			*(b+i)=*(a+i);
		};
	};
	for (k=0;k<STR_LENGTH;++k){
		*(b+k)=toupper(*(b+k));
		counter++;
		if(*(b+k)=='\n')
			break;
	}
	*(b+k)='\0';

	return counter;
};

//turns the clean string into a double
int dnaSequence(char *b,char a[][5],int len){
	int i,j,k=0;
	for(i=0;i<(len/4);++i){
		for(j=0;j<4;++j){
		a[i][j]=*(b+k);
		k++;
		}
		a[i][j]='\0';
		if(*(b+k)=='\0')
			break;
	};
	return i+1;
};


//prints the dna sequences
void printDNAseq(char a[][5], int b){
	int i;
	for(i=0;i<b;++i){
			printf("%s\n",*(a+i));
	};
	printf("\n");
};

//Returns an integer for a given dna sequence if it matches
int checkDNAseq(char *s){
	
	if (strcmp(s,"ACTG")==0){
		return 1;
	}else if(strcmp(s,"ACTC")==0){
		return 2;
	}else if(strcmp(s,"ACTH")==0){
		return 3;
	} else {
		return 0;
	};



};

