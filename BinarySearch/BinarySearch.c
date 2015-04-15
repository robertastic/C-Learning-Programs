#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int is_sorted(int array[],int length);
int binary_search(int array[],int key,int low,int high);
void merge_sort(int array[],int low, int high);
void merge(int array[],int low, int middle, int high);
void print(int array[],int length);

int main(int argc,char* argv[]){

	if (argc != 3){
		printf("Please use proper format\n");
		return -1;
	};
	

	FILE * fPointer = fopen(argv[2],"r");


	if(fPointer == NULL){
		printf("File NULL\n");
		return -1;
	};

	int a,sort,length,found,i=0;	
	int key = *argv[1];
	printf("%i\n\n",key);
	fscanf(fPointer,"%i\n",&length);

	int array[length];
	found = length+1;
	for(i=0;i<length;++i){
		fscanf(fPointer,"%i\n",&a);
		array[i] = a;
	};

	print(array,length);
	sort = is_sorted(array,length);
	
	//Checks if sorted
	
	if(sort == 1)
		printf("\nThe array is sorted\n");
	
	if(sort == 0){
		printf("\nThe array is not sorted\n");
		printf("Calling mergesort\n");
		merge_sort(array,0,length);
		printf("The array is sorted\n");
	};

	//Binary search on sorted array, causing a segfault
	/*	
	found = binary_search(array,key,0,length);

	if(found !=  length+1){
		printf("%i was found\n",key);
	} else {
		printf("%i was not found\n",key);
	};
	*/
	printf("\nThe sorted array\n");
	print(array,length);


	
	return 0;
};

//checks if the array is sorted
int is_sorted(int array[],int length){

	int num = 1,count=0,i;

	for(i=0;i<length;++i){
		if(array[i]<count)
			num = 0;
		count = array[i];
	};

	return num;
};

//preforms the binary search
int binary_search(int array[],int key,int low,int high){

	int mid = (low+high)/2;

		if(array[mid]<key){
			return binary_search(array,key,mid+1,high);
		} else if (array[mid] == key) {
			return mid;
		} else {
			return binary_search(array,key,low,mid);
		};
};

//sorts and calls merge
void merge_sort(int array[],int low, int high){

	int mid,length;
	length=(high-low);
	if (length<1) return;

	mid = ((high+low)/2);

	merge_sort(array,low,mid);
	merge_sort(array,mid+1,high);
	
	merge(array,low,mid,high);
};

//merges two sorted arrays
void merge(int array[],int low, int middle, int high){
	int left=low,right=middle+1,current=low,i;

	int helper[(high-low)+1];

	
	for (i=0;i<=high-low+1;i++)
		helper[i] = array[i];
		

	while(left<=middle && right<=high){
		if(helper[left] < helper[right]){
			array[current++] = helper[left++];
		} else {
			array[current++] = helper[right++];
		};
	};

	while (left<=middle)
	  	array[current++] = array[left++];
	while (right<=high) 
		array[current++] = array[right++];


};

//prints the givena array
void print(int array[],int length){
	int i;
	for(i=0;i<length;++i)
		printf("\n%i",array[i]);
	printf("\n");

};

