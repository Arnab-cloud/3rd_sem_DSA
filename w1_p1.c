#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			mat[i][j] = rand()%10;
}

void matrix_mult(int row1, int col1, int col2, int **mat1, int **mat2, int **mat3)
{
	for(int i=0; i<row1; i++)
		for(int j=0; j<col2; j++)
		{
			mat3[i][j] = 0;
			for(int k=0; k<col1; k++)
				mat3[i][j] += mat1[i][k]*mat2[k][j];
		}
}

void free_mat(int row, int **mat)
{
	for(int i=0; i<row; i++)
		free(mat[i]);
	free(mat);
}

int main()
{
	time_t  t1 = clock();
	srand((unsigned)time(NULL));
	int row1,col1,row2,col2;
	printf("Enter the row and column of the 1st matrix: ");
	scanf("%d%d", &row1, &col1);
	
	printf("Enter the row and column of the 2nd matrix: ");
	scanf("%d%d", &row2, &col2);
	
	if(col1!=row2)
	{
		printf("The matrices are not multipliable\n");
		return 1;
	}
	
	int** mat1 = (int**)malloc(row1*sizeof(int*));
	for(int i=0; i<row1; i++)
		mat1[i]  = (int*)malloc(col1*sizeof(int));
		
	int** mat2 = (int**)malloc(row2*sizeof(int*));
	for(int i=0; i<row2; i++)
		mat2[i]  = (int*)malloc(col2*sizeof(int));
	
	int** mat3 = (int**)malloc(row1*sizeof(int*));
	for(int i=0; i<row1; i++)
		mat3[i]  = (int*)malloc(col2*sizeof(int));

		
	matrix_input(row1,col1,mat1);
	printf("The 1st matrix is: \n");
	//print_matrix(row1,col1,mat1);
	
	matrix_input(row2,col2,mat2);
	printf("The 2nd matrix is: \n");
	//print_matrix(row2,col2,mat2);
	
	matrix_mult(row1,col1,col2,mat1,mat2,mat3);
	printf("The result Matrix is: \n");
	//print_matrix(row1,col2,mat3);
	
	free_mat(row1,mat1);
	free_mat(row2,mat2);
	free_mat(row1,mat3);
	
	time_t t2 = clock();
	printf("\nThe time taken: %f\n", (float)(t2-t1)/(float)CLOCKS_PER_SEC);
	
	return 0;
}
