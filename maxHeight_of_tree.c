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


int max_Height(struct Node* node)
{
    //change to -1 
    if (node == NULL)
        return 0;
    else {
        /* calculate the Height of each (Left/ right) subtree */
        int lHeight = max_Height(node->left);
        int rHeight = max_Height(node->right);
 
        /* use the larger value */
        if (lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}

int main() {
	
	struct Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->right->left = createNode (4);
	root->right->right = createNode(5);
	
	printf("The height of tree is : %d", max_Height(root));

}