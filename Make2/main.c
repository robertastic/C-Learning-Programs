#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char **argv){

	FILE *fPointer = fopen(argv[1],"r");

	if(fPointer == NULL){
		printf("Unable to open file");
		return 0;
	};

	FILE *searchNumbers = fopen(argv[2],"r");

	if(searchNumbers == NULL){
		printf("Unable to open file #2");
		return -1;
	};
	
	int size,i,num=0,search,found;
	
	fscanf(fPointer,"%d",&size);
	
	int arr[size];
	
	for(i=0;i<size;i++)
		fscanf(fPointer,"%d",&arr[i]);

	
	
	print(arr,size);

		printf("\nDo you want to sort with smaller values on left(1) or right(2)?\n");
		scanf("%d",&num);

		while(num < 1 || num > 2){
			printf("\nPlease enter 1 for smaller values on the left and 2 for smaller values on the right: ");
			scanf("%d",&num);
		};
	

	//Setting up the Compare function pointer
	int(*compareFunc)(int,int);

	if(num == 1)
		compareFunc = compareSmallerOnLeft;
	
	if(num == 2)
		compareFunc = compareSmallerOnRight;
		
	//Quicksort
	quick_sort(arr,0,size-1,compareFunc);

	print(arr,size);

	//Binary Search
	while(fscanf(searchNumbers,"%d",&search) != EOF){
	
		found = b_search(arr,search,compareFunc,0,size-1);
		if(found == 1)
			printf("\n%d is in the array\n",search);
		else
			printf("\n%d is not in the array\n",search);
	};
	
	fclose(searchNumbers);
	fclose(fPointer);
	
	return 0;	
};
