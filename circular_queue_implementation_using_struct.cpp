#include <stdio.h>
#include <stdlib.h>

struct Queue 
{ 
    int front, rear, currSize; 
    unsigned maxSize; 
    int* a;
}; 

struct Queue* createQueue(unsigned maxSize) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->maxSize = maxSize;
    queue->front = queue->rear = -1;
    queue->a = (int*) malloc(queue->maxSize * sizeof(int)); 
    return queue; 
} 

// Checking for Overflow condition
int isFull(struct Queue* queue){
    if ((queue->front == queue->rear + 1) || 
    (queue->front == 0 && queue->rear == queue->maxSize - 1)){
        return 1;
    }
    return 0;
}

// Checking for Underflow condition
int isEmpty(struct Queue* queue){
    if (queue->front == -1) 
    {
        return 1;
    }
  return 0;
}

// Function to do enqueue
void enqueue(struct Queue* queue,int value){
    if (isFull(queue))
        printf("Can't add the queue is full \n");
    
    else
    {
        if (queue->front == -1) 
            queue->front = 0;
        
        queue->rear = (queue->rear + 1) % queue->maxSize;
        queue->a[queue->rear] = value;
        printf("%d was added\n", value);
  }
}

// Function to do dequeue
int dequeue(struct Queue* queue)
{
    int item;
    if (isEmpty(queue)) 
    {
        printf("Can't add the queue is empty \n");
        return (-1);
    } 
    else
    {
        item = queue->a[queue->front];
        if (queue->front == queue->rear) 
        {
            queue->front = queue->rear = -1 ;
        } 
        else 
        {
            queue->front = (queue->front + 1) % queue->maxSize;
        }
        printf("%d dequeued\n", item);
    }
}

// Function to print the queue
void print(struct Queue* queue) {
  int i;
  if (isEmpty(queue))
    printf("Empty Queue\n");
  else {

    printf("\nThe items in the queue are : \n");
    for (i = queue->front; i != queue->rear; i = (i + 1) % queue->maxSize) {
      printf("%d ", queue->a[i]);
    }
    printf("%d \n\n", queue->a[i]);

  }
}

int main() {
  struct Queue* queue = createQueue(6);
  dequeue(queue);//Underflow condition

  enqueue(queue,12);
  enqueue(queue,14);
  enqueue(queue,16);
  enqueue(queue,18);
  enqueue(queue,20);

  print(queue);
  dequeue(queue);
  dequeue(queue);

  print(queue);

  enqueue(queue,22);
  enqueue(queue,24);
  enqueue(queue,26);
  enqueue(queue,28);//Overflow condition
  print(queue);

  return 0;
}