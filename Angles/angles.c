/* Ask user to create a proper triangle
 */
#include <stdio.h>
#include <math.h>

int main (void) {

	int a=0,b=0,c=0;
	float x=0,y=0,z=0,root=0,w=0;
	
	//Ask for three sides of a triangle
	printf("I'm going to construct a triangle for you. Give me three angles.");
	while (a+b+c != 180){
		printf("\nAngle 1: ");
		scanf("%d", &a);
		while (a<=0||a>=179){
			printf("The angle you have entered is not a possible angle for a triangle. Please try again.\nAngle 1: ");
			scanf("%d", &a);
			};

		printf("Angle 2: ");
		scanf("%d", &b);
		while (b<=0||b>=179){
			printf("The angle you have entered is not a possible angle for a triangle. Please try again.\nAngle 2: ");
			scanf("%d", &b);
			};

		printf("Angle 3: ");
		scanf("%d", &c);
		while (c<=0||c>=179){
			printf("The angle you have entered is not a possible angle for a triangle. Please try again.\nAngle 3: ");
			scanf("%d", &c);
			};
		
		if (a+b+c != 180){
			printf("Your angles do not add up to 180. Please try again.");
			};
	};
	//Tell the user what type of triangle it is
	if (a<90&&b<90&&c<90){
		printf("You have an acute triangle.");
		} else if (a==90||b==90||c==90){
			printf("You have a right triangle.");
			} else if (a>90||b>90||c>90){
				printf("You have an obtuse triangle.");
				} else {
					printf("Error.");
					};
	
	//Ask for the sides of the triangle
	printf("\nGood. Now let's make a new triangle. Give me the length of three sides to work with.\nSide 1: ");
	scanf("%f", &x);

	printf("Side 2: ");
	scanf("%f", &y);

	printf("Side 3: ");
	scanf("%f", &z);
	
	w = ((x+y+z)/2);

	root = sqrt(w*(w-x)*(w-y)*(w-z));
	
	printf("The Area of our triangle is %f.\n", root);

	

	return 0;
}
