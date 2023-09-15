#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
	int *arr, count, capacity;
}heap;

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void printArray(int* arr, int size)
{
	for(int i =0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void inputArray(int *arr, int size)
{
	for(int i=0; i<size; i++)
		scanf("%d", &arr[i]);
}

void printHeap(heap* h)
{
	printf("Heap untill now\n");
	printArray(h->arr,h->count);
}

heap* createHeap(int size)
{
	heap* h = (heap*)malloc(sizeof(heap));
	if(!h)
	{
		printf("ERROR: Memory allocation during creating heap\n");
		return NULL;
	}
	h->arr = (int*)malloc(sizeof(int)*size);
	if(!(h->arr))
	{
		printf("ERROR: Memory allocation during creating heap array\n");
		return NULL;
	}
	h->capacity = size;
	return h;
}


void min_heapify(heap* h, int i)
{
	int left = 2*i +1, right = 2*i +2, min=i;
	if(left < h->count && h->arr[min] > h->arr[left])
		min = left;
	if(right < h->count && h->arr[min] > h->arr[right])
		min = right;
	if(i!=min)
	{
		swap(&(h->arr[i]),&h->arr[min]);
		min_heapify(h,min);
	}
}

void buildHeap(heap*h)
{
	for(int i=(h->count)/2-1; i>-1; i--)
		min_heapify(h,i);
}

void enque(heap*h,int data)
{
	if(h->count == h->capacity)
	{
		h->capacity *= 2;
		h->arr = realloc(h->arr,h->capacity);
	}
	h->arr[++(h->count)] = data;
	int i=h->count-1;
	while(i>0 && data < h->arr[2*i-1])
	{
		h->arr[i] = h->arr[2*i-1];
		i = 2*i-1;
	}
	h->arr[i] = data;	
}

int deque(heap* h)
{
	if(!(h->count))
		return -1;
	--(h->count);
	if(h->count)
	{
		swap(&(h->arr[0]), &(h->arr[h->count]));
		min_heapify(h,0);
	}
	return h->arr[h->count];
}

void deletePriorityQueue(heap* h)
{
	free(h->arr);
	free(h);
}

int main()
{
	int size,data,ch;
	printf("Enter the size of the queue: ");
	scanf("%d", &size);
	heap* h = createHeap(size);
	printf("Enter the elements: ");
	inputArray(h->arr,h->capacity);
	h->count = size;
	buildHeap(h);
	printHeap(h);

	do
	{
		printf("\nMENU:\n1. Enque\n2. Deque\n3. Display Queue\n4. Get Element with maximum priority\n5. Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter the data: ");
				scanf("%d", &data);
				enque(h,data);
				break;
			case 2:
				if(!(h->count))
					printf("The queue is empty\n");
				else
					printf("Dequeued data = %d\n", deque(h));
				break;
			case 3:
				if(!(h->count))
					printf("The queue is empty\n");
				else
					printHeap(h);
				break;
			case 4:
				if(!(h->count))
					printf("The queue is empty\n");
				else
					printf("The element of most priority: %d\n", h->arr[0]);
				break;
			case 5:
				printf("Exiting...\n");
				deletePriorityQueue(h);
				exit(1);
			default:
				printf("ERROR: Wrong Choice\n");
		}
	}while(ch!=5);
	return 0;
}
