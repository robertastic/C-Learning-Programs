/*Name: Robert Stovall
 *TA: Stephen Slayden
 *Date: 4/1/2014
 *Project: Lab8
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct bt_{
	int value;
	struct bt_ *right;
	struct bt_ *left;
}BST;


BST* insert(BST* root,int value);
int search(BST* root,int value);
//BST* findNearest(BST* root,int value);
void printTree(BST* root);
void displayBST(BST* root,int depth);
void padding(char toPrint,int numTimes);


int main(int argc, char **argv){

	FILE *fPointer = fopen(argv[1],"r");
	int val,srch,result;

	BST* root = NULL;

	//run the insert program for each number in the file
	while(fscanf(fPointer, "%d",&val) != EOF){
		root = insert(root,val);
	}

	//print the tree
	printTree(root);

	//search for given number
	printf("\nEnter a number to search for in the tree: ");
	scanf("%d",&srch);
	result = search(root,srch);
	
	if(result == 1){
		printf("\n%d was found",srch);
	} else {
		printf("\n%d was not found",srch);
	};
	


	fclose(fPointer);
	
	return 0;
};

//malloc a new branch
BST* insert(BST* root,int value){

	if(root == NULL){
		BST* newNode = (BST*)malloc(sizeof(BST));
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	};

	if(value > root->value){
		root->right = insert(root->right,value);
	} else {
		root->left = insert(root->left,value);
	};

	return root;
};
//search
int search(BST* root,int value){

	BST* new = root;
	
	while(new!=NULL){
		if(new->value == value){
			return 1;
		}else if(value >= new->value){
			new = new->right;
		}else {
			new = new->left;
		}
	}
	return 0;

};

//Can't figure out how to get it to work, this is a mess
/*
BST* findNearest(BST* root,int value){

	int i,low,newLow=100;
	BST* new = root,lowest = new;
	
	while(new!=NULL){
		if(new->value == value){
			return new;
		}else if(value >= new->value){
			if(root->right == NULL)
				return lowest;
			low = abs(value-new->value);
			if(low<newLow){
				newLow = low;
				lowest = new;
			};
			root = findNearest(root->right,value);
		}else if {
			if(root->left == NULL)
				return lowest;
			low = abs(value-new->value);
			if(low<newLow){
				newLow = low;
				lowest = new;
			root = findNearest(root->left,value);
			};
		}
	}
	return lowest;
};
*/

void printTree(BST* root){
	displayBST(root,0);
};

void displayBST(BST* root,int depth){

	if(root == NULL){
		padding(' ',depth);
		printf("-\n");
		return;
	}

	displayBST(root->right,depth+4);
	padding(' ',depth);
	printf("%d\n",root->value);
	displayBST(root->left,depth+4);
};

void padding(char toPrint,int numTimes){
	int i;
	
	for(i=0;i<numTimes;i++)
		printf("%c",toPrint);
};
