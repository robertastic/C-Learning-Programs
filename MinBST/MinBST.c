//Name: Robert Stovall
//Date; 4/8/14
//TA: Stephen Slayden
#include <stdio.h>
#include "bst.h"

//create 2 files
//ones a header file (bst.h)
//#include "bst.h"
//include prototypes at top and your functions
//sort anyway, find the middle, middle is the root
//call create bst, print, sort, min bst, print

bst *createBST(int a[],int size);
void sort(int a[],int size);
bst *createMinBST(int a[],int start,int end);

int main(int argc, char** argv){

	//Open the file
	FILE *fPointer = fopen(argv[1],"r");
	
	int size, i;

	//find the size
	fscanf(fPointer,"%d",&size);

	//create an array
	int *array = malloc(size * sizeof(int));

	//fill the array
	for(i=0;i<size;i++)
		fscanf(fPointer,"%d ",&array[i]);

	//create bst
	printf("Creating Binary Search Tree...");
	bst* root = createBST(array,size);

	//print each different type of print
	printf("\nIn-Order:");
	printInorder(root);


	printf("\nPre-Order:");
	printPreorder(root);


	printf("\nPost-Order:");
	printPostorder(root);

	//sort the array
	sort(array,size);

	//create minimum bst
	root = createMinBST(array,0,size-1);
	
	printf("\n");	
	//print the tree
	printTree(root);
	
	//close
	fclose(fPointer);
	return 0;
};

//use insert function to create a bst
bst *createBST(int a[],int size){

	bst* root = NULL;
	int i;

	for (i=0;i<size;i++)
		root = insert(root,a[i]);
	
	return root;

};

//used a selection sort
void sort(int a[],int size){

	int min,temp,i,j;

	for(i=size-1;i>0;i--){
		min=i;
		for(j=0;j<i;j++){
			if(a[j] > a[min])
				min = j;
		}
		temp = a[i];
		a[i]=a[min];
		a[min]=temp;
	};
};

//recursively call to make sure its minimum height
bst *createMinBST(int a[],int start,int end){

	int mid = (start + end)/2;

	bst *root = create_node(a[mid]);

	if(mid-1>=start)
		root->left = createMinBST(a,start,mid-1);
	if(mid+1<=end)	
		root->right = createMinBST(a,mid+1,end);

	return root;
};

/*
void printGivenLevel(bst *root,int level){

};
int height(bst* root){


};
*/
	

