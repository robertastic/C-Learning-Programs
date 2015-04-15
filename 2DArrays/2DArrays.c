/****************************
 * Description: Playing around with 2d Arrays
 * **************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HIGHEST 100.00
#define NUMSTUDENTS 100 //Column Size

//Prototyes********************************************************
int check_error(int);
void initialize_2Darray(float scores[][NUMSTUDENTS],int);
void print_2Darray(float scores[][NUMSTUDENTS],int);
float column_average(float scores[][NUMSTUDENTS],int,int);
void average_scores(float scores[][NUMSTUDENTS],int);
char compute_grade(float scores[][NUMSTUDENTS],int,int);
float search_max(float scores[][NUMSTUDENTS],int,int,int);
void sort_2Darray(float scores[][NUMSTUDENTS],int);

//Main Function****************************************************
int main(void){
float scores[][NUMSTUDENTS] = {{0.00}};
int size=0,error=0,student=0,row=0,col=0;
float max=0.00;
char grade;
srand(time(NULL));

printf("Enter the size of array (1-100): ");
scanf("%d",&size);

error=check_error(size);

while(error==0){
	printf("Invalid input enter the size of the array again: ");
	scanf("%d",&size);
	error=check_error(size);
};

//Initialize and print overall scores and averages
initialize_2Darray(scores,size);
print_2Darray(scores,size);
average_scores(scores,size);

//Printing a students grade
printf("\nEnter a student number (1-%d): ",size);
scanf("%d",&student);
grade=compute_grade(scores,size,student);
printf("\nOverall grade for the %dth student is %c.\n",student,grade);

//Search the array
printf("\nEnter the row (1-%d): ",size);
scanf("%d",&row);
printf("\nEnter the column (1-%d): ",size);
scanf("%d",&col);
max=search_max(scores,row,col,size);
printf("The largest number present in row %d or col %d is %.2f\n.",row,col,max);

//BONUS
printf("\n\nArray before sorting: \n");
print_2Darray(scores,size);
sort_2Darray(scores,size);
printf("\n\nArray after sorting: \n");
print_2Darray(scores,size);

return 0;
};

//Functions********************************************************
int check_error(int size){
	int error=0;

	if(size>100||size<0){
		return error=0;
	}else{
		return error=1;
	};
};

void initialize_2Darray(float scores[][NUMSTUDENTS],int size){
	
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
		scores[i][j]= (HIGHEST* ((float)rand()/(float)RAND_MAX));
		};
	};

};

void print_2Darray(float scores[][NUMSTUDENTS],int size){
	int i,j,k;
	printf("\nScores:\n");
	for(k=1;k<=size;k++){
		printf("%5sC%d"," ",k);
	};
	for(i=0;i<size;i++){
		printf("\n");
		printf("S%d: ",i+1);
		for(j=0;j<size;j++){
			printf("%6.2f ",scores[i][j]);
		};
	};
	printf("\n");
};


float column_average(float scores[][NUMSTUDENTS],int size,int col){
	int i;
	float average=0.00,sum=0.00;
		for (i=0;i<size;i++){
			sum+=scores[i][col];	
		}
	average=sum/(float)size;
	return average;
};
void average_scores(float scores[][NUMSTUDENTS],int size){
	int i;
	float average=0.00;	
	for(i=0;i<size;i++){
		average=column_average(scores,size,i);
		printf("\nCourse %d average score is %.2f\n",i+1,average);
	};
};
char compute_grade(float scores[][NUMSTUDENTS],int size,int student){
	int i;
	float average=0.00,sum=0.00;
	for(i=0;i<size;i++){
		sum=sum+scores[student-1][i];
	};
	average=sum/size;
	
	if(average>=90){
		return 'A';
	}else if(average>=80){
		return 'B';
	}else if(average>=70){
		return 'C';
	}else if(average>=60){
		return 'D';
	}else{
		return 'F';
	};
	
};
float search_max(float scores[][NUMSTUDENTS],int row,int col,int size){
	int i=col-1,j=row-1;
	float high=0.00;
	for(i=col-1;i<size;i++){
		if(high<scores[i][j]){
				high=scores[i][j];
		};
	};
	i=row-1;
	for(j=row-1;j<size;j++){
			if(high<scores[i][j]){
				high=scores[i][j];
			};
		};
	return high;
};

void sort_2Darray(float scores[][NUMSTUDENTS],int size){
	int i,j,k;
	float temp=0.00;
	for (j=0;j<size;j++){
		for(k=0;k<size;k++){
			for (i=0;i<size-1;i++){
				if (scores[i][j]>scores[i+1][j]){
				temp=scores[i][j];
				scores[i][j]=scores[i+1][j];
				scores[i+1][j]=temp;
				};
			};
		};
	};
};



