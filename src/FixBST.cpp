/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void findvalues(int *, int *, int *, int);
void modify(struct node *, int, int);

void inordertoarray(struct node *root, int *arr, int *index){
	if (root != NULL){
		inordertoarray(root->left, arr, index);
		arr[*index] = root->data;
		*index = *index + 1;
		inordertoarray(root->right, arr, index);
	}
}

void findvalues(int *arr, int *misplaced1, int *misplaced2,int index){
	int i = 0;
	for (i = 0; i < index - 1; i++){
		if (arr[i]>arr[i + 1]){
			if (*misplaced1 == -1){
				*misplaced1 = arr[i];
			}
			else{
				*misplaced2 = arr[i + 1];
				break;
			}
		}
	}
}

void modify(struct node *root, int misplaced1, int misplaced2){
	if (root == NULL){
		return;
	}
	if (root->data == misplaced1){
		root->data = misplaced2;
	}
	else if (root->data == misplaced2){
		root->data = misplaced1;
	}
	modify(root->left, misplaced1, misplaced2);
	modify(root->right, misplaced1, misplaced2);
}

void fix_bst(struct node *root){
	if (root == NULL)
		return;
	int *arr, index = 0, misplaced1 = -1, misplaced2 = -1;
	arr = (int*)malloc(sizeof(int));
	inordertoarray(root, arr, &index);
	findvalues(arr, &misplaced1, &misplaced2, index);
	if (misplaced1 != -1 && misplaced2 != -1)
		modify(root, misplaced1, misplaced2);
}


