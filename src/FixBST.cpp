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

void findvalues(int **, int *, int *, int);
void modify(int **, int, int);

void inordertoarray(struct node *root, int **arr, int *index){
	if (root != NULL){
		inordertoarray(root->left, arr, index);
		arr[*index] = &root->data;
		*index = *index + 1;
		inordertoarray(root->right, arr, index);
	}
}

void findvalues(int **arr, int *misplaced1, int *misplaced2,int index){
	int i = 0;
	for (i = 0; i < index - 1; i++){
		if (*arr[i]>*arr[i + 1]){
			if (*misplaced1 == -1){
				*misplaced1 = i;
				*misplaced2 = *misplaced1 + 1;
			}
			else{
				*misplaced2 = i + 1;
			}
		}
	}
}

void modify(int **arr, int misplaced1, int misplaced2){
	int temp;
	temp = *arr[misplaced1];
	*arr[misplaced1] = *arr[misplaced2];
	*arr[misplaced2] = temp;
}

void fix_bst(struct node *root){
	if (root == NULL)
		return;
	int **arr, index = 0, misplaced1 = -1, misplaced2 = -1, i;
	arr = (int**)malloc(sizeof(int*));
	inordertoarray(root, arr, &index); 
	findvalues(arr, &misplaced1, &misplaced2, index);
	if (misplaced1 != -1 )
		modify(arr, misplaced1, misplaced2);
}


