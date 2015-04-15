/* fopen, fclose, and FILE *
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_LENGTH 20
#define MAX_ARRAY_LENGTH 20

typedef struct student_ {
	char name[MAX_NAME_LENGTH];
	int num_A;
	int num_B;
	int num_C;
	int num_D;
	int num_F;
	float gpa;
}student;

student class[MAX_ARRAY_LENGTH];

int read_file(FILE* input);
void print_grade_distribution(int num_students);
void calculate_gpa(int index);
void write_to_file(FILE *output, int num_students);

int main (int argc, char* argv[]){
	
	//Show errors if file cannot be opened/null
	if (argc != 3){
		printf("Format: ./a.out input.txt output.txt\n");
		return -1;
	}

	FILE * fPointer = fopen(argv[1],"r");

	if(fPointer == NULL) 
	{
		printf("File NULL\n");
		return -1;
	}
	//read file, send the address to read_file, close file
	int num_students = read_file(fPointer);
	fclose (fPointer);
	//Print the histogram
	print_grade_distribution(num_students);
	//Open the output, write to it, close it
	FILE * fPointer2 = fopen (argv[2],"w");
	write_to_file(fPointer2,num_students);
	fclose (fPointer2);


return 0;
}

int read_file(FILE* input){

	int i=0;


	int size=0;
	fscanf(input,"%d",&size);

	for(i=0;i<size;i++)
	{
		fscanf(input,"%s %d %d %d %d %d",&class[i].name,&class[i].num_A,&class[i].num_B,&class[i].num_C,&class[i].num_D,&class[i].num_F);
	//calculate the gpa within the for loop
	calculate_gpa(i);
	};

	return size;
};

void print_grade_distribution(int num_students){
	int i=0,counter=0;
	//Print A's
	for (i=0;i<num_students;++i){
		counter=counter+class[i].num_A;
	};
	printf("\nA:");
	for (i=0;i<counter;++i){
		printf("-");
	};
	//Print B's
	counter=0;
	for (i=0;i<num_students;++i){
		counter=counter+class[i].num_B;
	};
	printf("\nB:");
	for (i=0;i<counter;++i){
		printf("-");
	};
	//Print C's
	counter=0;
	for (i=0;i<num_students;++i){
		counter=counter+class[i].num_C;
	};
	printf("\nC:");
	for (i=0;i<counter;++i){
		printf("-");
	};
	//Print D's
	counter=0;
	for (i=0;i<num_students;++i){
		counter=counter+class[i].num_D;
	};
	printf("\nD:");
	for (i=0;i<counter;++i){
		printf("-");
	};
	//Print F's
	counter=0;
	for (i=0;i<num_students;++i){
		counter=counter+class[i].num_F;
	};
	printf("\nF:");
	for (i=0;i<counter;++i){
		printf("-");
	};

	printf("\n");
};


void calculate_gpa(int index){
	
	float A=0,B=0,C=0,D=0,F=0,total_gpa=0,total=0;
	
	A = class[index].num_A * 4;
	B = class[index].num_B * 3;
	C = class[index].num_C * 2;
	D = class[index].num_D * 1;
	//collects the numerator using the GPA scale
	total_gpa= A + B + C + D;
	//collects the denominator using base values
	total = class[index].num_A + class[index].num_B +  class[index].num_C +  class[index].num_D +  class[index].num_F;

	class[index].gpa = total_gpa/total;

	
};


void write_to_file(FILE *output, int num_students){

	int i=0;

	for(i=0;i<num_students;++i){
	fprintf(output,"%s %f\n",class[i].name,class[i].gpa);
	};

};

