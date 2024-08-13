#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  
};


struct Node* createNode(int data)
{
    // use malloc to create memory
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    // assign data
    newNode->data = data;
    
    //assign left and right to be NULL
    newNode->left = NULL;
    newNode->right = NULL;
    
    return(newNode);
}

int calcMax(struct Node* node){
    
    if(node == NULL)
        return INT_MIN;
    else
    {
        int res = node->data;
        int lsubtree = calcMax(node->left);
        int rsubtree = calcMax(node->right);
        
        if (lsubtree > res)
            res = lsubtree;
        if (rsubtree > res)
            res = rsubtree;
        return res;
    }
}

int main() {
	
	struct Node *root = createNode(20);
	root->left = createNode(70);
	root->right = createNode(90);
	root->left->left = createNode (30);
	root->left->right = createNode(40);
	root->right->right = createNode(70);
	
	printf("The Max Element is : %d", calcMax(root));


}