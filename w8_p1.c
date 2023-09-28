#include <stdio.h>
#include <stdlib.h>

// structure to impliment queue
struct queue
{
	// size = maximum capacity of the circular queue
	// front = points to the front of the queue
	// rear = points to the rear element of the queue
	int size, front, rear;
	// arr = int(array) to store the element
	int *arr;
}typedef q; // canbe used as "q" insted


// function to create a queue of size "size"
q* createQueue(int size)
{
	q* Q = (q*)malloc(sizeof(q));
	Q->size = size;
	Q->front = Q->rear = -1;
	Q->arr = (int*)malloc(size*sizeof(int));
	return Q;
}

// checks if the queue "Q" is empty or not
int isEmpty(q* Q)
{
	return Q->front==-1;
}

// checks if the queue "Q" is full or not
int isFull(q* Q)
{
	return (Q->rear+1)%(Q->size) == Q->front;
}

// pushes a element at the rear of queue "Q" if it is not empty
void enque(q* Q)
{
	if(isFull(Q))
	{
		printf("ERROR: The Queue is full\n");
		return;
	}
	int data;
	printf("Enter the data: ");
	scanf("%d", &data);
	Q->rear = (Q->rear+1)%(Q->size);
	Q->arr[Q->rear] = data;
	// if the queue was empty first
	if(Q->front==-1)
		Q->front++;
}

// prints the front element of the queue
void front(q* Q)
{
	if(isEmpty(Q))
	{
		printf("ERROR: The queue is already empty\n");
		return;
	}
	printf("The front element is %d\n", Q->arr[Q->front]);
}

// displays all the queue
void display(q* Q)
{
	if(isEmpty(Q))
	{
		printf("ERROR: The queue is already empty\n");
		return;
	}
	int i;
	printf("The queue is:\n");
	for(i=Q->front; i!=Q->rear; i = (i+1)%(Q->size))
		printf("%d ", Q->arr[i]);
	printf("%d \n\n", Q->arr[i]);
}

// deletes the front element of the queue "Q"
void deque(q* Q)
{	
	if(isEmpty(Q))
	{
		printf("ERROR: The queue is already empty\n");
		return;
	}
	
	// if "Q" has only one element
	if(Q->front == Q->rear)
	{
		Q->front = Q->rear = -1;
		return;
	}
	Q->front = (Q->front+1)%(Q->size);
}

// free up the space malloced to the queue
void deleteQueue(q* Q)
{
	free(Q->arr);
	free(Q);
}

int main()
{
	int size, ch;
	// input size
	printf("Enter the size of the queue: ");
	scanf("%d", &size);
	// create a queue of size "size"
	q* Q = createQueue(size);
	while(1)
	{
		printf("MENU:\n\n1. ENQUEUE\n2. DEQUEUE\n3. FRONT\n4. DISPLAY\n5. EXIT\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				// enqueue
				enque(Q);
				break;
			case 2:
				// dequeue
				deque(Q);
				break;
			case 3:
				// print the front
				front(Q);
				break;
			case 4:
				// diplay the whole queue
				display(Q);
				break;
			case 5:
				// free up the space and exit
				printf("EXITING...\n");
				deleteQueue(Q);
				exit(0);
			default:
				// wrong choice, thorgh error
				printf("ERROR: WRONG CHOICE\n");
		}	
	}
	return 0;
}
