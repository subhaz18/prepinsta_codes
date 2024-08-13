#include <stdio.h>
#include <stdlib.h>

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

int calcSize(Node *root){
    
    if(root==NULL)
        return 0;
    else
        return (1+ calcSize(root->left) + calcSize(root->right));
}

int main() {
	
	struct Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->right->left = createNode (4);
	root->right->right = createNode(5);
	int result=calcSize(root);
    printf("The size of Tree is : %d",result);

} 