/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int getheight(struct node *root){
	if (root == NULL){
		return 0;
	}
	if (getheight(root->left) >= getheight(root->right)){
		return getheight(root->left) + 1;
	}
	else{
		return getheight(root->right) + 1;
	}
}

void r2l(struct node*root, int *arr, int l,int *index){
	if (root != NULL){
		if (l == 1){
			arr[*index] = root->data;
			*index = *index + 1;
		}
		else if (l > 1){
			r2l(root->right, arr, l - 1, index);
			r2l(root->left, arr, l - 1, index);
		}
	}
}

int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int i;
	int *arr, index = 0;
	arr = (int*)malloc(sizeof(int));
	for (i = 1; i <= getheight(root); i++){
		r2l(root, arr, i,&index);
	}
	return arr;
}
