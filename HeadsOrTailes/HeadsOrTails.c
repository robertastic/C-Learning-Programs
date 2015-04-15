/*
 * Description: Game of Heads and Tails
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int generateNumber(void);
void displayMenu(void);
int checkGuess(int guess, int answer);
void printResult(int result, int guess);
int errorCheck(int guess);
//Create global variables to keep track the number of guesses
int correct=0,total=0;


int main(void){
//Create variables outside the do/while loop for playing again
int playAgain=0;
float percent=0;

do{
	int guess=0,answer=0,result=0,error=0;
	srand(time(NULL));
	answer = generateNumber();
	displayMenu();

	printf("Enter your choice: ");
	scanf("%d",&guess);
	
	//Return a 0 if the guess  is not 0 or 1
	error=errorCheck(guess);
	//Run an error check if the guess is not 0 or 1
	while (error==0){
		printf("Invalid guess enter your choice again: ");
		scanf("%d",&guess);
		error=errorCheck(guess);
			};

	
	result = checkGuess(guess,answer);

	printResult(result,guess);
	//Ask the user if they want to play again	
	printf("Would you like to play again?(1 yes,0 no): ");
	scanf("%d",&playAgain);

}while(playAgain==1);
//Return the results of the user's play session
printf("You have made %d correct guesses in %d tries.\n",correct,total);
percent = 100*((float)correct/(float)total);
printf("Your winning percentage is %.2f%%.\n",percent);

	return 0;
};
//Generates 0 or 1 randomly
int generateNumber(void){
	int x;
	x = rand()%2;

	return x;
	
};

//Displays the opening menu
void displayMenu(void){
	printf("Please take a guess.\n0: Heads\n1: Tails\n\n");
};

//Return 1 if the user is correct, 0 if incorrect
int checkGuess(int guess, int answer){
	
	int x;
	if (guess==answer){
		x=1;
	} else {
	     	x=0;
	};
	
	return x;	

};

//Prints out the results of the users guess compared to the answer
void printResult(int result, int guess){

	if (guess==1&&result==1){
		printf("Your answer was Tails and is correct.\n");
		//If the user was correct, add one to correct and total
		correct++;
		total++;
	} else if (guess==1&&result==0){
		printf("Your answer was Tails and is incorrect.\n");
		//Otherwise just add one to total
		total++;
	} else if (guess==0&&result==1){
		printf("Your answer was Heads and is correct.\n");
		correct++;
		total++;
	} else if (guess==0&&result==0){
		printf("Your answer was Heads and is incorrect.\n");
		total++;
	};


};

//If the user's guess is valid (1 or 0) return 1, otherwise return 0
int errorCheck(int guess){
		
	if (guess>1||guess<0){
		return 0;
	} else {
		return 1;
	};
};	

	

