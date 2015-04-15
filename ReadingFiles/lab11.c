/*
* Reading Files
 */

#include <stdio.h>
#include <string.h>
#define MAX 50

//Struct
typedef struct{

	int id;
	int grade;

} data;

data student[MAX];

//Prototypes
int loadArray(char* filename);
void printArray(int size);
int searchArray(int size, int id,int ngrade);
void writeContent(char* fname,int size);

//MAIN
int main(int argc, char** argv){

	int stdID=0,stdGrade=0,search=0;
	
	//Check if proper files are submitted
	if (argc != 3) {
		printf("Usage is ./a.out input.txt output.txt\n");
		return -1;
	}
	if (strcmp(argv[1], "input.txt") != 0 || strcmp(argv[2], "output.txt") != 0){
		printf("Files could not be opened\n");
		return -1;
	};
	
	//Print the array
	int size=loadArray(argv[1]);
	printf("\nStudent Record\nID    Grade\n");
	printArray(size);
	
	//Replace student's grade
	printf("\nEnter the ID of the student to search: ");
	scanf("%d",&stdID);
	printf("\nEnter a grade for the student: ");
	scanf("%d",&stdGrade);
	search=searchArray(size,stdID,stdGrade);
	//If there is no student with input ID terminate program
	if (search == 0){
		printf("Student with id %d is not present in the class\n",stdID);
		return 0;
	}
	//Write the content to an output file, then print the changes
	writeContent(argv[2],size);
	printf("\nUpdated student record\nID  Grade\n");
	printArray(size);

return 0;
}


int loadArray(char* filename){

	int i=0;
	FILE* file=fopen(filename,"r");
	if(file==NULL)
	{
		return 0;
	};

	int size;
	
	fscanf(file,"%d",&size);
	
	//Take data from input file and put into struct
	for(i=0;i<size;i++)
	{
		fscanf(file,"%d %d",&student[i].id,&student[i].grade);
	}

	fclose(file);
	return size;

};
	
//Print using the new struct info
void printArray(int size){
	int i;
	for(i=0;i<size;++i){
		printf("%d  %d\n",student[i].id,student[i].grade);
	};
};

//Search and replace a grade
int searchArray(int size, int id,int ngrade){
	int i,counter=0;
	for (i=0;i<size;++i){
		if (student[i].id == id){
			  student[i].grade = ngrade;
			  counter = 1;  
			  break;
		}
	};
	
	//If no student is found, return 0 
	return counter;
};

//Write new content to output.txt
void writeContent(char* fname,int size){
	
	int i=0,j=0;
	FILE* file=fopen(fname,"w");
	if(file==NULL){
		printf("error");
		return;
	};
	fprintf(file,"Updated student record\nID Grade\n");
	for(j=0;i<size;++i){
	fprintf(file,"%d %d\n",student[i].id,student[i].grade);
	};
	fclose(file);
		
};

