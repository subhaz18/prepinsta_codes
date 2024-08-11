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

void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);    
    }
}  

void preorder(struct Node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);    
    }
}
void postorder(struct Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);    
        printf("%d ",root->data);
    }
}


int main() {
	
	struct Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->right->left = createNode (4);
	root->right->right = createNode(5);
	
	printf("\nThe inorder is : ");
	inorder(root);
	printf("\nThe preorder is : ");
	preorder(root);
	printf("\nThe postorder is : ");
	postorder(root);

}