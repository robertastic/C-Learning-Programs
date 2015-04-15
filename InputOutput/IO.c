/*
 * Description: Ask for the user to enter a student's first and second midterm and final exam grades.
 *	        Print out which the student got the lowest grade on and which they got the highest.
 */

#include <stdio.h>
#include <math.h>

int main (void){
int cont=1;
do{
int a=0,b=0,c=0;
float sum=0;
char grade;
//Have the user enter the three seperate grades. Make sure the grades are in the proper parameters.
//First midterm
do{
	printf("Please enter the student's grade for the first midterm of a student using percanitles (0-100): ");
	scanf("%d", &a);
	
	if(a<0||a>100)
		printf("Your percentile was not valid. Please use the numbers 1-100.\n");
  }while(a<0||a>100);
//Second midterm
do{
	printf("Please enter the student's grade for the second midterm of a student using percentiles (0-100): ");
	scanf("%d", &b);

	if(b<0||b>100)
		printf("Your percentile was not valid. Please use the numbers 1-100.\n");
  }while(b<0||b>100);
//Third midterm
do{
	printf("Please enter the studen't grade for the final exam of the class using percentiles (0-100): ");
	scanf("%d", &c);

	if(c<0||c>100)
		printf("Your percentile was not valid. Please use the numbers 1-100.\n");
  }while(c<0||c>100);

//Print the student's highest grade of the 3 tests
printf("This student's highest grade was on their ");

if(a>b&&a>c)
	printf("first midterm, scoring %d percent.",a);
if(b>a&&b>c)
	printf("second midterm, scoring %d percent.",b);
if(c>a&&c>b)
	printf("final exam, scoring %d percent.",c);

//Print the student's lowest grade
printf("\nThis student's lowest grade was on their ");

if(a<b&&a<c)
	printf("first midterm, scoring %d percent.",a);
if(b<a&&b<c)
	printf("second midterm, scoring %d percent.",b);
if(c<a&&c<b)
	printf("final exam, scoring %d percent.",c);

//Calculate the letter grade
sum=(((float)a+(float)b+(float)c)/3);
if (sum>=90)
	grade='A';
else if (sum>=80)
	grade='B';
else if (sum>=70)
	grade='C';
else if (sum>=60)
	grade='D';
else 
	grade='F';

printf("\nStudent's Grade: %c,  %.2f percent.", grade, sum);
//Ask if they want to continue (or terminate the loop)
printf("\nWould you like to exit?\n0 to exit, 1 to use the program again: ");
scanf("%d", &cont);

} while (cont == 1);

return 0;
}
