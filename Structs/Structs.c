/* Structs
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 20

typedef struct node_{
	char* name;
	struct node_* next;
}node;

node* insert(node* head, char* name);
node* create_node(char* name);
void print(node* head);
void delete(node* head);

node* insert(node* head, char* name){

	//create 3 variables for swapping addresses
	node* currentPtr=head;
	node* previousPtr;
	node* newPtr=create_node(name);

		//if there is nothing in currentPtr fill it with head
	
	if(head == NULL){

		head = newPtr;

		//otherwise run the program
	} else {

		//while there is nothing in the tail, fill the current pointer with the address
		currentPtr=head;
		while(currentPtr->next !=NULL){
			currentPtr=currentPtr->next;
		}

		currentPtr->next=newPtr;
	};

	return head;
};

node* create_node(char* name){


	//allocate memory for the node
	node* newPtr = (node*)malloc(sizeof(node));
	//and the name
	newPtr->name = malloc(sizeof(newPtr->name));
	strcpy(newPtr->name,name);
	//put the tail as null
	newPtr->next=NULL;

	return newPtr;
}

void print(node* head){

	node* temp;
	//create a temporary variable to play with
	temp = head;

	while (temp != NULL){
		printf("%s",temp->name);
		temp=temp->next;
		if(temp != NULL)
			printf("->");
	};


};

void delete(node* head){

	//run a delete loop

	node* previousPtr;
	node* currentPtr=head;

	while (currentPtr != NULL){
		previousPtr=currentPtr;
		currentPtr=previousPtr->next;
		free(previousPtr);
	};

};




int main(int argc,char* argv[]){


	//makes sure you are passing a file
	if (argc != 2){
		printf("Please use proper format");
		return -1;
	};

	//opens the file

	FILE * fPointer = fopen(argv[1],"r");

	//makes sure the file has something in it

	if(fPointer == NULL)
	{
		printf("File NULL\n");
		return -1;
	};

	//create the beginning of a linked list
	node* head;
	char name[MAX_NAME_LEN];
	//while a name is still available to be scanned, continue the loop
	while(fscanf(fPointer,"%s",name)==1) {
		head = insert(head,name);
	};

	//calls the print function
	print(head);
	//frees the memory that was allocated
	delete(head);





	return 0;
};


