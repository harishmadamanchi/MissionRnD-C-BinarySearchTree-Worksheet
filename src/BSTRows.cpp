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


int getheight(struct node *);
void r2l(node * , int * );
void treeelements(node *, int, int *, int *);

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


int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int * resarr = (int *)malloc(sizeof(int)* 20);
	r2l(root, resarr);
	return resarr;
}

void r2l(node * root, int * resarr){
	int h = getheight(root);
	int index = 0;
	for (int i = 1; i <= h; i++){
		treeelements(root, i, resarr, &index);
	}
}

void treeelements(node * root, int level, int * resarr, int * index){
	if (root == NULL)
		return;
	if (level == 1)
		resarr[(*index)++] = root->data;
	else
	{
		treeelements(root->right, level - 1, resarr, index);
		treeelements(root->left, level - 1, resarr, index);
	}
}