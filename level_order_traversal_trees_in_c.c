#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  
};

struct Node** createQueue(int *front, int *rear)
{
    struct Node **queue = (struct Node **)malloc(sizeof(struct Node*)*SIZE);
 
    *front = *rear = 0;
    return queue;
}

void enQueue(struct Node **queue, int *rear, struct Node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

struct Node *deQueue(struct Node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

void printLevelOrder(struct Node* root)
{
    int rear, front;
    struct Node **queue = createQueue(&front, &rear);
    struct Node *tempNode = root;
 
    while (tempNode)
    {
        printf("%d ", tempNode->data);
 
        /*Enqueueing left child */
        if (tempNode->left)
            enQueue(queue, &rear, tempNode->left);
 
        /*Enqueueing right child */
        if (tempNode->right)
            enQueue(queue, &rear, tempNode->right);
 
        /*Dequeueing node and assigning value to tempNode*/
        tempNode = deQueue(queue, &front);
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
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	
    printLevelOrder(root);

}