/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

void inorder2array(struct node *, int *, int *);
void preorder2array(struct node *, int*, int *);
void postorder2array(struct node *, int *, int *);

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void inorder(struct node *root, int *arr){
	int index = 0;
	if (root == NULL || arr == NULL){
		return;
	}
	inorder2array(root, arr, &index);
}
void inorder2array(struct node *root, int *arr, int *index){
	if (root != NULL){
		inorder2array(root->left, arr, index);
		arr[*index] = root->data;
		*index = *index + 1;
		inorder2array(root->right, arr, index);
	}
}
void preorder(struct node *root, int *arr){
	int index = 0;
	if (root == NULL || arr == NULL){
		return;
	}
	preorder2array(root, arr, &index);
}
void preorder2array(struct node *root, int*arr, int *index){
	if (root != NULL){
		arr[*index] = root->data;
		*index = *index + 1;
		preorder2array(root->left, arr, index);
		preorder2array(root->right, arr, index);
	}
}
void postorder(struct node *root, int *arr){
	int index = 0;
	if (root == NULL || arr == NULL){
		return;
	}
	postorder2array(root, arr, &index);
}
void postorder2array(struct node *root, int *arr, int *index){
	if (root != NULL){
		postorder2array(root->left, arr, index);
		postorder2array(root->right, arr, index);
		arr[*index] = root->data;
		*index = *index + 1;
	}
}
