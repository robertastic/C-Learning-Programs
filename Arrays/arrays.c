/*
 * Descriptions: Playing with arrays
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY1 100

//PROTOTYPES
int Max(int);
int Min(int);
float Average(int);
int Search(int,int,int);
int biggerArray(int,int);
int errorCheck(int);
void initializeArray1(int);
void initializeArray2(int);
void displayMenu();
int commonNumbers(int,int);
void computeStats(int);
void printArray1(int);
void printArray2(int);
//Create the arrays as global variables, initialize them to 0
int first_array[ARRAY1] = {0};
int second_array[ARRAY1] = {0};



//MAIN FUNCTION
int main(){
//Local Variables
int size1=0,size2=0,error=0,choice=0,find=0,quit=0,result=-1,bA=0,cN=0;
//Seed time for random
srand(time(NULL));

//Greet the user, have them enter the size of their desired arrays
printf("Hello!");

//Array 1
do{
printf("\nPlease enter a size for your first array (1-100): ");
scanf("%d",&size1);
error=errorCheck(size1);
	if (error==0)
		printf("\nYou need to enter a number from 1-100. Try again.\n");
}while(error==0);

//Array 2
do{
printf("\nPlease enter a size for your second array (1-100): ");
scanf("%d",&size2);
error=errorCheck(size2);
	if (error==0)
		printf("\nYou need to enter a number from 1-100. Try again.\n");
}while(error==0);

//Run the menu loop
do{
	//First display the menu and initialize the arrays at the beinning of the loop
	printf("\n\n");
	displayMenu();
	initializeArray1(size1);
	initializeArray2(size2);
	scanf("%d",&choice);

	//Use a switch statement for the user's choice
	switch (choice){

		case 1:
			initializeArray1(size1);
			printf("\nInput array\n");
			printArray1(size1);
			computeStats(size1);
		break;

		case 2:
			printf("Enter the number you want to search: ");
			scanf("%d",&find);
			printf("\nInput arrays\n");
			printArray1(size1);
			printArray2(size2);
			result=Search(size1,size2,find);
			if (result!=-1){
				printf("The number %d is present %d times in the" 
				       " arrays.",find,result);}
			else 
				printf("The number %d is present 0 times in the"
				       " arrays.",find);
		break;
		
		case 3:
			initializeArray1(size1);
			initializeArray2(size2);
			printf("\nInput arrays\n");
			printArray1(size1);
			printArray2(size2);
			bA=biggerArray(size1,size2);
			switch(bA){
				case 1:
					printf("\nThe first array is bigger.\n");
				break;

				case 2:
					printf("\nThe second array is bigger.\n");
				break;

				case 3:
					printf("\nThe arrays are even.\n");
				break;

				case 4:
					printf("\nThe arrays are not equal. "
					       "Please enter arrays of the same length.");
				break;

				default:
					printf("Error");
				break;
			};
		break;

		case 4:
			initializeArray1(size1);
			initializeArray2(size2);
			printf("\nInput arrays\n");
			printArray1(size1);
			printArray2(size2);
			cN=commonNumbers(size1,size2);
			printf("There are %d numbers in common between the two arrays.",cN);
		break;

		case 5:
			printf("\nExiting the program.\n");
			quit=1;
		break;

		default:
			printf("Error");
		break;


	}
}while(quit==0);	

			
			
return 0;
};

//Max, Min, and Average are used for the commonNumbers function
int Max(int size1){
	
	int i,m=0;
	for (i=0;i<size1;++i){
		if(first_array[i]>m)
			m=first_array[i];
	};
	return m;
};

int Min(int size1){
	
	int i,m=9;
	for (i=0;i<size1;++i){
		if(first_array[i]<m)
			m=first_array[i];
	};
	return m;
};

float Average(int size1){

	int i;
	float m=0;
	for (i=0;i<size1;++i){
		m=m+first_array[i];
	};
	m=m/(float)size1;
	return m;
}

//Search function is used to find the occurance of a chosen number by the user
int Search(int size1,int size2, int find){
	
	int count=0,i,j;

	for (i=0;i<size1;i++){
		if(first_array[i]==find)
			count++;
	}
	for (j=0;j<size2;j++){
		if(second_array[j]==find)
			count++;
	};
	return count;
};

//Tells the user which array is larger
int biggerArray(int size1,int size2){

	int i,score1=0,score2=0;
	
	if(size1!=size2)
		return 4;
	while(size1==size2){
		for (i=0;i<size1;++i){
			if(first_array[i]>second_array[i])
				score1++;
			else if(first_array[i]<second_array[i])
				score2++;
		};
	if(score1>score2)
		return 1;
	else if(score1<score2)
		return 2;
	else if(score1==score2)
		return 3;
	else
		return 0;
	};
	return 0;
};

//Make sure the arrays are 1-100
int errorCheck(int size1){

	if (size1>100||size1<1)
		return 0;
	else
		return 1;
};
//Initialize the first array with random numbers
void initializeArray1(int size1){

	int i;
	for (i=0;i<size1;++i){
	
		first_array[i]=rand()%10;
	};

}
//Initialize the second array with random numbers
void initializeArray2(int size2){

	int i;
	for (i=0;i<size2;++i){
	
		second_array[i]=rand()%10;
	};
}

//void function that prints out the menu, used every time an operation ends
void displayMenu(){

	printf("\nArray operations, your options are:"
	       "\n\n1:General Statistics"
	       "\n2:Search a number"
	       "\n3:Bigger array"
	       "\n4:Common number"
	       "\n5:Exit"
	       "\n\nEnter the operation you want to perform: ");
};
	
//Tells what numbers the arrays have in common
int commonNumbers(int size1,int size2){

	int i,j,counter=0;

	for (i=0;i<size1;++i){
		for(j=0;j<size2;++j){
			if(first_array[i]==second_array[j]){
				counter++;
				j=size2;
			};
		};
	};
	return counter;
};

//Combines 3 other functions to print out stats
void computeStats(int size1){

	printf("\nLargest number is %d",Max(size1));
	printf("\nSmallest number is %d",Min(size1));
	printf("\nAverage of the numbers is %.2f",Average(size1));
	printf("\nRange of the numbers is %.2f",(float)Max(size1)-(float)Min(size1));
	
};


//Functions for printing the two arrays
void printArray1(int size1){
	
	int i;
	for(i=0;i<size1;++i){
	printf("%d ",first_array[i]);
	};
	printf("\n");
};

void printArray2(int size2){
	
	int i;
	for(i=0;i<size2;++i){
	printf("%d ",second_array[i]);
	};
	printf("\n");
};





