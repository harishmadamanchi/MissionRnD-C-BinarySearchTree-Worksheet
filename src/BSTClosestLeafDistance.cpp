/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

void preorderarray(struct node*root, int *pre, int *leaf, int *preindex, int *leafindex){
	if (root != NULL){
		pre[*preindex] = root->data;
		*preindex = *preindex + 1;
		if (root->left == NULL&&root->right == NULL){
			leaf[*leafindex] = root->data;
			*leafindex = *leafindex + 1;
		}
		preorderarray(root->left, pre, leaf, preindex, leafindex);
		preorderarray(root->right, pre, leaf, preindex, leafindex);
	}
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL){
		return -1;
	}
	int *pre, *leaf, preindex = 0, leafindex = 0;
	int i, j, k, mindist, dist, tempelmentindex, leafelementindex;
	pre = (int*)malloc(sizeof(int));
	leaf = (int*)malloc(sizeof(int));
	preorderarray(root, pre, leaf, &preindex, &leafindex);
	mindist = preindex;
	for (k = 0; k < preindex; k++){
		if (pre[k] == temp->data){
			tempelmentindex = k;
			break;
		}
	}
	for (i = 0; i < leafindex; i++){
		for (j = 0; j < preindex; j++){
			if (leaf[i] == pre[j]){
				leafelementindex = j;
				break;
			}
		}
		if (leafelementindex < tempelmentindex)
			dist = tempelmentindex - leafelementindex + 1;
		else if (leafelementindex == tempelmentindex)
			dist = 0;
		else
			dist = leafelementindex - tempelmentindex;
		if (mindist>dist){
			mindist = dist;
		}
	}
	return mindist;
}