#include <stdio.h>

void print_matrix(int row, int col, int mat[][col])
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

void matrix_input(int row, int col, int mat[][col])
{
	printf("Enter the elements of the matrix: \n");
	for(int i=0; i<row; i++)
	{
		printf("row %d: ",i+1);
		for(int j=0; j<col; j++)
			scanf("%d", &mat[i][j]);
	}
}

int main()
{
	int row1,row2,col1,col2;
	printf("Enter the row and column of the 1st matrix: ");
	scanf("%d%d", &row1,&col1);
	printf("Enter the row and column of the 1st matrix: ");
	scanf("%d%d", &row1,&col1);
}
