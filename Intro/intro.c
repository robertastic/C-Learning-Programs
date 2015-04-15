/* Name: Robert Stovall
 * Date: 8/22/2013
 * Sub Code: sub sandwiches
 * Lead TA: Tyler Nivin 
 * */

#include <stdio.h>

int main(void)
{
	float time;
	int distance;
	int speed;
	//Inform the user what the program is
	printf("\nThis program is used to calculate the flight time of an aero plane.\n");
	//Have the user enter the distance of the flight
	printf("Distance of flight in meters: ");
	scanf("%d", &distance);
        while(distance<=0){
		printf("The distance must be a positive number\nDistance of flight in meters: ");
		scanf("%d", &distance);
		}
	//Have the user enter the speed of the flight
	printf("Speed of flight in miles/hour: ");
	scanf("%d", &speed);
	//Create a failsafe incase the speed is at or less than 0
	while(speed<=0){
		printf("The speed must be a positive number\nSpeed of flight in miles/hour: ");
		scanf("%d", &speed);
		}
	//Calculate flight time
	time = ((float)(distance/((speed*1600)/3600)));
	//Return to the user how long their flight will take
	printf("Flight time of given plane is %f seconds.\n", time);
	return 0;
}


