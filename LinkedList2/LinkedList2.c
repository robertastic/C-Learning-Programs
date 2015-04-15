/* More Linked List
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node{
	int value;
	struct node* next;
}node;

//Prototypes

node* insert_end(node* head, int data);
void print_list(node* head);
int search(node* head, int data);
int factorial(int n);
void factorial_list(node* head);
void delete_list(node* head);

int main(int argc, char **argv){
	int data=0,delete=0,srch=0;

	//Create an empty linked list
	node *head = NULL;

	//Open the file
	FILE *fPointer = fopen(argv[1],"r");

	//input numbers to the list using insert_end
	while(fscanf(fPointer,"%i\n",&data) != EOF){
		head = insert_end(head,data);
	};

	//print the unmodified list
	print_list(head);

	//run the search function
	printf("Enter a number to search for: ");
	scanf("%d",&delete);
	srch = search(head,delete); 
	if (srch == 1)
		printf("%i was found!\n",delete);
	if (srch == 0)
		printf("%i was NOT found!\n",delete);

	//run factorial list
	factorial_list(head);

	//print the modified list and free the memory
	print_list(head);
	delete_list(head);
	return 0;

};

node* insert_end(node* head, int data){

	//creats a new pointer at the end of the function

	if(head==NULL){
		node* newPtr = (node*)malloc(sizeof(node));
		newPtr->value = data;
		newPtr->next = NULL;
		return newPtr;
	} else {
		head->next = insert_end(head->next,data);
		return head;
	};
	
};
void print_list(node* head){

	//print list until reaching NULL

	if(head != NULL){
		printf("%i->",head->value);
		print_list(head->next);
	};

	if(head == NULL)
		printf("NULL\n");


};
int search(node* head, int data){
	//search, if it gets to NULL and the number was not found, return 0
	int srch=0;
	if (head == NULL)
		return 0;

	if (head->value == data){
		return 1;
	} else {
		srch = search(head->next,data);
	};

	return 0;

};
int factorial(int n){

	//simple factorial function, base case is n == 1
	if (n == 1){
		return n;
	} else {
		return n * factorial(n - 1);
	};

};
void factorial_list(node* head){
	//call the factorial function for data then call again with next
	head->value = factorial(head->value);
	if (head->next == NULL)
		return;
	factorial_list(head->next);
};

void delete_list(node* head){
	//if head is not NULL, free the node and call again with next
	node* temp;
	if (head != NULL){
		temp=head->next;
		free(head);
		head=NULL;
		delete_list(temp);
	};
	return;
};

