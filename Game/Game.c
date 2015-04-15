/* Creating a simple game
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

/* Constants used within the program */
#define ROW_SIZE 10
#define COL_SIZE 10
#define STR_LENGTH 10

/* Function Prototypes*/
void initializeGameBoard(char gameBoard[][COL_SIZE], int rowSize , int colSize);
void displayGameBoard (char gameBoard[][COL_SIZE], int rowSize , int colSize);
void populateGameBoard(char gameBoard[][COL_SIZE], int rowSize , int colSize ,int numPieces);
char getPieceType (void);
int verifyCoordinates(int convertedRow, int convertedCol, int rowSize, int colSize);
int attackTarget (char gameBoard[][COL_SIZE],int rowSize,int colSize);
int convertStringCoordinateToInt (char* str);
int defenseAttacks (char gameBoard[][COL_SIZE], int rowSize, int colSize);
int countPieceType(char gameBoard[][COL_SIZE], int rowSize,  int colSize, char type);

int main (int argc, char *argv[]) {
    // Checks if the number of arguements on the command line is 3 else terminate
	if (argc != 3)
		return -1;
	srand(time(NULL)); 
	// Converts a string into a integer
	const int row_size = atoi(argv[1]);
	const int col_size = atoi(argv[2]);
	  // Checks if the values passed in are within the dimensions of the game board
	if (row_size > COL_SIZE || row_size < 1 || col_size > COL_SIZE || col_size < 1)
		return -1;
	/* implement main logic code starting here*/
	char gameBoard[ROW_SIZE][COL_SIZE]; // Create the static gameboard
	int level = row_size; // assign the number of units to place each turn
	int player_life = 100; // the starting life of the player
	int total_score = 0; // the total player's score counter
	int devastator_missiles = 0; // a counter used for the devastator missiles obtained
	char str_buffer[STR_LENGTH]; // used for the answer 

	initializeGameBoard (gameBoard,row_size,col_size); // fill the gameboard with empty spaces
	populateGameBoard (gameBoard,row_size,col_size,level); // populate the gameboard 
	printf("\nPlayer's life left is [%d]\nNumber of devastor missiles is [%d]\nPlayer's score is [%d]\n\n", player_life,devastator_missiles,total_score);
	displayGameBoard(gameBoard,row_size,col_size); // print the initial gameboard
	
	while (player_life > 0) { // terminates the loop when player's life is less than 0
		
		if (devastator_missiles > 0) { // If the player has obtained a devastator missile
			printf("\nWould you like to fire a devastator_missile? (yes or no)?: ");
			scanf("%s", str_buffer);
			if (strcmp(str_buffer, "yes") == 0) { // Check if user wants to use a devastator missile and call attackTarget 3 times
				total_score += attackTarget (gameBoard,row_size,col_size); 
				total_score += attackTarget (gameBoard,row_size,col_size);
				total_score += attackTarget (gameBoard,row_size,col_size);
				--devastator_missiles; // used a devastator missile so decrement the count
			}
			else { // Fire a laser guided missile instead
				printf("\nFiring a Laser Guided Missile!!\n");
				total_score += attackTarget (gameBoard,row_size,col_size);
			}
		}
		else { // No devastator missile to use so I fire a laser guided missile instead
			printf("\nFiring a Laser Guided Missile!!\n");
			total_score += attackTarget (gameBoard,row_size,col_size);
		}
		
		player_life -= defenseAttacks (gameBoard,row_size,col_size); // obtain and assign damage by remaining units on the gameboard
		const int aa_found = countPieceType(gameBoard,row_size,col_size,'A'); // obtain the count of Anti-Air Craft units
		if (aa_found == 0) { // If zero Anti-Aircraft units are found, add more units to the gameboard and increment the devastator missile count
			++devastator_missiles;
			populateGameBoard(gameBoard,row_size,col_size,level);
		}
		printf("\nPlayer's life left is [%d]\nNumber of devastor missiles is [%d]\nPlayer's score is [%d]\n\n", player_life,devastator_missiles,total_score);
		displayGameBoard(gameBoard,row_size,col_size); // print the gameboard to the player
	}
	printf("\nGame over! Your Helicopter is destroyed!\n");
	return 0;
}

/* Define functions starting here */

//Initialize the board with blank spaces
void initializeGameBoard(char gameBoard[][COL_SIZE], int rowSize , int colSize) {
	int i,j;

	for(i=0;i<rowSize;++i){
		for(j=0;j<colSize;++j){
			gameBoard[j][i]=' ';
		};
	};
}

//Print out the board, using ascii characters for the labels
void displayGameBoard (char gameBoard[][COL_SIZE], int rowSize , int colSize) {
	int j,l,i;
	char ascii1,ascii2;
	printf("\n\n    ");
	for (i=0;i<rowSize;++i){
		ascii1 = i+97;
		printf("%c    ",ascii1);
	};

	for (l=0;l<rowSize;++l){
		ascii2 = l+97;
		printf("\n%c ",ascii2);
		for (j=0;j<colSize;++j){
			printf("[ %c ]",gameBoard[j][l]);
		};
	};
}

//populate the board with enemies based on the rowSize chosen
void populateGameBoard(char gameBoard[][COL_SIZE], int rowSize , int colSize ,int numPieces) {
	
	int total=0,i=0,r,c;
	total=countPieceType(gameBoard,rowSize,colSize,'A');
	total+=countPieceType(gameBoard,rowSize,colSize,'T');

	while(total + numPieces > rowSize * colSize){
		--numPieces;
	};

	while(i < numPieces) {
		r = rand() % rowSize;
		c = rand() % colSize;
		if (gameBoard[r][c] == ' '){
			gameBoard[r][c] = getPieceType();
		}else{
			do{
				r = rand() % rowSize;
				c = rand() % colSize;
			} while (gameBoard[r][c] != ' ');
			
			gameBoard[r][c] = getPieceType();
		};
		i++;
	};
}

//50/50 chance for an AA or a tank
char getPieceType (void) {
	int ran;
	
	ran=rand()%2;
	if(ran==1){
		return 'A';
	}else{
		return 'T';
	};
}

//Make sure the coordinates given are within the bounds
int verifyCoordinates(int convertedRow, int convertedCol, int rowSize, int colSize) {
	if(convertedRow<=rowSize&&convertedCol<=colSize){
		return 1;
	} else {
		return 0;
	};
}

//Attack given target, return points depending on what is hit, fill with ' '
int attackTarget (char gameBoard[][COL_SIZE],int rowSize,int colSize) {
	char row_str[STR_LENGTH];
	char col_str[STR_LENGTH];
	int col,row,points=0;

	printf("\nEnter Target Coordinates: ");
	do{
		scanf("%s %s", row_str, col_str);
		row=convertStringCoordinateToInt (row_str);
		col=convertStringCoordinateToInt (col_str);
		
		if( col>=colSize || col<0 || row>=rowSize || row<0)
			printf("Improper coordinates, Try Again: ");

	} while ( col>=colSize || col<0 || row>=rowSize || row<0);

	if(gameBoard[row][col]==' '){
		printf("\nMiss!");
	}else if (gameBoard[row][col]=='A'){
		points = 25;
	}else if (gameBoard[row][col]=='T'){
		points = 35;
	};

	gameBoard[row][col]=' ';

	return points;
}

//checks to see if a string fits the NATO code
int convertStringCoordinateToInt (char *str) {

	int digit;
	
		if(strcmp("alfa",str)==0){
			digit = 0;		
		}else if(strcmp("bravo",str)==0){
			digit = 1;
		}else if(strcmp("charlie",str)==0){
			digit = 2;		
		}else if(strcmp("delta",str)==0){
			digit = 3;		
		}else if(strcmp("echo",str)==0){
			digit = 4;		
		}else if(strcmp("foxtrot",str)==0){
			digit = 5;		
		}else if(strcmp("golf",str)==0){
			digit = 6;		
		}else if(strcmp("hotel",str)==0){
			digit = 7;
		}else if(strcmp("india",str)==0){
			digit = 8;				
		}else if(strcmp("juliett",str)==0){
			digit = 9;
		}else{
			digit = -1;
		};

	return digit;

}

//damages the user based on what enemies are on the board
int defenseAttacks (char gameBoard[][COL_SIZE], int rowSize, int colSize) {
	
	int tanks=0,AAs=0,i,j,totalDamage=0;
	
	tanks=countPieceType(gameBoard,rowSize,colSize,'T');
	AAs=countPieceType(gameBoard,rowSize,colSize,'A');

	for(i=0;i<=tanks;++i)
		totalDamage=totalDamage+rand()%4+2;

	for(j=0;j<=AAs;++j)
		totalDamage=totalDamage+rand()%6+5;

	return totalDamage;


}

//counts how many pieces of T's or AA's are on the board
int countPieceType(char gameBoard[][COL_SIZE], int rowSize,  int colSize, char type) {
	int i,j,counter=0;

	for (i=0;i<rowSize;++i){
		for(j=0;j<colSize;j++){
			if(gameBoard[j][i]==type)
				counter++;
		};
	};
	return counter;
}
