#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void quick_sort( int* arr, int start, int end,int(*compare)(int,int))
{
   int j;

   if( start < end ) 
   {
       j = partition( arr, start, end,compare);
       quick_sort( arr, start, j-1,compare);
       quick_sort( arr, j+1, end,compare);
   }

}



int partition( int* arr, int start, int end, int(*compare)(int,int)) {
   
   int pivot, i, j, temp;
   pivot = start+rand()%(end-start+1);
   i = start; 
   j = end;
  
   temp = arr[start]; 
   arr[start] = arr[pivot]; 
   arr[pivot] = temp;
 

   while(1)
   {

		while( compare(arr[j],arr[start]) == -1 ){
			j--;
		};

		while(compare(arr[i],arr[start])== 1||compare(arr[i],arr[start]) == 0){
			i++;
		}
		
		
		if( compare(i,j) == 0 || compare(i,j) == -1) 
			break;
			
			temp = arr[i]; 
			arr[i] = arr[j]; 
			arr[j] = temp;
   }
   
   temp = arr[start]; 
   arr[start] = arr[j]; 
   arr[j] = temp;
   
   return j;
}

int compareSmallerOnLeft(int num1, int num2){

	if(num1 == num2)
		return 0;
	if(num1 > num2)
		return -1;
	
	return 1;
};

int compareSmallerOnRight(int num1, int num2){

	if(num1 == num2)
		return 0;
	if(num1 > num2)
		return 1;
	
	return -1;
};


int b_search(int* arr, int data,int(*compare)(int,int),int start, int end){

	if(compare(start,end) == 0)
		return -1;

	int mid = (start+end)/2;

	if(arr[mid] < data){
		return b_search(arr,data,compare,mid+1,end);

	} else if (compare(arr[mid],data) == 0) {
		return 1;

	} else {
		return b_search(arr,data,compare,start,mid);
	}

};


void print(int* arr, int length){

	printf("\n");

	int i;

	for(i=0;i<length;i++)
		printf("%d ",arr[i]);

	printf("\n");
};
