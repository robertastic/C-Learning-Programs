/* 
 * More 2D fun
 */

#include <stdio.h>
#include <ctype.h>
#define MAX 100


//PROTOTYPES********************************************************
int length(char[]);

void reverse(char [],char[],int);

void sort(char[],int);

int search(char [],char,int);

void merge(char a[], char b[],char c[],int);

//MAIN**************************************************************
int main()
{
	//Initialize the arrays
	char x[MAX];
	char y[MAX];
	char z[MAX];
	char q[MAX];
	
	//Ask for the initial array
	printf("Enter a string: ");
	scanf("%s",x);
	//Find the length
	int len=length(x);
	printf("\n Input string is %s", x);
	//Run the reverse function
	reverse(x,y,len);
	//Run the sort function
	sort(x,len);
	//Print th
	printf("\n Length of the string is %d", len);

	char c;
	scanf("%c",&c);

	printf("\n Enter the character to search : ");
	scanf("%c",&c);

	int s=search(x,c,len);
	
	printf("\n Character %c is present %d times in the string",c,s);


	//BONUS
	
	printf("\nEnter a new string: ");
	scanf("%s",z);
	merge(x,z,q,len);
	
	return 0;
};	
//FUNCTIONS*********************************************************

//Find the length
int length(char a[]){
	
	int len=0,i;

	for (i=0;i<=MAX;i++){
		if (a[i] != '\0'){
			len++;
		}else{
			break;
		};
	};


return len;
};

//Take in the given array and an initialized array
//Fill the second array with the reverse of the first
void reverse(char a[],char b[],int length){
	
	int i,j=0;
	for (i=length - 1;i>=0;--i){
		b[j] = a[i];
		j++;
	}
	b[j] = '\0';
	printf("\n Reverse string is %s", b);


};

//Sort the given array in alphabetical order
void sort(char a[],int length){
	
	int i,j;
	char temp;
	for (i=1;i<length;i++){
		for(j=0;j<length-1;j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			};
		};
	};
	
	printf("\n Sorted string is %s",a);


};

//Search for a certain letter and return the amount of occurences
int search(char a[],char c,int length){
	
	int i,y=0;

	for(i=0;i<=length;i++){
		if (a[i]==c){
			y++;
		};
	};		

	return y;
};
//BONUS
//merge two given arrays
void merge(char a[], char b[],char c[],int length){
	
	int i,counter=0;
	for(i=0;i<length;i++){
		if(a[i]!='\0'){
			c[counter]=a[i];
	       		counter++;	
		};
		if(b[i]!='\0'){
			c[counter]=b[i];
			counter++;
		};
	};
	c[counter]='\0';
	printf("\n First string is %s",a);
	printf("\n Second string is %s",b);
	printf("\n Merged string is %s",c);
};



