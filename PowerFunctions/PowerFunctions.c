/***********************************
 * Description: Find interest using a personally written power function
 ***********************************/


#include <stdio.h>

//Define functions
float pwr (float x,int y);
float interest(float cmp,float amt);
float total(float amt, float rate, int year);


//Main function
int main (void){ 

	int choice=0,year=0;
        float amt=0, rate=0, tot=0, inter=0;

//Original Menu, determines output of the switch statement

do{
	printf("\nBank account type\n(1)Checking\n(2)Saving\n(3)Fixed Deposit\n\nPlease make a selection: ");
	scanf("%d",&choice);

		if (choice>3||choice<1)
			printf("Incorrect choice.\n");
   }while(choice>3||choice<1);
//Enter year
do{
	printf("Enter a year: ");
	scanf("%d", &year);

		if (year<1||year>10)
			printf("The year should be between 1-10\n");
   }while(year<1||year>10);
//Enter amount
do{
	printf("Enter the amount: $");
	scanf("%f",&amt);

		if (amt<=0)
			printf("Amount can't be negative of zero.\n");
   }while(amt<=0);

//Switch to determine proper interest
switch (choice){

	case 1:
		rate = .01;
	break;

	case 2:
		rate = .03;
	break;

	case 3:
		rate = .07;
	break;

	default:
		printf("Error");
	break;
};
//Run the functions
tot = total(amt,rate,year);
inter = interest(tot,amt);

//Make rate look like a percentile
rate = rate*100;

//Tell the user the total amount earned and interest
printf("Total amount in the account after %d year(s) at the interest rate of %.0f%% is $%.2f.", year,rate,tot);
printf("\nTotal interest earned in %d year(s) on the amount $%.2f is $%.2f.\n",year,amt,inter);

//Bonus

printf("\n\nBONUS: \nEnter a number: ");
scanf("%f",&rate);
printf("Enter an exponent: ");
scanf("%d",&year);
amt = pwr(rate,year);
printf("Answer: %.4f.\n",amt);
return 0;
};


//Power function 
float pwr (float x,int y){

	int i;
	float z=1;
	//If exponent is positive
	if (y>0){
		for(i=0; i<y;i++){
			z = x*z;
			 	 };
		}
	//If exponent is 0
	else if (y==0){
		z=1;
		}
	//If exponent is negative
	else if (y<0){
		for(i=0;i>y;i--){
			z = x*z;
				};
		z=1/z;
		};
	
	return z;
};

//Total after interest calculates
float total(float amt, float rate, int year){

	float tot;
	rate = rate+1;

	tot = amt * pwr(rate,year);

	return tot;
};
		
//Interest earned		
float interest(float tot,float amt){
	float z;
	z = tot - amt;

	return z;
};
