/* Name: Robert Stovall
 * TA: Tyler Nivins
 * Project: Homework 4
 * Date: 11/24/13
 */
#include <stdio.h>
#include <string.h>
#define MAX 50
typedef struct
{
	int id;
	int grade;
} data;
data student[MAX];

int loadArray(char *filename);
void printArray(int size);
int updateArray(char *filename, int n);
int findHighestGrade(int size);
int findLowestGrade(int size);
float averageClassgrade(int size);
int writeContent(char *fname,int size, int low, int high, float avg);


int main(int argc, char** argv){

	//Make sure all arguments are properly given
	if (argc != 4){
		printf("Usage is ./a.out input.txt update.txt output.txt\n");
		return -1;
	};
	if (strcmp(argv[1], "input.txt") != 0 || strcmp(argv[2], "update.txt") != 0 || strcmp(argv[3], "output.txt") != 0){
	       printf("Files count not be opened\n");
       return -1;
	};       

	int high,low,highGrade=0,lowGrade=0,newSize=0,j,k;
	float avg=0;
	//Print the input.txt array
	int size=loadArray(argv[1]);
	printf("\nStudent Record\nID    Grade\n");
	printArray(size);

	//calculate stats
	high=findHighestGrade(size);
	low=findLowestGrade(size);
	avg=averageClassgrade(size);

	//Create a for loop to find the grade of the highest student
	
	for(j=0;j<size;++j){
		if(high==student[j].id){
			highGrade=student[j].grade;
			break;
		};
	};
	
	
	//Create a for loop to find the grade ofo the lowest student
	
	for(k=0;k<size;++k){
		if(low==student[k].id){
			lowGrade=student[k].grade;
			break;
		};
	};
	
	//print stats
	printf("\n\nStudent with the highest grade has the id %d and the grade %d",high,highGrade);
	printf("\nStudent with the lowest grade has the id %d and the grade %d",low,lowGrade);
	printf("\nAverage class grade is %.2f",avg);


	//Update the record
	newSize=updateArray(argv[2],size);

	//print the new array
	printf("\n\nUpdated Student Record\nID    Grade\n");
	printArray(newSize);

	//Call the functions again
	high=findHighestGrade(newSize);
	low=findLowestGrade(newSize);
	avg=averageClassgrade(newSize);

	//Rerun the high for loop
	
	for(j=0;j<newSize;++j){
		if(high==student[j].id){
			highGrade=student[j].grade;
			break;
		};
	};
	
	
	//Rerun the low for loop
	
	for(k=0;k<newSize;++k){
		if(low==student[k].id){
			lowGrade=student[k].grade;
			break;
		};
	};
	
	printf("Student Statistics after update operation");
	printf("\n\nStudent with the highest grade has the id %d and the grade %d",high,highGrade);
	printf("\nStudent with the lowest grade has the id %d and the grade %d",low,lowGrade);
	printf("\nAverage class grade is %.2f",avg);

	//Write the content to an output file
	writeContent(argv[3],newSize,low,high,avg);
	

return 0;
};


int loadArray(char *filename){

	int i=0;
	FILE* file=fopen(filename,"r");
	if(file==NULL)
	{
		return 0;
	};

	int size;

	fscanf(file,"%d",&size);

	for(i=0;i<size;i++){
		fscanf(file,"%d %d",&student[i].id,&student[i].grade);
	};

	fclose(file);
	return size;

};
void printArray(int size){
	int i;
	for(i=0;i<size;++i){
		printf("%d  %d\n",student[i].id,student[i].grade);
	};

};

int updateArray(char *filename, int size){

	int i=0,size2=0,size3=0;
	FILE* file=fopen(filename,"r");
	if(file==NULL)
	{
		return 0;
	};

	//get the number to update, add to original number to get total
	fscanf(file,"%d",&size2);
	size3=size+size2;

	for(i=size;i<size3;i++){
		fscanf(file,"%d %d",&student[i].id,&student[i].grade);
	};

	fclose(file);
	return size3;


};


int findHighestGrade(int size){

	int i,highGrade=0,highStudent=0;

	for(i=0;i<size;++i){
		if(student[i].grade>highGrade){
			highGrade=student[i].grade;
			highStudent=student[i].id;
		};
	};


	return highStudent;

};
int findLowestGrade(int size){

	int i,lowGrade=100,lowStudent=0;

	for(i=0;i<size;++i){
		if(student[i].grade<lowGrade){
			lowGrade=student[i].grade;
			lowStudent=student[i].id;
		};
	};

	return lowStudent;
};
float averageClassgrade(int size){
	
	int i;
	float average=0;

	for(i=0;i<size;++i){
		average=average+student[i].grade;
	};

	average=average/size;

	return average;
		
};
int writeContent(char *fname,int size, int low, int high, float avg){
	
	int i=0,j=0,k=0,highGrade=0,lowGrade=0;
	FILE* file=fopen(fname,"w");
	if(file==NULL){
		printf("error");
		return 0;
	};
	for(i=0;i<size;++i){
		fprintf(file,"%d  %d\n",student[i].id,student[i].grade);
	};
	
	//Create a for loop to find the grade of the highest student
	
	for(j=0;j<size;++j){
		if(high==student[j].id){
			highGrade=student[j].grade;
			break;
		};
	};
	
	
	//Create a for loop to find the grade ofo the lowest student
	//
	
	for(k=0;k<size;++k){
		if(low==student[k].id){
			lowGrade=student[k].grade;
			break;
		};
	};
	

	fprintf(file,"\n\nStudent with the highest grade has the id %d and the grade %d",high,highGrade);
	fprintf(file,"\nStudent with the lowest grade has the id %d and the grade %d",low,lowGrade);
	fprintf(file,"\nAverage class grade is %.2f",avg);
	fclose(file);

	return 1;
};





