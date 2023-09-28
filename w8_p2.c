#include <stdio.h>
#include <stdlib.h>

// structue to define node of a linked list
typedef struct node
{
	int val;
	struct node* next;
}node;

// structure to define a queue using a circular linked list
typedef struct queue
{
	node* front, *rear;
}queue;

// function to create node
node* createNode(int data)
{
	node* new = (node*)malloc(sizeof(node));
	new->val = data;
	new->next = NULL;
	return new;
}

// function to create a queue
queue* createQueue()
{
	queue* q = (queue*)malloc(sizeof(queue));
	q->rear = q->front = NULL;
	return q;
}

int isEmpty(queue* q)
{
	return q->front==NULL;
}

// function to enque
void enque(queue* q)
{
	int data;
	printf("Enter data: ");
	scanf("%d", &data);
	node* new = createNode(data);
	if(isEmpty(q))
	{
		q->front = q->rear = new;
		q->rear->next = q->front;
		return;
	}
	new->next = q->front;
	q->rear->next = new;
	q->rear = new;
}


// function to dequeue
void deque(queue* q)
{
	if(isEmpty(q))
	{
		printf("ERROR: The queue is already empty\n");
		return;
	}
	if(q->front==q->rear)
	{
		free(q->front);
		q->front = q->rear = NULL;
		return;
	}
	q->rear->next = q->front->next;
	free(q->front);
	q->front = q->rear->next;
}

// display the front data
void front(queue* q)
{
	if(isEmpty(q))
	{
		printf("ERROR: The queue is already empty\n");
		return;
	}
	printf("The front element is: %d\n", q->front->val);
}

// display the queue
void display(queue* q)
{
	if(isEmpty(q))
	{
		printf("ERROR: The queue is already empty\n");
		return;
	}
	node* temp= q->front;
	printf("The queue is:\n");
	do
	{
		printf("%d ", temp->val);
		temp = temp->next;
	}while(temp!=(q->front));
	printf("\n\n");
}

// free up the spacce

void deleteNode(node* head, node* temp)
{
	if(temp->next==head)
	{
		free(temp);
		return;
	}
	deleteNode(head,temp->next);
	free(temp);
}

void deleteQueue(queue* q)
{
	if(q->front)
		deleteNode(q->front,q->front);
	free(q);
}

int main()
{
	int ch;
	queue* Q = createQueue();
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
