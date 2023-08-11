#include <stdio.h>

void swap(int* a, int* b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;	
}

void reverse_array(int size, int *arr)
{
	for(int i=0; i<size/2; i++)
		swap(arr+i, arr+(size-i-1));
}

void print_array(int size, int *arr)
{
	for(int i=0; i<size; i++)
		printf("%d ", arr[i]);
		printf("\n");
}

int main()
{
	int size;
	printf("Enter size of the array: ");
	scanf("%d", &size);
	int arr[size];
	printf("Enter the elements of the array: ");
	for(int i=0; i<size; i++)
		scanf("%d", &arr[i]);
	printf("The array is before reversing: \n");
	print_array(size, arr);
	
	reverse_array(size,arr);
	printf("After reversing: \n");
	print_array(size, arr);
	
	return 0;
	
}
