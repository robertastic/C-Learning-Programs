/* Name: Robert Stovall
 * TA: Stephen Slayden
 * Date: 3/18/14
 * Project: Lab7
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EQU_LEN 100

typedef struct node_{
	char data;
	struct node_ *next;
}node;

typedef struct stack_{
	unsigned int size;
	node* stack;
}stack;


stack* create_stack();
void push(stack* s, char val);
char top(stack* s);
void pop(stack* s);
int paren_match(char* equation);


int main(int argc, char **argv){

	FILE *fPointer = fopen(argv[1],"r");

	char *equ = malloc(MAX_EQU_LEN * sizeof(char));

	while(fscanf(fPointer, "%s", equ) != EOF){
		int result = paren_match(equ);
		if(result == 1)
			printf("\n %s Equal!\n", equ);
		else
			printf("\n %s Not Equal!\n", equ);
	}

	free(equ);
	fclose(fPointer);
	return 0;
};

//Creates an empty stack
stack* create_stack(){

	stack* newStack = (stack*)malloc(sizeof(stack));
	newStack->size = 0;
	newStack->stack = NULL;
	return newStack;

};

//Inserts a new element into the top of the stack
void push(stack* s, char val){
	
	node* newPtr = (node*)malloc(sizeof(node));
	newPtr->data = val;
	newPtr->next = s->stack;
	s->stack = newPtr;
	s->size++;
};

char top(stack* s){

	if(s->size == 0){
		printf("There is no spoon.\n");
		return 'F';
	};

	return s->stack->data;

};

//deletes the top paren
void pop(stack* s){

	node* temp = s->stack;
	s->stack = s->stack->next;
	s->size--;
	free(temp);

};

//makes sure theres an equal # of paren
int paren_match(char* equation){

	stack* s = create_stack();
	int i=0,length;
	char d;

	length = strlen(equation);

	while(i < length){
		d = equation[i];

		if(d == '('){

			push(s,d);

		} else if (d == ')'){

			if(s->size == 0){
				printf("More rights than lefts");
				return 0;
			} else {
				pop(s);
			};
		};

		i++;
	};
	if(s->size == 0)
		return 1;

		return 0;
};

int paren_and_brackets_match(char* equation){


return 0; 
}

