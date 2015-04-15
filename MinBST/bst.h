//prelab 9 sample code by alex lobzhanidze
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *left, *right;
} bst;

bst *create_node(int val);
bst *insert(bst *root, int val);
void printPreorder(bst *root);
void printInorder(bst *root);
void printPostorder(bst *root);
void printTree(bst* root);
void displayBST(bst* root, int depth);
void padding(char toPrint, int numTimes);

bst *create_node(int val)
{
	bst *n = malloc(sizeof(bst));
		n->val=val;
		n->left = NULL;
		n->right = NULL;
	return n;
}

//used to create a bst
bst *insert(bst *root, int val)
{
	if (root == NULL)
		root = create_node(val);
	else
	{
		if (val < root->val)
			root->left = insert(root->left, val);
		else
			root->right = insert(root->right, val);
	}

 return root;
}

//prints in Preorder, Inorder, and Postorder
void printPreorder(bst *root)
{
	if(root != NULL){
		printf(" %d",root->val);
		printPreorder(root->left);
		printPreorder(root->right);
	};
}

void printInorder(bst *root)
{
	if(root != NULL){
		printInorder(root->left);
		printf(" %d",root->val);
		printInorder(root->right);
	};
}

void printPostorder(bst *root)
{
	if(root != NULL){
		printPostorder(root->left);
		printPostorder(root->right);
		printf(" %d",root->val);

	};
}

void padding(char toPrint, int numTimes)
{
	int i;
	for (i = 0; i < numTimes; i++)
		printf("%c", toPrint);
}

void displayBST(bst* root, int depth)
{
	if (root == NULL)
	{
		padding(' ', depth);
		printf("-\n");
		return;
	}

	displayBST(root->left, depth+4);
	padding(' ', depth);
	printf("%d\n", root->val);
	displayBST(root->right, depth+4);
}

void printTree(bst* root)
{
	displayBST(root, 0);
}
