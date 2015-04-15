/* 
 * Description: Compound Interest Calculation
 */

#include <stdio.h>
#include <math.h>

//Create a function to calculate the compound interest
float CI (int years, float org, float inter){

	float a=0;
	a = org*pow(1+(inter/100),(float)years);

	return (a);
};

//Main function
int main (void){

int years=0;
float org=0,inter=0, compound=0,interest=0;

//Use a do/while loop to run the program a first time
do{

//Have the user enter the original amount in the account
	printf("This is a program to calculate compound interest over a set number of years.\n"
       	       "Enter the amount of money originally in the bank account: $");
	scanf("%f",&org);

//if the amount entered is less than or equal to 0, make the user reenter
	if (org<=0)
		printf("Please enter a number greater than 0.\n");
} while (org<=0);

//Have the user enter the number of years to calculate interest
do{
	printf("Enter the number of years you wish to calculate interest for (1-10): ");
	scanf("%d", &years);
//Make sure the years is within the set parameters
	if (years<1||years>10)
		printf("Please enter 1-10 for the years calculation.\n");
} while (years<1||years>10);

//Have the user enter the rate of interest to calculate
printf("Enter the rate of interest this account increases per year (0.00-100.00): ");
scanf("%f",&inter);

//Calculate the compound iterest using the function
compound = CI (years,org,inter);

//Find the interest gained from subtracting the original account from the compound calculation
interest = compound - org;

//Read the results to the user
printf("The amount in the account after %d years with the interest rate of %.2f%% is $%.2f.\n"
		"Interest earned is %.2f.\n",years,inter,compound,interest);

	return 0;
}
