#include <stdio.h>
#include <stdlib.h>

void print_matrix(int row, int col, int **mat)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

void matrix_input(int row, int col, int **mat)
{
	printf("Enter the elemnts of the matrix: \n");
	for(int i=0; i<row; i++)
	{
		printf("row %d: ", i+1);
		for(int j=0; j<col;j++)
			scanf("%d", &mat[i][j]);
	}
}

int isDiagonal(int row, int col, int **mat)
{
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			if(i!=j && mat[i][j])
				return 0;
		return 1;
}

int isIdentity(int row, int col, int **mat)
{
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			if(i!=j && mat[i][j] || i==j && mat[i][j] !=1)
				return 0;
		return 1;
}

void free_mat(int row, int**mat)
{
	for(int i=0; i<row; i++)
		free(mat[i]);
	free(mat);
}

int main()
{
	int row, col;
	printf("Enter the row and column for Diagoal matrix: ");
	scanf("%d%d", &row, &col);
	int **mat = (int**)malloc(row*sizeof(int*));
	for(int i=0; i<row; i++)
		mat[i] = (int*)malloc(col*sizeof(int));
	matrix_input(row, col, mat);
	printf("The matrix %s Diagonal\n", isDiagonal(row,col,mat) ? "is" : "is not");
	free_mat(row,mat);
	
	printf("Enter the row and column for identity matrix: ");
	scanf("%d%d", &row, &col);
	int **mat1 = (int**)malloc(row*sizeof(int*));
	for(int i=0; i<row; i++)
		mat1[i] = (int*)malloc(col*sizeof(int));
	matrix_input(row, col, mat1);
	printf("The matrix %s identity\n", isIdentity(row,col,mat1) ? "is" : "is not");
	free_mat(row,mat);
	return 0;
}
