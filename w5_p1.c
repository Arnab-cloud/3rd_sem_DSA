#include<stdio.h>

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void printArray(int *arr, int size)
{
	for(int i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


void improvedBubbleSort(int *arr, int size)
{
	int t, bound = size-1, pass = 1;
	do
	{
		t=0;
		for(int i=0; i<bound; i++)
		{
			if(arr[i]>arr[i+1])
			{
				swap(&arr[i], &arr[i+1]);
				t=i;
			}
		}
		bound = t;
		printf("pass %d\n", pass++);
		printArray(arr,size);
	}while(t>0);
}


int main()
{
	int arr[] = {8,9,2,4,1,-9,-3,0,42};
	int size = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	improvedBubbleSort(arr,size);
	printArray(arr,size);
	return 0;
}
