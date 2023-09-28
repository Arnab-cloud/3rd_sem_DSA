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

void insertionSort(int *arr, int size)
{
	int pass = 1;
	for(int i=1; i<size; i++)
	{
		int temp = arr[i];
		int j = i-1;
		while(j >-1 && arr[j] > temp)
			arr[(j--)+1] = arr[j];
		arr[j+1] = temp;
		printf("pass %d:\n", pass++);
		printArray(arr,size);
	}
}

void selectionSort(int *arr, int size)
{
	int pass=1;
	for(int i=0; i<size-1; i++)
	{
		int min = i;
		for(int j=i+1; j<size; j++)
			if(arr[j] < arr[min])
				min = j;
		if(i!=min)
			swap(&arr[i], &arr[min]);
		printf("pass %d:\n", pass++);
		printArray(arr,size);
	}
}

int main()
{
	//int arr[] = {};
	int arr[] = {2,2,5,1,0,8,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("Array before soring: \n");
	printArray(arr,size);
	insertionSort(arr,size);
	printf("\nArray ater sorting: \n");
	printArray(arr,size);
	return 0;
}
