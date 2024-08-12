#include <stdio.h>
#include <stdlib.h>

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  
};

void printKDistance(Node *root,int k){
    if(root==NULL)
        return;
    
    if(k == 0){
        printf("%d ",root->data);
        
    }
    else{
    printKDistance(root->left,k-1);
    printKDistance(root->right,k-1);
    }
}


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

int main() {
	
	struct Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode (4);
	root->left->right = createNode(5);
	
	int k = 2;
	
	printKDistance(root,k);

}