/* Name: Robert Stovall
 * Pawprint: rcsc77
 * TA: Stephen Slayden
 * Date: 3/11/2014
 * Project: Lab 6
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "timing.h"

typedef struct Node_{
	int value;
	struct Node_* next;
}Node;

int linearSearch(int array[],int length,int key);
int nodeSearch(Node* head,int key);
void free_Nodes(Node* head);
Node* insert_end(Node* head,int data);

int main (int argc, char* argv[]){

//open the file
//first file will be length
//Store to int array
//call clock function

	//open function
	if (argc != 3){
		printf("Please include x input.txt");
		return -1;
	};

	FILE * fPointer = fopen(argv[2],"r");

	if(fPointer == NULL)
	{
		printf("File NULL\n");
		return -1;
	};

	//get the key and start the linked list
	int key = atoi(argv[1]);
	Node* head = NULL;
	int length,i,data;

	fscanf(fPointer,"%i\n",&length);

	int array[length];

	//Putting the data into linked list and array
	
	for(i=0;i<length;++i){
		fscanf(fPointer,"%i\n",&data);
		head = insert_end(head,data);
		array[i] = data;
		//printf("%i\n",array[i]);
	};
	
	/*
	clock_t start,end;
	start = clock();
	linearSearch(array,length,key);
	end = clock();
	double time = (double)(end-start)/CLOCKS_PER_SEC;

	start = clock();
	nodeSearch(head,key);
	end = clock();
	double time2 = (double)(end-start)/CLOCKS_PER_SEC;
	*/

	printf("\nLinear Saerch:\n");


	//use stephen's function to call the time

	all_times a1,a2;
	get_time(&a1);
	i = linearSearch(array,length,key);
	get_time(&a2);
	print_duration(&a1,&a2);

	printf("\nNode Search:\n");

	get_time(&a1);
	i = nodeSearch(head,key);
	get_time(&a2);
	print_duration(&a1,&a2);
	
	
	
	
	printf("\n");


	//free the linked list 
	
	free_Nodes(head);
	


	return 0;

};

//search the array
int linearSearch(int array[],int length,int key){

	int i,num=0;

	for(i=0;i<length;++i){
		if(array[i] == key)
			num = 1;
	};

	return num;
};

//search the linked list
int nodeSearch(Node* head,int key){

	Node* currentPtr=head;
	int num=0;

	while(currentPtr != NULL){
		if (currentPtr->value == key)
			num = 1;
		
		currentPtr = currentPtr->next;
	};

	return num;
};

//free the linked list
void free_Nodes(Node* head){

	Node* currentPtr = head;
	

	while(currentPtr != NULL){
		free(currentPtr);
		currentPtr = currentPtr->next;
	};
};

//fill the linked list
Node* insert_end(Node* head,int data){

	Node* newPtr = (Node*)malloc(sizeof(Node));
	newPtr->value = data;
	newPtr->next = NULL;
	Node* currentPtr = head;

	if (head == NULL){
		head = newPtr;
		return head;
	};

	while(currentPtr->next != NULL){
		currentPtr=currentPtr->next;
	};

	currentPtr->next = newPtr;

	return head;
};
