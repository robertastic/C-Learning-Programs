/* Linked List
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Create a struct node
typedef struct node_{
	int value;
	struct node_* next;
}node;

//prototypes
node* insert(node* head, int value);
node* delete(node* head,int value);
void mul_even(node* head,int multiplier);
void print(node* head);

//main requires an input file
int main(int argc,char* argv[]){

	//make sure it has the input file in the command line
	if (argc != 2){
		printf("Please use proper format");
		return -1;
	};
	
	//make sure the input file is there
	FILE * fPointer = fopen(argv[1],"r");

	if(fPointer == NULL)
	{
		printf("File NULL\n");
		return -1;
	};

	//create an empty linked list
	node* head = NULL;
	char type;
	int value=0;

	//run a while loop for all the values in the input file
	//perform a different action depending on input char
	while(fscanf(fPointer,"%c %i\n",&type,&value)==2) {
		if(type=='i'){
			printf("\nInserting %i into the list\n",value);
			head = insert(head,value);
		} else if (type=='d'){
			printf("\nDeleting %i from the list\n",value);
			head = delete(head,value);
		} else if (type=='m'){
			printf("\nMultiplying all even numbers by %i\n",value);
			mul_even(head,value);
		}
		print(head);
	};



	return 0;

};


node* insert(node* head, int value){

	//allocating memory
	node* newPtr = (node*)malloc(sizeof(node));
	newPtr->value = value;
	newPtr->next = NULL;
	node* previousPtr = NULL;
	node* currentPtr = head;

	//inset into head or tail accordingly
	if (head == NULL){
		head = newPtr;
		return head;
	} else if(value%2==0){
		newPtr->next = currentPtr;
		currentPtr = newPtr;
		return currentPtr;
	} else if(value%2==1){
		while(currentPtr->next != NULL){
			currentPtr=currentPtr->next;
		};
		currentPtr->next = newPtr;
	};
	
	return head;
};

node* delete(node* head,int value){
	node* currentPtr=head;
	node* nextPtr=head;
	node* temporary=NULL;
	node* previousPtr=NULL;

	//first check if it is a list with only a head
	
	if (head->next == NULL){
		if(head->value == value){
			head=NULL;
		};
		return head;
	};

	//while there is still links, keep running the loop
	while(currentPtr != NULL) {
		//changing the head if deleting
		if (head->value == value){
			temporary=head;
			head = head->next;
			free(temporary);
			currentPtr=head;
		//changing a link
		} else if (currentPtr->value == value){
			temporary=currentPtr;
			previousPtr->next=currentPtr->next;
			free(temporary);
			previousPtr=currentPtr;
			currentPtr=currentPtr->next;
		//moving the current and previous ptrs otherwise
		} else {
			previousPtr=currentPtr;
			currentPtr=currentPtr->next;

		};
	};

	return head;

};

//multiplies evens
void mul_even(node* head,int mult){

	node* currentPtr = head;
	node* temporary = NULL;

	while (currentPtr != NULL){
		if(currentPtr->value % 2 == 0){
			currentPtr->value = currentPtr->value * mult;
		};
		currentPtr=currentPtr->next;
	};


};

//prints
void print(node* head){

	node* temp=head;

	while (temp != NULL){
		printf("%i",temp->value);
		temp=temp->next;
		if(temp != NULL)
			printf("->");
	};


};

