/*
 * Description: Ask for an array size, generate random numbers in that 	* 	       array, print them out, then show the frequency
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY 100
#define ARRAY2 10

//PROTOTYPES
int check_error(int);
void initialize_array(int[],int);
void print_array(int[],int);
void frequency(int[],int[],int);
int mode(int[]);
void print_histogram(int []);
void sort_array(int a[], int size);


//MAIN
int main(){
int statistics_array[ARRAY] = {0};
int frequency_array[ARRAY2] = {0};
int size=0,error=0,reset=0,m=0;
srand(time(NULL));

//Have the user enter the array size
do{
printf("\nPlease enter the size of an array (0-100): ");
scanf("%d",&size);
error=check_error(size);
	if (error==0)
		printf("Please enter a number from 0-100.\n");
}while(error==0);

printf("\nArray numbers generated: ");

//fill the array with random numbers then print it out
initialize_array(statistics_array,size);
print_array(statistics_array,size);

//initialize the frequency array to 0
for (reset=0;reset<=ARRAY2;++reset){
	frequency_array[reset] = 0;
				   };
//Fill the frequency array with the statistics_array numbers
frequency(frequency_array,statistics_array,size);

//Find the mode of the statistics_array
m=mode(frequency_array);
printf("\n\nMode for the array is the number %d.\n",m);

//print a histogram of the frequency of the statistics array
printf("\n\nPrinting Histogram\n\n");
print_histogram(frequency_array);

//show the original array again
printf("\n\nArray before sorting\n\n");
print_array(statistics_array,size);

//show the array after being sorted
sort_array(statistics_array,size);
printf("\n\nArray after sorting\n\n");
print_array(statistics_array,size);
printf("\n\n");




return 0;
};

//FUNCTIONS
//Check error
int check_error(int size){
	
	if (size>100||size<0)
		return 0;
	else 
		return 1;
};
//Initialize the array
void initialize_array(int a[],int size){
	int i;
	for(i=0;i<=size;++i){
		a[i]=rand()%10;
	}

};
//print the array
void print_array(int a[],int size){
	int i;
		for(i=0;i<=size;++i){
		printf("%d ",a[i]);
			    };
};
//record the frequency of the numbers 0-9
void frequency(int a[],int b[],int size){
	int add;	
	for (add=0;add<=size;++add){
		++a[b[add]];
				     };
};



//Tell the mode of the array
int mode(int a[]){
	int i,m=0, max = 0;
	for (i=0;i<ARRAY2;++i){
		if (a[i]>max) {
			max =a[i];
			m = i;
			
		}
	}
	return m;
};

//Print a histogram
void print_histogram(int a[]){

	int i,j;

	for (i=0;i<10;++i){
		printf("\n%d:",i);
		for (j=0;j<a[i];++j){
			printf("*");
		};
	};
};

//Sort the original array
void sort_array(int a[], int size){
int i,j,temp=0;
	for (j=0;j<size;j++){
		for (i=0;i<size;++i){
			if (a[i]>a[i+1]){
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			};
		};
	};


}



